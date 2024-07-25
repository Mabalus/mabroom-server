#include "Response.h"

lib::webserver::Response::Response(MHD_Connection *pt_connection)
	: pt_connection(pt_connection) {
		this->st_content = nullptr;
		this->o_header = new lib::webserver::response::Header();
	};

lib::webserver::Response::~Response() {}

lib::webserver::response::Header *lib::webserver::Response::header(void) {
	return this->o_header;
}

int lib::webserver::Response::send(u_int32_t in_code) {
	/*
	* Prepare Content
	*/
	MHD_Response *t_response = nullptr;
	char *pch_content = nullptr;
	u_int64_t in_content = 0;
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
	std::vector<lib::util::String> *vst_header = this->o_header->list();
	for (auto st_item = vst_header->begin(); st_item != vst_header->end(); ++st_item) {
		lib::util::String st_name = *st_item;
		u_int64_t in_name = st_name.length() + 1;
		char *pch_name = new char[in_name];
		std::strcpy(pch_name, st_name.c_str());
		lib::util::String st_value = this->o_header->get(st_name);
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
	int in_response = MHD_queue_response(this->pt_connection, in_code, t_response);
	MHD_destroy_response(t_response);
	return in_response;
}

void lib::webserver::Response::setContent(lib::util::String *st_content,lib::util::String st_content_type) {
	this->o_header->set("Content-Type",st_content_type);
	this->st_content = st_content;
}
