/* 
* @file: MathExpressoins.c
* @brief: Implementação de funções para criação, manipulação e cálculo de expressões matemáticas
* @author: Rafael Eustáquio Pinto
* @date: 12/09/2022 
*/

/* Includes */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

#include "StringStack.h"
#include "StringList.h"
#include "MathVariables.h"
#include "iocli.h"

#include "MathExpressions.h"

#define ESPACO 3
#define DELIMITADOR 2
#define OPERADOR 1
#define OPERANDO 0


/* Functions */

/* MathExpression List Manipulation */

//Create a empty MathExpression
MathExpression_t* createMathExpression(){
    return NULL;
}

//Append a element in MathExpression
MathExpression_t* appendMathExpression(MathExpression_t* list, char* value, int type){
    MathExpression_t* new = (MathExpression_t*)malloc(sizeof(MathExpression_t));

    new->value = value;
    new->type = type;
    
    new->next = list;
    list = new;
    return list;
}

//Remove um elemento da lista MathExpression
MathExpression_t* removeMathExpression(MathExpression_t* list, char* value){
    MathExpression_t* tmp = list;
    MathExpression_t* ant = NULL;


    //Procura pelo elemento a ser removido
    while(tmp != NULL && strcmp(tmp->value, value) != 0)
    {
        ant = tmp;
        tmp = tmp->next;
    }

    if(tmp == NULL)
        return list; //Elemento não encontrado
    else if(ant == NULL)
        list = list->next; //Primeiro elemento a ser removido
    else
    {
        ant->next = tmp->next;
    }
    free(tmp);
    return list;
}

//Verifica se a MathExpression está vazia
bool isEmptyMathExpression(MathExpression_t* list){
    if(list == NULL) return true;
    else return false;
}

//Imprime a MathExpression
void printMathExpression(MathExpression_t* list){
    int i;
    for(i=0; list!=NULL; i++, list = list->next)
        printf("[%d] - Type: %3d Value: %s\n", i, list->type, list->value);
}

//Libera a MathExpression
void freeMathExpression(MathExpression_t* list){

    while(list!=NULL)
    {
        MathExpression_t* tmp = list->next;
        free(list);
        list = tmp;
    }
}

//Inverte a MathExpression
MathExpression_t* invertMathExpression(MathExpression_t* list){

    if(list == NULL) return NULL;

    MathExpression_t* inverted_list = createMathExpression();
    MathExpression_t* tmp = list;

    do{
        inverted_list = appendMathExpression(inverted_list, tmp->value, tmp->type);
        tmp = tmp->next;
    }while(tmp != NULL);
    return inverted_list;
}


/* ----------------------------------------------------------------------------------------------------------- */



//Checa a categoria de um caracter
//espaço -> return 3
//delimitador -> return 2
//operador -> return 1
//Operando -> return 0
int checkCharCategory(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') return OPERADOR;
    else if (c == '(' || c == ')') return DELIMITADOR;
    else if (c == ' ') return ESPACO;
    else return OPERANDO;
}

//Cria um string otimizada e copia o valor da bruta pela otimizada
char* createNewOptimizedString(char* heavyString){
    int lenOptimizedString = strlen(heavyString);

    char* optimizedString = (char*) malloc(lenOptimizedString * sizeof(char));
    strcpy(optimizedString, heavyString);
    return optimizedString;
}

