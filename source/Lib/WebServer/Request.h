#ifndef LIB_WEBSERVER_REQUEST_H
#define LIB_WEBSERVER_REQUEST_H

#include "Connection.h"
#include "Request/Header.h"
#include "Request/Query.h"
#include "../Util/String.h"
#include "../Util/UUID.h"
#include <microhttpd.h>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <memory>

namespace lib {

	namespace webserver {

		class Request {

			public:
				Request(
					std::shared_ptr<lib::webserver::Connection>,
					lib::util::String,
					lib::util::String,
					lib::util::String
				);
				~Request();
				std::shared_ptr<lib::webserver::Connection> connection(void);
				std::shared_ptr<lib::webserver::request::Header> header(void);
				std::shared_ptr<lib::webserver::request::Query> query(void);
				lib::util::UUID id(void);
				lib::util::String url(void);
				lib::util::String method(void);
				void trace(void);
				lib::util::String version(void);
				lib::util::String content(void);

			private:
				std::shared_ptr<lib::webserver::Connection> po_connection;
				lib::util::String st_url;
				lib::util::String st_method;
				lib::util::String st_version;
				std::shared_ptr<lib::util::String> pmx_content;
				lib::util::UUID o_id;
				std::shared_ptr<lib::webserver::request::Header> po_header;
				std::shared_ptr<lib::webserver::request::Query> po_query;
		};
	}
}

#endif
