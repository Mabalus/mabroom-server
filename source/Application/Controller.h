#ifndef APPLICATION_CONTROLLER_H
#define APPLICATION_CONTROLLER_H

#include "PointerDestroyer.h"
#include "Dispatcher.h"
#include "../Dispatcher/Base.h"
#include "../Data/Controller.h"
#include "../Middleware/Controller.h"
#include "../Resource/Controller.h"
#include "../Server/Controller.h"
#include "../Lib/JSON/Controller.h"
#include "../Lib/Util/Environment.h"
#include "../Lib/Util/Exception.h"
#include "../Lib/Util/String.h"
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <memory>

namespace data {
	class Controller;
}

namespace middleware {
	class Controller;
}

namespace resource {
	class Controller;
}

namespace server {
	class Controller;
}

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
			std::shared_ptr<data::Controller> data(void);
			std::shared_ptr<middleware::Controller> middleware(void);
			std::shared_ptr<resource::Controller> resource(void);
			std::shared_ptr<server::Controller> server(void);
			Controller(const Controller &) = delete;
    		Controller &operator=(const Controller &) = delete;
		private:
			Controller();
			~Controller();
			friend struct pointerDestroyer<application::Controller>;
			std::shared_ptr<data::Controller> po_data;
			std::shared_ptr<middleware::Controller> po_middleware;
			std::shared_ptr<resource::Controller> po_resource;
			std::shared_ptr<server::Controller> po_server;
			void start(std::shared_ptr<application::Controller>);
	};
}

#endif
