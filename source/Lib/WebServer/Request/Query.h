#ifndef LIB_WEBSERVER_REQUEST_QUERY_H
#define LIB_WEBSERVER_REQUEST_QUERY_H

#include "../Connection.h"
#include "../../Util/String.h"
#include <microhttpd.h>
#include <any>
#include <iostream>
#include <memory>
#include <typeinfo>
#include <unordered_map>
#include <vector>

namespace lib {

	namespace webserver {

		namespace request {

			class Query {
				public:
					Query(std::shared_ptr<lib::webserver::Connection> po_connection);
					~Query();
					bool has(lib::util::String);
					std::shared_ptr<std::vector<lib::util::String>> list(void);
					void trace(void);
					std::any value(lib::util::String);
					
				private:
					std::shared_ptr<std::unordered_map<std::string,std::any>> phmx_query;
			};
		}
	}
}

#endif
