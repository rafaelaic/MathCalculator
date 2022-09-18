APPS = ./apps
BIN = ./bin
INCLUDE = ./include
OBJ = ./obj
SRC = ./src

FLAGS = -Wall -lm

$(OBJ)/%.o: $(SRC)/%.c $(INCLUDE)/%.h #Template for compile object files 
	gcc -c $< -I $(INCLUDE) -o $@ $(FLAGS)


$(BIN)/%: $(APPS)/%.c #Template for compile main source files
	gcc $< $(OBJ)/*.o -I $(INCLUDE) -o $@ $(FLAGS)

all: clean compile_libs compile_apps

compile_libs: 	\
		$(OBJ)/StringList.o \
		$(OBJ)/StringStack.o \
		$(OBJ)/iocli.o \
		$(OBJ)/MathExpressions.o \
		$(OBJ)/MathVariables.o \
		$(OBJ)/commands.o
		

		

compile_apps:  \
		$(BIN)/MathCalculator

depurate:
	gcc -g $(APPS)/MathCalculator.c $(SRC)/*.c  -I $(INCLUDE) -o $(BIN)/Depurate_MathCalculator $(FLAGS)


run: 
	./bin/MathCalculator

clean:
	rm -rf $(OBJ)/* $(BIN)/*
	clear

