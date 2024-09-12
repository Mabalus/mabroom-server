/**
 * @file String.h
 * @brief This file contains the declaration of the String class, which is a derived class from std::string.
 */

#ifndef LIB_UTIL_STRING_H
#define LIB_UTIL_STRING_H

#include <algorithm>
#include <cctype>
#include <cstring>
#include <iostream>
#include <regex>
#include <string>
#include <vector>

namespace lib {

	namespace util {

		/**
		 * @class String
		 * @brief The String class is a derived class from std::string and provides additional string manipulation functions.
		 */
		class String : public std::string {

			public:
				/**
				 * @brief Default constructor for the String class.
				 */
				String() = default;

				/**
				 * @brief Constructor for the String class that takes a std::string as input.
				 * @param str The input std::string.
				 */
				String(const std::string &str);

				/**
				 * @brief Constructor for the String class that takes a C-style string as input.
				 * @param str The input C-style string.
				 */
				String(const char* str);

				/**
				 * @brief Converts the string to lowercase.
				 */
				void toLower(void);

				/**
				 * @brief Converts the string to uppercase.
				 */
				void toUpper(void);

				/**
				 * @brief Converts the input string to lowercase and returns a new String object.
				 * @param st_input The input string.
				 * @return A new String object with the lowercase string.
				 */
				static lib::util::String lower(const lib::util::String st_input);

				/**
				 * @brief Splits the input string based on a delimiter character and returns a vector of String objects.
				 * @param st_input The input string.
				 * @param ch_delimiter The delimiter character.
				 * @return A shared pointer to a vector of String objects.
				 */
				static std::shared_ptr<std::vector<lib::util::String>> split(const lib::util::String st_input, const char ch_delimiter);

				/**
				 * @brief Splits the input string based on a delimiter string and returns a vector of String objects.
				 * @param st_input The input string.
				 * @param st_delimiter The delimiter string.
				 * @return A shared pointer to a vector of String objects.
				 */
				static std::shared_ptr<std::vector<lib::util::String>> split(const lib::util::String st_input, const lib::util::String st_delimiter);

				/**
				 * @brief Splits the input string based on a regular expression delimiter and returns a vector of String objects.
				 * @param st_input The input string.
				 * @param rg_delimiter The regular expression delimiter.
				 * @return A shared pointer to a vector of String objects.
				 */
				static std::shared_ptr<std::vector<lib::util::String>> split(const lib::util::String st_input, const std::regex rg_delimiter);

				/**
				 * @brief Converts the input string to uppercase and returns a new String object.
				 * @param st_input The input string.
				 * @return A new String object with the uppercase string.
				 */
				static lib::util::String upper(const lib::util::String st_input);        
		};
	}
}

#endif
