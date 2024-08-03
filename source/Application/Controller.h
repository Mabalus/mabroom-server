#ifndef APPLICATION_CONTROLLER_H
#define APPLICATION_CONTROLLER_H

#include "Dispatcher.h"
#include "../Dispatcher/Base.h"
#include "../Lib/WebServer/Controller.h"
#include "../Lib/Util/String.h"
#include <cstdint>
#include <iostream>
#include <memory>

namespace application {

	class Dispatcher;

	class Controller : public std::enable_shared_from_this<Controller> {
		public:
			Controller();
			~Controller();
			void run(void);
			void dispatcher(
				std::shared_ptr<lib::webserver::Request> po_request,
				std::shared_ptr<lib::webserver::Response> po_response
			);
		private:
			static const uint16_t PORT;
			std::shared_ptr<lib::webserver::Controller> po_webserver;
	};
}

#endif
