#include "Exception.h"

lib::util::Exception::Exception(
	uint16_t in_code,
	lib::util::String st_tag,
	lib::util::String st_class,
	lib::util::String st_method,
	uint64_t in_line,
	lib::util::String st_message,
	std::shared_ptr<lib::util::Exception> po_exception
) :
	in_code(in_code),
	st_tag(st_tag),
	st_class(st_class),
	st_method(st_method),
	in_line(in_line),
	st_message(st_message),
	po_child(po_exception)
{
	std::chrono::time_point o_now = std::chrono::high_resolution_clock::now();
	this->in_nanotimestamp = std::chrono::duration_cast<std::chrono::nanoseconds>(o_now.time_since_epoch()).count();
}

lib::util::Exception::~Exception() {}

uint16_t lib::util::Exception::code(void) {
	return this->in_code;
}

lib::util::String lib::util::Exception::tag(void) {
	return this->st_tag;
}

lib::util::String lib::util::Exception::classname(void) {
	return this->st_class;
}

lib::util::String lib::util::Exception::method(void) {
	return this->st_method;
}

uint64_t lib::util::Exception::line(void) {
	return this->in_line;
}

lib::util::String lib::util::Exception::message(void) {
	return this->st_message;
}

std::shared_ptr<lib::util::Exception> lib::util::Exception::trace(void) {
	return this->po_child;
}

size_t lib::util::Exception::logged(void) {
	return this->in_nanotimestamp;
}

void lib::util::Exception::dump(void) {
	if(this->po_child)
		this->po_child->dump();
	std::cout << "================================" << std::endl;
	std::cout << "=========== EXCEPTION ==========" << std::endl;
	std::cout << "================================" << std::endl;
	std::cout << "\t CODE> " << +this->in_code << std::endl;
	std::cout << "\t TAG> " << this->st_tag << std::endl;
	std::cout << "\t CLASS> " << this->st_class << std::endl;
	std::cout << "\t METHOD> " << this->st_method << std::endl;
	std::cout << "\t LINE> " << +this->in_line << std::endl;
	std::cout << "\t MESSAGE> " << this->st_message << std::endl;
	std::cout << "\t LOGGED> " << this->in_nanotimestamp << std::endl;
};