#include "Header.h"

lib::webserver::request::Header::Header(std::shared_ptr<lib::webserver::Connection> po_connection) {
	 auto getHeaders = [](void *pmx_data, enum MHD_ValueKind en_kind, const char *pch_name, const char *pch_value) -> enum MHD_Result {
        (void) en_kind;
		auto *phst_data = static_cast<std::unordered_map<std::string, std::string>*>(pmx_data);
		lib::util::String st_name = lib::util::String(pch_name);
		lib::util::String st_value = lib::util::String(pch_value);
		st_name.toLower();
		(*phst_data)[st_name] = st_value;
		return MHD_YES;
    };
	this->phst_header = std::make_shared<std::unordered_map<std::string, std::string>>();
	MHD_get_connection_values(po_connection->get(), MHD_HEADER_KIND, getHeaders, this->phst_header.get());
}

lib::webserver::request::Header::~Header() {}

bool lib::webserver::request::Header::has(lib::util::String st_name) {
	st_name.toLower();
	return (*this->phst_header).contains(st_name);
}

std::vector<lib::util::String> *lib::webserver::request::Header::list(void) {
	std::vector<lib::util::String> *vst_name = new std::vector<lib::util::String>();
	for(const auto &o_header : *this->phst_header)
		vst_name->push_back(o_header.first);
    return vst_name;
}

void lib::webserver::request::Header::trace(void) {
	std::cout << "===== Header Section =====" << std::endl;
	for(const auto &o_header : *this->phst_header)
		std::cout << "\t" << o_header.first << ": " << o_header.second << std::endl;
}

lib::util::String lib::webserver::request::Header::operator[](lib::util::String st_name) {
	st_name.toLower();
	return (*this->phst_header)[st_name];
}