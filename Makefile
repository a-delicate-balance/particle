SHELL = /bin/sh

PKGS=sdl2 SDL2_ttf
CFLAGS=`pkg-config --cflags $(PKGS)`
REL_CFLAGS=$(CFLAGS) -O2
DEB_CFLAGS=$(CFLAGS) -Wall -Wextra -pedantic -ggdb

INCLUDE_PATH=./include
SRC=./src/*.cpp
LIBS=-lm `pkg-config --libs $(PKGS)`

BASE_DIR=$()

particle:
	$(CXX) $(CFLAGS) -I$(INCLUDE_PATH) $< $(SRC) $(LIBS) -o ./build/$@

clean:
	rm -rf ./build/particle

test:particle
	./build/particle

debug:
	$(CXX) $(DEB_CFLAGS) -I$(INCLUDE_PATH) $< $(SRC) $(LIBS) -o ./build/particle-debug
	# valgrind ./build/particle-debug --leak-check=full -track-origins=yes
	


