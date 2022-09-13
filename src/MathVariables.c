/* 
* @file: MathVariables.c
* @brief: Implementação de funções para criação, edição e remoção de variáveis
* @author: Rafael Eustáquio Pinto
* @date: 13/09/2022 
*/

/* Includes */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "StringStack.h"
#include "MathExpressions.h"
#include "MathExpressions.h"
#include "iocli.h"
#include "MathVariables.h"

//Create a math var
MathVariable_t* createMathVariable(char* name, double value){
    MathVariable_t* var = (MathVariable_t*) malloc(sizeof(MathVariable_t));
    var->name = name;
    var->value = value;

    return var;
}

//Create a empty list
MathVariableList_t* createMathVariableList(){
    return NULL;
}

//Append a element in list
MathVariableList_t* appendMathVariableList(MathVariableList_t* list, MathVariable_t* var){
    MathVariableList_t* new = (MathVariableList_t*)malloc(sizeof(MathVariableList_t));

    new->var = var;
    new->next = list;
    list = new;
    return list;
}

//Remove um elemento da lista,se encontrado
MathVariableList_t* removeMathVariableList(MathVariableList_t* list, MathVariable_t* var){
    MathVariableList_t* tmp = list;
    MathVariableList_t* ant = NULL;


    //Procura pelo elemento a ser removido
    while(tmp != NULL && strcmp(tmp->var->name, var->name) != 0)
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
bool isEmptyMathVariableList(MathVariableList_t* list){
    if(list == NULL) return true;
    else return false;
}

//Imprime a lista
void printMathVariableList(MathVariableList_t* list){
    int i;
    for(i=0; list!=NULL; i++, list = list->next)
        printf("%s -> %lf\n", list->var->name, list->var->value);
}

//Libera a lista
void freeMathVariableList(MathVariableList_t* list){
    while(list!=NULL)
    {
        MathVariableList_t* tmp = list->next;
        free(list);
        list = tmp;
    }
}

//Inverte a lista
MathVariableList_t* invertMathVariableList(MathVariableList_t* list){

    MathVariableList_t* inverted_list = createMathVariableList();
    MathVariableList_t* tmp = list;

    do{
        inverted_list = appendMathVariableList(inverted_list, tmp->var);
        tmp = tmp->next;
    }while(tmp != NULL);
    return inverted_list;
}


