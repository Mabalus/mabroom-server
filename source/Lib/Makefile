LIB = lib.a

CXX = clang++-16
CXXFLAGS = -Wall -Wextra -std=c++20

UTIL_SOURCES = $(wildcard ./Util/*.cpp)
WEBSERVER_SOURCES = $(wildcard ./WebServer/*.cpp ./WebServer/Request/*.cpp ./WebServer/Response/*.cpp)

SOURCES = $(UTIL_SOURCES) $(WEBSERVER_SOURCES)
OBJECTS = $(SOURCES:.cpp=.o)

LIBS = -lmicrohttpd -lpthread -luuid

all: $(LIB)

$(LIB): $(OBJECTS)
	ar rcs $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(LIB) $(OBJECTS)

.PHONY: all clean
