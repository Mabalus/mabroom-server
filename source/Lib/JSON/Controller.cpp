#include "Controller.h"

std::shared_ptr<lib::json::Node> lib::json::Controller::parser(std::shared_ptr<lib::util::String> pst_json) {
	std::shared_ptr<size_t> pin_index = std::make_shared<size_t>(0);
	if(pst_json->length() < 1)
		throw lib::util::Exception(1,"ERR_JSON_PARSING","lib::json::Controller",__FUNCTION__,__LINE__,"Invalid JSON",nullptr);
	return lib::json::Controller::processNode(pin_index,pst_json);
}

void lib::json::Controller::findKey(
	std::shared_ptr<size_t> pin_index,
	std::shared_ptr<lib::util::String> pst_json,
	std::shared_ptr<lib::json::Node> po_node
) {
	/*
	* Find Begin
	*/
	lib::json::Controller::skipBlank(pin_index,pst_json);
	if(*pin_index >= pst_json->length())
		throw lib::util::Exception(2,"ERR_JSON_FIND_KEY","lib::json::Controller",__FUNCTION__,__LINE__,"Invalid JSON",nullptr);
	char ch_element = pst_json->at(*pin_index);
	if(ch_element != '"')
		throw lib::util::Exception(3,"ERR_JSON_FIND_KEY","lib::json::Controller",__FUNCTION__,__LINE__,"Invalid JSON",nullptr);
	(*pin_index)++;
	/*
	* Process Name
	*/
	lib::util::String st_name = lib::json::Controller::findName(pin_index,pst_json);
	/*
	* Find :
	*/
	lib::json::Controller::skipBlank(pin_index,pst_json);
	ch_element = pst_json->at(*pin_index);
	if(ch_element != ':')
		throw lib::util::Exception(4,"ERR_JSON_FIND_KEY","lib::json::Controller",__FUNCTION__,__LINE__,"Invalid JSON",nullptr);
	(*pin_index)++;
	/*
	* Process Value
	*/
	lib::json::Controller::skipBlank(pin_index,pst_json);
	ch_element = pst_json->at(*pin_index);
	if(ch_element == 'T' || ch_element == 't' || ch_element == 'F' || ch_element == 'f')
		po_node->insertKey(st_name,lib::json::Controller::processBooleanValue(pin_index,pst_json));
	else if(ch_element == '-' || isdigit(ch_element)) {
		std::any mx_value = lib::json::Controller::processNumberValue(pin_index,pst_json);
		if(mx_value.type() == typeid(int64_t)) {
			int64_t in_value = any_cast<int64_t>(mx_value);
			po_node->insertKey(st_name,in_value);
		} else {
			float128_t fl_value = any_cast<float128_t>(mx_value);
			po_node->insertKey(st_name,fl_value);
		}
	} else if(ch_element == '"')
		po_node->insertKey(st_name,lib::json::Controller::processStringValue(pin_index,pst_json));
	else if(ch_element == '[')
		po_node->insertArray(st_name,lib::json::Controller::processArray(pin_index,pst_json));
	else if(ch_element == '{')
		po_node->insertNode(st_name,lib::json::Controller::processNode(pin_index,pst_json));
	else if(ch_element == 'N' || ch_element == 'n')
		lib::json::Controller::processNullValue(pin_index,pst_json);
	else
		throw lib::util::Exception(5,"ERR_JSON_FIND_KEY","lib::json::Controller",__FUNCTION__,__LINE__,"Invalid JSON",nullptr);
}

lib::util::String lib::json::Controller::findName(
	std::shared_ptr<size_t> pin_index,
	std::shared_ptr<lib::util::String> pst_json
) {
	size_t in_begin = *pin_index;
	size_t in_length = pst_json->length();
	lib::util::String st_name;
	while(*pin_index < in_length) {
		char ch_element = pst_json->at(*pin_index);
		if(!isgraph(ch_element))
			throw lib::util::Exception(6,"ERR_JSON_FIND_KEY_NAME","lib::json::Controller",__FUNCTION__,__LINE__,"Invalid JSON",nullptr);
		if(ch_element == '/')
			(*pin_index)++;
		else if(ch_element == '"') {
			st_name = lib::util::String(pst_json->substr(in_begin,(*pin_index) - in_begin));
			(*pin_index)++;
			break;
		}
		(*pin_index)++;
	}
	return st_name;
}

