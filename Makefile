SHELL = /bin/sh

PKGS=sdl2 SDL2_ttf
CFLAGS=-Wall -Wextra -pedantic -ggdb `pkg-config --cflags $(PKGS)`

INCLUDE_PATH=-I./include
SRC=./src/*.cpp
LIBS=-lm `pkg-config --libs $(PKGS)`

BASE_DIR=$()

particle:
	$(CXX) $(CFLAGS) $(INCLUDE_PATH) $< $(SRC) $(LIBS) -o ./build/$@

clean:
	rm -rf ./build/particle

test:particle
	./build/particle