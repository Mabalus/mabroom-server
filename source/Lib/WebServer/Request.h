#ifndef LIB_WEBSERVER_REQUEST_H
#define LIB_WEBSERVER_REQUEST_H

#include "Connection.h"
#include "Request/Header.h"
#include "Request/Query.h"
#include "../Util/String.h"
#include "../Util/UUID.h"
#include <microhttpd.h>
#include <iostream>
#include <memory>

namespace lib {

	namespace webserver {

		class Request {

			public:
				Request(
					std::shared_ptr<lib::webserver::Connection>,
					lib::util::String,
					lib::util::String,
					lib::util::String,
					std::shared_ptr<lib::util::String>
				);
				~Request();
				const std::shared_ptr<lib::util::String> body(void) const;
				const std::shared_ptr<lib::util::String> boundary(void) const;
				std::shared_ptr<lib::webserver::Connection> connection(void);
				const std::shared_ptr<lib::util::String> contentType(void) const;
				std::shared_ptr<lib::webserver::request::Header> header(void);
				lib::util::UUID id(void);
				lib::util::String method(void);
				std::shared_ptr<lib::webserver::request::Query> query(void);				
				void dump(void);
				lib::util::String url(void);
				lib::util::String version(void);

			private:
				lib::util::UUID o_id;
				std::shared_ptr<lib::webserver::Connection> po_connection;
				std::shared_ptr<lib::webserver::request::Header> po_header;
				std::shared_ptr<lib::webserver::request::Query> po_query;
				std::shared_ptr<lib::util::String> pst_body;
				std::shared_ptr<lib::util::String> pst_boundary;
				std::shared_ptr<lib::util::String> pst_content_type;
				lib::util::String st_method;
				lib::util::String st_url;
				lib::util::String st_version;
		};
	}
}

#endif
