#include "Controller.h"

resource::Controller::Controller(
	std::shared_ptr<application::Controller> po_application
) : po_application(po_application) { }

resource::Controller::~Controller(void) { }

std::shared_ptr<application::Controller> resource::Controller::application(void) {
	return this->po_application;
}