std::shared_ptr<lib::json::Array> lib::json::Controller::processArray(
	std::shared_ptr<size_t> pin_index,
	std::shared_ptr<lib::util::String> pst_json
) {
	size_t in_length = pst_json->length();
	(*pin_index)++;
	std::shared_ptr<lib::json::Array> pvo_value = std::make_shared<lib::json::Array>();
	while(*pin_index < in_length) {
		lib::json::Controller::skipBlank(pin_index,pst_json);
		char ch_element = pst_json->at(*pin_index);
		/*
		* Process Value
		*/
		if(ch_element == ']') {
			(*pin_index)++;
			break;
		} else if(ch_element == 'T' || ch_element == 't' || ch_element == 'F' || ch_element == 'f')
			pvo_value->insert(lib::json::Controller::processBooleanValue(pin_index,pst_json));
		else if(ch_element == 'N' || ch_element == 'n')
			lib::json::Controller::processNullValue(pin_index,pst_json);
		else if(ch_element == '-' || isdigit(ch_element)) {
			std::any mx_value = lib::json::Controller::processNumberValue(pin_index,pst_json);
			if(mx_value.type() == typeid(int64_t)) {
				int64_t in_value = any_cast<int64_t>(mx_value);
				pvo_value->insert(in_value);
			} else {
				float128_t fl_value = any_cast<float128_t>(mx_value);
				pvo_value->insert(fl_value);
			}
		} else if(ch_element == '"')
			pvo_value->insert(lib::json::Controller::processStringValue(pin_index,pst_json));
		else if(ch_element == '[')
			pvo_value->insert(lib::json::Controller::processArray(pin_index,pst_json));
		else if(ch_element == '{')
			pvo_value->insert(lib::json::Controller::processNode(pin_index,pst_json));
		else if(ch_element == ',')
			(*pin_index)++;
		else
			throw lib::util::Exception(7,"ERR_JSON_PROCESS_ARRAY_VALUE","lib::json::Controller",__FUNCTION__,__LINE__,"Invalid JSON",nullptr);
	}
	return pvo_value;
}

bool lib::json::Controller::processBooleanValue(
	std::shared_ptr<size_t> pin_index,
	std::shared_ptr<lib::util::String> pst_json
) {
	size_t in_begin = *pin_index;
	char ch_element = pst_json->at(*pin_index);
	lib::util::String st_value;
	if(ch_element == 'T' || ch_element == 't') {
		st_value = lib::util::String::lower(pst_json->substr(in_begin,4));
		if(st_value != "true")
			throw lib::util::Exception(8,"ERR_JSON_PROCESS_BOOLEAN_VALUE","lib::json::Controller",__FUNCTION__,__LINE__,"Invalid JSON",nullptr);
		(*pin_index) += 4;
		return true;
	} else {
		st_value = lib::util::String::lower(pst_json->substr(in_begin,5));
		if(st_value != "false")
			throw lib::util::Exception(9,"ERR_JSON_PROCESS_BOOLEAN_VALUE","lib::json::Controller",__FUNCTION__,__LINE__,"Invalid JSON",nullptr);
		(*pin_index) += 5;
		return false;
	}
}

std::shared_ptr<lib::json::Node> lib::json::Controller::processNode(
	std::shared_ptr<size_t> pin_index,
	std::shared_ptr<lib::util::String> pst_json
) {
	/*
	* Find Begin
	*/
	lib::json::Controller::skipBlank(pin_index,pst_json);
	if(*pin_index >= pst_json->length())
		new lib::util::Exception(10,"ERR_JSON_PROCESS_NODE_VALUE","lib::json::Controller",__FUNCTION__,__LINE__,"Invalid JSON",nullptr);
	char ch_element = pst_json->at(*pin_index);
	if(ch_element != '{')
		new lib::util::Exception(11,"ERR_JSON_PROCESS_NODE_VALUE","lib::json::Controller",__FUNCTION__,__LINE__,"Invalid JSON",nullptr);
	(*pin_index)++;
	/*
	* Process Keys
	*/
	std::shared_ptr<lib::json::Node> po_node = std::make_shared<lib::json::Node>();
	while(*pin_index < pst_json->length()) {
		lib::json::Controller::findKey(pin_index,pst_json,po_node);
		lib::json::Controller::skipBlank(pin_index,pst_json);
		if(*pin_index >= pst_json->length())
			throw lib::util::Exception(14,"ERR_JSON_PROCESS_NODE_VALUE","lib::json::Controller",__FUNCTION__,__LINE__,"Invalid JSON",nullptr);
		ch_element = pst_json->at(*pin_index);
		if(ch_element == '}') {
			(*pin_index)++;
			break;
		} else if(ch_element == ',')
			(*pin_index)++;
		else
			throw lib::util::Exception(12,"ERR_JSON_PROCESS_NODE_VALUE","lib::json::Controller",__FUNCTION__,__LINE__,"Invalid JSON",nullptr);
	}
	return po_node;
}

