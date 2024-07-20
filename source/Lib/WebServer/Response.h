#ifndef LIB_WEBSERVER_RESPONSE_H
#define LIB_WEBSERVER_RESPONSE_H

#include "ResponseHeader.h"
#include <microhttpd.h>
#include <string>
#include <cstring>
#include <vector>

namespace Lib {

	namespace WebServer {

		class Response {

			public:
				Response(MHD_Connection *);
				~Response();
				Lib::WebServer::ResponseHeader *header(void);
				int send(void);
				void setContent(std::string *,std::string);

			private:
				MHD_Connection *pt_connection;
				std::string *st_content;
				Lib::WebServer::ResponseHeader *o_header;
		};
	}
}

#endif
