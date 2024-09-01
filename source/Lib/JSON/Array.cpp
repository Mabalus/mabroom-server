#include "Array.h"
#include "Node.h"

lib::json::Array::Array() {}

lib::json::Array::~Array() {}

size_t lib::json::Array::insert(std::shared_ptr<lib::json::Node> po_node) {
	this->vmx_array.push_back(po_node);
	return this->vmx_array.size() - 1;
}

void lib::json::Array::insert(std::shared_ptr<lib::json::Node> po_node,size_t in_index) {
	this->vmx_array.insert(this->vmx_array.begin() + in_index,po_node);
}

size_t lib::json::Array::insert(std::shared_ptr<lib::json::Array> pvmx_value) {
	this->vmx_array.push_back(pvmx_value);
	return this->vmx_array.size() - 1;
}

void lib::json::Array::insert(std::shared_ptr<lib::json::Array> pvmx_value,size_t in_index) {
	this->vmx_array.insert(this->vmx_array.begin() + in_index,pvmx_value);
}

size_t lib::json::Array::insert(bool bo_value) {
	this->vmx_array.push_back(bo_value);
	return this->vmx_array.size() - 1;
}

void lib::json::Array::insert(bool bo_value,size_t in_index) {
	this->vmx_array.insert(this->vmx_array.begin() + in_index,bo_value);
}

size_t lib::json::Array::insert(int64_t in_value) {
	this->vmx_array.push_back(in_value);
	return this->vmx_array.size() - 1;
}

void lib::json::Array::insert(int64_t in_value,size_t in_index) {
	this->vmx_array.insert(this->vmx_array.begin() + in_index,in_value);
}

size_t lib::json::Array::insert(float128_t fl_value) {
	this->vmx_array.push_back(fl_value);
	return this->vmx_array.size() - 1;
}

void lib::json::Array::insert(float128_t fl_value,size_t in_index) {
	this->vmx_array.insert(this->vmx_array.begin() + in_index,fl_value);
}

size_t lib::json::Array::insert(const char *ch_value) {
	this->vmx_array.push_back(static_cast<lib::util::String>(ch_value));
	return this->vmx_array.size() - 1;
}

void lib::json::Array::insert(const char *ch_value,size_t in_index) {
	this->vmx_array.insert(this->vmx_array.begin() + in_index,static_cast<lib::util::String>(ch_value));
}

size_t lib::json::Array::insert(std::string st_value) {
	this->vmx_array.push_back(static_cast<lib::util::String>(st_value));
	return this->vmx_array.size() - 1;
}

void lib::json::Array::insert(std::string st_value,size_t in_index) {
	this->vmx_array.insert(this->vmx_array.begin() + in_index,static_cast<lib::util::String>(st_value));
}

size_t lib::json::Array::insert(lib::util::String st_value) {
	this->vmx_array.push_back(st_value);
	return this->vmx_array.size() - 1;
}

void lib::json::Array::insert(lib::util::String st_value,size_t in_index) {
	this->vmx_array.insert(this->vmx_array.begin() + in_index,st_value);
}

size_t lib::json::Array::insertArray(void) {
	std::shared_ptr<lib::json::Array> pvmx_child = std::make_shared<lib::json::Array>();
	this->vmx_array.push_back(pvmx_child);
	return this->vmx_array.size() - 1;
}

void lib::json::Array::insertArray(size_t in_index) {
	std::shared_ptr<lib::json::Array> pvmx_child = std::make_shared<lib::json::Array>();
	this->vmx_array.insert(this->vmx_array.begin() + in_index,pvmx_child);
}

size_t lib::json::Array::insertNode(void) {
	std::shared_ptr<lib::json::Node> po_child = std::make_shared<lib::json::Node>();
	this->vmx_array.push_back(po_child);
	return this->vmx_array.size() - 1;
}

void lib::json::Array::insertNode(size_t in_index) {
	std::shared_ptr<lib::json::Node> po_child = std::make_shared<lib::json::Node>();
	this->vmx_array.insert(this->vmx_array.begin() + in_index,po_child);
}

std::shared_ptr<lib::json::Array> lib::json::Array::array(size_t in_index) {
	std::any mx_value = this->vmx_array[in_index];
	std::shared_ptr<lib::json::Array> pvmx_child = std::any_cast<std::shared_ptr<lib::json::Array>>(mx_value);
	return pvmx_child;
}

std::shared_ptr<lib::json::Node> lib::json::Array::node(size_t in_index) {
	std::any mx_value = this->vmx_array[in_index];
	std::shared_ptr<lib::json::Node> po_child = std::any_cast<std::shared_ptr<lib::json::Node>>(mx_value);
	return po_child;
}

bool lib::json::Array::boolean(size_t in_index) {
	std::any mx_value = this->vmx_array[in_index];
	bool bo_value = std::any_cast<bool>(mx_value);
	return bo_value;
}

int64_t lib::json::Array::integer(size_t in_index) {
	std::any mx_value = this->vmx_array[in_index];
	int64_t in_value = std::any_cast<int64_t>(mx_value);
	return in_value;
}

float128_t lib::json::Array::real(size_t in_index) {
	std::any mx_value = this->vmx_array[in_index];
	float128_t fl_value = std::any_cast<float128_t>(mx_value);
	return fl_value;
}

