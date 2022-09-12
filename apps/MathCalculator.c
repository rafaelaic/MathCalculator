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

#include "MathExpressions.h"
#include "StringList.h"
#include "StringStack.h"
#include "iocli.h"



/* Defines */
#define MAX_EXP_INPUT 100


/* Functions */
int main(int argc, char ** argv){
    char * mathString = "5  + 12 - 123";

    StringList_t* mathStrList = mathStrToMathStrList(mathString);
    printStringList(mathStrList);


    return EXIT_SUCCESS;
}

