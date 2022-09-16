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

//Analisa operadores adjacentes com '-'
MathExpression_t* analyseAdjacentOperators(MathExpression_t* old_expression)
{
    MathExpression_t* new_expression;
    while(old_expression != NULL)
    {
        if(old_expression->type == OPERADOR && old_expression->next->value[0] == '-' && old_expression->next->next->type == OPERANDO)
        {
            new_expression = appendMathExpression(new_expression, old_expression->value, old_expression->type); //ADD OPERADOR
            new_expression = appendMathExpression(new_expression, "(", DELIMITADOR); //ADD PARENTESES
            new_expression = appendMathExpression(new_expression, "0", OPERANDO); //ADD 0
            new_expression = appendMathExpression(new_expression, "-", OPERADOR); //ADD -
            new_expression = appendMathExpression(new_expression, old_expression->next->next->value, OPERANDO); //ADD OPERANDO
            new_expression = appendMathExpression(new_expression, ")", DELIMITADOR); //ADD PARENTESES

            old_expression = old_expression->next->next->next;
        }
        else
        {
            new_expression = appendMathExpression(new_expression, old_expression->value, old_expression->type);
            old_expression = old_expression->next;   
        }
            
    }
    return invertMathExpression(new_expression);
}

//Converte uma string em uma expressão matemática no formato MathExpression_t
MathExpression_t* stringToMathExpression(char* mathString){

    MathExpression_t* MathExpression = createMathExpression(); //Cria a MathExpression
    

    char* tmpString = (char*) malloc(MAX_LEN_INPUT * sizeof(char)); //Cria uma string temporaria que será usada para construir as outras strings


    char c, d; //Caracteres temporários

    int i, j;
    int t, k;

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


            //Verifica se o operador é um '-' e se o pŕoximo caracter é de um operando
            //Então analisa o que fazer de acordo com o próximo caractere
            if(c == '-')
            {
                //Encontra o próximo caracter sem ser espaço
                k = i;
                do{
                    t = checkCharCategory(mathString[k + 1]);
                    d = mathString[k + 1];
                    k++;
                }while(t == ESPACO && d!= '\0');
                
                if(d == '\0') return INVALID_MATH_EXPRESSION;

                else if(t == OPERANDO) //Próximo caracter operando
                {
                    //Encontra o caracter anterior sem ser espaço                 
                    k = i;

                    if(k == 0)
                    {
                        MathExpression = appendMathExpression(MathExpression, createNewOptimizedString("0"), OPERANDO);
                    }

                    else if(k > 0)
                    {
                        do{
                            t = checkCharCategory(mathString[k - 1]);
                            d = mathString[k - 1];
                            k--;
                        }while(t == ESPACO && k != 0);


                        if (t == ESPACO)
                        {
                            MathExpression = appendMathExpression(MathExpression, createNewOptimizedString("0"), OPERANDO);
                        }

                        //Se o elemento antes do '-' for um operando ou um ')', ele adiciona a operação '+'
                        else if(t == OPERANDO || d == ')')
                        {
                            MathExpression = appendMathExpression(MathExpression, createNewOptimizedString("+"), OPERADOR);
                            MathExpression = appendMathExpression(MathExpression, createNewOptimizedString("0"), OPERANDO);
                        }
                        else if(d == '(')
                        {
                            MathExpression = appendMathExpression(MathExpression, createNewOptimizedString("0"), OPERANDO);
                        }
                    }
                    

                
                }
                else if(t == OPERADOR || d == ')')
                {
                    return INVALID_MATH_EXPRESSION;
                }
            }

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

    
    free(tmpString);
    if(MathExpression->type == OPERADOR) return INVALID_MATH_EXPRESSION;
    //Inverte a lista
    MathExpression = invertMathExpression(MathExpression);

    //Analisa os operadores
    MathExpression = analyseAdjacentOperators(MathExpression);

    

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
    case '^':
        result = pow(strtod(s1, &endStr), strtod(s2,&endStr));
        break;
    default:
        return NULL;
        break;
    }

    sprintf(string_result, "%lf", result);
    char* optimized_string = createNewOptimizedString(string_result);
    free(string_result);
    return optimized_string;
}


