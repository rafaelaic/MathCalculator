#ifndef MATH_EXPRESSIONS_INCLUDED
#define MATH_EXPRESSIONS_INCLUDED

/* 
* @file: MathExpressions.h
* @brief: Protótipos para criação, manipulação e cálculo de expressões matemáticas
* @author: Rafael Eustáquio Pinto
* @date: 12/09/2022 
*/

//Checa a categoria de um caracter
//espaço -> return 3
//delimitador -> return 2
//operador -> return 1
//Operando -> return 0
int checkCharCategory(char c);

//Cria um string otimizada e copia o valor da bruta pela otimizada
char* createOptimizedString(char* heavyString);

//Converte uma string em uma expressão matemática em formato de lista de strings
StringList_t* mathStrToMathStrList(char* mathString);



#endif