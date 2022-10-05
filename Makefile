# clang
CC = clang++
CCFLAGS  = -std=c++20 -O2 -g -Wall -Wno-unused-parameter

# src, obj, bin
SRC = $(shell find src -name "*.cpp")
OBJ = $(SRC:.cpp=.o)
BIN = bin

# Include Flags
INCFLAGS  = -I/opt/homebrew/opt/sdl2/include/SDL2 -D_THREAD_SAFE
INCFLAGS += -I/opt/homebrew/opt/sdl2_image/include/SDL2
INCFLAGS += -I/opt/homebrew/opt/sdl2_ttf/include/SDL2
CCFLAGS += $(INCFLAGS)

# Extra Flags
LDFLAGS  = -L/opt/homebrew/opt/sdl2/lib -lSDL2
LDFLAGS += -L/opt/homebrew/opt/sdl2_image/lib -lSDL2_image
LDFLAGS += -L/opt/homebrew/opt/sdl2_ttf/lib -lSDL2_ttf
LDFLAGS += $(FRAMEWORKS)
LDFLAGS += $(INCFLAGS)

# [TODO: shaders here]

.PHONY: all dirs build clean

all: build run

dirs:
	@mkdir -p ./$(BIN)

build: dirs $(OBJ)
	$(CC) -o $(BIN)/maple $(filter %.o, $^) $(LDFLAGS)  

%.o: %.cpp
	$(CC) -o $@ -c $^ $(CCFLAGS) 

run:
	$(BIN)/maple

# make clear : removes all project build files
clean:
	rm -rf $(BIN) $(OBJ)