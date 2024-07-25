#ifndef LIB_WEBSERVER_RESPONSE_H
#define LIB_WEBSERVER_RESPONSE_H

#include "Response/Header.h"
#include "../Util/String.h"
#include <microhttpd.h>
#include <cstring>
#include <vector>

namespace lib {

	namespace webserver {

		class Response {

			public:
				Response(MHD_Connection *);
				~Response();
				lib::webserver::response::Header *header(void);
				int send(u_int32_t in_code);
				void setContent(lib::util::String *,lib::util::String);

			private:
				MHD_Connection *pt_connection;
				lib::util::String *st_content;
				lib::webserver::response::Header *o_header;
		};
	}
}

#endif