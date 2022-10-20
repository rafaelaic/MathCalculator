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
#include "commands.h"


MathVariableList_t* initializeVarList(){
    MathVariableList_t* varList = createMathVariableList();

    MathVariable_t* var= createMathVariable("$pi", 3.14159265359);
    varList = appendMathVariableList(varList, var);
    return varList;
}

/* Functions */
int main(int argc, char ** argv){

    MathVariableList_t* varList = initializeVarList(); //Inicializa a lista de variáveis
    MathVariable_t* previous_result = createMathVariable("$s", 0);
    varList = appendMathVariableList(varList, previous_result);

    //Aloca string para entrada
    char* input_expression = (char*) malloc(sizeof(char)* MAX_LEN_INPUT);
    char* input_optmized_expression;

    //Init message
    boldPrint("\nMathCalculador RP - 1.1 Version\n");

    while(true)
    {
        boldPrint(">> ");
        fgets(input_expression, MAX_LEN_INPUT, stdin);
        input_optmized_expression = optimizeString(input_expression);

        if(input_optmized_expression == NULL) continue;

        //Tenta executar comando
        bool status = execCommand(input_optmized_expression, varList);
        if(status == true) continue;

        //Tenta declarar variável
        MathVariableList_t* declare_var_status = NULL;
        declare_var_status = declareMathVariable(createNewOptimizedString(input_optmized_expression), varList);
        if(declare_var_status != NULL)
        { 
            varList = declare_var_status;
            continue;
        }

        double* result = calcStringMathExpression(input_optmized_expression, varList);

        if(result == INVALID_MATH_EXPRESSION) printf("Invalid Input\n");
        else 
        {
            printf("%.2lf\n", *result);
            previous_result->value = *result;
        }
        
        free(result);
    }

}

