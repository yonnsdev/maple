# clang
CC = clang++
CXXFLAGS = -std=c++17 -Wall -O2

# src, obj, bin
SRC = $(shell find src -name "*.cpp")
OBJ = $(SRC:.cpp=.o)
BIN = build

# include
INCFLAGS = 
CXXFLAGS += $(INCFLAGS)

# linker
LDFLAGS = 

.PHONY: all dirs build clean

all: build run

dirs:
	@mkdir -p ./$(FLD)

build: dirs $(OBJ)
	$(CC) -o $(FLD)/$(OUT) $(filter %.o, $^) $(LDFLAGS)  

%.o: %.cpp
	$(CC) -o $@ -c $^ $(CXXFLAGS) 

run:
	@$(FLD)/$(OUT)

clean:
	rm -rf $(FLD) $(OBJ)
