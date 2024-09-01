#include "Environment.h"

extern char **environ;

std::shared_ptr<std::vector<lib::util::String>> lib::util::Environment::list(void) {
	if(environ == nullptr)
		return nullptr;
	std::shared_ptr<std::vector<lib::util::String>> pst_environment = std::make_shared<std::vector<lib::util::String>>();
	for(char **pch_env = environ; *pch_env != nullptr; ++pch_env) {
		lib::util::String st_environment(*pch_env);
		size_t in_position = st_environment.find('=');
		size_t in_length = st_environment.length();
		if(in_position < in_length) {
			st_environment = st_environment.substr(0, in_position);
			pst_environment->push_back(st_environment);
		}
	}
	return pst_environment;
};

std::shared_ptr<lib::util::String> lib::util::Environment::get(const char *pch_name) {
	const char *pch_environment = std::getenv(pch_name);
	if(!pch_environment)
		return nullptr;
	std::shared_ptr<lib::util::String> pst_environment = std::make_shared<lib::util::String>(pch_environment);
	if(pst_environment->front() == '"' && pst_environment->back() == '"') {
		pst_environment->erase(pst_environment->begin());
		pst_environment->erase(pst_environment->end());
	}
	return pst_environment; 
}

std::shared_ptr<lib::util::String> lib::util::Environment::get(lib::util::String st_name) {
	size_t in_name = st_name.length() + 1;
	char *pch_name = new char[in_name];
	std::strncpy(pch_name, st_name.c_str(),in_name);
	const char *pch_environment = std::getenv(pch_name);
	if(!pch_environment)
		return nullptr;
	std::shared_ptr<lib::util::String> pst_environment = std::make_shared<lib::util::String>(pch_environment);
	if(pst_environment->front() == '"' && pst_environment->back() == '"') {
		pst_environment->erase(pst_environment->begin());
		pst_environment->erase(pst_environment->end());
	}
	return pst_environment;
}

void lib::util::Environment::dump(void) {
	if(environ == nullptr) {
		std::cerr << "Nenhuma variável de ambiente encontrada." << std::endl;
		return;
		
	}
	for (char **pch_environment = environ; *pch_environment != nullptr; ++pch_environment) {
		std::cout << *pch_environment << std::endl;
	}
};