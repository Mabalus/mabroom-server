#include "String.h"

lib::util::String::String(const std::string &st_input) : std::string(st_input) {}

lib::util::String::String(const char* st_input) : std::string(st_input) {}

void lib::util::String::toUpper(void) {
	std::transform(this->begin(), this->end(), this->begin(), ::toupper);
}

void lib::util::String::toLower(void) {
	std::transform(this->begin(), this->end(), this->begin(), ::tolower);
}

lib::util::String lib::util::String::lower(const lib::util::String st_input) {
	lib::util::String st_output = st_input;
	std::transform(st_output.begin(), st_output.end(), st_output.begin(), ::tolower);
	return st_output;
}

std::shared_ptr<std::vector<lib::util::String>> lib::util::String::split(const lib::util::String st_input,const char ch_delimiter) {
	const size_t in_input = st_input.length();
	std::shared_ptr<std::vector<lib::util::String>> pvst_token = std::make_shared<std::vector<lib::util::String>>();
	size_t in_begin = 0;
	size_t in_position = st_input.find(ch_delimiter);
	while(in_position < in_input) {
		if(in_position > in_begin)
			pvst_token->push_back(st_input.substr(in_begin, in_position - in_begin));	
		in_begin = in_position + 1;
		in_position = st_input.find(ch_delimiter, in_begin);
	}
	if(in_begin > 0 && in_begin < in_input)
		pvst_token->push_back(st_input.substr(in_begin, in_position));
	if(pvst_token->size() > 0)
		return pvst_token;
	return nullptr;
}

std::shared_ptr<std::vector<lib::util::String>> lib::util::String::split(const lib::util::String st_input,const lib::util::String st_delimiter) {
	const size_t in_input = st_input.length();
	const size_t in_delimiter = st_delimiter.length();
	if(in_delimiter < 1)
		return nullptr;
	std::shared_ptr<std::vector<lib::util::String>> pvst_token = std::make_shared<std::vector<lib::util::String>>();
	size_t in_begin = 0;
	size_t in_position = st_input.find(st_delimiter);
	while(in_position < in_input) {
		if(in_position > in_begin)
			pvst_token->push_back(st_input.substr(in_begin, in_position - in_begin));
		in_begin = in_position + in_delimiter;
		in_position = st_input.find(st_delimiter, in_begin);
	}
	if(in_begin > 0 && in_begin < in_input)
		pvst_token->push_back(st_input.substr(in_begin, in_position));
	if(pvst_token->size() > 0)
		return pvst_token;
	return nullptr;
	
}

std::shared_ptr<std::vector<lib::util::String>> lib::util::String::split(const lib::util::String st_input,const std::regex rx_delimiter) {
	std::sregex_token_iterator it_input(st_input.begin(), st_input.end(), rx_delimiter, -1);
	std::sregex_token_iterator it_end;
	std::shared_ptr<std::vector<lib::util::String>> pvst_token = std::make_shared<std::vector<lib::util::String>>();
	while(it_input != it_end) {
		if(!it_input->str().empty())
			pvst_token->push_back(it_input->str());
		++it_input;
	}
	if(pvst_token->size() < 1)
		return nullptr;
    return pvst_token;
}

lib::util::String lib::util::String::upper(const lib::util::String st_input) {
	lib::util::String st_output = st_input;
	std::transform(st_output.begin(), st_output.end(), st_output.begin(), ::toupper);
	return st_output;
}
