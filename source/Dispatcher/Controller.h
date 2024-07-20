#ifndef APPLICATION_H
#define APPLICATION_H

namespace Dispatcher {

	class Controller {
		public:
			Controller(const std::string &name, int version);
			~Controller();
			void routing()
	};
}

#endif
