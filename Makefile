CXX := g++
CC := gcc

CXXFLAGS := -Iinclude -Wall -std=c++17
CFLAGS := -Iinclude -Wall

LDFLAGS := -lglfw -ldl -lGL

SRC_CPP := src/main.cpp
SRC_C := src/glad.c
OBJ := $(SRC_CPP:.cpp=.o) $(SRC_C:.c=.o)

TARGET := game

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $@ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
