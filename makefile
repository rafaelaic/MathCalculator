TARGET = ./bin/MathCalculator

compile: ./apps/MathCalculator.c ./include/*.h
	#Compile TAD StringList
	gcc -c ./src/StringList.c -I ./include/ -o ./obj/StringList.o
	#Compile TAD StringStack
	gcc -c ./src/StringStack.c -I ./include/ -o ./obj/StringStack.o
	#Compile IOCLI
	gcc -c ./src/iocli.c -I ./include/ -o ./obj/iocli.o
	#Compile TAD MathExpressions
	gcc -c ./src/MathExpressions.c ./obj/String*.o -I ./include/ -o ./obj/MathExpressions.o
	#Compile Math Calculator
	gcc ./apps/MathCalculator.c ./obj/*.o -I ./include/ -o MathCalculator
