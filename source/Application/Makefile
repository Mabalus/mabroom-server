TARGET = application.a

CXX = clang++-16
CXXFLAGS = -Wall -Wextra -std=c++20

SOURCE = $(wildcard *.cpp)
OBJECT = $(SOURCE:.cpp=.o)

LIBS = -lmicrohttpd -lpthread -luuid

all: message $(TARGET)

message:
	@echo "========================================"
	@echo "======= ...Compiling Application ======="
	@echo "========================================"

$(TARGET): $(OBJECT)
	ar rcs $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJECT)

.PHONY: all clean
