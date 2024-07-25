#ifndef LIB_UTIL_UUID_H
#define LIB_UTIL_UUID_H

#include "String.h"
#include <uuid/uuid.h>
#include <iostream>

namespace lib {

	namespace util {

		class UUID  {

			public:
				UUID();
				~UUID();
				const uuid_t &get(void) const;
				lib::util::String string(void);
				void trace(void);
				lib::util::UUID &operator=(const UUID &);

			private:
				uuid_t t_uuid;
		};
	}
}

#endif
