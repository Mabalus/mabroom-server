#include "Header.h"

lib::webserver::response::Header::Header() {
	this->phst_header = std::make_shared<std::unordered_map<std::string, std::string>>();
}

lib::webserver::response::Header::~Header() {}

lib::util::String lib::webserver::response::Header::get(lib::util::String st_name) {
	st_name.toLower();
	return (*this->phst_header)[st_name];
}

bool lib::webserver::response::Header::has(lib::util::String st_name) {
	st_name.toLower();
	return this->phst_header->contains(st_name);
}

std::shared_ptr<const std::unordered_map<std::string, std::string>> lib::webserver::response::Header::iterator(void) {
	return this->phst_header;
}

std::vector<lib::util::String> lib::webserver::response::Header::list(void) {
	std::vector<lib::util::String> vst_name;
	for(const auto &o_header : *this->phst_header)
		vst_name.push_back(o_header.first);
    return vst_name;
}

void lib::webserver::response::Header::set(lib::util::String st_name,lib::util::String st_value) {
	st_name.toLower();
	(*this->phst_header)[st_name] = st_value;
}

void lib::webserver::response::Header::trace(void) {
	std::cout << "===== Header Section =====" << std::endl;
	for(const auto &o_header : *this->phst_header)
		std::cout << "\t" << o_header.first << ": " << o_header.second << std::endl;
}

void lib::webserver::response::Header::unset(lib::util::String st_name) {
	st_name.toLower();
	this->phst_header->erase(st_name);
}