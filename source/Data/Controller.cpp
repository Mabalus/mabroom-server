#include "Controller.h"

data::Controller::Controller(
	std::shared_ptr<application::Controller> po_application
) : po_application(po_application) { 
	this->loadConfiguration();
}

data::Controller::~Controller(void) { }

std::shared_ptr<lib::json::Node> data::Controller::configuration(void) {
	return this->po_configuration;
}

void data::Controller::loadConfiguration(void) {
	const lib::util::String st_path = "/etc/mabroom/mabroom.json";
	std::ifstream o_file(st_path);
	if(!o_file.is_open()) {
		std::cerr << "Não foi possível abrir o arquivo: " << st_path << std::endl;
		exit(0);
	}
	std::shared_ptr<lib::util::String> pst_config = std::make_shared<lib::util::String>();
	std::string st_line;
	while(std::getline(o_file, st_line))
		*pst_config += st_line;
	o_file.close();
	this->po_configuration = lib::json::Controller::parser(pst_config);
}
