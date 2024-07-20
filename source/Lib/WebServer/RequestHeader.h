#ifndef LIB_WEBSERVER_REQUESTHEADER_H
#define LIB_WEBSERVER_REQUESTHEADER_H

#include <string>

namespace Lib {

	namespace WebServer {

		class RequestHeader {
			public:
				RequestHeader(const char * , const char *);
				~RequestHeader();
				std::string name(void);
				std::string value(void);
			private:
				std::string st_name;
				std::string st_value;
		};
	}
}

#endif
