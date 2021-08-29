#ifndef SCANNER_H_INCLUDED
#define SCANNER_H_INCLUDED
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum{
    CADENA = 0,
    SEPARADOR = 1,
    FDT = 2
} TOKEN;

typedef struct {
    TOKEN tok;
    char lexema[20];
} t_token;

t_token* get_token (FILE *archivo);
int transicion (char leido, FILE *archivo);
bool hayToken (int estado);



#endif // SCANNER_H_INCLUDED
