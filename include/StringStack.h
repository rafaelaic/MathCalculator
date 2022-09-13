#ifndef STRING_STACK_INCLUDED
#define STRING_STACK_INCLUDED

/* 
* @file: StringStack.h
* @brief: Protótipos para TAD Pilha
* @author: Rafael Eustáquio Pinto
* @date: 06/09/2022 
*/

#include "StringList.h"

//Estrutura para TAD Pilha
typedef struct StringStack_s{
    StringList_t* top;
}StringStack_t;

//Cria uma pilha vazia
StringStack_t* createStringStack();

//Empilha um elemento 
void pushStringStack(StringStack_t* stack, char* info);

//Remove um elemento
char* popStringStack(StringStack_t* stack);

//Verifica se a pilha está vazia
bool isEmptyStringStack(StringStack_t* stack);

//Libera a pilha
void freeStringStack(StringStack_t* stack);

//Imprime a pilha
void printStringStack(StringStack_t* stack);

//Retorna o topo da pilha
char* topStringStack(StringStack_t* stack);

StringList_t* testeMaroto();

#endif