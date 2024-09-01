#ifndef LIB_JSON_Array_H
#define LIB_JSON_Array_H

#include "../Type.h"
#include "../Util/String.h"
#include <any>
#include <cstdint>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <unordered_map>
#include <vector>

namespace lib {

	namespace json {

		class Node;

		class Array {

			public:
				Array();
				~Array();
				size_t insert(std::shared_ptr<lib::json::Node>);
				void insert(std::shared_ptr<lib::json::Node>,size_t in_index);
				size_t insert(std::shared_ptr<lib::json::Array>);
				void insert(std::shared_ptr<lib::json::Array>,size_t in_index);
				size_t insert(bool);
				void insert(bool,size_t in_index);
				size_t insert(int64_t);
				void insert(int64_t,size_t in_index);
				size_t insert(float128_t);
				void insert(float128_t,size_t in_index);
				size_t insert(const char *);
				void insert(const char *,size_t in_index);
				size_t insert(std::string);
				void insert(std::string,size_t in_index);
				size_t insert(lib::util::String);
				void insert(lib::util::String,size_t in_index);
				size_t insertArray(void);
				void insertArray(size_t in_index);
				size_t insertNode(void);
				void insertNode(size_t in_index);
				std::shared_ptr<lib::json::Array> array(size_t);
				std::shared_ptr<lib::json::Node> node(size_t);
				bool boolean(size_t);
				int64_t integer(size_t);
				float128_t real(size_t);
				lib::util::String string(size_t);
				void remove(size_t in_index);
				size_t size(void);
				void dump(uint8_t = 0);
				lib::util::String json(uint8_t = 0);
			private:
				using array_t = std::vector<std::any>;
				lib::json::Array::array_t vmx_array;
				lib::util::String toJSON(std::any,uint8_t);
		};
	}

}

#endif