#include "Connection.h"

lib::webserver::Connection::Connection(MHD_Connection *pt_connection) 
	: pt_connection(pt_connection) {}

lib::webserver::Connection::~Connection() {}

MHD_Connection *lib::webserver::Connection::get(void) {
	return this->pt_connection;
}

lib::webserver::Connection &lib::webserver::Connection::operator=(const lib::webserver::Connection &o_connection) {
	if (this != &o_connection)
		this->pt_connection = o_connection.pt_connection;
	return *this;
}
