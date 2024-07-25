#include "Request.h"

lib::webserver::Request::Request(
	std::shared_ptr<lib::webserver::Connection> po_connection,
	lib::util::String st_url,
	lib::util::String st_method,
	lib::util::String st_version
) : po_connection(po_connection),
	st_url(st_url),
	st_method(st_method),
	st_version(st_version),
	po_header(std::make_shared<lib::webserver::request::Header>(po_connection)),
	po_query(std::make_shared<lib::webserver::request::Query>(po_connection))
{
	//std::shared_ptr<lib::webserver::Connection> po_connection = std::make_shared<lib::webserver::Connection>(pt_connection);
	/*
	auto getBody = [](
		void *coninfo_cls,
		enum MHD_ValueKind kind,
		const char *key,
		const char *filename,
        const char *content_type,
		const char *transfer_encoding,
		const char *data,
		uint64_t off,
		size_t size
	) -> enum MHD_Result {
		(void) en_kind;
		std::cout << "key: " << key << std::endl;
		std::cout << "filename: " << filename << std::endl;
		std::cout << "content_type: " << content_type << std::endl;
		std::cout << "transfer_encoding: " << transfer_encoding << std::endl;
		std::cout << "off: " << off << std::endl;
		std::cout << "size: " << size << std::endl;
		/*
		std::unordered_map<std::string, std::string> *phst_header = static_cast<std::unordered_map<std::string, std::string> *>(pmx_data);
		lib::util::String st_name = lib::util::String(pch_name);
		lib::util::String st_value = lib::util::String(pch_value);
		st_name.toLower();
		(*phst_header)[st_name] = st_value;
		
		return MHD_YES;
	};
	lib::util::String *st_body;
	MHD_get_connection_values(pt_connection, MHD_POSTDATA_KIND, getBody, st_body);
	*/
	//std::cout << " >>>>>>> test >> " << test << std::endl;
}

lib::webserver::Request::~Request() {}

std::shared_ptr<lib::webserver::Connection> lib::webserver::Request::connection(void) {
	return	this->po_connection;
}

void *lib::webserver::Request::content(void) {
	return	this->pmx_content;
}

std::shared_ptr<lib::webserver::request::Header> lib::webserver::Request::header(void) {
	return this->po_header;
}

lib::util::UUID lib::webserver::Request::id(void) {
	return this->o_id;
}

lib::util::String lib::webserver::Request::method(void) {
	return	this->st_method;
}

std::shared_ptr<lib::webserver::request::Query> lib::webserver::Request::query(void) {
	return this->po_query;
}

void lib::webserver::Request::trace(void) {
	std::cout << "=====================================" << std::endl;
	std::cout << "============== REQUEST ==============" << std::endl;
	std::cout << "=====================================" << std::endl;
	std::cout << " id: " << this->o_id.string() << std::endl;
	std::cout << " url: " << this->st_url << std::endl;
	std::cout << " method: " << this->st_method << std::endl;
	std::cout << " version: " << this->st_version << std::endl;
	this->po_header->trace();
	this->po_query->trace();
}

lib::util::String lib::webserver::Request::url(void) {
	return	this->st_url;
}

lib::util::String lib::webserver::Request::version(void) {
	return	this->st_version;
}

