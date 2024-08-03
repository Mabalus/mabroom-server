#ifndef DISPATCHER_BASE_H
#define DISPATCHER_BASE_H

#include "../Application/Dispatcher.h"
#include <iostream>
#include <memory>

namespace application {
	class Dispatcher;
}

namespace dispatcher {

	class Base {
		public:
			static void routing(std::shared_ptr<application::Dispatcher>);
	};
}

#endif
