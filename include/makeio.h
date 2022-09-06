#ifndef MAKE_IO_INCLUDED
#define MAKE_IO_INCLUDED
/* 
* @file: makeio.h
* @brief: Protótipos para funções de manipução de entrada/saída
* @author: Rafael Eustáquio Pinto
* @date: 06/09/2022 
*/

/* Defines */
#define BOLD_EC "\033[1m"
#define RESET_EC "\033[m"

//Imprime um const char* em negrito
void boldPrint(const char* str);


#endif