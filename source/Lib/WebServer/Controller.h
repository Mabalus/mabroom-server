#ifndef LIB_WEBSERVER_CONTROLLER_H
#define LIB_WEBSERVER_CONTROLLER_H

#include "./Connection.h"
#include "./Request.h"
#include "./Response.h"
#include "../Util/String.h"
#include <microhttpd.h>
#include <cstring>
#include <functional>
#include <iostream>
#include <memory>

namespace lib {

	namespace webserver {
				
		class Controller {
			public:
				using callback_t = std::function<void(std::shared_ptr<lib::webserver::Request>,std::shared_ptr<lib::webserver::Response>)>;
				Controller(u_int16_t, std::shared_ptr<callback_t>);
				~Controller();
				bool start(void);
				void stop(void);
				u_int16_t getPort(void);
				void setPort(u_int16_t);

			private:

				MHD_Daemon *pt_daemon;
				std::shared_ptr<callback_t> fn_callback;
				u_int16_t uin_port;
				static int processRequest(
					void *,
					MHD_Connection *,
					const char *,
					const char *,
					const char *,
					const char *,
					size_t *,
					void **
				);
		};
	}
}

#endif
