#ifndef LIB_UTIL_STRING_H
#define LIB_UTIL_STRING_H

#include <algorithm>
#include <cctype>
#include <cstring>
#include <regex>
#include <string>
#include <vector>

namespace lib {

	namespace util {

		class String : public std::string {

			public:
				String() = default;
				String(const std::string &);
				String(const char*);
				void toLower(void);
				void toUpper(void);
				static lib::util::String lower(const lib::util::String st_input);
				static std::shared_ptr<std::vector<lib::util::String>> split(const lib::util::String st_input,const char ch_delimiter);
				static std::shared_ptr<std::vector<lib::util::String>> split(const lib::util::String st_input,const lib::util::String st_delimiter);
				static std::shared_ptr<std::vector<lib::util::String>> split(const lib::util::String st_input, const std::regex rg_delimiter);
				static lib::util::String upper(const lib::util::String st_input);		
		};
	}
}

#endif
