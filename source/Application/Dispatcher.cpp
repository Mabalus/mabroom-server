#include "Dispatcher.h"

application::Dispatcher::Dispatcher(
	std::shared_ptr<application::Controller> po_application,
	std::shared_ptr<lib::webserver::Request> po_request,
	std::shared_ptr<lib::webserver::Response> po_response
) : po_application(po_application),
	po_request(po_request),
	po_response(po_response)
{ }

application::Dispatcher::~Dispatcher(void) { }

std::shared_ptr<application::Controller> application::Dispatcher::application(void) {
	return this->po_application;
}

std::shared_ptr<lib::webserver::Request> application::Dispatcher::request(void) {
	return this->po_request;
}

std::shared_ptr<lib::webserver::Response> application::Dispatcher::response(void) {
	return this->po_response;
}