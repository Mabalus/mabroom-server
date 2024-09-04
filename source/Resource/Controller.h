#ifndef RESOURCE_CONTROLLER_H
#define RESOURCE_CONTROLLER_H

#include "../Application/Controller.h"
#include <iostream>
#include <memory>

namespace application {

	class Controller;

}

namespace resource {

	class Controller final {
		public:
			Controller(std::shared_ptr<application::Controller> po_application);
			~Controller();
			std::shared_ptr<application::Controller> application(void);
		private:
			std::shared_ptr<application::Controller> po_application;
	};
}

#endif
