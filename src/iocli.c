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
#include <stdint.h>
#include "iocli.h"

//Imprime um const char* em negrito
void boldPrint(const char* str){
    printf("%s%s%s", BOLD_EC, str, RESET_EC);
}


//Remove o \n
char* optimizeString(char* string){
    if(string[0] == '\n' || string[0] == '\0') return NULL;
    uint64_t len_string = strlen(string);
    
    //Remove o \n
    if (string[len_string - 1] == '\n')
    {
        string[len_string - 1] = '\0'; 
    }
        

    
    return string;
}
