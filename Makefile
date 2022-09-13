APPS = ./apps
INCLUDE = ./include
OBJ = ./obj
SRC = ./src

%.o: $(SRC)/%.c $(INCLUDE)/%.h #Template for compile object files 
	gcc -c $< -I $(INCLUDE) -o $@


all: compile_libs compile_apps

compile_libs: StringList.o StringStack.o MathExpressions.c iocli.c

compile_apps:
	gcc $(SRC)/MathCalculator.c $(OBJ)/*.o -I $(INCLUDE) -o MathCalculator

run: 
	./MathCalculator

clean:
	rm ./MathCalculator ./obj/*