EXE = binary_tree
CC = g++
SRC = $(wildcard *.cpp)
HDR = $(wildcard *.h)
LIBS = -Wall

$(EXE): $(OBJ)
	$(CC) $(OBJ) -o $(EXE) $(LIBS)

clean:
	rm $(EXE)

debug: $(SRC) $(HDR)
	$(CC) $(SRC) -g -o $(EXE) $(LIBS)

testing: $(SRC) $(HDR)
	$(CC) $(SRC) -g -fsanitize=address -o $(EXE) $(LIBS)
