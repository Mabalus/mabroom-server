#include "Controller.h"

service::Controller::Controller(
	std::shared_ptr<application::Controller> po_application
) : po_application(po_application) { }

service::Controller::~Controller(void) { }

std::shared_ptr<application::Controller> service::Controller::application(void) {
	return this->po_application;
}