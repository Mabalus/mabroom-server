#include "Response.h"

lib::webserver::Response::Response(std::shared_ptr<lib::webserver::Connection> po_connection)
	: po_connection(po_connection) {
	this->st_content = nullptr;
	this->o_header =std::make_shared<lib::webserver::response::Header>();
};

lib::webserver::Response::~Response() {}

std::shared_ptr<lib::webserver::response::Header> lib::webserver::Response::header(void) {
	return this->o_header;
}

int lib::webserver::Response::send(u_int32_t in_code) {
	/*
	* Prepare Content
	*/
	MHD_Response *t_response = nullptr;
	char *pch_content = nullptr;
	size_t in_content = 0;
	if(this->st_content) {
		if(!this->o_header->has("content-type"))
			this->o_header->set("content-type","plain/text");
		in_content = this->st_content->length() + 1;
		pch_content = new char[in_content];
		std::strcpy(pch_content,this->st_content->c_str());
	}
	t_response = MHD_create_response_from_buffer(
		in_content,
		(void*) pch_content,
		MHD_RESPMEM_MUST_FREE
	);
	if(!t_response)
		return MHD_NO;
	/*
	* Prepare Content Type
	*/
	for(const auto &o_header : *this->o_header->iterator()) {
		lib::util::String st_name = o_header.first;
		lib::util::String st_value = o_header.second; 
		size_t in_name = st_name.length() + 1;
		char *pch_name = new char[in_name];
		std::strcpy(pch_name, st_name.c_str());
		if(st_value.length() > 0) {
			size_t in_value = st_value.length() + 1;
			char *pch_value = new char[in_value];
			std::strcpy(pch_value, st_value.c_str());
			MHD_add_response_header(t_response, pch_name, pch_value);
		}
	}
	/*
	* Send Response
	*/
	int in_response = MHD_queue_response(this->po_connection->get(), in_code, t_response);
	MHD_destroy_response(t_response);
	return in_response;
}

void lib::webserver::Response::setContent(lib::util::String st_content,lib::util::String st_content_type) {
	this->o_header->set("Content-Type",st_content_type);
	this->st_content = std::make_unique<lib::util::String>(st_content);
}
