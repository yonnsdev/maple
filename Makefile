# clang
CC = clang++
CXXFLAGS = -std=c++17 -Wall -O2

# src, obj, bin
SRC = $(shell find src -name "*.cpp")
OBJ = $(SRC:.cpp=.o)
BIN = bin

# include
INCFLAGS = -I/usr/local/include/SDL2
CXXFLAGS += $(INCFLAGS)

# linker
LDFLAGS = -L/usr/local/lib
LDFLAGS += -lSDL2

.PHONY: all libs dirs build clean

all: build run

libs:
	cd libs/SDL && mkdir -p build && cd build && CC=../build-scripts/clang-fat.sh ../configure && make && sudo make install

dirs:
	@mkdir -p ./$(BIN)

build: dirs $(OBJ)
	$(CC) -o $(BIN)/maple $(filter %.o, $^) $(LDFLAGS)  

%.o: %.cpp
	$(CC) -o $@ -c $^ $(CXXFLAGS) 

run:
	$(BIN)/maple

clean:
	rm -rf $(BIN) $(OBJ)
