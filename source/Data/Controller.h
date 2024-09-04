#ifndef DATA_CONTROLLER_H
#define DATA_CONTROLLER_H

#include "../Application/Controller.h"
#include "../Lib/JSON/Controller.h"
#include <iostream>
#include <memory>

namespace application {

	class Controller;

}

namespace data {

	class Controller final {
		public:
			Controller(std::shared_ptr<application::Controller> po_application);
			~Controller();
			std::shared_ptr<lib::json::Node> configuration(void);
		private:
			std::shared_ptr<application::Controller> po_application;
			std::shared_ptr<lib::json::Node> po_configuration;
			void loadConfiguration(void);
	};
}

#endif
