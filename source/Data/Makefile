PATH_DIR = ../..

TARGET = $(PATH_DIR)/libs/data.a
INCLUDE = $(PATH_DIR)/include
SOURCE_DIR = $(shell find . -type d)
SOURCE = $(foreach dir, $(SOURCE_DIR), $(wildcard $(dir)/*.cpp))

OBJECT = $(SOURCE:.cpp=.o)

CXX = clang++-16
CXXFLAGS = -Wall -Wextra -std=c++20 -I$(INCLUDE)

all: message $(TARGET)

message:
	@echo "=========================================="
	@echo "=========== ...Compiling Data  ==========="
	@echo "=========================================="

$(TARGET): $(OBJECT)
	ar rcs $@ $^ $(OBJECT)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJECT)

.PHONY: all clean
