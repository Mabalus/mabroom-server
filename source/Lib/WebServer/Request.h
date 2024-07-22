#ifndef LIB_WEBSERVER_REQUEST_H
#define LIB_WEBSERVER_REQUEST_H

#include "RequestHeader.h"
#include "RequestQuery.h"
#include "../Util/String.h"
#include "../Util/UUID.h"
#include <microhttpd.h>
#include <iostream>
#include <unordered_map>
#include <vector>

namespace Lib {

	namespace WebServer {

		class Request {

			public:
				Request(
					MHD_Connection *o_connection,
					Lib::Util::String,
					Lib::Util::String,
					Lib::Util::String,
					Lib::Util::String
				);
				~Request();
				MHD_Connection *connection(void);
				Lib::WebServer::RequestHeader *header(void);
				Lib::WebServer::RequestQuery *query(void);
				Lib::Util::UUID id(void);
				Lib::Util::String url(void);
				Lib::Util::String method(void);
				void trace(void);
				Lib::Util::String version(void);
				void *content(void);

			private:
				MHD_Connection *o_connection;
				Lib::Util::String st_url;
				Lib::Util::String st_method;
				Lib::Util::String st_version;
				void *pmx_content;
				Lib::Util::UUID o_id;
				Lib::WebServer::RequestHeader *o_header;
				Lib::WebServer::RequestQuery *o_query;
		};
	}
}

#endif
