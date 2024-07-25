#ifndef LIB_WEBSERVER_RESPONSEHEADER_H
#define LIB_WEBSERVER_RESPONSEHEADER_H

#include "../../Util/String.h"
#include <iostream>
#include <unordered_map>
#include <vector>

namespace lib {

	namespace webserver {

		namespace response {

			class Header {

				public:
					Header();
					~Header();
					std::vector<lib::util::String> *list(void);
					lib::util::String get(lib::util::String);
					bool has(lib::util::String);
					void set(lib::util::String, lib::util::String);
					void unset(lib::util::String);
				private:
					std::unordered_map<std::string, std::string> vh_header;
			};
		}
	}
}

#endif
