/*
* @file: makeio.c
* @brief: Implementação de funções para manipulação de entrada/saída
* @author: Rafael Eustáquio Pinto
* @date: 06/09/2022
*/

/* Includes */
#include <stdio.h>
#include <string.h>
#include "makeio.h"

//Imprime um const char* em negrito
void boldPrint(const char* str){
    printf("%s%s%s", BOLD_EC, str, RESET_EC);
}



