/* 
* @file: list.c
* @brief: Implementação da TAD Lista
* @author: Rafael Eustáquio Pinto
* @date: 11/09/2022 
*/

/* Includes */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "list.h"

//Create a empty list
list_t* createList(){
    return NULL;
}

//Append a element in list
list_t* appendList(list_t* list, char* info){
    list_t* new = (list_t*)malloc(sizeof(list_t));

    new->info = info;
    new->next = list;
    list = new;
    return list;
}

//Remove um elemento da lista,se encontrado
list_t* removeList(list_t* list, char* info){
    list_t* tmp = list;
    list_t* ant = NULL;


    //Procura pelo elemento a ser removido
    while(tmp != NULL && strcmp(tmp->info, info) != 0)
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

//Verifica se a lista está vazia
bool isEmptyList(list_t* list){
    if(list == NULL) return true;
    else return false;
}

//Imprime a lista
void printList(list_t* list){
    int i;
    for(i=0; list!=NULL; i++, list = list->next)
        printf("[%d] %s\n", i, list->info);
}

//Libera a lista
void freeList(list_t* list){

    while(list!=NULL)
    {
        list_t* tmp = list->next;
        free(list);
        list = tmp;
    }
}