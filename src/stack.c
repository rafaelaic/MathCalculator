/* 
* @file: stack.c
* @brief: Implementação da TAD Pilha
* @author: Rafael Eustáquio Pinto
* @date: 06/09/2022 
*/

/* Includes */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

//Cria uma pilha vazia
stack_t* createStack(){
    stack_t* stack = (stack_t*) malloc(sizeof(stack_t)); //Aloca a pilha

    stack->top = NULL; //Inicializa o topo da pilha com NULL

    return stack;
}

//Empilha um elemento 
void pushStack(stack_t* stack, char* info){
    list_t* list = (list_t*) malloc(sizeof(list_t)); //Aloca um nó da lista
    list->info = info; //Salva a informação

    //Empilha
    list->prox = stack->top;
    stack->top = list;
}

//Remove um elemento
char* popStack(stack_t* stack){
    list_t* list;
    char* info;

    if(isEmptyStack(stack)){
        return NULL;
    }

    //Salva o topo da lista
    list=stack->top; 
    info = list->info;

    //Pop
    stack->top = list->prox;
    free(list);

    return info;
}

//Verifica se a pilha está vazia
bool isEmptyStack(stack_t* stack){
    return (stack->top==NULL);
}

//Libera a pilha
void freeStack(stack_t* stack){
    list_t* list = stack->top;
    list_t* temp;

    while(list != NULL)
    {
        temp = list->prox;
        free(list);
        list=temp;
    }
    free(stack);
}

//Imprime a pilha
void printStack(stack_t* stack){
    list_t* top;
    int i;

    for(top = stack->top, i = 0; top != NULL; top = top->prox, i++)
        printf("[%d] %s\n", i, top->info);
}

//Retorna o topo da pilha
char* topStack(stack_t* stack){
    //if(isEmptyStack(stack)) return NULL;
    //else return stack->top->info;

    return stack->top->info;
}





