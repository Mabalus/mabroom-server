#ifndef LIB_UTIL_UUID_H
#define LIB_UTIL_UUID_H

#include "String.h"
#include <uuid/uuid.h>
#include <iostream>

namespace Lib {

	namespace Util {

		class UUID  {

			public:
				UUID();
				~UUID();
				const uuid_t &get(void) const;
				Lib::Util::String string(void);
				void trace(void);
				Lib::Util::UUID &operator=(const UUID &);

			private:
				uuid_t t_uuid;
		};
	}
}

#endif
