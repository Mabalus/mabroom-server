#ifndef LIB_WEBSERVER_RESPONSE_H
#define LIB_WEBSERVER_RESPONSE_H

#include "ResponseHeader.h"
#include "../Util/String.h"
#include <microhttpd.h>
#include <cstring>
#include <vector>

namespace Lib {

	namespace WebServer {

		class Response {

			public:
				Response(MHD_Connection *);
				~Response();
				Lib::WebServer::ResponseHeader *header(void);
				int send(u_int32_t in_code);
				void setContent(Lib::Util::String *,Lib::Util::String);

			private:
				MHD_Connection *pt_connection;
				Lib::Util::String *st_content;
				Lib::WebServer::ResponseHeader *o_header;
		};
	}
}

#endif