#include "RequestHeader.h"

Lib::WebServer::RequestHeader::RequestHeader(MHD_Connection *o_connection) {
	auto getHeaders = [](void *pmx_data, enum MHD_ValueKind en_kind, const char *pch_name, const char *pch_value) -> enum MHD_Result {
		std::unordered_map<std::string, std::string> *phst_header = static_cast<std::unordered_map<std::string, std::string> *>(pmx_data);
		(void) en_kind;
		Lib::Util::String st_name = Lib::Util::String(pch_name);
		Lib::Util::String st_value = Lib::Util::String(pch_value);
		st_name.toLower();
		(*phst_header)[st_name] = st_value;
		return MHD_YES;
	};
	this->phst_header = new std::unordered_map<std::string, std::string>();
	MHD_get_connection_values(o_connection, MHD_HEADER_KIND, getHeaders, this->phst_header);
}

Lib::WebServer::RequestHeader::~RequestHeader() {}

bool Lib::WebServer::RequestHeader::has(Lib::Util::String st_name) {
	st_name.toLower();
	return (*this->phst_header).contains(st_name);
}

std::vector<Lib::Util::String> *Lib::WebServer::RequestHeader::list(void) {
	std::vector<Lib::Util::String> *vst_name = new std::vector<Lib::Util::String>();
	for(const auto &o_header : *this->phst_header)
		vst_name->push_back(o_header.first);
    return vst_name;
}

void Lib::WebServer::RequestHeader::trace(void) {
	std::cout << "===== Header Section =====" << std::endl;
	for(const auto &o_header : *this->phst_header)
		std::cout << "\t" << o_header.first << ": " << o_header.second << std::endl;
}

Lib::Util::String Lib::WebServer::RequestHeader::operator[](Lib::Util::String st_name) {
	st_name.toLower();
	return (*this->phst_header)[st_name];
}