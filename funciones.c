#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define pf printf



int obtenerEspacioLibre(EPersona lista[]){
    int retorno = -1;
    int i;

    for(i=0;i<5;i++)
    {
        if(lista[i].estado != 1)
        {

            retorno = i;
            break;
        }
    }


    return retorno;
}

//devuelve el indice del dni encontrado o error
int buscarPorDni(EPersona lista[], int dni){
int retorno = -1;
int i;

if(lista != NULL){
    for(i=0;i<5;i++){
            if(lista[i].dni == dni)
            retorno = dni;
            break;
    }


}
else {
        pf("no se encontro dni");

}

return retorno;

}


EPersona nuevaPersona(int indice){
    EPersona persona;

    pf("\n Ingrese nombre de la persona:\n");
    fflush(stdin);
    gets(persona.nombre);

    pf("\n Ingrese DNI:\n");
    scanf("%d",&persona.dni);

    pf("\n Ingrese edad:\n");
    scanf("%d",&persona.edad);

    persona.estado=1;


    return persona;

}


void initPersona(EPersona *persona,int TAM){
int i;
if(persona != NULL && TAM>0 ){
    for(i=0;i<TAM;i++){
            persona[i].estado=0;
    }

}

}





