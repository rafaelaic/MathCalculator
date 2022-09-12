#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

/* 
* @file: stack.h
* @brief: Protótipos para TAD Pilha
* @author: Rafael Eustáquio Pinto
* @date: 06/09/2022 
*/

//Estrutura para TAD Pilha
typedef struct stack_s{
    list_t* top;
}stack_t;

//Cria uma pilha vazia
stack_t* createStack();

//Empilha um elemento 
void pushStack(stack_t* stack, char* info);

//Remove um elemento
char* popStack(stack_t* stack);

//Verifica se a pilha está vazia
bool isEmptyStack(stack_t* stack);

//Libera a pilha
void freeStack(stack_t* stack);

//Imprime a pilha
void printStack(stack_t* stack);

//Retorna o topo da pilha
char* topStack(stack_t* stack);

#endif