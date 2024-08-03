#include "./Application/Controller.h"

int main (void) {
	std::shared_ptr<application::Controller> po_application = std::make_shared<application::Controller>();
	po_application->run();
	return 1;
}