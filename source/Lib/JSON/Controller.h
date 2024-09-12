/**
 * @file Controller.h
 * @brief Contains the declaration of the Controller class.
 */

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

		/**
		 * @class Controller
		 * @brief Parses JSON strings and constructs a JSON node hierarchy.
		 */
		class Controller {
			public:
				/**
				 * @brief Parses a JSON string and returns the root node of the JSON hierarchy.
				 * @param json The JSON string to parse.
				 * @return A shared pointer to the root node of the JSON hierarchy.
				 */
				static std::shared_ptr<lib::json::Node> parser(std::shared_ptr<lib::util::String> json);

			private:
				/**
				 * @brief Recursively finds a key in the JSON hierarchy and returns the corresponding node.
				 * @param index A shared pointer to the current index in the JSON string.
				 * @param key The key to search for.
				 * @param node A shared pointer to the current node in the JSON hierarchy.
				 */
				static void findKey(
					std::shared_ptr<size_t> index,
					std::shared_ptr<lib::util::String> key,
					std::shared_ptr<lib::json::Node> node
				);

				/**
				 * @brief Finds the name of a JSON object or array.
				 * @param index A shared pointer to the current index in the JSON string.
				 * @param json A shared pointer to the JSON string.
				 * @return The name of the JSON object or array.
				 */
				static lib::util::String findName(
					std::shared_ptr<size_t> index,
					std::shared_ptr<lib::util::String> json
				);

				/**
				 * @brief Processes a JSON array and returns a shared pointer to the corresponding Array object.
				 * @param index A shared pointer to the current index in the JSON string.
				 * @param json A shared pointer to the JSON string.
				 * @return A shared pointer to the Array object.
				 */
				static std::shared_ptr<lib::json::Array> processArray(
					std::shared_ptr<size_t> index,
					std::shared_ptr<lib::util::String> json
				);

				/**
				 * @brief Processes a JSON boolean value and returns its corresponding boolean value.
				 * @param index A shared pointer to the current index in the JSON string.
				 * @param json A shared pointer to the JSON string.
				 * @return The boolean value.
				 */
				static bool processBooleanValue(
					std::shared_ptr<size_t> index,
					std::shared_ptr<lib::util::String> json
				);

				/**
				 * @brief Processes a JSON node and returns a shared pointer to the corresponding Node object.
				 * @param index A shared pointer to the current index in the JSON string.
				 * @param json A shared pointer to the JSON string.
				 * @return A shared pointer to the Node object.
				 */
				static std::shared_ptr<lib::json::Node> processNode(
					std::shared_ptr<size_t> index,
					std::shared_ptr<lib::util::String> json
				);

				/**
				 * @brief Processes a JSON null value.
				 * @param index A shared pointer to the current index in the JSON string.
				 * @param json A shared pointer to the JSON string.
				 */
				static void processNullValue(
					std::shared_ptr<size_t> index,
					std::shared_ptr<lib::util::String> json
				);

				/**
				 * @brief Processes a JSON number value and returns its corresponding value as std::any.
				 * @param index A shared pointer to the current index in the JSON string.
				 * @param json A shared pointer to the JSON string.
				 * @return The value as std::any.
				 */
				static std::any processNumberValue(
					std::shared_ptr<size_t> index,
					std::shared_ptr<lib::util::String> json
				);

				/**
				 * @brief Processes a JSON string value and returns the string value.
				 * @param index A shared pointer to the current index in the JSON string.
				 * @param json A shared pointer to the JSON string.
				 * @return The string value.
				 */
				static lib::util::String processStringValue(
					std::shared_ptr<size_t> index,
					std::shared_ptr<lib::util::String> json
				);

				/**
				 * @brief Skips any blank characters in the JSON string.
				 * @param index A shared pointer to the current index in the JSON string.
				 * @param json A shared pointer to the JSON string.
				 */
				static void skipBlank(
					std::shared_ptr<size_t> index,
					std::shared_ptr<lib::util::String> json
				);
		};
	}

}

#endif