#include "Base.h"

void dispatcher::Base::routing(std::shared_ptr<application::Dispatcher> po_dispatcher) {
	po_dispatcher->request()->trace();
	if(po_dispatcher->request()->url() == "/") {
		po_dispatcher->response()->setContent("{ \"name\": \"backend\", \"version\": \"0.1.0\" }","application/json");
		po_dispatcher->response()->send(200);
	} else
		po_dispatcher->response()->send(404);
}