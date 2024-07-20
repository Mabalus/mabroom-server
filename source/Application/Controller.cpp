#include "Controller.h"

MHD_Daemon *Application::Controller::pt_daemon = nullptr;

enum MHD_Result getHeaders(void *pmx_data, enum MHD_ValueKind en_kind, const char *st_key, const char *st_value) {
    std::unordered_map<std::string, std::string> *phst_header = pmx_data;
    (void)en_kind;
    std::cout << st_key << ": " << st_value << std::endl;
    return MHD_YES;
}

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
	std::unordered_map<std::string, std::string> *phst_header = new std::unordered_map<std::string, std::string>();
	MHD_get_connection_values(o_connection, MHD_HEADER_KIND, getHeaders, vh_header);
	std::string st_url(pch_url);
	std::string st_method(pch_method);
	std::string st_version(pch_version);
	std::string st_content = (pch_content != nullptr) ? std::string(pch_content) : std::string();
	Lib::WebServer::Request *o_request = new Lib::WebServer::Request(
		st_url,
		st_method,
		st_version,
		st_content
	);
	Lib::WebServer::Response *o_response = new Lib::WebServer::Response(o_connection);
	int ret = Application::Controller::dispatcher(
		o_request,
		o_response
	);
	return ret;
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
	std::string st_content = "{ \"name\": \"backend\", \"pch_version\": \"0.1.0\" }";
	
	o_response->setContent(&st_content,"application/json");
	o_response->header()->set("X-Power", "Mabalus");
	return o_response->send();
}


