/**
 * @file Environment.h
 * @brief This file contains the declaration of the Environment class.
 */

#ifndef LIB_UTIL_ENVIRONMENT_H
#define LIB_UTIL_ENVIRONMENT_H

#include "String.h"
#include "../Type.h"
#include <cstdlib>
#include <cerrno>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <vector>

namespace lib {

	namespace util {

		/**
		 * @class Environment
		 * @brief The Environment class provides utility functions for working with the environment variables.
		 */
		class Environment {
			public:
				/**
				 * @brief Lists all the environment variables.
				 * @return A shared pointer to a vector of strings containing the names of the environment variables.
				 */
				static std::shared_ptr<std::vector<lib::util::String>> list(void);

				/**
				 * @brief Gets the value of the specified environment variable.
				 * @param name The name of the environment variable.
				 * @return A shared pointer to a string containing the value of the environment variable.
				 */
				static std::shared_ptr<lib::util::String> get(const char *);

				/**
				 * @brief Gets the value of the specified environment variable.
				 * @param name The name of the environment variable.
				 * @return A shared pointer to a string containing the value of the environment variable.
				 */
				static std::shared_ptr<lib::util::String> get(lib::util::String);

				/**
				 * @brief Dumps all the environment variables to the standard output.
				 */
				static void dump(void);
		};

	}
}

#endif
