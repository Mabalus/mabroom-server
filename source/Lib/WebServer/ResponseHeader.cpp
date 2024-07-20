#include "ResponseHeader.h"
#include <algorithm>
#include <cctype>

void toLowerCase(std::string *st_input) {
	std::transform(st_input->begin(), st_input->end(), st_input->begin(), [](unsigned char ch_input){ return std::tolower(ch_input); });
}

Lib::WebServer::ResponseHeader::ResponseHeader() {}

Lib::WebServer::ResponseHeader::~ResponseHeader() {}

std::vector<std::string> *Lib::WebServer::ResponseHeader::list(void) {
	std::vector<std::string> *vst_name = new std::vector<std::string>();
	for(const auto &o_hash : this->vh_header)
		vst_name->push_back(o_hash.first);
    return vst_name;
}

std::string Lib::WebServer::ResponseHeader::get(std::string st_name) {
	toLowerCase(&st_name);
	return this->vh_header[st_name];
}

bool Lib::WebServer::ResponseHeader::has(std::string st_name) {
	toLowerCase(&st_name);
	return this->vh_header.contains(st_name);
}

void Lib::WebServer::ResponseHeader::set(std::string st_name, std::string st_value) {
	toLowerCase(&st_name);
	this->vh_header[st_name] = st_value;
}

void Lib::WebServer::ResponseHeader::unset(std::string st_name) {
	toLowerCase(&st_name);
	this->vh_header.erase(st_name);
}