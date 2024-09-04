#include "Controller.h"

server::Controller::Controller(
	std::shared_ptr<application::Controller> po_application
) : po_application(po_application) { 
	this->startWebServer();
}

server::Controller::~Controller(void) { }

std::shared_ptr<lib::webserver::Controller> server::Controller::webserver(void) {
	return this->po_webserver;
}

void server::Controller::startWebServer(void) { 
	auto fn_dispatcher = [po_application = this->po_application] (
		std::shared_ptr<lib::webserver::Request> po_request,
		std::shared_ptr<lib::webserver::Response> po_response
	) {
		po_application->dispatcher(po_application,po_request,po_response);
	};
	uint16_t in_port;
	try {
		in_port = this->po_application->data()->configuration()->node("webserver")->integer("port");
	} catch(std::exception &e) {
		in_port = 8080;
	}
	std::shared_ptr<lib::webserver::Controller::callback_t> pfn_callback = std::make_shared<lib::webserver::Controller::callback_t>(fn_dispatcher);
	this->po_webserver = std::make_shared<lib::webserver::Controller>(in_port,pfn_callback);
	if(this->po_webserver->start()) {
		std::cout << "The HTTP server started listening on port " << this->po_webserver->getPort() << std::endl;
		std::cin.get();
	} else
		std::cerr << "Error starting HTTP server listening on port " << this->po_webserver->getPort() << std::endl;
}