void lib::json::Controller::processNullValue(
	std::shared_ptr<size_t> pin_index,
	std::shared_ptr<lib::util::String> pst_json
) {
	size_t in_begin = *pin_index;
	size_t in_length = pst_json->length();
	size_t in_position = in_begin;
	while(in_position < in_length) {
		lib::json::Controller::skipBlank(pin_index,pst_json);
		char ch_element = pst_json->at(in_position);
		if(ch_element == ',' || ch_element == '}' || ch_element == ']')
			break;
		in_position++;
	}
	if(in_position >= in_length)
		throw lib::util::Exception(18,"ERR_JSON_PROCESS_NULL_VALUE","lib::json::Controller",__FUNCTION__,__LINE__,"Invalid JSON",nullptr);
	in_position -= in_begin;
	lib::util::String st_value = lib::util::String::lower(pst_json->substr(in_begin,in_position));
	if(st_value != "null")
		throw lib::util::Exception(19,"ERR_JSON_PROCESS_NULL_VALUE","lib::json::Controller",__FUNCTION__,__LINE__,"Invalid JSON",nullptr);
	*pin_index += in_position;
}

std::any lib::json::Controller::processNumberValue(
	std::shared_ptr<size_t> pin_index,
	std::shared_ptr<lib::util::String> pst_json
) {
	size_t in_length = pst_json->length();
	bool bo_dot = false;
	bool bo_minus = false;
	lib::util::String st_value = "";
	while(*pin_index < in_length) {
		lib::json::Controller::skipBlank(pin_index,pst_json);
		char ch_element = pst_json->at(*pin_index);
		if(ch_element == '-')
			if(bo_minus == false)
				bo_minus = true;
			else
				throw lib::util::Exception(19,"ERR_JSON_PROCESS_NUMBER_VALUE","lib::json::Controller",__FUNCTION__,__LINE__,"Invalid JSON",nullptr);
		else if(ch_element == '.')
			if(bo_dot == false)
				bo_dot = true;
			else
				throw lib::util::Exception(13,"ERR_JSON_PROCESS_NUMBER_VALUE","lib::json::Controller",__FUNCTION__,__LINE__,"Invalid JSON",nullptr);
		else if(ch_element == ',' || ch_element == '}' || ch_element == ']')
			break;
		else if(!isdigit(ch_element))
			throw lib::util::Exception(20,"ERR_JSON_PROCESS_NUMBER_VALUE","lib::json::Controller",__FUNCTION__,__LINE__,"Invalid JSON",nullptr);
		st_value += ch_element;
		(*pin_index)++;
	}
	if(*pin_index >= in_length)
		throw lib::util::Exception(21,"ERR_JSON_PROCESS_NUMBER_VALUE","lib::json::Controller",__FUNCTION__,__LINE__,"Invalid JSON",nullptr);
	if(bo_dot == true) {
		float128_t fl_value = std::stold(st_value);
		return fl_value;
	} else {
		int64_t in_value = std::stoll(st_value);
		return in_value;
	}
}

lib::util::String lib::json::Controller::processStringValue(
	std::shared_ptr<size_t> pin_index,
	std::shared_ptr<lib::util::String> pst_json
) {
	(*pin_index)++;
	size_t in_begin = *pin_index;
	size_t in_length = pst_json->length();
	lib::util::String st_value = "";
	while(*pin_index < in_length) {
		char ch_element = pst_json->at(*pin_index);
		if(ch_element == '/')
			(*pin_index)++;
		else if(ch_element == '"') {
			st_value = pst_json->substr(in_begin,(*pin_index) - in_begin);
			(*pin_index)++;
			break;
		}
		(*pin_index)++;
	}
	return st_value;
}

void lib::json::Controller::skipBlank(
	std::shared_ptr<size_t> pin_index,
	std::shared_ptr<lib::util::String> pst_json
) {
	while(*pin_index < pst_json->length()) {
		if(!isspace(pst_json->at(*pin_index)))
			break;
		(*pin_index)++;
	}
}