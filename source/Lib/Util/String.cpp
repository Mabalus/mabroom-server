#include "String.h"

Lib::Util::String::String(const std::string& st_input) : std::string(st_input) {}

Lib::Util::String::String(const char* st_input) : std::string(st_input) {}

std::string Lib::Util::String::String::lower(void) const {
	std::string st_output = *this;
	std::transform(st_output.begin(), st_output.end(), st_output.begin(), ::tolower);
	return st_output;
}

void Lib::Util::String::String::toUpper(void) {
	std::transform(this->begin(), this->end(), this->begin(), ::toupper);
}

void Lib::Util::String::String::toLower(void) {
	std::transform(this->begin(), this->end(), this->begin(), ::tolower);
}

std::string Lib::Util::String::String::upper(void) const {
	std::string st_output = *this;
	std::transform(st_output.begin(), st_output.end(), st_output.begin(), ::toupper);
	return st_output;
}
