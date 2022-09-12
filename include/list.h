#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

/* 
* @file: list.h
* @brief: Protótipos para TAD Lista
* @author: Rafael Eustáquio Pinto
* @date: 11/09/2022 
*/

// Estrutura para TAD Lista
typedef struct list_s{ 
    char* info;
    struct list_s *next;
} list_t;

//Create a empty list
list_t* createList();

//Append a element in list
list_t* appendList(list_t* list, char* info);

//Remove um elemento da lista
list_t* removeList(list_t* list, char* info);

//Verifica se a lista está vazia
bool isEmptyList(list_t* list);

//Imprime a lista
void printList(list_t* list);

//Libera a lista
void freeList(list_t* list);

#endif