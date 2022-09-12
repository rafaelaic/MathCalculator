/*
* @file: MathCalculator.c
* @brief: Arquivo principal do projeto MathCalculator
* @author: Rafael Eustáquio Pinto
* @date: 06/09/2022
*/



/* Includes */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "../include/list.h"
#include "../include/stack.h"
#include "../include/iocli.h"



/* Defines */
#define MAX_EXP_INPUT 100


/* Functions */
int main(int argc, char ** argv){

    list_t* list = createList();

    list = appendList(list, "maria");
    list = appendList(list, "jao");
    list = appendList(list, "jose");
    list = appendList(list, "arnaldo");
    printList(list);

    printf("\n\n");

    list = removeList(list, "Joao");
    list = removeList(list, "jose");

    freeList(list);
    
    printList(list);



    return EXIT_SUCCESS;
}

