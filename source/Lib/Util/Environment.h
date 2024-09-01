#ifndef LIB_UTIL_ENVIRONMENT_H
#define LIB_UTIL_ENVIRONMENT_H

#include "String.h"
#include "../Type.h"
#include <cstdlib>
#include <cerrno>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <vector>

namespace lib {

	namespace util {

		class Environment {
			public:
				static std::shared_ptr<std::vector<lib::util::String>> list(void);
				static std::shared_ptr<lib::util::String> get(const char *);
				static std::shared_ptr<lib::util::String> get(lib::util::String);
				static void dump(void);
		};

	}
}

#endif
