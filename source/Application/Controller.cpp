#include "Controller.h"

const uint16_t Application::Controller::PORT = 8000;

Application::Controller::Controller(void) { }

Application::Controller::~Controller(void) { }

void Application::Controller::run(void) {
	Application::Controller *po_application = this;
	auto dispatcher = [po_application](
		std::shared_ptr<lib::webserver::Request> o_request,
		std::shared_ptr<lib::webserver::Response> o_response
	) {
		//std::cout << " >>>>>>>>>>> URL >>>> " << o_request->url() << std::endl;
		//lib::util::String st_header = (*o_request->header())["Accept"];
		//std::cout << " >>>>>> uin_test >> " << po_application->getTest() << std::endl;
		o_request->trace();
		if(o_request->url() == "/") {
			o_response->setContent("{ \"name\": \"backend\", \"version\": \"0.1.0\" }","application/json");
			return o_response->send(MHD_HTTP_OK);
		}
		return o_response->send(MHD_HTTP_NOT_FOUND);
	};
	std::shared_ptr<lib::webserver::Controller::callback_t> pfn_callback = std::make_shared<lib::webserver::Controller::callback_t>(dispatcher);
	this->po_webserver = std::make_shared<lib::webserver::Controller>(Application::Controller::PORT,pfn_callback);
	if(this->po_webserver->start()) {
		std::cout << "Servidor HTTP iniciado na porta " << this->po_webserver->getPort() << std::endl;
		std::cin.get();
	} else
		std::cerr << "Erro ao iniciar o servidor HTTP na porta " << this->po_webserver->getPort() << std::endl;
}