//Converte uma string em uma expressão matemática no formato MathExpression_t
MathExpression_t* stringToMathExpression(char* mathString){

    MathExpression_t* MathExpression = createMathExpression(); //Cria a MathExpression
    

    char* tmpString = (char*) malloc(MAX_LEN_INPUT * sizeof(char)); //Cria uma string temporaria que será usada para construir as outras strings


    char c; //Caracter temporário

    int i, j;

    //Percorre todos os caracteres da string exceto o '\0' e o 'n'
    for(i = 0, j = 0; mathString[i] != '\0' && mathString[i] != '\n'; i++)
    {
        c = mathString[i];
        int charCategory = checkCharCategory(c); //Checa a categoria do caractere

        if(charCategory == OPERADOR || charCategory == DELIMITADOR || charCategory == ESPACO)
        {
            //Adiciona o operando anterior na lista
            tmpString[j] = '\0';
            if(strlen(tmpString) > 0) MathExpression = appendMathExpression(MathExpression, createNewOptimizedString(tmpString), OPERANDO);
            
            //Adiciona o operador na lista, se diferente de espaço
            if(charCategory != ESPACO)
            {
                tmpString[0] = c;
                tmpString[1] = '\0';

                if(charCategory == DELIMITADOR)
                    MathExpression = appendMathExpression(MathExpression, createNewOptimizedString(tmpString), DELIMITADOR);
                else if(charCategory == OPERADOR)
                    MathExpression = appendMathExpression(MathExpression, createNewOptimizedString(tmpString), OPERADOR);
            }

            //Reseta a lista e o contador de índice
            tmpString[0] = '\0';
            j = 0;
        }
        else if(charCategory == OPERANDO)
        {
            //Adiciona o caracterer na string temporaria e incrementa o contador
            tmpString[j] = c;
            j++;
        }
    }

    tmpString[j] = '\0';
    if(strlen(tmpString) > 0) MathExpression = appendMathExpression(MathExpression, createNewOptimizedString(tmpString), OPERANDO);

    //Inverte a lista
    MathExpression = invertMathExpression(MathExpression);
    free(tmpString);
    return MathExpression;
}




//Checa se uma string é numérica
bool isNumericString(char* string){

    char* endStr;
    (void)strtod(string, &endStr);

    if(endStr[0] == '\0') return true;
    else return false;
}

//Converte as variáveis de uma expressão matemática para seu valor
// True se conseguir converter todas as variáveis
bool convertMathExpressionVariables(MathExpression_t* math_expression, MathVariableList_t* var_list){

    while (math_expression != NULL)
    {
        if(math_expression->type == OPERANDO)
        {
            if(checkValidityVariableName(math_expression->value))
            {
                MathVariable_t* var = searchMathVariable(var_list, math_expression->value);

                if(var == NULL) return false; //Se não encontrar retorna NULL

                sprintf(math_expression->value, "%lf", var->value); //Imprime o valor da variável na string math_expression
            }
            else if(isNumericString(math_expression->value) == false) return false; //Se a expressao não for numérica retorna falso
        }
        math_expression = math_expression->next;
    }
    
    return true;
}


//Calcula uma operação dada por um operador op, entre duas strings s1 e s2
char* calcOperationBetwenTwoStrings(char* s1, char* s2, char* op)
{
    char* endStr;
    double result;
    char* string_result = (char*) malloc(MAX_LEN_INPUT * sizeof(char));
    switch (op[0])
    {
    case '+':
        result = strtod(s1, &endStr) + strtod(s2,&endStr);
        break;
    case '-':
        result = strtod(s1, &endStr) - strtod(s2,&endStr);
        break;
    case '*':
        result = strtod(s1, &endStr) * strtod(s2,&endStr);
        break;
    case '/':
        result = strtod(s1, &endStr) / strtod(s2,&endStr);
        break;
    //case '^':
        //result = pow(strtod(s1, &endStr), strtod(s2,&endStr));
        //break;
    default:
        return NULL;
        break;
    }

    sprintf(string_result, "%lf", result);
    char* optimized_string = createNewOptimizedString(string_result);
    free(string_result);
    return optimized_string;
}


//Resolve uma expressão na notação polonesa inversa
double resolvePostfixMathExpression(MathExpression_t* math_expression){

    StringStack_t* stack = createStringStack();
    char* op1, *op2;

    char* tmp;
    //Percorre a lista
    while(math_expression != NULL)
    {
        //Adiciona o operando se pilha se for operando
        if(math_expression->type == OPERANDO)
            pushStringStack(stack, math_expression->value);
        //Se for operador remove dois elementos da pilha, atua com o operador e empilha o resultado
        else
        {
            op2 = popStringStack(stack);
            op1 = popStringStack(stack);

            pushStringStack(stack, calcOperationBetwenTwoStrings(op1, op2, math_expression->value));
        }

        math_expression = math_expression->next;
    }

    return strtod(topStringStack(stack), &tmp);
}