#ifndef LIB_UTIL_STRING_H
#define LIB_UTIL_STRING_H

#include <string>
#include <cstring>
#include <cctype>
#include <algorithm>

namespace lib {

	namespace util {

		class String : public std::string {

			public:
				String() = default;
				String(const std::string&);
				String(const char*);
				std::string lower() const;
				void toLower();
				void toUpper();
				std::string upper() const;
		};
	}
}

#endif
