/* 
* @file: commands.c
* @brief: Protótipos de funções para os comandos aceitos pelo CLI
* @author: Rafael Eustáquio Pinto
* @date: 18/09/2022 
*/

#include "MathVariables.h"

//Lista as variavéis
void listVarCommand(MathVariableList_t* var_list);


//Executa um comando se exixtente
//Retorna true se executado, false se não encontrado
bool execCommand(char* command, MathVariableList_t* var_list);


