#ifndef LIB_WEBSERVER_REQUESTQUERY_H
#define LIB_WEBSERVER_REQUESTQUERY_H

#include "../Util/String.h"
#include <microhttpd.h>
#include <iostream>
#include <unordered_map>
#include <vector>

namespace Lib {

	namespace WebServer {

		struct query_t {
			bool bo_array;
			void *pmx_value;
		};

		class RequestQuery {
			public:
				const bool QUERY_TYPE_ARRAY = true;
				const bool QUERY_TYPE_SCALAR = false;
				RequestQuery(MHD_Connection *o_connection);
				~RequestQuery();
				bool has(Lib::Util::String);
				std::vector<Lib::Util::String> *list(void);
				void trace(void);
				bool type(Lib::Util::String);
				void *value(Lib::Util::String);
				
			private:
				std::unordered_map<std::string, Lib::WebServer::query_t> *phmx_query;
		};
	}
}

#endif
