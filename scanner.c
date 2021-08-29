#include "scanner.h"

static int tablaTrancision[5][4] = {
/*TT       C  S  E  FDT  */
/*0 */    {1, 3, 0, 4},
/*1 */    {1, 2 ,2, 2},
/*2+*/    {99,99,99,99}, //CADENA
/*3+*/    {99,99,99,99}, //SEP
/*4+*/    {99,99,99,99}  //FDT
};

t_token* get_token (FILE *archivo)
{
    int estado = 0;
    int columna = 0;
    int i = 0;

    char leido = '\0';
    t_token * token_leido = malloc(sizeof(t_token));

    do{
        leido = fgetc(archivo);
        if(!isspace(leido)) {
            (token_leido->lexema)[i] = leido;
            i++;
        }
        columna = transicion(leido, archivo);
        estado = tablaTrancision[estado][columna];
    }while(!hayToken(estado));


    if(estado == 2){
        ungetc(leido, archivo);
        if((token_leido->lexema)[i-1] == ',')
            (token_leido->lexema)[i-1]= '\0';
        token_leido->tok = CADENA;
    }

    if(estado == 3){
        token_leido->tok = SEPARADOR;
    }

    if(estado == 4){
        token_leido->tok = FDT;
    }
    return token_leido;
}

bool hayToken(int estado){
    return estado >= 2;
}

int transicion(char leido, FILE *archivo){
    if(isspace(leido)) return 2;

    if(leido == ',') return 1;

    if(feof(archivo)) return 3;

    else return 0;
}
