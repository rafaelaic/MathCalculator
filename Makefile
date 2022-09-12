APPS = ./apps
INCLUDE = ./include
OBJ = ./obj
SRC = ./src


all: compile_libs compile_apps

compile_libs: StringList.o StringStack.o MathExpressions.c iocli.c

compile_apps: 

%.o 