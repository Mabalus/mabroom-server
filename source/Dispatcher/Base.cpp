#include "Base.h"
#include "../Lib/JSON/Controller.h"

void dispatcher::Base::routing(std::shared_ptr<application::Dispatcher> po_dispatcher) {
	/*
	lib::util::String st_json = R"({
		"name": "John Doe",
		"age": 30,
		"is_student": false,
		"marks": {
			"math": 8.5,
			"science": 9
		},
		"friends": [
			"Alice",
			"Bob"
		]
	})";
	*/
	//std::shared_ptr<lib::json::Node> po_node = lib::json::Controller::parser(std::make_shared<lib::util::String>(st_json));
	//po_dispatcher->dump();
	std::shared_ptr<lib::util::String> pst_path = po_dispatcher->path();
	if(!pst_path) {
		lib::json::Node o_root;
		o_root.insertKey("name","backend");
		o_root.insertKey("version","0.1.0");
		po_dispatcher->response()->setContent(o_root.json(),"application/json");
		po_dispatcher->response()->send(200);
	} else if(*pst_path == "test") {
		lib::json::Node o_root;
		po_dispatcher->response()->setContent(o_root.json(),"application/json");
		po_dispatcher->response()->send(200);
	} else
		po_dispatcher->response()->send(404);
}