# Nome do executável
TARGET = server

# Compilador e flags
CXX = clang++-16
CXXFLAGS = -Wall -Wextra -ftime-report -fsanitize=address -std=c++20 -I.

SRCDIR = ./source
LIBS = -lmicrohttpd -lpthread -luuid

MAIN_DIR = $(SRCDIR)/main.a
APPLICATION_DIR = $(SRCDIR)/Application/application.a
LIB_DIR = $(SRCDIR)/Lib/lib.a

all: build $(TARGET)

build: 
	$(MAKE) -C $(SRCDIR)/Lib
	$(MAKE) -C $(SRCDIR)/Application 
	$(MAKE) -C $(SRCDIR)

$(TARGET):
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS) $(MAIN_DIR) $(APPLICATION_DIR) $(LIB_DIR)

clean:
	rm -f server
	$(MAKE) -C $(SRCDIR) clean
	$(MAKE) -C $(SRCDIR)/Application clean
	$(MAKE) -C $(SRCDIR)/Lib clean

.PHONY: all clean