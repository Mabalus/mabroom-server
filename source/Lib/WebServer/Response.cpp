#include "Response.h"

Lib::WebServer::Response::Response(MHD_Connection *pt_connection)
	: pt_connection(pt_connection) {
		this->st_content =  new std::string();
		this->o_header = new Lib::WebServer::ResponseHeader();
	};

Lib::WebServer::Response::~Response() {}

Lib::WebServer::ResponseHeader *Lib::WebServer::Response::header(void) {
	return this->o_header;
}

int Lib::WebServer::Response::send(void) {
	/*
	* Prepare Content
	*/
	u_int64_t in_content = this->st_content->length() + 1;
	char *pch_content = new char[in_content];
	std::strcpy(pch_content,this->st_content->c_str());
	/*
	* Create Response
	*/
	MHD_Response *t_response = MHD_create_response_from_buffer(
		in_content,
		(void*) pch_content,
		MHD_RESPMEM_PERSISTENT
	);
	/*
	* Prepare Content Type
	*/
	std::vector<std::string> *vst_header = this->o_header->list();
	for (auto st_item = vst_header->begin(); st_item != vst_header->end(); ++st_item) {
		std::string st_name = *st_item;
		u_int64_t in_name = st_name.length() + 1;
		char *pch_name = new char[in_name];
		std::strcpy(pch_name, st_name.c_str());
		std::string st_value = this->o_header->get(st_name);
		if(st_value.length() > 0) {
			u_int64_t in_value = st_value.length() + 1;
			char *pch_value = new char[in_value];
			std::strcpy(pch_value, st_value.c_str());
			MHD_add_response_header(t_response, pch_name, pch_value);
		}
	}
	/*
	* Send Response
	*/
	int in_response = MHD_queue_response(this->pt_connection, MHD_HTTP_OK, t_response);
	MHD_destroy_response(t_response);
	return in_response;
}

void Lib::WebServer::Response::setContent(std::string *st_content,std::string st_content_type) {
	this->o_header->set("Content-Type",st_content_type);
	this->st_content = st_content;
}
