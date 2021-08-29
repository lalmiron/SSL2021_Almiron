#include <stdio.h>
#include <stdlib.h>
#include "scanner.h"
#include <stdbool.h>

int main(void){
    TOKEN tok_leido;
    t_token* tok;
    FILE * archivo;
    archivo = fopen("entrada.txt", "r");

    if(archivo == NULL){
        printf("No se pudo leer el archivo.\n");
        return 1;
    }else{
        do{
            tok = get_token(archivo);
            switch(tok->tok){
                case SEPARADOR:
                    printf("Separador: %s\n", tok->lexema);
                    break;

                case CADENA:
                    printf("Cadena: %s\n", tok->lexema);
                    break;

                case FDT:
                    printf("Fin de Texto\n");
                    break;
            }
            tok_leido = tok->tok;
            free(tok);
        }while(tok_leido == CADENA || tok_leido == SEPARADOR);

        fclose(archivo);
    }

    return 0;
}
