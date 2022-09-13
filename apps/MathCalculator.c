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

#include "../include/MathVariables.h"
#include "../include/MathExpressions.h"
#include "../include/StringList.h"
#include "../include/StringStack.h"
#include "../include/iocli.h"


/* Defines */
#define MAX_EXP_INPUT 100

/* Functions */
int main(int argc, char ** argv){


/*     MathVariableList_t* mathVarList = createMathVariableList();
    for(int i = 0; i< 4; i++)
    {
        char* mathVar = (char*) malloc(MAX_LEN_INPUT * sizeof(char));
        double value;
        scanf("%s %lf", mathVar, &value);
        mathVar = optimizeString(mathVar);

        MathVariable_t* var = createMathVariable(mathVar, value);
        mathVarList = appendMathVariableList(mathVarList, var);

    }
    printf("\n\n---------------------------\n\n");
    MathVariable_t* varzin = searchMathVariable(mathVarList, "cleitin");

    printMathVariableList(mathVarList);

    if(varzin != MATH_VAR_NOT_FOUND)
        printf("%s -> %lf\n", varzin->name, varzin->value);
    else
        printf("cleitin not found\n");
        MathExpression_t* MathExpression = createMathExpression(); //Cria a MathExpression
    

    return EXIT_SUCCESS; */

    char* string = (char*) malloc(sizeof(char) * 100);
    while (true)
    {
        fgets(string, 100, stdin);
        optimizeString(string);
        MathExpression_t* MathExpression =  stringToMathExpression(string);
        printMathExpression(MathExpression);
        printf("\n\n---------------\n\n");
    }
    



}

