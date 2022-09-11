#ifndef MATH_EXPRESSION_INCLUDED
#define MATH_EXPRESSION_INCLUDED

/*
* @file: mathExpressions.c
* @brief: Protótipos para TAD MathExpression
* @author: Rafael Eustáquio Pinto
* @date: 06/09/2022
*/

//Estrutura usada para as expressões matemáticas
typedef struct MathExpression_s{
    char * expression; //String contendo a expressão
    double value; //Double contendo o resultado da expressão
}MathExpression_t;





#endif