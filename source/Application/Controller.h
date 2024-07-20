#ifndef APPLICATION_CONTROLLER_H
#define APPLICATION_CONTROLLER_H

#include "../Lib/WebServer/Request.h"
#include "../Lib/WebServer/Response.h"
#include <microhttpd.h>
#include <iostream>
#include <string>
#include <cstring>

namespace Application {

	class Controller {
		public:
			static void run();
			static int dispatcher(
				Lib::WebServer::Request *,
				Lib::WebServer::Response *
			);

		private:
			static const u_int16_t PORT = 8000;
			static MHD_Daemon *pt_daemon;
	};
}

#endif
