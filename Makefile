CC=g++-10

CFLAGS= -std=c++2a -g -Wall
CLINKS="./src"

TARGET= main
MAIN_SOURCE=main.cpp
SRC = $(wildcard src/**/*.cpp)
SRC+= $(wildcard src/*.cpp)
OBJ = $(patsubst src/%.cpp, obj/%.o, $(SRC))
INC = -I./src/
LIB = -llapack -lblas

TEST_SEQUENTIALS=./tests/test_sequentials.cpp
TEST_TABLE_SORT=./tests/test_table_sort.cpp
TEST_DATAFILE=./main.cpp


run: build
	@./$(TARGET)

build: $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ) $(MAIN_SOURCE) $(INC) $(LIB)

obj/%.o: src/%.cpp
	@mkdir -p $(shell dirname $@)
	$(CC) $(CFLAGS) -c $< -o $@ $(INC) $(LIB)

test_Point: $(OBJ)
	$(CC) $(CFLAGS) -o ./test_Point $(OBJ) ./tests/test_Point.cpp $(INC) $(LIB)
	./test_Point
	@rm test_Point
	
test_GPoint: $(OBJ)
	$(CC) $(CFLAGS) -o ./test_GPoint $(OBJ) ./tests/test_GPoint.cpp $(INC) $(LIB)
	./test_GPoint
	@rm test_GPoint

test_Array: $(OBJ)
	$(CC) $(CFLAGS) -o ./test_Array $(OBJ) ./tests/test_Array.cpp $(INC) $(LIB)
	./test_Array
	# @rm test_Array

test_point1D: $(OBJ)
	$(CC) $(CFLAGS) -o ./test_point1D $(OBJ) ./tests/test_point1D.cpp $(INC) $(LIB)
	./test_point1D

test_node: $(OBJ)
	$(CC) $(CFLAGS) -o ./test_node $(OBJ) ./tests/test_Node.cpp $(INC) $(LIB)
	./test_node
	@rm test_node

test_Mesh1D: $(OBJ)
	$(CC) $(CFLAGS) -o ./test_Mesh1D $(OBJ) ./tests/test_Mesh1D.cpp $(INC) $(LIB)
	./test_Mesh1D
	@rm test_Mesh1D


test_Node3D: $(OBJ)
	$(CC) $(CFLAGS) -o ./test_Node3D $(OBJ) ./tests/test_Node3D.cpp $(INC) $(LIB)
	./test_Node3D
	@rm test_Node3D

test_Mesh3D: $(OBJ)
	$(CC) $(CFLAGS) -o ./test_Mesh3D $(OBJ) ./tests/test_Mesh3D.cpp $(INC) $(LIB)
	./test_Mesh3D
	@rm test_Mesh3D

test_Brick: $(OBJ)
	$(CC) $(CFLAGS) -o ./test_Brick $(OBJ) ./tests/test_Brick.cpp $(INC) $(LIB)
	./test_Brick
	@rm test_Brick

test_AsciiTecplot: $(OBJ)
	$(CC) $(CFLAGS) -o ./test_AsciiTecplot $(OBJ) ./tests/test_AsciiTecplot.cpp $(INC)
	./test_AsciiTecplot
	@rm test_AsciiTecplot

test_DenseMatrix: $(OBJ)
	$(CC) $(CFLAGS) -o ./test_DenseMatrix $(OBJ) ./tests/test_DenseMatrix.cpp $(INC) $(LIB)
	./test_DenseMatrix
	@rm test_DenseMatrix

test_solver_lapack: $(OBJ)
	$(CC) $(CFLAGS) -o ./test_solver_lapack $(OBJ) ./tests/test_solver_lapack.cpp $(INC) $(LIB)
	./test_solver_lapack
	# @rm test_solver_lapack
	#
test_BasisFunction: $(OBJ)
	$(CC) $(CFLAGS) -o ./test_BasisFunction $(OBJ) ./tests/test_BasisFunction.cpp $(INC) $(LIB)
	./test_BasisFunction
	@rm test_BasisFunction


test_GaussPoint1D: $(OBJ)
	$(CC) $(CFLAGS) -o ./test_GaussPoint1D $(OBJ) ./tests/test_GaussPoint1D.cpp $(INC)
	./test_GaussPoint1D
	@rm test_GaussPoint1D

test_sequentials: $(OBJ)
	$(CC) $(CFLAGS) -o $(TEST_SEQUENTIALS:.cpp=.exe) $(OBJ) $(TEST_SEQUENTIALS) $(INC)
	@./$(TEST_SEQUENTIALS:.cpp=.exe)
	@echo "done"

test_table_sort: $(OBJ)
	$(CC) $(CFLAGS) -o $(TEST_TABLE_SORT:.cpp=.exe) $(OBJ) $(TEST_TABLE_SORT) $(INC)
	@./$(TEST_TABLE_SORT:.cpp=.exe)
	@echo "done"

test_datafile: $(OBJ)
	$(CC) $(CFLAGS) -o $(TEST_DATAFILE:.cpp=.exe) $(OBJ) $(TEST_DATAFILE) $(INC) $(LIB)
	./$(TEST_DATAFILE:.cpp=.exe)

clean:
	@rm -rf obj
