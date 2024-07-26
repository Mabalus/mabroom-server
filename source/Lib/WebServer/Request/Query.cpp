#include "Query.h"

lib::webserver::request::Query::Query(std::shared_ptr<lib::webserver::Connection> po_connection) {
	auto getQuery = [](void *pmx_data, enum MHD_ValueKind en_kind, const char *pch_name, const char *pch_value) -> enum MHD_Result {
		(void) en_kind;
		auto *phst_data = static_cast<std::unordered_map<std::string, std::any>*>(pmx_data);
		lib::util::String st_name = lib::util::String(pch_name);
		if((*phst_data).contains(st_name))
			if((*phst_data)[st_name].type() == typeid(std::shared_ptr<lib::util::String>)) {
				std::shared_ptr<lib::util::String> pst_value = std::any_cast<std::shared_ptr<lib::util::String>>((*phst_data)[st_name]);
				(*phst_data)[st_name] = std::make_shared<std::vector<lib::util::String>>();
				std::any_cast<std::shared_ptr<std::vector<lib::util::String>>>((*phst_data)[st_name])->push_back(*pst_value);
				std::any_cast<std::shared_ptr<std::vector<lib::util::String>>>((*phst_data)[st_name])->push_back(pch_value);
			} else
				std::any_cast<std::shared_ptr<std::vector<lib::util::String>>>((*phst_data)[st_name])->push_back(pch_value);
		else
			(*phst_data)[st_name] = std::make_shared<lib::util::String>(pch_value);
		return MHD_YES;
	};
	this->phmx_query = std::make_unique<std::unordered_map<std::string, std::any>>();
	MHD_get_connection_values(po_connection->get(), MHD_GET_ARGUMENT_KIND, getQuery, this->phmx_query.get());
}

lib::webserver::request::Query::~Query() {}

bool lib::webserver::request::Query::has(lib::util::String st_name) {
	st_name.toLower();
	return (*this->phmx_query).contains(st_name);
}

std::vector<lib::util::String> lib::webserver::request::Query::list(void) {
	std::vector<lib::util::String> vst_name;
	for(const auto &o_hash : *this->phmx_query)
		vst_name.push_back(o_hash.first);
	return vst_name;
}

void lib::webserver::request::Query::trace(void) {
	std::cout << "===== Query Section =====" << std::endl;
	for(const auto &mx_value : *this->phmx_query) {
		if(mx_value.second.type() == typeid(std::shared_ptr<lib::util::String>)) {
			std::shared_ptr<lib::util::String> pst_value = std::any_cast<std::shared_ptr<lib::util::String>>(mx_value.second);
			std::cout << "\t" << mx_value.first << ": " << *pst_value << std::endl;
		} else {
			std::cout << "\t" << mx_value.first << ": [ " << std::endl;
			std::shared_ptr<std::vector<lib::util::String>> pvst_value = std::any_cast<std::shared_ptr<std::vector<lib::util::String>>>(mx_value.second);
			for(const auto &st_value : *pvst_value)
				std::cout << "\t\t" << st_value << std::endl;
			std::cout << "\t" << "] " << std::endl;
		}
	}
}

std::any lib::webserver::request::Query::value(lib::util::String st_name) {
	st_name.toLower();
	//if(!(*this->phmx_query).contains(st_name))
	if((*this->phmx_query)[st_name].type() == typeid(std::shared_ptr<lib::util::String>)) {
		std::shared_ptr<lib::util::String> pst_value = std::any_cast<std::shared_ptr<lib::util::String>>((*this->phmx_query)[st_name]);
		return *pst_value;
	} else {
		std::shared_ptr<std::vector<lib::util::String>> pvst_value = std::any_cast<std::shared_ptr<std::vector<lib::util::String>>>((*this->phmx_query)[st_name]);
		return *pvst_value;
	}
}
