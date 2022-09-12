#ifndef STRING_LIST_INCLUDED
#define STRING_LIST_INCLUDED

/* 
* @file: StringList.h
* @brief: Protótipos para TAD Lista
* @author: Rafael Eustáquio Pinto
* @date: 11/09/2022 
*/

// Estrutura para TAD Lista
typedef struct StringList_s{ 
    char* info;
    struct StringList_s *next;
} StringList_t;

//Create a empty list
StringList_t* createStringList();

//Append a element in list
StringList_t* appendStringList(StringList_t* list, char* info);

//Remove um elemento da lista
StringList_t* removeStringList(StringList_t* list, char* info);

//Verifica se a lista está vazia
bool isEmptyStringList(StringList_t* list);

//Imprime a lista
void printStringList(StringList_t* list);

//Libera a lista
void freeStringList(StringList_t* list);

#endif