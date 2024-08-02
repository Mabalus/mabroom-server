PATH_DIR = ..

TARGET = $(PATH_DIR)/libs/main.a
INCLUDE = $(PATH_DIR)/include
SOURCE = main.cpp
OBJECT = $(SOURCE:.cpp=.o)

CXX = clang++-16
CXXFLAGS = -Wall -Wextra -std=c++20 -I$(INCLUDE)

all: message $(TARGET)

message:
	@echo "================================="
	@echo "======= ...Compiling Main ======="
	@echo "================================="

$(TARGET): $(OBJECT)
	ar rcs $@ $^ $(OBJECT)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJECT)

.PHONY: all clean
