#include "Request.h"

lib::webserver::Request::Request(
	std::shared_ptr<lib::webserver::Connection> po_connection,
	lib::util::String st_url,
	lib::util::String st_method,
	lib::util::String st_version
) : po_connection(po_connection),
	st_url(st_url),
	st_method(st_method),
	st_version(st_version),
	po_header(std::make_shared<lib::webserver::request::Header>(po_connection)),
	po_query(std::make_shared<lib::webserver::request::Query>(po_connection))
{ }

lib::webserver::Request::~Request() {}

std::shared_ptr<lib::webserver::Connection> lib::webserver::Request::connection(void) {
	return	this->po_connection;
}

lib::util::String lib::webserver::Request::content(void) {
	return	*this->pmx_content;
}

std::shared_ptr<lib::webserver::request::Header> lib::webserver::Request::header(void) {
	return this->po_header;
}

lib::util::UUID lib::webserver::Request::id(void) {
	return this->o_id;
}

lib::util::String lib::webserver::Request::method(void) {
	return	this->st_method;
}

std::shared_ptr<lib::webserver::request::Query> lib::webserver::Request::query(void) {
	return this->po_query;
}

void lib::webserver::Request::trace(void) {
	std::cout << "=====================================" << std::endl;
	std::cout << "============== REQUEST ==============" << std::endl;
	std::cout << "=====================================" << std::endl;
	std::cout << " id: " << this->o_id.string() << std::endl;
	std::cout << " url: " << this->st_url << std::endl;
	std::cout << " method: " << this->st_method << std::endl;
	std::cout << " version: " << this->st_version << std::endl;
	if(this->pmx_content)
		std::cout << " payload: " << *this->pmx_content << std::endl;
	this->po_header->trace();
	this->po_query->trace();
}

lib::util::String lib::webserver::Request::url(void) {
	return	this->st_url;
}

lib::util::String lib::webserver::Request::version(void) {
	return	this->st_version;
}

