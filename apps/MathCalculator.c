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

    //boldPrint("Lista de Variaveis\n");
    //printMathVariableList(mathVarList);

     
    //printf("\n\n--------------------------------------------------------\n\n"); 
    

/* ---------------------------------------------------------------------------------- */
    //Found a variable
/*     MathVariable_t* varzin = searchMathVariable(mathVarList, "bob");

    if(varzin != MATH_VAR_NOT_FOUND)
        printf("%s -> %lf\n", varzin->name, varzin->value);
    else
        printf("cleitin not found\n"); */
/* ---------------------------------------------------------------------------------- */

    //Var para expressão lida do stdin
    char* input_expression = (char*) malloc(sizeof(char)*MAX_LEN_INPUT);



    //Init message
    boldPrint("\nMathCalculador RP - Alfa Version\n");

    
    while(true)
    {
        printf(">> ");
        fgets(input_expression, MAX_LEN_INPUT, stdin);
        input_expression = optimizeString(input_expression);

        if(input_expression == NULL || strcmp("exit", input_expression) == 0)
        {
            boldPrint("\nThank you for test my calculator!\n");
            return EXIT_SUCCESS;
        }

        double* result = calcStringMathExpression(input_expression, mathVarList);

        if(result == INVALID_MATH_EXPRESSION) printf("Invalid Input\n");
        else printf("%.2lf\n", *result);
    }





/* 
    boldPrint("\nExpressao em String\n");
    printf("\n>> %s", mathString);

    printf("\n\n--------------------------------------------------------\n\n");


    MathExpression_t* MathExpression = stringToMathExpression(mathString);
    printMathExpression(MathExpression);

    printf("\n\n--------------------------------------------------------\n\n");

    // Converte as variáveis
    //boldPrint("Expressao Matematica com variaveis convertidas\n");
    bool status = convertMathExpressionVariables(MathExpression, mathVarList);
    if(status) printf("\n[Sucesso ao converter]\n\n");
    else 
    {
        printf("\n[Erro ao converter]\n\n");
        return EXIT_FAILURE;
    }
    
    //printMathExpression(MathExpression);

    printf("\n\n--------------------------------------------------------\n\n");

    MathExpression_t* postfix_expression = convertInfixToPostFixMathExpression(MathExpression);

    if(postfix_expression == INVALID_MATH_EXPRESSION)
    {
        printf("ERRO AO CONVERTER PARA POSTFIX\n\n");
        return INVALID_MATH_EXPRESSION;
    }

    boldPrint("Expressao pos-fixada\n");
    printMathExpression(postfix_expression);

    printf("\n\n--------------------------------------------------------\n\n");

    double* result = resolvePostfixMathExpression(postfix_expression);

    if(result == INVALID_MATH_EXPRESSION) printf("Invalid Input\n");
    else printf("Result -> %lf\n", *result);


    return EXIT_SUCCESS;  */

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

