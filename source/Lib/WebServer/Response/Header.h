#ifndef LIB_WEBSERVER_RESPONSEHEADER_H
#define LIB_WEBSERVER_RESPONSEHEADER_H

#include "../../Util/String.h"
#include <iostream>
#include <memory>
#include <unordered_map>
#include <vector>

namespace lib {

	namespace webserver {

		namespace response {

			class Header {

				public:
					Header();
					~Header();
					lib::util::String get(lib::util::String);
					bool has(lib::util::String);
					std::shared_ptr<const std::unordered_map<std::string, std::string>> iterator();
					std::vector<lib::util::String> list(void);
					void set(lib::util::String,lib::util::String);
					void trace(void);
					void unset(lib::util::String);
				private:
					std::shared_ptr<std::unordered_map<std::string, std::string>> phst_header;
			};
		}
	}
}

#endif
