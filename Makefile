APPS = ./apps
BIN = ./bin
INCLUDE = ./include
OBJ = ./obj
SRC = ./src

FLAGS = -Wall

$(OBJ)/%.o: $(SRC)/%.c $(INCLUDE)/%.h #Template for compile object files 
	gcc $(FLAGS) -c $< -I $(INCLUDE) -o $@


$(BIN)/%: $(APPS)/%.c #Template for compile main source files
	gcc $(FLAGS) $< $(OBJ)/*.o -I $(INCLUDE) -o $@

all: clean compile_libs compile_apps

compile_libs: 	\
		$(OBJ)/StringList.o \
		$(OBJ)/StringStack.o \
		$(OBJ)/iocli.o \
		$(OBJ)/MathExpressions.o
		

compile_apps:  \
		$(BIN)/MathCalculator
	
run: 
	./bin/MathCalculator

clean:
	rm -rf $(OBJ)/* $(BIN)/*