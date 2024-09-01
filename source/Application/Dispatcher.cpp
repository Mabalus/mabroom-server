#include "Dispatcher.h"

application::Dispatcher::Dispatcher(
	std::shared_ptr<application::Controller> po_application,
	std::shared_ptr<lib::webserver::Request> po_request,
	std::shared_ptr<lib::webserver::Response> po_response
) : po_application(po_application),
	po_request(po_request),
	po_response(po_response)
{ 
	this->pvst_path = lib::util::String::split(this->po_request->url(),"/");
}

application::Dispatcher::~Dispatcher(void) { }

std::shared_ptr<application::Controller> application::Dispatcher::application(void) {
	return this->po_application;
}

std::shared_ptr<lib::util::String> application::Dispatcher::path(void) {
	if(!this->pvst_path || this->pvst_path->size() < 1)
		return nullptr;
	lib::util::String st_resp = this->pvst_path->front();
	this->pvst_path->erase(this->pvst_path->begin());
	return std::make_shared<lib::util::String>(st_resp);
}

std::shared_ptr<lib::webserver::Request> application::Dispatcher::request(void) {
	return this->po_request;
}

std::shared_ptr<lib::webserver::Response> application::Dispatcher::response(void) {
	return this->po_response;
}

void application::Dispatcher::dump(void) {
	if(this->pvst_path) {
		const size_t in_size = this->pvst_path->size();
		std::cout << "[" << std::endl;
		for(std::size_t in_index = 0;in_index < in_size;in_index++)
			std::cout << "\t\"" << this->pvst_path->at(in_index) << "\"" << std::endl;
		std::cout << "]" << std::endl;
	} else
		std::cout << "NULL" << std::endl;
};