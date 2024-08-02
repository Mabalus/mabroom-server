#ifndef LIB_WEBSERVER_RESPONSE_H
#define LIB_WEBSERVER_RESPONSE_H

#include "Connection.h"
#include "Response/Header.h"
#include "../Util/String.h"
#include <microhttpd.h>
#include <cstdint>
#include <cstring>
#include <vector>

namespace lib {

	namespace webserver {

		class Response {

			public:
				Response(std::shared_ptr<lib::webserver::Connection>);
				~Response();
				std::shared_ptr<lib::webserver::response::Header> header(void);
				bool send(uint16_t in_code);
				void setContent(lib::util::String,lib::util::String);

			private:
				std::shared_ptr<lib::webserver::Connection> po_connection;
				std::unique_ptr<lib::util::String> st_content;
				std::shared_ptr<lib::webserver::response::Header> o_header;
		};
	}
}

#endif