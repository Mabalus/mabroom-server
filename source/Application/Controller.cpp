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

application::Controller::Controller(void) { }

application::Controller::~Controller(void) { }

void application::Controller::start(std::shared_ptr<application::Controller> po_application) {
	application::Controller::loadConfig();
	auto fn_dispatcher = [po_application] (
		std::shared_ptr<lib::webserver::Request> po_request,
		std::shared_ptr<lib::webserver::Response> po_response
	) {
		po_application->dispatcher(po_application,po_request,po_response);
	};
	std::shared_ptr<lib::webserver::Controller::callback_t> pfn_callback = std::make_shared<lib::webserver::Controller::callback_t>(fn_dispatcher);
	this->po_webserver = std::make_shared<lib::webserver::Controller>(this->po_config->node("webserver")->integer("port"),pfn_callback);
	if(this->po_webserver->start()) {
		std::cout << "Servidor HTTP iniciado na porta " << this->po_webserver->getPort() << std::endl;
		std::cin.get();
	} else
		std::cerr << "Erro ao iniciar o servidor HTTP na porta " << this->po_webserver->getPort() << std::endl;
}

void application::Controller::loadConfig(void) {
	const lib::util::String st_path = "./config.json";
	std::ifstream o_file(st_path);
	if(!o_file.is_open()) {
		std::cerr << "Não foi possível abrir o arquivo: " << st_path << std::endl;
		return;
	}
	std::shared_ptr<lib::util::String> pst_config = std::make_shared<lib::util::String>();
	std::string st_line;
	while(std::getline(o_file, st_line))
		*pst_config += st_line;
	o_file.close();
	this->po_config = lib::json::Controller::parser(pst_config);
}
