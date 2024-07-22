#include "ResponseHeader.h"

Lib::WebServer::ResponseHeader::ResponseHeader() {}

Lib::WebServer::ResponseHeader::~ResponseHeader() {}

std::vector<Lib::Util::String> *Lib::WebServer::ResponseHeader::list(void) {
	std::vector<Lib::Util::String> *vst_name = new std::vector<Lib::Util::String>();
	for(const auto &o_hash : this->vh_header)
		vst_name->push_back(o_hash.first);
    return vst_name;
}

Lib::Util::String Lib::WebServer::ResponseHeader::get(Lib::Util::String st_name) {
	st_name.toLower();
	return this->vh_header[st_name];
}

bool Lib::WebServer::ResponseHeader::has(Lib::Util::String st_name) {
	st_name.toLower();
	return this->vh_header.contains(st_name);
}

void Lib::WebServer::ResponseHeader::set(Lib::Util::String st_name, Lib::Util::String st_value) {
	st_name.toLower();
	this->vh_header[st_name] = st_value;
}

void Lib::WebServer::ResponseHeader::unset(Lib::Util::String st_name) {
	st_name.toLower();
	this->vh_header.erase(st_name);
}