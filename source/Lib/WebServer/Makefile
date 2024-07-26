TARGET = webserver.a

CXX = clang++-16
CXXFLAGS = -Wall -Wextra -std=c++20


SOURCE = $(wildcard ./*.cpp ./Request/*.cpp ./Response/*.cpp)
OBJECT = $(SOURCE:.cpp=.o)

LIBS = -lmicrohttpd -lpthread -luuid

all: message $(TARGET)

message:
	@echo "=========================================="
	@echo "======= ...Compiling Lib WebServer ======="
	@echo "=========================================="

$(TARGET): $(OBJECT)
	ar rcs $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJECT)

.PHONY: all clean
