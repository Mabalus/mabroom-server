# Nome do executável
TARGET = server

# Compilador e flags
CXX = clang++-16
CXXFLAGS = -Wall -Wextra -std=c++20 -I.

SRCDIR = ./source
LIBS = -lmicrohttpd -lpthread -luuid
INCLUDE = -L$(SRCDIR)/Lib/lib -llib

MAIN_SOURCES = $(SRCDIR)/server.cpp
APP_SOURCES = $(wildcard $(SRCDIR)/Application/*.cpp)

SOURCES = $(MAIN_SOURCES) $(APP_SOURCES)
OBJECTS = $(SOURCES:.cpp=.o)

all: lib main

lib:
	$(MAKE) -C $(SRCDIR)/Lib

main: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS) $(INCLUDE)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(SRCDIR)/Lib clean
	rm -f $(TARGET) $(OBJECTS)

.PHONY: all clean