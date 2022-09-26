# clang
CC = clang++
CXXFLAGS = -std=c++17 -Wall -O2

# src, obj, bin
SRC = $(shell find src -name "*.cpp")
OBJ = $(SRC:.cpp=.o)
BIN = bin

# include
INCFLAGS = -Ilibs/SDL/include
CXXFLAGS += $(INCFLAGS)

# linker
LDFLAGS = 

.PHONY: all libs dirs build clean

all: build run

libs:
	cd libs/SDL && ./configure && make && sudo make install

dirs:
	@mkdir -p ./$(FLD)

build: dirs $(OBJ)
	$(CC) -o $(BIN)/maple $(filter %.o, $^) $(LDFLAGS)  

%.o: %.cpp
	$(CC) -o $@ -c $^ $(CXXFLAGS) 

run:
	@$(BIN)/maple

clean:
	rm -rf $(BIN) $(OBJ)
