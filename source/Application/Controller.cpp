#include "Controller.h"

const uint16_t application::Controller::PORT = 8000;

application::Controller::Controller(void) { }

application::Controller::~Controller(void) { }

void application::Controller::run(void) {
	application::Controller *po_application = this;
	auto fn_dispatcher = [po_application] (
		std::shared_ptr<lib::webserver::Request> po_request,
		std::shared_ptr<lib::webserver::Response> po_response
	) {
		po_application->dispatcher(po_request,po_response);
	};
	std::shared_ptr<lib::webserver::Controller::callback_t> pfn_callback = std::make_shared<lib::webserver::Controller::callback_t>(fn_dispatcher);
	this->po_webserver = std::make_shared<lib::webserver::Controller>(application::Controller::PORT,pfn_callback);
	if(this->po_webserver->start()) {
		std::cout << "Servidor HTTP iniciado na porta " << this->po_webserver->getPort() << std::endl;
		std::cin.get();
	} else
		std::cerr << "Erro ao iniciar o servidor HTTP na porta " << this->po_webserver->getPort() << std::endl;
}

void application::Controller::dispatcher(
	std::shared_ptr<lib::webserver::Request> po_request,
	std::shared_ptr<lib::webserver::Response> po_response
) {
	std::shared_ptr<application::Controller> po_application = shared_from_this();
	std::shared_ptr<application::Dispatcher> po_dispatcher = std::make_shared<application::Dispatcher>(
		po_application,
		po_request,
		po_response
	);
	dispatcher::Base::routing(po_dispatcher);
}