#include "String.h"

lib::util::String::String(const std::string& st_input) : std::string(st_input) {}

lib::util::String::String(const char* st_input) : std::string(st_input) {}

std::string lib::util::String::String::lower(void) const {
	std::string st_output = *this;
	std::transform(st_output.begin(), st_output.end(), st_output.begin(), ::tolower);
	return st_output;
}

void lib::util::String::String::toUpper(void) {
	std::transform(this->begin(), this->end(), this->begin(), ::toupper);
}

void lib::util::String::String::toLower(void) {
	std::transform(this->begin(), this->end(), this->begin(), ::tolower);
}

std::string lib::util::String::String::upper(void) const {
	std::string st_output = *this;
	std::transform(st_output.begin(), st_output.end(), st_output.begin(), ::toupper);
	return st_output;
}
