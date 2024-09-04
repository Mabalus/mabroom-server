#include "Controller.h"

void application::Controller::run(void) {
	std::shared_ptr<application::Controller> po_application(new application::Controller(), application::pointerDestroyer<application::Controller>());
	po_application->start(po_application);
}

void application::Controller::dispatcher(
	std::shared_ptr<application::Controller> po_application,
	std::shared_ptr<lib::webserver::Request> po_request,
	std::shared_ptr<lib::webserver::Response> po_response
) {
	std::shared_ptr<application::Dispatcher> po_dispatcher = std::make_shared<application::Dispatcher>(
		po_application,
		po_request,
		po_response
	);
	dispatcher::Base::routing(po_dispatcher);
}

std::shared_ptr<data::Controller> application::Controller::data(void) {
	return this->po_data;
}

std::shared_ptr<middleware::Controller> application::Controller::middleware(void) {
	return this->po_middleware;
}

std::shared_ptr<resource::Controller> application::Controller::resource(void) {
	return this->po_resource;
}

std::shared_ptr<server::Controller> application::Controller::server(void) {
	return this->po_server;
}

application::Controller::Controller(void) { }

application::Controller::~Controller(void) { }

void application::Controller::start(std::shared_ptr<application::Controller> po_application) {
	this->po_data = std::make_shared<data::Controller>(po_application);
	this->po_middleware = std::make_shared<middleware::Controller>(po_application);
	this->po_resource = std::make_shared<resource::Controller>(po_application);
	this->po_server = std::make_shared<server::Controller>(po_application);
}

