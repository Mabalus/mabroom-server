#include "Node.h"
#include "Array.h"

lib::json::Node::Node() {}

lib::json::Node::~Node() {}

void lib::json::Node::insertNode(lib::util::String st_name) {
	this->hmx_node[st_name] = std::make_shared<lib::json::Node>();
}

void lib::json::Node::insertNode(lib::util::String st_name, std::shared_ptr<lib::json::Node> po_node) {
	this->hmx_node[st_name] = po_node;
}

void lib::json::Node::insertArray(lib::util::String st_name) {
	this->hmx_node[st_name] = std::make_shared<lib::json::Array>();
}

void lib::json::Node::insertArray(lib::util::String st_name,std::shared_ptr<lib::json::Array> pvmx_value) {
	this->hmx_node[st_name] = pvmx_value;
}

void lib::json::Node::insertKey(lib::util::String st_name, bool bo_value) {
	this->hmx_node[st_name] = bo_value;
}

void lib::json::Node::insertKey(lib::util::String st_name, int64_t in_value) {
	this->hmx_node[st_name] = in_value;
}

void lib::json::Node::insertKey(lib::util::String st_name, float128_t fl_value) {
	this->hmx_node[st_name] = fl_value;
}

void lib::json::Node::insertKey(lib::util::String st_name, const char *ch_value) {
	this->hmx_node[st_name] = static_cast<lib::util::String>(ch_value);
}

void lib::json::Node::insertKey(lib::util::String st_name, std::string st_value) {
	this->hmx_node[st_name] = static_cast<lib::util::String>(st_value);
}

void lib::json::Node::insertKey(lib::util::String st_name, lib::util::String st_value) {
	this->hmx_node[st_name] = st_value;
}

std::shared_ptr<lib::json::Node> lib::json::Node::node(lib::util::String st_name) {
	std::any mx_value = this->hmx_node[st_name];
	std::shared_ptr<lib::json::Node> po_child = std::any_cast<std::shared_ptr<lib::json::Node>>(mx_value);
	return po_child;
}

std::shared_ptr<lib::json::Array> lib::json::Node::array(lib::util::String st_name) {
	std::any mx_value = this->hmx_node[st_name];
	std::shared_ptr<lib::json::Array> po_child = std::any_cast<std::shared_ptr<lib::json::Array>>(mx_value);
	return po_child;
}

bool lib::json::Node::boolean(lib::util::String st_name) {
	std::any mx_value = this->hmx_node[st_name];
	bool bo_value = std::any_cast<bool>(mx_value);
	return bo_value;
}

int64_t lib::json::Node::integer(lib::util::String st_name) {
	std::any mx_value = this->hmx_node[st_name];
	int64_t in_value = std::any_cast<int64_t>(mx_value);
	return in_value;
}

float128_t lib::json::Node::real(lib::util::String st_name) {
	std::any mx_value = this->hmx_node[st_name];
	float128_t fl_value = std::any_cast<float128_t>(mx_value);
	return fl_value;
}

lib::util::String lib::json::Node::string(lib::util::String st_name) {
	std::any mx_value = this->hmx_node[st_name];
	lib::util::String st_value = std::any_cast<lib::util::String>(mx_value);
	return st_value;
}

bool lib::json::Node::has(lib::util::String st_name) {
	std::any mx_value = this->hmx_node[st_name];
	if(mx_value.type() == typeid(void))
		return false;
	else
		return true;
}

lib::util::String lib::json::Node::json(uint8_t in_ident) {
	lib::util::String st_response = "";
	if(in_ident > 0) {
		std::string st_root_ident = std::string(in_ident - 1, '\t');
		std::string st_ident = std::string(in_ident, '\t');
		st_response += st_root_ident + "{\n";
		bool bo_first = true;
		lib::util::String st_key = "";
		for(const std::pair<const std::string,std::any> &o_key : this->hmx_node) {
			if(bo_first == true) {
				st_key = "";
				bo_first = false;
			} else
				st_key = ",\n";
			st_key += st_ident + "\"" + o_key.first + "\": ";
			st_key += this->toJSON(o_key.second,in_ident);
			st_response += st_key;
		}
		st_response += st_root_ident + "\n}";
	} else {
		st_response += "{";
		bool bo_first = true;
		lib::util::String st_key = "";
		for(const std::pair<const std::string,std::any> &o_key : this->hmx_node) {
			if(bo_first == true) {
				st_key = "";
				bo_first = false;
			} else
				st_key = ",";
			st_key += "\"" + o_key.first + "\":";
			st_key += this->toJSON(o_key.second,in_ident);
			st_response += st_key;
		}
		st_response += "}";
	}
	return st_response;
}

void lib::json::Node::remove(lib::util::String st_name) {
	this->hmx_node.erase(st_name);
}

void lib::json::Node::dump(uint8_t in_ident) {
	std::string st_ident = std::string(in_ident, '\t');
	for(const std::pair<const std::string,std::any> &mx_value : this->hmx_node) {
		if(mx_value.second.type() == typeid(bool)) {
			bool bo_value = std::any_cast<bool>(mx_value.second);
			std::cout << st_ident << "(boolean) " << mx_value.first << ": " << bo_value << std::endl;
		} else if(mx_value.second.type() == typeid(int64_t)) {
			int64_t in_value = std::any_cast<int64_t>(mx_value.second);
			std::cout << st_ident << "(integer) " << mx_value.first << ": " << in_value << std::endl;
		} else if(mx_value.second.type() == typeid(float128_t)) {
			float128_t fl_value = std::any_cast<float128_t>(mx_value.second);
			std::cout << st_ident << "(float) " << mx_value.first << ": " << fl_value << std::endl;
		} else if(mx_value.second.type() == typeid(lib::util::String)) {
			lib::util::String st_value = std::any_cast<lib::util::String>(mx_value.second);
			std::cout << st_ident << "(string) " << mx_value.first << ": " << st_value << std::endl;
		} else if(mx_value.second.type() == typeid(std::shared_ptr<lib::json::Node>)) {
			std::shared_ptr<lib::json::Node> po_child = std::any_cast<std::shared_ptr<lib::json::Node>>(mx_value.second);
			std::cout << st_ident << "(Node) " << mx_value.first << ": {"  << std::endl;
			po_child->dump(in_ident + 1);
			std::cout << st_ident << "}"  << std::endl;
		} else if(mx_value.second.type() == typeid(std::shared_ptr<lib::json::Array>)) {
			std::shared_ptr<lib::json::Array> po_child = std::any_cast<std::shared_ptr<lib::json::Array>>(mx_value.second);
			std::cout << st_ident << "(Array) " << mx_value.first << ": ["  << std::endl;
			po_child->dump(in_ident + 1);
			std::cout << st_ident << "]"  << std::endl;
		}
	}
}

uint8_t lib::json::Node::type(lib::util::String st_name) {
	std::any mx_value = this->hmx_node[st_name];
	if(mx_value.type() == typeid(int64_t))
		return 2;
	else if(mx_value.type() == typeid(float128_t))
		return 3;
	else if(mx_value.type() == typeid(lib::util::String))
		return 4;
	else if(mx_value.type() == typeid(std::shared_ptr<lib::json::Node>))
		return 0;
	else if(mx_value.type() == typeid(std::shared_ptr<lib::json::Array>))
		return 5;
	return 1;
}

lib::util::String lib::json::Node::toJSON(std::any mx_value,uint8_t in_ident) {
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
