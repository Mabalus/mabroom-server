TARGET = webserver.a

INCLUDE = ../../../include
SOURCE = $(wildcard ./*.cpp ./Request/*.cpp ./Response/*.cpp)
OBJECT = $(SOURCE:.cpp=.o)

CXX = clang++-16
CXXFLAGS = -Wall -Wextra -std=c++20 -I$(INCLUDE)
#CXXFLAGS = -Wall -Wextra -ftime-report -fsanitize=address -std=c++20 -I.

UTIL_LIB = ../Util/util.a

all: message $(TARGET)

message:
	@echo "=========================================="
	@echo "======= ...Compiling Lib WebServer ======="
	@echo "=========================================="

$(TARGET): $(OBJECT)
	ar rcs $@ $^ $(OBJECT) $(UTIL_LIB)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJECT)

.PHONY: all clean
