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


/* Defines */
#define MAX_EXP_INPUT 100

/* Functions */
int main(int argc, char ** argv){

    printf("\n\n--------------------------------------------------------\n\n");

    MathVariableList_t* mathVarList = createMathVariableList();


    char* name1 = "xau" ;
    double value1 = 23.1;
    MathVariable_t* var1 = createMathVariable(name1, value1);
    
    char* name2 = "bob" ;
    double value2 = 43434.12;
    MathVariable_t* var2 = createMathVariable(name2, value2);

    char* name3 = "jao" ;
    double value3 = 54.12;
    MathVariable_t* var3 = createMathVariable(name3, value3);

    mathVarList = appendMathVariableList(mathVarList, var1);
    mathVarList = appendMathVariableList(mathVarList, var2);
    mathVarList = appendMathVariableList(mathVarList, var3);

    boldPrint("Lista de Variaveis\n");
    printMathVariableList(mathVarList);

        
    printf("\n\n--------------------------------------------------------\n\n");
    
    
    MathVariable_t* varzin = searchMathVariable(mathVarList, "bob");

    if(varzin != MATH_VAR_NOT_FOUND)
        printf("%s -> %lf\n", varzin->name, varzin->value);
    else
        printf("cleitin not found\n");

    MathExpression_t* MathExpression = createMathExpression(); //Cria a MathExpression
        
    

    return EXIT_SUCCESS; 

 /*    char* string = (char*) malloc(sizeof(char) * 100);
    while (true)
    {
        fgets(string, 100, stdin);
        optimizeString(string);
        MathExpression_t* MathExpression =  stringToMathExpression(string);
        printMathExpression(MathExpression);
        printf("\n\n---------------\n\n");
    }
   

 */

}

