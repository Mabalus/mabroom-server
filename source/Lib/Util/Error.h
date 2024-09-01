#ifndef LIB_UTIL_ERROR_H
#define LIB_UTIL_ERROR_H

#include "String.h"
#include "../Type.h"
#include <chrono>
#include <cstdint>
#include <iostream>

namespace lib {

	namespace util {

		class Error {
			public:
				Error(
					uint16_t in_code,
					lib::util::String st_tag,
					lib::util::String st_category,
					lib::util::String st_type,
					lib::util::String st_message
				);
				~Error();
				uint16_t code(void);
				lib::util::String tag(void);
				lib::util::String category(void);
				lib::util::String type(void);
				lib::util::String message(void);
				size_t logged(void);
				void dump(void);
			private:
				uint16_t in_code;
				lib::util::String st_tag;
				lib::util::String st_category;
				lib::util::String st_type;
				lib::util::String st_message;
				size_t in_nanotimestamp;
		};

	}
}

#endif
