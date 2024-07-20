#ifndef LIB_WEBSERVER_REQUEST_H
#define LIB_WEBSERVER_REQUEST_H

#include <microhttpd.h>
#include <string>
#include <iostream>
#include <unordered_map>

namespace Lib {

	namespace WebServer {

		class Request {

			public:
				Request(
					std::string,
					std::string,
					std::string,
					std::string
				);
				~Request();
				std::string url(void);
				std::string method(void);
				std::string version(void);
				std::string content(void);

			private:
				std::string st_url;
				std::string st_method;
				std::string st_version;
				std::string st_content;
		};
	}
}

#endif
