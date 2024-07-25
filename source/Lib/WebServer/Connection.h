#ifndef LIB_WEBSERVER_CONNECTION_H
#define LIB_WEBSERVER_CONNECTION_H

#include <microhttpd.h>

namespace lib {

	namespace webserver {

		class Connection {

			public:
				Connection(MHD_Connection *);
				~Connection();
				MHD_Connection *get(void);
				lib::webserver::Connection &operator=(const lib::webserver::Connection &);

			private:
				MHD_Connection *pt_connection;
		};
	}
}

#endif
