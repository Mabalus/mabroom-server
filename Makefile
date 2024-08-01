# Nome do executável
TARGET = server

INCLUDE = ./include
SOURCE = ./source

# Compilador e flags
CXX = clang++-16
CXXFLAGS = -Wall -Wextra -std=c++20 -I$(INCLUDE)
#CXXFLAGS = -Wall -Wextra -ftime-report -fsanitize=address -std=c++20 -I.
LDFLAGS = -lpthread -luuid

MICROHTTPD_LIB=./libs/libmicrohttpd.a
MAIN_DIR = $(SOURCE)/main.a
APPLICATION_DIR = $(SOURCE)/Application/application.a
UTIL_DIR = $(SOURCE)/Lib/Util/util.a
WEBSERVER_DIR = $(SOURCE)/Lib/WebServer/webserver.a

all: clean build message $(TARGET)

message:
	@echo "================================="
	@echo "======= ...Compiling Binary ======="
	@echo "================================="

build: 
	$(MAKE) -C $(SOURCE)/Lib
	$(MAKE) -C $(SOURCE)/Application 
	$(MAKE) -C $(SOURCE)

$(TARGET):
	$(CXX) $(CXXFLAGS) -o $@ $^ $(MAIN_DIR) $(APPLICATION_DIR) $(WEBSERVER_DIR) $(UTIL_DIR) $(MICROHTTPD_LIB) $(LDFLAGS)

clean:
	rm -f server
	$(MAKE) -C $(SOURCE) clean
	$(MAKE) -C $(SOURCE)/Application clean
	$(MAKE) -C $(SOURCE)/Lib clean

.PHONY: all clean