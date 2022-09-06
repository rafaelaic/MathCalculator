/*
* @file: MathCalculator.c
* @brief: Arquivo principal do projeto MathCalculator
* @author: Rafael Eustáquio Pinto
* @date: 06/09/2022
*/



/* Includes */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "../include/stack.h"
#include "../include/makeio.h"


/* Defines */
#define MAX_EXP_INPUT 100


/* Functions */
int main(int argc, char ** argv){

    while (strcmp(expression, ""))
    char* expression = (char*) malloc(MAX_EXP_INPUT * sizeof(char));
    fgets(expression, MAX_EXP_INPUT, stdin);

    expression = (char*) realloc(expression, strlen(expression) * sizeof(char));
    printf("%lu\n", strlen(expression));

    boldPrint((const char*) expression);



    return EXIT_SUCCESS;
}

