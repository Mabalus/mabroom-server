#include "RequestQuery.h"

Lib::WebServer::RequestQuery::RequestQuery(MHD_Connection *o_connection) {
	auto getQuery = [](void *pmx_data, enum MHD_ValueKind en_kind, const char *pch_name, const char *pch_value) -> enum MHD_Result {
		(void) en_kind;
		std::unordered_map<std::string, Lib::WebServer::query_t> *phmx_query = static_cast<std::unordered_map<std::string, Lib::WebServer::query_t> *>(pmx_data);
		Lib::Util::String *pst_value = nullptr;
		Lib::Util::String st_name = Lib::Util::String(pch_name);
		if((*phmx_query).contains(pch_name)) {
			std::vector<Lib::Util::String> *vst_value = nullptr;			
			if((*phmx_query)[pch_name].bo_array == false) {
				vst_value = new std::vector<Lib::Util::String>();
				pst_value = static_cast<Lib::Util::String*>((*phmx_query)[pch_name].pmx_value);
				vst_value->push_back(*pst_value);
				pst_value = new Lib::Util::String(pch_value);
				vst_value->push_back(*pst_value);
				(*phmx_query)[pch_name].bo_array = true;
				(*phmx_query)[pch_name].pmx_value = (void *) vst_value;
			} else {
				vst_value = static_cast<std::vector<Lib::Util::String>*>((*phmx_query)[pch_name].pmx_value);
				vst_value->push_back(pch_value);
			}
		} else {
			pst_value = new Lib::Util::String(pch_value);
			(*phmx_query)[pch_name] = { false, pst_value };
		} 
		return MHD_YES;
	};
	this->phmx_query = new std::unordered_map<std::string, Lib::WebServer::query_t>();
	MHD_get_connection_values(o_connection, MHD_GET_ARGUMENT_KIND, getQuery, this->phmx_query);
}

Lib::WebServer::RequestQuery::~RequestQuery() {}

bool Lib::WebServer::RequestQuery::has(Lib::Util::String st_name) {
	st_name.toLower();
	return (*this->phmx_query).contains(st_name);
}

std::vector<Lib::Util::String> *Lib::WebServer::RequestQuery::list(void) {
	std::vector<Lib::Util::String> *vst_name = new std::vector<Lib::Util::String>();
	for(const auto &o_hash : *this->phmx_query)
		vst_name->push_back(o_hash.first);
    return vst_name;
}

void Lib::WebServer::RequestQuery::trace(void) {
	std::cout << "===== Query Section =====" << std::endl;
	for(const auto &mx_value : *this->phmx_query) {
		if(mx_value.second.bo_array == false) {
			Lib::Util::String *pst_value = static_cast<Lib::Util::String*>(mx_value.second.pmx_value);
			std::cout << "\t" << mx_value.first << ": " << *pst_value << std::endl;
		} else {
			std::cout << "\t" << mx_value.first << ": [ " << std::endl;
			std::vector<Lib::Util::String> *pvst_value = static_cast<std::vector<Lib::Util::String>*>(mx_value.second.pmx_value);
			for(const auto &st_value : *pvst_value)
				std::cout << "\t\t" << st_value << std::endl;
			std::cout << "\t" << "] " << std::endl;
		}
	}
}

bool Lib::WebServer::RequestQuery::type(Lib::Util::String st_name) {
	return (*this->phmx_query)[st_name].bo_array;
}

void *Lib::WebServer::RequestQuery::value(Lib::Util::String st_name) {
	return (*this->phmx_query)[st_name].pmx_value;
}
