#ifndef LIB_JSON_CONTROLLER_H
#define LIB_JSON_CONTROLLER_H

#include "Array.h"
#include "Node.h"
#include "../Type.h"
#include "../Util/Exception.h"
#include "../Util/String.h"
#include <any>
#include <cctype>
#include <cstdint>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <typeinfo>
#include <unordered_map>
#include <vector>

namespace lib {

	namespace json {

		class Controller {
			public:
				static std::shared_ptr<lib::json::Node> parser(std::shared_ptr<lib::util::String>);

			private:
				static void findKey(
					std::shared_ptr<size_t>,
					std::shared_ptr<lib::util::String>,
					std::shared_ptr<lib::json::Node>
				);
				static lib::util::String findName(
					std::shared_ptr<size_t> pin_index,
					std::shared_ptr<lib::util::String> pst_json
				);
				static std::shared_ptr<lib::json::Array> processArray(
					std::shared_ptr<size_t> pin_index,
					std::shared_ptr<lib::util::String> pst_json
				);
				static bool processBooleanValue(
					std::shared_ptr<size_t> pin_index,
					std::shared_ptr<lib::util::String> pst_json
				);
				static std::shared_ptr<lib::json::Node> processNode(
					std::shared_ptr<size_t>,
					std::shared_ptr<lib::util::String>
				);
				static std::any processNumberValue(
					std::shared_ptr<size_t> pin_index,
					std::shared_ptr<lib::util::String> pst_json
				);
				static lib::util::String processStringValue(
					std::shared_ptr<size_t>,
					std::shared_ptr<lib::util::String>
				);
				static void skipBlank(
					std::shared_ptr<size_t>,
					std::shared_ptr<lib::util::String>
				);
		};
	}

}

#endif