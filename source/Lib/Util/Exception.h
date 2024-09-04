#ifndef LIB_UTIL_EXCEPTION_H
#define LIB_UTIL_EXCEPTION_H

#include "String.h"
#include "../Type.h"
#include <chrono>
#include <cstdint>
#include <iostream>
#include <memory>

namespace lib {

	namespace util {

		class Exception {
			public:
				Exception(
					uint16_t in_code,
					lib::util::String st_tag,
					lib::util::String st_class,
					lib::util::String st_method,
					uint64_t in_line,
					lib::util::String st_message,
					std::shared_ptr<lib::util::Exception> po_exception
				);
				~Exception();
				uint16_t code(void);
				lib::util::String tag(void);
				lib::util::String classname(void);
				lib::util::String method(void);
				uint64_t line(void);
				lib::util::String message(void);
				std::shared_ptr<lib::util::Exception> trace(void);
				size_t logged(void);
				void dump(void);
			private:
				uint16_t in_code;
				lib::util::String st_tag;
				lib::util::String st_class;
				lib::util::String st_method;
				uint64_t in_line;
				lib::util::String st_message;
				std::shared_ptr<lib::util::Exception> po_child;
				size_t in_nanotimestamp;
		};

	}
}

#endif
