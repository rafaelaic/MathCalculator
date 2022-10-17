/* 
* @file: commands.c
* @brief: Implementação de funções para os comandos aceitos pelo CLI
* @author: Rafael Eustáquio Pinto
* @date: 18/09/2022 
*/

/* Includes */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>

#include "MathVariables.h"
#include "iocli.h"

/* macro definition for console clearing */
#ifdef _WIN32
    #define CLEAR_SCREEN system("cls")
#else
    #define CLEAR_SCREEN puts("\x1b[H\x1b[2J")
#endif

void listCommands(){
    printf("\n-------------------------------\n");
    printf("|        Commands List        |");    
    printf("\n-------------------------------\n");
    printf(""\
    "listcommands -> List the registered commands\n"\
    "listvar -> List the registered variables\n"\
    "clear -> Clear the CLI\n"\
    "exit -> Exit the program\n");
    printf("\n");
}


//Lista as variavéis
void listVarCommand(MathVariableList_t* var_list){
    printf("\n-------------------------------\n");
    printf("|        Variables List       |");   
    printf("\n-------------------------------\n");
    while(var_list != NULL)
    {
        printf("%s -> %.2lf\n", var_list->var->name, var_list->var->value);
        var_list = var_list->next;
    }
    printf("\n");
}



//Executa um comando se exixtente
//Retorna true se executado, false se não encontrado
bool execCommand(char* command, MathVariableList_t* varList){
if(strcmp(command, "exit") == 0) //Sai do programa
{
    boldPrint("\nThank you for test my calculator!\n");
    exit(EXIT_SUCCESS);
}
else if(strcmp(command, "listcommands") == 0)
{
    listCommands();
}
else if(strcmp(command, "listvar") == 0)
{
    listVarCommand(varList);
}
else if(strcmp(command, "clear") == 0)
{
    CLEAR_SCREEN;
}
else return false;
return true;
}
