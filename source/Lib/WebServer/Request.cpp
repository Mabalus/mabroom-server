#include "Request.h"

Lib::WebServer::Request::Request(
	std::string st_url,
	std::string st_method,
	std::string st_version,
	std::string st_content
) {
	std::cout << " >>>>>>>>>> st_url : " << st_url << std::endl;  
}

Lib::WebServer::Request::~Request() {

}