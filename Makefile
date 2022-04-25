CC=g++
CFLAGS= -g -Wall
CLINKS="./src"

TARGET= main
MAIN_SOURCE=main.cpp
SRC = $(wildcard src/**/*.cpp)
SRC+= $(wildcard src/*.cpp)
OBJ = $(patsubst src/%.cpp, obj/%.o, $(SRC))
INC = -I./src

TEST_SEQUENTIALS=./tests/test_sequentials.cpp
TEST_TABLE_SORT=./tests/test_table_sort.cpp
TEST_DATAFILE=./main.cpp


run: build
	@./$(TARGET)

build: $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ) $(MAIN_SOURCE) $(INC)

obj/%.o: src/%.cpp
	@mkdir -p $(shell dirname $@)
	$(CC) $(CFLAGS) -c $< -o $@

test_point1D: $(OBJ)
	$(CC) $(CFLAGS) -o ./test_point1D $(OBJ) ./tests/test_point1D.cpp $(INC)
	./test_point1D

test_node: $(OBJ)
	$(CC) $(CFLAGS) -o ./test_node $(OBJ) ./tests/test_Node.cpp $(INC)
	./test_node
	@rm test_node





test_sequentials: $(OBJ)
	$(CC) $(CFLAGS) -o $(TEST_SEQUENTIALS:.cpp=.exe) $(OBJ) $(TEST_SEQUENTIALS) $(INC)
	@./$(TEST_SEQUENTIALS:.cpp=.exe)
	@echo "done"

test_table_sort: $(OBJ)
	$(CC) $(CFLAGS) -o $(TEST_TABLE_SORT:.cpp=.exe) $(OBJ) $(TEST_TABLE_SORT) $(INC)
	@./$(TEST_TABLE_SORT:.cpp=.exe)
	@echo "done"

test_datafile: $(OBJ)
	$(CC) $(CFLAGS) -o $(TEST_DATAFILE:.cpp=.exe) $(OBJ) $(TEST_DATAFILE) $(INC)
	./$(TEST_DATAFILE:.cpp=.exe)

clean:
	@rm -rf obj
