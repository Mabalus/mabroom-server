#include "Controller.h"

routine::Controller::Controller(
	std::shared_ptr<application::Controller> po_application
) : po_application(po_application) { }

routine::Controller::~Controller(void) { }

std::shared_ptr<application::Controller> routine::Controller::application(void) {
	return this->po_application;
}