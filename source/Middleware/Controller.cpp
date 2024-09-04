#include "Controller.h"

middleware::Controller::Controller(
	std::shared_ptr<application::Controller> po_application
) : po_application(po_application) { }

middleware::Controller::~Controller(void) { }

std::shared_ptr<application::Controller> middleware::Controller::application(void) {
	return this->po_application;
}