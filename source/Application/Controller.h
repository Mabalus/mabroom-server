#ifndef APPLICATION_CONTROLLER_H
#define APPLICATION_CONTROLLER_H

#include "../Lib/WebServer/Connection.h"
#include "../Lib/WebServer/Request.h"
#include "../Lib/WebServer/Response.h"
#include "../Lib/Util/String.h"
#include <microhttpd.h>
#include <iostream>
#include <cstring>
#include <memory>

namespace Application {

	class Controller {
		public:
			static void run();
			static int dispatcher(
				lib::webserver::Request *,
				lib::webserver::Response *
			);

		private:
			static const u_int16_t PORT = 8000;
			static MHD_Daemon *pt_daemon;
	};
}

#endif
