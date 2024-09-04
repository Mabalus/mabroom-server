TARGET = bin/server

INCLUDE = ./include
SOURCE = ./source

CXX = clang++-16
CXXFLAGS = -Wall -Wextra -std=c++20 -I$(INCLUDE)
#CXXFLAGS = -ftime-report -fsanitize=address
LDFLAGS = -lpthread -luuid

MICROHTTPD_LIB=./libs/libmicrohttpd.a
MAIN_DIR = ./libs/main.a
APPLICATION_DIR = ./libs/application.a
DATA_DIR = ./libs/data.a
RESOURCE_DIR = ./libs/resource.a
MIDDLEWARE_DIR = ./libs/middleware.a
SERVER_DIR = ./libs/server.a
SERVICE_DIR = ./libs/service.a
ROUTINE_DIR = ./libs/routine.a
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
	$(MAKE) -C $(SOURCE)/Data
	$(MAKE) -C $(SOURCE)/Resource
	$(MAKE) -C $(SOURCE)/Middleware
	$(MAKE) -C $(SOURCE)/Server
	$(MAKE) -C $(SOURCE)/Service
	$(MAKE) -C $(SOURCE)/Routine
	$(MAKE) -C $(SOURCE)/Dispatcher
	$(MAKE) -C $(SOURCE)

$(TARGET):
	$(CXX) $(CXXFLAGS) -o $@ $^ \
	$(MAIN_DIR) \
	$(APPLICATION_DIR) \
	$(DATA_DIR) \
	$(RESOURCE_DIR) \
	$(MIDDLEWARE_DIR) \
	$(SERVER_DIR) \
	$(SERVICE_DIR) \
	$(ROUTINE_DIR) \
	$(DISPATCHER_DIR) \
	$(LIB_DIR) \
	$(MICROHTTPD_LIB) \
	$(LDFLAGS)

clean:
	$(MAKE) -C $(SOURCE)/Lib clean
	$(MAKE) -C $(SOURCE)/Application clean
	$(MAKE) -C $(SOURCE)/Data clean
	$(MAKE) -C $(SOURCE)/Resource clean
	$(MAKE) -C $(SOURCE)/Middleware clean
	$(MAKE) -C $(SOURCE)/Server clean
	$(MAKE) -C $(SOURCE)/Service clean
	$(MAKE) -C $(SOURCE)/Routine clean
	$(MAKE) -C $(SOURCE)/Dispatcher clean
	$(MAKE) -C $(SOURCE) clean
	rm -f bin/server

.PHONY: all build clean message