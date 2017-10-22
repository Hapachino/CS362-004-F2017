# Citations: http://stackoverflow.com/questions/16886591/how-do-i-enable-c11-in-gcc
# Citations: James Harlan's sample make file on Canvas

CXX = gcc
CXXFLAGS = -std=c99 -Wall
BIN = testme
SRC = $(wildcard *.c)
OBJ = $(SRC:.cpp=.o)

ZIP = $(notdir $(CURDIR))_Brownfield_Erick
ZIPFILES = $(wildcard *.cpp *.hpp *.h) makefile 

VOPT = --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes

all: $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(BIN) $^
	./testme

%.o: %.c
	$(CXX) $(CXXFLAGS) -c $<

debug: 
	@valgrind $(VOPT) ./$(BIN)

zip:
	zip $(ZIP) $(ZIPFILES) *.pdf *.txt

.PHONY: clean
clean:
	rm -f *.o *.zip 
	rm -f $(BIN)