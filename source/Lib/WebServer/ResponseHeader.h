#ifndef LIB_WEBSERVER_RESPONSEHEADER_H
#define LIB_WEBSERVER_RESPONSEHEADER_H

#include "../Util/String.h"
#include <iostream>
#include <unordered_map>
#include <vector>

namespace Lib {

	namespace WebServer {

		class ResponseHeader {

			public:
				ResponseHeader();
				~ResponseHeader();
				std::vector<Lib::Util::String> *list(void);
				Lib::Util::String get(Lib::Util::String);
				bool has(Lib::Util::String);
				void set(Lib::Util::String, Lib::Util::String);
				void unset(Lib::Util::String);
			private:
				std::unordered_map<std::string, std::string> vh_header;
		};
	}
}

#endif
