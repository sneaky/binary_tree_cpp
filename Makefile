EXE = binary_tree
CC = g++
OBJDIR = obj
SRC = $(wildcard *.cpp)
HDR = $(wildcard *.h)
#OBJ = $(patsubst %.cpp, %.o, $(SRC))
LIBS = -Wall --std=c++11

$(EXE): $(SRC)
	$(CC) $(SRC) -o $(EXE) $(LIBS)

clean:
	rm -rf $(EXE)

debug: $(SRC) $(HDR)
	$(CC) $(SRC) -g -o $(EXE) $(LIBS)

testing: $(SRC) $(HDR)
	$(CC) $(SRC) -g -fsanitize=address -o $(EXE) $(LIBS)
