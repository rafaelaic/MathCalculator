/*
* @file: iocli.c
* @brief: Implementação de funções para manipulação de entrada/saída
* @author: Rafael Eustáquio Pinto
* @date: 06/09/2022
*/

/* Includes */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "iocli.h"

//Imprime um const char* em negrito
void boldPrint(const char* str){
    printf("%s%s%s", BOLD_EC, str, RESET_EC);
}


//Otimiza um vetor de caracteres, realocando para o tamanho exato do vetor
char* optimizeString(char* string){
    string = (char*) realloc(string, strlen(string) * sizeof(char));
    return string;
}
