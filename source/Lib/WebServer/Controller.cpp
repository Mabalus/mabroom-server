#include "Controller.h"

lib::webserver::Controller::Controller(
	uint16_t uin_port,
	std::shared_ptr<callback_t> fn_callback
) : uin_port(uin_port), fn_callback(fn_callback) { }

lib::webserver::Controller::~Controller() {
	this->stop();
}

uint16_t lib::webserver::Controller::getPort(void) {
	return this->uin_port;
}

void lib::webserver::Controller::setPort(uint16_t uin_port) {
	this->uin_port = uin_port;
}

bool lib::webserver::Controller::start() {
	this->pt_daemon = MHD_start_daemon(
		MHD_USE_THREAD_PER_CONNECTION,
		this->uin_port,
		nullptr,
		nullptr,
		(MHD_AccessHandlerCallback) &lib::webserver::Controller::processRequest,
		this->fn_callback.get(),
		MHD_OPTION_END
	);
	if(this->pt_daemon)
		return true;		
	return false;
}

void lib::webserver::Controller::stop() {
	if(this->pt_daemon)
		MHD_stop_daemon(this->pt_daemon);
}

int lib::webserver::Controller::processRequest(
	void *pmx_data,
	MHD_Connection *pt_connection,
	const char *pch_url,
	const char *pch_method,
	const char *pch_version,
	const char *pch_content,
	size_t *pin_content_size,
	void **pmx_args
) {
	callback_t *pfn_callback = static_cast<callback_t *>(pmx_data);
	lib::util::String st_url(pch_url);
	lib::util::String st_method(pch_method);
	lib::util::String st_version(pch_version);
	lib::util::String *pst_content = nullptr;
	std::shared_ptr<lib::util::String> pst_body = nullptr;
	std::shared_ptr<lib::webserver::Connection> po_connection = std::make_shared<lib::webserver::Connection>(pt_connection);
	if(st_method == "DELETE" || st_method == "PATCH" || st_method == "POST" || st_method == "PUT") {
		if(*pmx_args == nullptr) {
			pst_content = new lib::util::String();
			*pmx_args = pst_content;
			return MHD_YES;
		}
		pst_content = static_cast<lib::util::String *>(*pmx_args);
		if(*pin_content_size != 0) {
			pst_content->append(pch_content);
			*pin_content_size = 0;
			return MHD_YES;
		}
		pst_body = std::make_shared<lib::util::String>(*pst_content); 
	}
	std::shared_ptr<lib::webserver::Request> o_request = std::make_shared<lib::webserver::Request>(
		po_connection,
		st_url,
		st_method,
		st_version,
		pst_body
	);
	std::shared_ptr<lib::webserver::Response> o_response = std::make_shared<lib::webserver::Response>(po_connection);
	(*pfn_callback)(o_request,o_response);
	return MHD_YES;
	
}