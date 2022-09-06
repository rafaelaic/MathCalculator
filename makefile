TARGET = ./bin/MathCalculator

compile: ./apps/MathCalculator.c ./include/*.h ./obj/*.o
	#Compile TAD stack
	gcc -c ./src/stack.c -I ./include/ -o ./obj/stack.o
	#Compile MAKEIO
	gcc -c ./src/makeio.c -I ./include/ -o ./obj/makeio.o
	#Compile Math Calculator
	gcc ./apps/MathCalculator.c ./obj/*.o -I ./include/ -o ./bin/MathCalculator
