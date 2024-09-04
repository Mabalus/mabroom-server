#ifndef SERVER_CONTROLLER_H
#define SERVER_CONTROLLER_H

#include "../Application/Controller.h"
#include "../Application/Dispatcher.h"
#include "../Lib/Util/Exception.h"
#include "../Lib/Util/String.h"
#include "../Lib/WebServer/Controller.h"
#include "../Dispatcher/Base.h"
#include <iostream>
#include <memory>

namespace application {

	class Controller;

}

namespace server {

	class Controller final {
		public:
			Controller(std::shared_ptr<application::Controller> po_application);
			~Controller();
			std::shared_ptr<lib::webserver::Controller> webserver(void);
		private:
			std::shared_ptr<application::Controller> po_application;
			std::shared_ptr<lib::webserver::Controller> po_webserver;
			void startWebServer(void);
	};
}

#endif
