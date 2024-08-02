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
LIB_DIR = $(SOURCE)/Lib/lib.a

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
	$(CXX) $(CXXFLAGS) -o $@ $^ $(MAIN_DIR) $(APPLICATION_DIR) $(LIB_DIR) $(MICROHTTPD_LIB) $(LDFLAGS)

clean:
	rm -f server
	$(MAKE) -C $(SOURCE) clean
	$(MAKE) -C $(SOURCE)/Application clean
	$(MAKE) -C $(SOURCE)/Lib clean

.PHONY: all clean