CXX = g++
CXX_FLAGS = -Wall -std=c++11
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

OBJ = grille.o piece.o

MAIN_OBJ = main.o $(OBJ)
TEST_OBJ = test.o $(OBJ)

all: main

main: $(MAIN_OBJ)
	$(CXX) -o $@ $^

test: $(TEST_OBJ)
	$(CXX) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXX_FLAGS) -c $< -o $@

check: test
	./test

clean:
	rm -f main *.o