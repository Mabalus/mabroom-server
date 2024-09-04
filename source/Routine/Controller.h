#ifndef ROUTINE_CONTROLLER_H
#define ROUTINE_CONTROLLER_H

#include "../Application/Controller.h"
#include <iostream>
#include <memory>

namespace application {

	class Controller;

}

namespace routine {

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
