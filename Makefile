TARGET = server

INCLUDE = ./include
SOURCE = ./source

CXX = clang++-16
CXXFLAGS = -Wall -Wextra -std=c++20 -I$(INCLUDE)
#CXXFLAGS = -ftime-report -fsanitize=address
LDFLAGS = -lpthread -luuid

MICROHTTPD_LIB=./libs/libmicrohttpd.a
MAIN_DIR = ./libs/main.a
APPLICATION_DIR = ./libs/application.a
DISPATCHER_DIR = ./libs/dispatcher.a
LIB_DIR = ./libs/lib.a

all: clean build message $(TARGET)

message:
	@echo "================================="
	@echo "====== ...Compiling Binary ======"
	@echo "================================="

build: 
	$(MAKE) -C $(SOURCE)/Lib
	$(MAKE) -C $(SOURCE)/Application
	$(MAKE) -C $(SOURCE)/Dispatcher
	$(MAKE) -C $(SOURCE)

$(TARGET):
	$(CXX) $(CXXFLAGS) -o $@ $^ $(MAIN_DIR) $(APPLICATION_DIR) $(DISPATCHER_DIR) $(LIB_DIR) $(MICROHTTPD_LIB) $(LDFLAGS)

clean:
	$(MAKE) -C $(SOURCE)/Lib clean
	$(MAKE) -C $(SOURCE)/Application clean
	$(MAKE) -C $(SOURCE)/Dispatcher clean
	$(MAKE) -C $(SOURCE) clean
	rm -f server

.PHONY: all build clean message