lib::util::String lib::json::Array::string(size_t in_index) {
	std::any mx_value = this->vmx_array[in_index];
	lib::util::String st_value = std::any_cast<lib::util::String>(mx_value);
	return st_value;
}

void lib::json::Array::remove(size_t in_index) {
	this->vmx_array.erase(this->vmx_array.begin() + in_index);
}

size_t lib::json::Array::size(void) {
	return this->vmx_array.size();
}

void lib::json::Array::dump(uint8_t in_ident) {
	std::string st_ident = std::string(in_ident, '\t');
	const size_t in_size = this->vmx_array.size();
	for(std::size_t in_index = 0;in_index < in_size;in_index++) {
		std::any mx_value = this->vmx_array[in_index];
		if(mx_value.type() == typeid(bool)) {
			bool bo_value = std::any_cast<bool>(mx_value);
			std::cout << st_ident << "(boolean) " << bo_value << std::endl;
		} else if(mx_value.type() == typeid(int64_t)) {
			int64_t in_value = std::any_cast<int64_t>(mx_value);
			std::cout << st_ident << "(integer) " << in_value << std::endl;
		} else if(mx_value.type() == typeid(float128_t)) {
			float128_t fl_value = std::any_cast<float128_t>(mx_value);
			std::cout << st_ident << "(float) " << fl_value << std::endl;
		} else if(mx_value.type() == typeid(lib::util::String)) {
			lib::util::String st_value = std::any_cast<lib::util::String>(mx_value);
			std::cout << st_ident << "(string) " << st_value << std::endl;
		} else if(mx_value.type() == typeid(std::shared_ptr<lib::json::Node>)) {
			std::shared_ptr<lib::json::Node> po_child = std::any_cast<std::shared_ptr<lib::json::Node>>(mx_value);
			std::cout << st_ident << "(Node) " << "{"  << std::endl;
			po_child->dump(in_ident + 1);
			std::cout << st_ident << "}"  << std::endl;
		} else if(mx_value.type() == typeid(std::shared_ptr<lib::json::Array>)) {
			std::shared_ptr<lib::json::Array> pt_array = std::any_cast<std::shared_ptr<lib::json::Array>>(mx_value);
			std::cout << st_ident << "(Array) " << "["  << std::endl;
			pt_array->dump(in_ident + 1);
			std::cout << st_ident << "]"  << std::endl;
		}
	}
}

lib::util::String lib::json::Array::json(uint8_t in_ident) {
	lib::util::String st_response = "";
	const size_t in_size = this->vmx_array.size();
	if(in_ident > 0) {
		std::string st_root_ident = std::string(in_ident - 1, '\t');
		std::string st_ident = std::string(in_ident, '\t');
		st_response += st_root_ident + "[\n";
		bool bo_first = true;
		lib::util::String st_key = "";
		for(std::size_t in_index = 0;in_index < in_size;in_index++) {
			std::any mx_value = this->vmx_array[in_index];
			if(bo_first == true) {
				st_key = "";
				bo_first = false;
			} else
				st_key = ",\n";
			st_key += st_ident + this->toJSON(mx_value,in_ident);
			st_response += st_key;
		}
		st_response += st_root_ident + "\n]";
	} else {
		st_response += "[";
		bool bo_first = true;
		lib::util::String st_key = "";
		for(std::size_t in_index = 0;in_index < in_size;in_index++) {
			std::any mx_value = this->vmx_array[in_index];
			if(bo_first == true) {
				st_key = "";
				bo_first = false;
			} else
				st_key = ",";
			st_key += this->toJSON(mx_value,in_ident);
			st_response += st_key;
		}
		st_response += "]";
	}
	return st_response;
}

lib::util::String lib::json::Array::toJSON(std::any mx_value,uint8_t in_ident) {
	lib::util::String st_key = "";
	if(in_ident > 0)
		in_ident++;
	if(mx_value.type() == typeid(bool)) {
		bool bo_value = std::any_cast<bool>(mx_value);
		st_key += bo_value ? "true" : "false";
	} else if(mx_value.type() == typeid(int64_t)) {
		int64_t in_value = std::any_cast<int64_t>(mx_value);
		st_key += std::to_string(in_value);
	} else if(mx_value.type() == typeid(float128_t)) {
		float128_t fl_value = std::any_cast<float128_t>(mx_value);
		std::ostringstream o_stream;
		o_stream << fl_value;
		st_key += o_stream.str();
	} else if(mx_value.type() == typeid(lib::util::String)) {
		lib::util::String st_value = std::any_cast<lib::util::String>(mx_value);
		st_key += "\"" + st_value + "\"";
	} else if(mx_value.type() == typeid(std::shared_ptr<lib::json::Node>)) {
		std::shared_ptr<lib::json::Node> po_child = std::any_cast<std::shared_ptr<lib::json::Node>>(mx_value);
		st_key += po_child->json(in_ident);
	} else if(mx_value.type() == typeid(std::shared_ptr<lib::json::Array>)) {
		std::shared_ptr<lib::json::Array> pvmx_child = std::any_cast<std::shared_ptr<lib::json::Array>>(mx_value);
		st_key += pvmx_child->json(in_ident);
	}
	return st_key;
}