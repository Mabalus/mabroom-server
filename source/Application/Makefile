TARGET = application.a

INCLUDE = ../../include
SOURCE = $(wildcard *.cpp)
OBJECT = $(SOURCE:.cpp=.o)

CXX = clang++-16
CXXFLAGS = -Wall -Wextra -std=c++20 -I$(INCLUDE)

all: message $(TARGET)

message:
	@echo "========================================"
	@echo "======= ...Compiling Application ======="
	@echo "========================================"

$(TARGET): $(OBJECT)
	ar rcs $@ $^ $(OBJECT)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJECT)

.PHONY: all clean
