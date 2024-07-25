#include "Header.h"

lib::webserver::response::Header::Header() {}

lib::webserver::response::Header::~Header() {}

std::vector<lib::util::String> *lib::webserver::response::Header::list(void) {
	std::vector<lib::util::String> *vst_name = new std::vector<lib::util::String>();
	for(const auto &o_hash : this->vh_header)
		vst_name->push_back(o_hash.first);
    return vst_name;
}

lib::util::String lib::webserver::response::Header::get(lib::util::String st_name) {
	st_name.toLower();
	return this->vh_header[st_name];
}

bool lib::webserver::response::Header::has(lib::util::String st_name) {
	st_name.toLower();
	return this->vh_header.contains(st_name);
}

void lib::webserver::response::Header::set(lib::util::String st_name, lib::util::String st_value) {
	st_name.toLower();
	this->vh_header[st_name] = st_value;
}

void lib::webserver::response::Header::unset(lib::util::String st_name) {
	st_name.toLower();
	this->vh_header.erase(st_name);
}