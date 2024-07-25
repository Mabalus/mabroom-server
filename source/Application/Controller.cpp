#include "Controller.h"
#include "../Lib/WebServer/Connection.h"

MHD_Daemon *Application::Controller::pt_daemon = nullptr;

int request(
	void *pmx_data,
	MHD_Connection *pt_connection,
	const char *pch_url,
	const char *pch_method,
	const char *pch_version,
	const char *pch_content,
	size_t *pin_content_size,
	void **pmx_args
) {
	lib::util::String st_url(pch_url);
	lib::util::String st_method(pch_method);
	lib::util::String st_version(pch_version);
	lib::util::String st_content = (pch_content != nullptr) ? lib::util::String(pch_content) : lib::util::String();
	std::cout << " pch_content: " << st_content << std::endl;
	std::cout << " pin_content_size: " << *pin_content_size << std::endl;
	std::shared_ptr<lib::webserver::Connection> po_connection = std::make_shared<lib::webserver::Connection>(pt_connection);
	lib::webserver::Request *o_request = new lib::webserver::Request(
		po_connection,
		st_url,
		st_method,
		st_version
	);
	lib::webserver::Response *o_response = new lib::webserver::Response(pt_connection);
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
	lib::webserver::Request *o_request,
	lib::webserver::Response *o_response
) {
	//std::cout << " >>>>>>>>>>> URL >>>> " << o_request->url() << std::endl;
	//lib::util::String st_header = (*o_request->header())["Accept"];
	//std::cout << " >>>>>> header >> " << st_header << std::endl;
	o_request->trace();
	if(o_request->url() == "/") {
		lib::util::String st_content = "{ \"name\": \"backend\", \"version\": \"0.1.0\" }";
		o_response->setContent(&st_content,"application/json");
		return o_response->send(MHD_HTTP_OK);
	}
	return o_response->send(MHD_HTTP_NOT_FOUND);
}


