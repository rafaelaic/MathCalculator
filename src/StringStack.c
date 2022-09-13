/* 
* @file: StringStack.c
* @brief: Implementação da TAD Pilha
* @author: Rafael Eustáquio Pinto
* @date: 06/09/2022 
*/

/* Includes */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "StringList.h"
#include "StringStack.h"

//Cria uma pilha vazia
StringStack_t* createStringStack(){
    StringStack_t* stack = (StringStack_t*) malloc(sizeof(StringStack_t)); //Aloca a pilha

    stack->top = NULL; //Inicializa o topo da pilha com NULL

    return stack;
}

//Empilha um elemento 
void pushStringStack(StringStack_t* stack, char* info){
    StringList_t* list = (StringList_t*) malloc(sizeof(StringList_t)); //Aloca um nó da lista
    list->info = info; //Salva a informação

    //Empilha
    list->next = stack->top;
    stack->top = list;
}

//Remove um elemento
char* popStringStack(StringStack_t* stack){
    StringList_t* list;
    char* info;

    if(isEmptyStringStack(stack)){
        return NULL;
    }

    //Salva o topo da lista
    list=stack->top; 
    info = list->info;

    //Pop
    stack->top = list->next;
    free(list);

    return info;
}

//Verifica se a pilha está vazia
bool isEmptyStringStack(StringStack_t* stack){
    return (stack->top==NULL);
}

//Libera a pilha
void freeStringStack(StringStack_t* stack){
    StringList_t* list = stack->top;
    StringList_t* temp;

    while(list != NULL)
    {
        temp = list->next;
        free(list);
        list=temp;
    }
    free(stack);
}

//Imprime a pilha
void printStringStack(StringStack_t* stack){
    StringList_t* top;
    int i;

    for(top = stack->top, i = 0; top != NULL; top = top->next, i++)
        printf("[%d] %s\n", i, top->info);
}

//Retorna o topo da pilha
char* topStringStack(StringStack_t* stack){
    //if(isEmptyStack(stack)) return NULL;
    //else return stack->top->info;

    return stack->top->info;
}

StringList_t* testeMaroto(){
    StringList_t* list = createStringList();

    list = appendStringList(list, "Carlos");
    list = appendStringList(list, "Alberto");
    list = appendStringList(list, "de Souza");

    printStringList(list);

    return list;
}




