#ifndef MATH_EXPRESSIONS_INCLUDED
#define MATH_EXPRESSIONS_INCLUDED

/* 
* @file: MathExpressions.h
* @brief: Protótipos para criação, manipulação e cálculo de expressões matemáticas
* @author: Rafael Eustáquio Pinto
* @date: 12/09/2022 
*/

// Estrutura para armazenar uma unidade das expressões matemáticas, 
// a qual pode ser um operador, operando ou delimitador
// operador -> type = 1
// delimitador -> type = 2
// operando -> type = 0
typedef struct MathExpression_s{
    char* value;
    int type; 
    struct MathExpression_s* next;
}MathExpression_t;

//Create a empty MathExpression
MathExpression_t* createMathExpression();

//Append a element in MathExpression
MathExpression_t* appendMathExpression(MathExpression_t* list, char* value, int type);

//Remove um elemento da lista MathExpression
MathExpression_t* removeMathExpression(MathExpression_t* list, char* value);

//Verifica se a MathExpression está vazia
bool isEmptyMathExpression(MathExpression_t* list);

//Imprime a MathExpression
void printMathExpression(MathExpression_t* list);

//Libera a MathExpression
void freeMathExpression(MathExpression_t* list);

//Inverte a MathExpression
MathExpression_t* invertMathExpression(MathExpression_t* list);


/* ---------------------------------------------------------------------------------------------------------- */


//Checa a categoria de um caracter
//espaço -> return 3
//delimitador -> return 2
//operador -> return 1
//Operando -> return 0
int checkCharCategory(char c);

//Cria um string otimizada e copia o valor da bruta pela otimizada
char* createNewOptimizedString(char* heavyString);

//Converte uma string em uma expressão matemática no formato MathExpression_t
MathExpression_t* stringToMathExpression(char* mathString);

#endif