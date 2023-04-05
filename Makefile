CXX := g++
CXX_FLAGS := -Wall -Wextra -std=c++20 -ggdb

BIN := bin
SRC := src
INCLUDE := include
LIB := lib

LIBRARIES :=
EXECUTABLE := main

all: $(BIN)/$(EXECUTABLE)

run: clean all
	./$(BIN)/$(EXECUTABLE) 'echo million | cat static/text.txt | cat static/zarplata.txt | wc -c | echo rambler | cat static/zarplata.txt | wc -c | cat static/text.txt | wc -c'

$(BIN)/$(EXECUTABLE): $(wildcard $(SRC)/*.cpp)
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES)

clean:
	-rm -f $(BIN)/*