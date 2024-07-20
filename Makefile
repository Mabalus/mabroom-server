# Nome do executável
TARGET = server

# Compilador e flags
CXX = clang++-16
CXXFLAGS = -Wall -Wextra -std=c++20

SRCDIR = ./source
INCDIR = ./include

MAIN_SOURCES = $(SRCDIR)/server.cpp
APP_SOURCES = $(wildcard $(SRCDIR)/Application/*.cpp)
LIB_SOURCES = $(wildcard $(SRCDIR)/Lib/WebServer/*.cpp)

SOURCES = $(MAIN_SOURCES) $(APP_SOURCES) $(LIB_SOURCES)

OBJECTS = $(SOURCES:.cpp=.o)

LIBS = -lmicrohttpd -lpthread

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJECTS)

.PHONY: all clean