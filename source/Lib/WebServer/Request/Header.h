#ifndef LIB_WEBSERVER_REQUEST_HEADER_H
#define LIB_WEBSERVER_REQUEST_HEADER_H

#include "../Connection.h"
#include "../../Util/String.h"
#include <microhttpd.h>
#include <memory>
#include <iostream>
#include <unordered_map>
#include <vector>

namespace lib {

	namespace webserver {

		namespace request {

			class Header {
				public:
					Header(std::shared_ptr<lib::webserver::Connection> po_connection);
					~Header();
					bool has(lib::util::String);
					std::vector<lib::util::String> list(void);
					void dump(void);
					lib::util::String operator[](lib::util::String);
				private:
					std::unique_ptr<std::unordered_map<std::string, std::string>> phst_header;
			};
		}
	}
}

#endif
