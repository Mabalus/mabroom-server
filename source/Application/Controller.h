#ifndef APPLICATION_CONTROLLER_H
#define APPLICATION_CONTROLLER_H

#include "PointerDestroyer.h"
#include "Dispatcher.h"
#include "../Dispatcher/Base.h"
#include "../Lib/JSON/Controller.h"
#include "../Lib/Util/Environment.h"
#include "../Lib/Util/String.h"
#include "../Lib/WebServer/Controller.h"
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <memory>

namespace application {

	class Dispatcher;

	class Controller : public std::enable_shared_from_this<Controller> {
		public:
			static void run(void);			
			void dispatcher(
				std::shared_ptr<application::Controller> po_application,
				std::shared_ptr<lib::webserver::Request> po_request,
				std::shared_ptr<lib::webserver::Response> po_response
			);
			Controller(const Controller &) = delete;
    		Controller &operator=(const Controller &) = delete;
		private:
			Controller();
			~Controller();
			friend struct pointerDestroyer<application::Controller>;
			std::shared_ptr<lib::json::Node> po_config;
			std::shared_ptr<lib::webserver::Controller> po_webserver;
			void start(std::shared_ptr<application::Controller>);
			void loadConfig(void);
	};
}

#endif
