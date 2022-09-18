#ifndef MATH_VARIABLES_INCLUDED
#define MATH_VARIABLES_INCLUDED

/* 
* @file: MathVariables.h
* @brief: Implementação de funções para criação, edição e remoção de variáveis
* @author: Rafael Eustáquio Pinto
* @date: 13/09/2022 
*/

#define MATH_VAR_NOT_FOUND NULL
#define INVALID_VAR_DECLARATION NULL

//Estrutura para armazenar uma variável, que contém um nome e um valor
typedef struct MathVariable_s{
    char* name;
    double value;
}MathVariable_t;

//Estrutura para armazenar uma lista de variáveis
typedef struct MathVariableList_s{
    MathVariable_t* var;
    struct MathVariableList_s* next;
}MathVariableList_t;


//Create a math var
MathVariable_t* createMathVariable(char* name, double value);

//Create a empty list
MathVariableList_t* createMathVariableList();

//Append a element in list
MathVariableList_t* appendMathVariableList(MathVariableList_t* list, MathVariable_t* var);

//Remove um elemento da lista,se encontrado
MathVariableList_t* removeMathVariableList(MathVariableList_t* list, MathVariable_t* var);

//Procura uma variável na lista de variáveis e a retorna, se não encontrar retorna NULL
MathVariable_t* searchMathVariable(MathVariableList_t* list, char* name);

//Verifica se a lista está vazia
bool isEmptyMathVariableList(MathVariableList_t* list);

//Imprime a lista
void printMathVariableList(MathVariableList_t* list);

//Libera a lista
void freeMathVariableList(MathVariableList_t* list);

//Inverte a lista
MathVariableList_t* invertMathVariableList(MathVariableList_t* list);

// Checa a validade de um caracter,
// LETTER_OR_UNDERLINE 1
// NUMBER 2
// INVALID_VAR_CHARACTER 0
int checkValidityCharacterVariable(char c);

//Checa se o nome de uma variável é válido
// True -> possui somente letras, numeros ou underlines, e o primeiro caractere é uma letra ou underline
bool checkValidityVariableName(char* name);

//Insere uma variável na lista se ela não existir
//Se existir edita seu valor
MathVariableList_t* writeMathVariable(MathVariableList_t* varList, MathVariable_t* var);

/* Declaração de variáveis */

MathVariableList_t* declareMathVariable(char* str_expression, MathVariableList_t* var_list);
#endif
