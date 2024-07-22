#include "Request.h"

Lib::WebServer::Request::Request(
	MHD_Connection *o_connection,
	Lib::Util::String st_url,
	Lib::Util::String st_method,
	Lib::Util::String st_version,
	Lib::Util::String st_content
) : o_connection(o_connection),  
	st_url(st_url),
	st_method(st_method),
	st_version(st_version)
{
	this->o_header = new Lib::WebServer::RequestHeader(o_connection);
	this->o_query = new Lib::WebServer::RequestQuery(o_connection);
	
	//std::cout << " >>>>>>> test >> " << test << std::endl;
}

Lib::WebServer::Request::~Request() {}

MHD_Connection *Lib::WebServer::Request::connection(void) {
	return	this->o_connection;
}

void *Lib::WebServer::Request::content(void) {
	return	this->pmx_content;
}

Lib::WebServer::RequestHeader *Lib::WebServer::Request::header(void) {
	return this->o_header;
}

Lib::Util::UUID Lib::WebServer::Request::id(void) {
	return this->o_id;
}

Lib::Util::String Lib::WebServer::Request::method(void) {
	return	this->st_method;
}

Lib::WebServer::RequestQuery *Lib::WebServer::Request::query(void) {
	return this->o_query;
}

void Lib::WebServer::Request::trace(void) {
	std::cout << "=====================================" << std::endl;
	std::cout << "============== REQUEST ==============" << std::endl;
	std::cout << "=====================================" << std::endl;
	std::cout << " id: " << this->o_id.string() << std::endl;
	std::cout << " url: " << this->st_url << std::endl;
	std::cout << " method: " << this->st_method << std::endl;
	std::cout << " version: " << this->st_version << std::endl;
	this->o_header->trace();
	this->o_query->trace();
}

Lib::Util::String Lib::WebServer::Request::url(void) {
	return	this->st_url;
}

Lib::Util::String Lib::WebServer::Request::version(void) {
	return	this->st_version;
}

