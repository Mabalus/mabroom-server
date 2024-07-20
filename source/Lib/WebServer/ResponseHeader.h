#ifndef LIB_WEBSERVER_RESPONSEHEADER_H
#define LIB_WEBSERVER_RESPONSEHEADER_H

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

namespace Lib {

	namespace WebServer {

		class ResponseHeader {

			public:
				ResponseHeader();
				~ResponseHeader();
				std::vector<std::string> *list(void);
				std::string get(std::string);
				bool has(std::string);
				void set(std::string, std::string);
				void unset(std::string);
			private:
				std::unordered_map<std::string, std::string> vh_header;
		};
	}
}

#endif
