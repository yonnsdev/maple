# clang
CC = clang++

# src, obj, bin
SRC = $(shell find src -name "*.cpp")
OBJ = $(SRC:.cpp=.o)
BIN = bin

# Include Flags


# Compiler Flags
CXXFLAGS  = -std=c++20 -O2 -g -Wall
CXXFLAGS += -Wno-unused-parameter
CXXFLAGS += $(INCFLAGS)

# Extra Flags
LDFLAGS  = -lm
LDFLAGS += $(INCFLAGS)


# [TODO: shaders here]

.PHONY: all libs dirs build clean

all: build run

libs:


dirs:
	@mkdir -p ./$(BIN)

build: dirs $(OBJ)
	$(CC) -o $(BIN)/maple $(filter %.o, $^) $(LDFLAGS)  

%.o: %.cpp
	$(CC) -o $@ -c $^ $(CXXFLAGS) 

run:
	$(BIN)/maple

# make clear : removes all project build files
clean:
	rm -rf $(BIN) $(OBJ)