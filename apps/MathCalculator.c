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

#include "MathVariables.h"
#include "MathExpressions.h"
#include "StringList.h"
#include "StringStack.h"
#include "iocli.h"


/* Functions */
int main(int argc, char ** argv){


    //printf("\n\n--------------------------------------------------------\n\n");

    MathVariableList_t* mathVarList = createMathVariableList();


    char* name1 = "pi" ;
    double value1 = 3.141592;
    MathVariable_t* var1 = createMathVariable(name1, value1);

    mathVarList = appendMathVariableList(mathVarList, var1);


    //Var para expressão lida do stdin
    char* input_expression = (char*) malloc(sizeof(char)*MAX_LEN_INPUT);
    char* input_optmized_expression;


    //Init message
    boldPrint("\nMathCalculador RP - Alfa Version\n");

    
    while(true)
    {
        printf(">> ");
        fgets(input_expression, MAX_LEN_INPUT, stdin);
        input_optmized_expression = optimizeString(input_expression);

        if(input_optmized_expression == NULL) continue;

        if(strcmp("exit", input_optmized_expression) == 0)
        {
            boldPrint("\nThank you for test my calculator!\n");
            return EXIT_SUCCESS;
        }

        double* result = calcStringMathExpression(input_optmized_expression, mathVarList);

        if(result == INVALID_MATH_EXPRESSION) printf("Invalid Input\n");
        else printf("%.2lf\n", *result);
        free(result);
    }

}

