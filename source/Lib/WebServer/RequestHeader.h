#ifndef LIB_WEBSERVER_REQUESTHEADER_H
#define LIB_WEBSERVER_REQUESTHEADER_H

#include "../Util/String.h"
#include <microhttpd.h>
#include <iostream>
#include <unordered_map>
#include <vector>

namespace Lib {

	namespace WebServer {

		class RequestHeader {
			public:
				RequestHeader(MHD_Connection *o_connection);
				~RequestHeader();
				bool has(Lib::Util::String);
				std::vector<Lib::Util::String> *list(void);
				void trace(void);
				Lib::Util::String operator[](Lib::Util::String);
			private:
				std::unordered_map<std::string, std::string> *phst_header;
		};
	}
}

#endif
