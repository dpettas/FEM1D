CC=g++-10
CFLAGS= -std=c++2a -g -Wall
CLINKS="./src"

TARGET= main
MAIN_SOURCE=main.cpp
SRC = $(wildcard src/**/*.cpp)
SRC+= $(wildcard src/*.cpp)
OBJ = $(patsubst src/%.cpp, obj/%.o, $(SRC))
INC = -I./src/

TEST_SEQUENTIALS=./tests/test_sequentials.cpp
TEST_TABLE_SORT=./tests/test_table_sort.cpp
TEST_DATAFILE=./main.cpp


run: build
	@./$(TARGET)

build: $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ) $(MAIN_SOURCE) $(INC)

obj/%.o: src/%.cpp
	@mkdir -p $(shell dirname $@)
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

test_point1D: $(OBJ)
	$(CC) $(CFLAGS) -o ./test_point1D $(OBJ) ./tests/test_point1D.cpp $(INC)
	./test_point1D

test_node: $(OBJ)
	$(CC) $(CFLAGS) -o ./test_node $(OBJ) ./tests/test_Node.cpp $(INC)
	./test_node
	@rm test_node

test_Mesh1D: $(OBJ)
	$(CC) $(CFLAGS) -o ./test_Mesh1D $(OBJ) ./tests/test_Mesh1D.cpp $(INC)
	./test_Mesh1D
	@rm test_Mesh1D

test_Point3D: $(OBJ)
	$(CC) $(CFLAGS) -o ./test_Point3D $(OBJ) ./tests/test_Point3D.cpp $(INC)
	./test_Point3D
	@rm test_Point3D

test_Node3D: $(OBJ)
	$(CC) $(CFLAGS) -o ./test_Node3D $(OBJ) ./tests/test_Node3D.cpp $(INC)
	./test_Node3D
	@rm test_Node3D

test_Mesh3D: $(OBJ)
	$(CC) $(CFLAGS) -o ./test_Mesh3D $(OBJ) ./tests/test_Mesh3D.cpp $(INC)
	./test_Mesh3D
	@rm test_Mesh3D

test_Brick: $(OBJ)
	$(CC) $(CFLAGS) -o ./test_Brick $(OBJ) ./tests/test_Brick.cpp $(INC)
	./test_Brick
	@rm test_Brick

test_AsciiTecplot: $(OBJ)
	$(CC) $(CFLAGS) -o ./test_AsciiTecplot $(OBJ) ./tests/test_AsciiTecplot.cpp $(INC)
	./test_AsciiTecplot
	@rm test_AsciiTecplot

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
