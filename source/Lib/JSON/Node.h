#ifndef LIB_JSON_NODE_H
#define LIB_JSON_NODE_H

#include "../Type.h"
#include "../Util/Exception.h"
#include "../Util/String.h"
#include <any>
#include <cstdint>
#include <iostream>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <unordered_map>
#include <vector>

namespace lib {

	namespace json {

		class Array;

		class Node {

			public:
				Node();
				~Node();
				void insertNode(lib::util::String);
				void insertNode(lib::util::String,std::shared_ptr<lib::json::Node>);
				void insertArray(lib::util::String);
				void insertArray(lib::util::String,std::shared_ptr<lib::json::Array>);
				void insertKey(lib::util::String,bool);
				void insertKey(lib::util::String,int64_t);
				void insertKey(lib::util::String,float128_t);
				void insertKey(lib::util::String,const char *);
				void insertKey(lib::util::String,std::string);
				void insertKey(lib::util::String,lib::util::String);
				std::shared_ptr<lib::json::Node> node(lib::util::String);
				std::shared_ptr<lib::json::Array> array(lib::util::String);
				bool boolean(lib::util::String);
				int64_t integer(lib::util::String);
				float128_t real(lib::util::String);
				lib::util::String string(lib::util::String);
				bool has(lib::util::String);
				void remove(lib::util::String);
				void dump(uint8_t = 0);
				lib::util::String toString(uint8_t = 0);
				uint8_t type(lib::util::String);
			private:
				using node_t = std::unordered_map<std::string,std::any>;
				lib::json::Node::node_t hmx_node;
				lib::util::String makeJSON(std::any,uint8_t);
		};
	}

}

#endif