#ifndef MATH_VARIABLES_INCLUDED
#define MATH_VARIABLES_INCLUDED

/* 
* @file: MathVariables.h
* @brief: Implementação de funções para criação, edição e remoção de variáveis
* @author: Rafael Eustáquio Pinto
* @date: 13/09/2022 
*/

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

//Verifica se a lista está vazia
bool isEmptyMathVariableList(MathVariableList_t* list);

//Imprime a lista
void printMathVariableList(MathVariableList_t* list);

//Libera a lista
void freeMathVariableList(MathVariableList_t* list);

//Inverte a lista
MathVariableList_t* invertMathVariableList(MathVariableList_t* list);



#endif