//Calcula a prioridade entre dois operadores op_exp e op_stack
//Retorna true se a prioridade de op_exp for maior que a prioridade de op_stack
bool calcPriorityBetweenTwoOperators(char* op_exp, char* op_stack){
    int p_stack, p_exp;
    p_stack = p_exp = 0;

    //Define a prioridade do operador da expressão
    if(op_exp[0] == '^')
        p_exp = 4;
    else if (op_exp[0] == '*' || op_exp[0] == '/')
        p_exp = 2;
    else if (op_exp[0] == '+' || op_exp[0] == '-')
        p_exp = 1;
    else if (op_exp[0] == '(')
        p_exp = 4;

    //Define a prioridade do Operador da pilha
    if(op_stack[0] == '^')
        p_stack = 3;
    else if (op_stack[0] == '*' || op_stack[0] == '/')
        p_stack = 2;
    else if (op_stack[0] == '+' || op_stack[0] == '-')
        p_stack = 1;
    else if (op_stack[0] == '(')
        p_stack = 0;


    if(p_exp > p_stack) return true;
    else return false;
}


//Convert Infix to postfix MathExpression
MathExpression_t* convertInfixToPostFixMathExpression(MathExpression_t* infix_expression){

    char* op, *t, c, d; //Caracteres e strings temporarias

    //Pilha para os operadores
    StringStack_t* op_stack = createStringStack();

    //Insere um parenteses pra não dar erro
    pushStringStack(op_stack, "(");

    //Postfix expression
    MathExpression_t* postfix_expression = createMathExpression();

    //Percore enquanto não terminar a expressão
    while(infix_expression != NULL)
    {

        if(infix_expression->type == OPERANDO)
        {
        postfix_expression = appendMathExpression(postfix_expression, infix_expression->value, OPERANDO);
        }
        else
        {
            op = infix_expression->value;
            c = op[0];
            if(c == '(')
            {
                pushStringStack(op_stack, op);
            }
            else if(c == ')' || c == '\0')
            {
                do{
                    t = popStringStack(op_stack);
                    d = t[0];

                    if(d != '(')
                    {
                    postfix_expression = appendMathExpression(postfix_expression, t, OPERADOR);
                    }
                }while(d != '(');
            }
            else
            {
                while(true)
                {
                    t = popStringStack(op_stack);
                    if(calcPriorityBetweenTwoOperators(op, t))
                    {
                        pushStringStack(op_stack, t);
                        pushStringStack(op_stack, op);
                        break;
                    }
                    else
                    {
                        postfix_expression = appendMathExpression(postfix_expression, t, OPERADOR);
                    }
                }
            }
        }
        infix_expression = infix_expression->next;
    }

    //Insere os operadores restantes na expressão
    do{
        t = popStringStack(op_stack);
        d = t[0];
        if(d != '(')
        {
            postfix_expression = appendMathExpression(postfix_expression, t, OPERADOR);
        }
    }while(d != '(');

    if(isEmptyStringStack(op_stack) == false) return NULL;
    //Inverte e retorna a expressão
    else
    {
        postfix_expression =  invertMathExpression(postfix_expression);
        return postfix_expression;
    }
    
} 


//Resolve uma expressão na notação polonesa inversa
double* resolvePostfixMathExpression(MathExpression_t* math_expression){

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

            if(op1 == NULL || op2 == NULL) return INVALID_MATH_EXPRESSION; //Retorna NULL se verificar invalidez na expressão

            pushStringStack(stack, calcOperationBetwenTwoStrings(op1, op2, math_expression->value));
        }

        math_expression = math_expression->next;
    }

    double* result = (double*) malloc(sizeof(double));
    *result = strtod(popStringStack(stack), &tmp);

    if(isEmptyStringStack(stack)) return result;
    else return INVALID_MATH_EXPRESSION;

}


//Calcula uma expressão matemática baseada em uma string e uma lista de variáveis
double* calcStringMathExpression(char* str_expression, MathVariableList_t* var_list){

    //Transforma a string na expressão matemática
    MathExpression_t* math_expression = stringToMathExpression(str_expression);
    if(math_expression == NULL) return INVALID_MATH_EXPRESSION;

    //Converte as variáveis
    bool status = convertMathExpressionVariables(math_expression, var_list);
    if(status == false) return INVALID_MATH_EXPRESSION;

    //Converte para expressão pós fixa
    math_expression = convertInfixToPostFixMathExpression(math_expression);
    if(math_expression == NULL) return INVALID_MATH_EXPRESSION;

    //Calcula a expressão pós fixa
    double* result = (double*) malloc(sizeof(double));
    result = resolvePostfixMathExpression(math_expression);
    
    freeMathExpression(math_expression); //Libera a expressão matemática

    return result;
}