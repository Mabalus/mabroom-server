#ifndef APPLICATION_DISPATCHER_H
#define APPLICATION_DISPATCHER_H

#include "Controller.h"
#include "../Lib/Util/String.h"
#include "../Lib/WebServer/Request.h"
#include "../Lib/WebServer/Response.h"
#include <iostream>
#include <memory>
#include <queue>
#include <vector>

namespace application {

	class Controller;

	class Dispatcher {
		public:
			Dispatcher(
				std::shared_ptr<application::Controller>,
				std::shared_ptr<lib::webserver::Request>,
				std::shared_ptr<lib::webserver::Response>
			);
			~Dispatcher();
			std::shared_ptr<application::Controller> application(void);
			std::shared_ptr<lib::util::String> path(void);
			std::shared_ptr<lib::webserver::Request> request(void);
			std::shared_ptr<lib::webserver::Response> response(void);
			void dump(void);
		private:
			std::shared_ptr<application::Controller> po_application;
			std::shared_ptr<lib::webserver::Request> po_request;
			std::shared_ptr<lib::webserver::Response> po_response;
			std::shared_ptr<std::vector<lib::util::String>> pvst_path;
	};
}

#endif
