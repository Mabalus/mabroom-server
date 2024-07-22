#include "Controller.h"

MHD_Daemon *Application::Controller::pt_daemon = nullptr;

int request(
	void *pmx_data,
	MHD_Connection *o_connection,
	const char *pch_url,
	const char *pch_method,
	const char *pch_version,
	const char *pch_content,
	size_t *pin_content_size,
	void **pmx_args
) {
	Lib::Util::String st_url(pch_url);
	Lib::Util::String st_method(pch_method);
	Lib::Util::String st_version(pch_version);
	Lib::Util::String st_content = (pch_content != nullptr) ? Lib::Util::String(pch_content) : Lib::Util::String();
	Lib::WebServer::Request *o_request = new Lib::WebServer::Request(
		o_connection,
		st_url,
		st_method,
		st_version,
		st_content
	);
	Lib::WebServer::Response *o_response = new Lib::WebServer::Response(o_connection);
	int in_response = Application::Controller::dispatcher(
		o_request,
		o_response
	);
	return in_response;
}

void Application::Controller::run() {
	pt_daemon = MHD_start_daemon(
		MHD_USE_THREAD_PER_CONNECTION,
		PORT,
		NULL,
		NULL,
		(MHD_AccessHandlerCallback) &request,
		NULL,
		MHD_OPTION_END
	);
	if(!pt_daemon) {
		std::cerr << "Erro ao iniciar o servidor HTTP na porta " << PORT << std::endl;
		return;
	}
	std::cout << "Servidor HTTP iniciado na porta " << PORT << std::endl;
	std::cin.get();
	MHD_stop_daemon(pt_daemon);
}

int Application::Controller::dispatcher(
	Lib::WebServer::Request *o_request,
	Lib::WebServer::Response *o_response
) {
	//std::cout << " >>>>>>>>>>> URL >>>> " << o_request->url() << std::endl;
	//Lib::Util::String st_header = (*o_request->header())["Accept"];
	//std::cout << " >>>>>> header >> " << st_header << std::endl;
	o_request->trace();
	if(o_request->url() == "/") {
		Lib::Util::String st_content = "{ \"name\": \"backend\", \"version\": \"0.1.0\" }";
		o_response->setContent(&st_content,"application/json");
		return o_response->send(MHD_HTTP_OK);
	}
	return o_response->send(MHD_HTTP_NOT_FOUND);
}


