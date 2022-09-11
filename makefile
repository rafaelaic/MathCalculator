TARGET = ./bin/MathCalculator

compile: ./apps/MathCalculator.c ./include/*.h ./obj/*.o
	#Compile TAD stack
	gcc -c ./src/stack.c -I ./include/ -o ./obj/stack.o
	#Compile IOCLI
	gcc -c ./src/iocli.c -I ./include/ -o ./obj/iocli.o
	#Compile Math Calculator
	gcc ./apps/MathCalculator.c ./obj/*.o -I ./include/ -o MathCalculator
