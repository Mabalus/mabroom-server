#include "Controller.h"

void Application::Controller::run() {
	auto dispatcher = [](
		std::shared_ptr<lib::webserver::Request> o_request,
		std::shared_ptr<lib::webserver::Response> o_response
	) {
		//std::cout << " >>>>>>>>>>> URL >>>> " << o_request->url() << std::endl;
		//lib::util::String st_header = (*o_request->header())["Accept"];
		//std::cout << " >>>>>> header >> " << st_header << std::endl;
		o_request->trace();
		if(o_request->url() == "/") {
			o_response->setContent("{ \"name\": \"backend\", \"version\": \"0.1.0\" }","application/json");
			return o_response->send(MHD_HTTP_OK);
		}
		return o_response->send(MHD_HTTP_NOT_FOUND);
	};
	std::shared_ptr<lib::webserver::Controller::callback_t> fn_callback = std::make_shared<lib::webserver::Controller::callback_t>(dispatcher);
	lib::webserver::Controller o_server(Application::Controller::PORT,fn_callback);
	if(o_server.start()) {
		std::cout << "Servidor HTTP iniciado na porta " << o_server.getPort() << std::endl;
		std::cin.get();
	} else
		std::cerr << "Erro ao iniciar o servidor HTTP na porta " << o_server.getPort() << std::endl;
}
