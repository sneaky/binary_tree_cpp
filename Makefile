EXE = binary_tree
CC = g++
OBJDIR = obj
SRC = $(wildcard *.cpp)
HDR = $(wildcard *.h)
OBJ = $(patsubst %.c++, $(OBJDIR)/%.o, $(SRC))
LIBS = -Wall

$(EXE): $(OBJ)
	$(CC) $(OBJ) -o $(EXE) $(LIBS)

$(OBJDIR)/%.o: %.c++ $(HDR) | $(OBJDIR)
	$(CC) -c $< -o $@ $(LIBS)

$(OBJDIR):
	mkdir -p $@

clean:
	rm -rf $(OBJDIR)

debug: $(SRC) $(HDR)
	$(CC) $(SRC) -g -o $(EXE) $(LIBS)

testing: $(SRC) $(HDR)
	$(CC) $(SRC) -g -fsanitize=address -o $(EXE) $(LIBS)
