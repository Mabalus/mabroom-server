#ifndef APPLICATION_CONTROLLER_H
#define APPLICATION_CONTROLLER_H

#include "../Lib/WebServer/Controller.h"
#include "../Lib/Util/String.h"
#include <microhttpd.h>
#include <iostream>
#include <cstring>
#include <memory>

namespace Application {

	class Controller {
		public:
			static void run();

		private:
			static const u_int16_t PORT = 8000;
	};
}

#endif
