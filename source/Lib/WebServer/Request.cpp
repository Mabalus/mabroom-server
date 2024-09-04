#include "Request.h"

lib::webserver::Request::Request(
	std::shared_ptr<lib::webserver::Connection> po_connection,
	lib::util::String st_url,
	lib::util::String st_method,
	lib::util::String st_version,
	std::shared_ptr<lib::util::String> pst_body
) : po_connection(po_connection),
	st_url(st_url),
	st_method(st_method),
	st_version(st_version),
	pst_body(pst_body),
	po_header(std::make_shared<lib::webserver::request::Header>(po_connection)),
	po_query(std::make_shared<lib::webserver::request::Query>(po_connection)) {
	if(this->po_header->has("content-type")) {
		this->pst_content_type = std::make_shared<lib::util::String>((*this->po_header)["content-type"]);
		std::shared_ptr<std::vector<lib::util::String>> pvst_result = lib::util::String::split(*this->pst_content_type,";");
		if(pvst_result) {
			this->pst_content_type = std::make_shared<lib::util::String>(pvst_result->at(0));
			this->pst_boundary = std::make_shared<lib::util::String>(pvst_result->at(1));
			size_t in_position = this->pst_boundary->find("boundary=");
			size_t in_length = this->pst_boundary->length();
			if(in_position < in_length)
				this->pst_boundary = std::make_shared<lib::util::String>(this->pst_boundary->substr(in_position + 9,in_length));
			else
				this->pst_boundary = nullptr;
		}
	}
}

lib::webserver::Request::~Request() {}

const std::shared_ptr<lib::util::String> lib::webserver::Request::body(void) const {
	return this->pst_body;
}

const std::shared_ptr<lib::util::String> lib::webserver::Request::boundary(void) const {
	return this->pst_boundary;
}

std::shared_ptr<lib::webserver::Connection> lib::webserver::Request::connection(void) {
	return	this->po_connection;
}

const std::shared_ptr<lib::util::String> lib::webserver::Request::contentType(void) const {
	return this->pst_content_type;
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

void lib::webserver::Request::dump(void) {
	std::cout << "=====================================" << std::endl;
	std::cout << "============== REQUEST ==============" << std::endl;
	std::cout << "=====================================" << std::endl;
	std::cout << " id: " << this->o_id.string() << std::endl;
	std::cout << " url: " << this->st_url << std::endl;
	std::cout << " method: " << this->st_method << std::endl;
	std::cout << " version: " << this->st_version << std::endl;
	if(this->pst_content_type)
		std::cout << " content-type: " << *this->pst_content_type << std::endl;
	if(this->pst_boundary)
		std::cout << " boundary: " << *this->pst_boundary << std::endl;
	if(this->pst_body) {
		std::cout << " payload length: " << +this->pst_body->size() << std::endl;
		if(this->pst_body->size() < 2049)
			std::cout << " payload : " << *this->pst_body << std::endl;
	}
	
	this->po_header->dump();
	this->po_query->dump();
}

lib::util::String lib::webserver::Request::url(void) {
	return this->st_url;
}

lib::util::String lib::webserver::Request::version(void) {
	return	this->st_version;
}

