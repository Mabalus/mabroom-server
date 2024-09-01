#include "Error.h"

lib::util::Error::Error(
	uint16_t in_code,
	lib::util::String st_tag,
	lib::util::String st_category,
	lib::util::String st_type,
	lib::util::String st_message
) :
	in_code(in_code),
	st_tag(st_tag),
	st_category(st_category),
	st_type(st_type),
	st_message(st_message)
{
	std::chrono::time_point o_now = std::chrono::high_resolution_clock::now();
	this->in_nanotimestamp = std::chrono::duration_cast<std::chrono::nanoseconds>(o_now.time_since_epoch()).count();
}

lib::util::Error::~Error() {}

uint16_t lib::util::Error::code(void) {
	return this->in_code;
}

lib::util::String lib::util::Error::tag(void) {
	return this->st_tag;
}

lib::util::String lib::util::Error::category(void) {
	return this->st_category;
}

lib::util::String lib::util::Error::type(void) {
	return this->st_type;
}

lib::util::String lib::util::Error::message(void) {
	return this->st_message;
}

size_t lib::util::Error::logged(void) {
	return this->in_nanotimestamp;
}

void lib::util::Error::dump(void) {
	std::cout << "================================" << std::endl;
	std::cout << "============= ERROR ============" << std::endl;
	std::cout << "================================" << std::endl;
	std::cout << "\t CODE> " << +this->in_code << std::endl;
	std::cout << "\t TAG> " << this->st_tag << std::endl;
	std::cout << "\t CATEGORY> " << this->st_category << std::endl;
	std::cout << "\t TYPE> " << this->st_type << std::endl;
	std::cout << "\t MESSAGE> " << this->st_message << std::endl;
	std::cout << "\t LOGGED> " << this->in_nanotimestamp << std::endl;
};