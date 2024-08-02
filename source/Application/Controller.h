#ifndef APPLICATION_CONTROLLER_H
#define APPLICATION_CONTROLLER_H

#include "../Lib/WebServer/Controller.h"
#include "../Lib/Util/String.h"
#include <microhttpd.h>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <memory>

namespace Application {

	class Controller {
		public:
			Controller();
			~Controller();
			void run(void);
		private:
			static const uint16_t PORT;
			std::shared_ptr<lib::webserver::Controller> po_webserver;
	};
}

#endif
