/* 
* @file: MathExpressoins.c
* @brief: Implementação de funções para criação, manipulação e cálculo de expressões matemáticas
* @author: Rafael Eustáquio Pinto
* @date: 12/09/2022 
*/

/* Includes */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "StringStack.h"
#include "StringList.h"
#include "MathExpressions.h"
#include "iocli.h"

#define ESPACO 3
#define DELIMITADOR 2
#define OPERADOR 1
#define OPERANDO 0


/* Functions */

//Checa a categoria de um caracter
//espaço -> return 3
//delimitador -> return 2
//operador -> return 1
//Operando -> return 0
int checkCharCategory(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') return OPERADOR;
    else if (c == '(' || c == ')') return DELIMITADOR;
    else if (c == ' ') return ESPACO;
    else return OPERANDO;
}

//Cria um string otimizada e copia o valor da bruta pela otimizada
char* createOptimizedString(char* heavyString){
    int lenOptimizedString = strlen(heavyString);

    char* optimizedString = (char*) malloc(lenOptimizedString * sizeof(char));
    strcpy(optimizedString, heavyString);
    return optimizedString;
}


//Converte uma string em uma expressão matemática em formato de lista de strings
StringList_t* mathStrToMathStrList(char* mathString){

    StringList_t* mathStrList = createStringList(); //Cria a lista de strings
    

    char* tmpString = (char*) malloc(MAX_LEN_INPUT * sizeof(char)); //Cria uma string temporaria que será usada para construir as outras strings


    char c; //Caracter temporário

    int i, j;

    //Percorre todos os caracteres da string exceto o '\0' e o 'n'
    for(i = 0, j = 0; mathString[i] != '\0' && mathString[i] != '\n'; i++)
    {
        c = mathString[i];
        int charCategory = checkCharCategory(c); //Checa a categoria do caractere

        if(charCategory == OPERADOR || charCategory == DELIMITADOR || charCategory == ESPACO)
        {
            //Adiciona a expressão anterior na lista
            tmpString[j] = '\0';
            if(strlen(tmpString) > 0) mathStrList = appendStringList(mathStrList, createOptimizedString(tmpString));
            
            //Adiciona o operador na lista, se diferente de espaço
            if(charCategory != ESPACO)
            {
                tmpString[0] = c;
                tmpString[1] = '\0';

                mathStrList = appendStringList(mathStrList, createOptimizedString(tmpString));
            }

            //Reseta a lista e o contador de índice
            tmpString[0] = '\0';
            j = 0;
        }
        else if(charCategory == OPERANDO)
        {
            //Adiciona o caracterer na string temporaria e incrementa o contador
            tmpString[j] = c;
            j++;
        }
    }
    //Adiciona a string restante na lista
    if(strlen(tmpString) > 0) mathStrList = appendStringList(mathStrList, createOptimizedString(tmpString));

    //Inverte a lista
    mathStrList = invertStringList(mathStrList);
    free(tmpString);
    return mathStrList;
}
