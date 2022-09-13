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
#include "StringList.h"

//Create a empty list
StringList_t* createStringList(){
    return NULL;
}

//Append a element in list
StringList_t* appendStringList(StringList_t* list, char* info){
    StringList_t* new = (StringList_t*)malloc(sizeof(StringList_t));

    new->info = info;
    new->next = list;
    list = new;
    return list;
}

//Remove um elemento da lista,se encontrado
StringList_t* removeStringList(StringList_t* list, char* info){
    StringList_t* tmp = list;
    StringList_t* ant = NULL;


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
bool isEmptyStringList(StringList_t* list){
    if(list == NULL) return true;
    else return false;
}

//Imprime a lista
void printStringList(StringList_t* list){
    int i;
    for(i=0; list!=NULL; i++, list = list->next)
        printf("[%d] %s\n", i, list->info);
}

//Libera a lista
void freeStringList(StringList_t* list){

    while(list!=NULL)
    {
        StringList_t* tmp = list->next;
        free(list);
        list = tmp;
    }
}

//Inverte a lista
StringList_t* invertStringList(StringList_t* list){

    StringList_t* inverted_list = createStringList();
    StringList_t* tmp = list;

    do{
        inverted_list = appendStringList(inverted_list, tmp->info);
        tmp = tmp->next;
    }while(tmp != NULL);
    return inverted_list;
}