# MathCalculator
A math calculator made in C

# How it Works
1º: Lê string -> char*

//Modo comando

//Modo declaração de variável

//Modo expressão matemática
2º: Transforma em lista de operadores e operandos -> list_t* (char* list)
3°: Transforma as variáveis em seus respectivos valores e transforma em lista mathList_t -> mathList_t *
4º: Verifica se a ordem dos parenteses é valida, e se a expressao é valida
5º: Transforma em notação polonesa inversa, ainda em mathList_t
6°: Calcula o resultado e retorna um mathResult_t

a-z
A-Z
0-9
_

