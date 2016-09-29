#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define pf printf



int obtenerEspacioLibre(EPersona lista[]){
    int retorno = -1;
    int i;
    //int dni =0;

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

//devuelve indice
int buscarPorDni(EPersona lista[], int dni){

int retorno = -1;
int i;

if(lista != NULL ){
    for(i=0;i<5;i++){
            if(lista[i].dni == dni && lista[i].estado == 1){
            retorno = i;
            break;
            }
    }
}

if(retorno==-1){
printf("\nNo se encontro la persona.\n");
}

return retorno;

}


EPersona nuevaPersona(int indice){
    EPersona persona;


    pf("\nIngrese DNI:\n");
    scanf("%d",&persona.dni);
    if(persona.dni < 1){
        pf("\nIngrese un DNI valido:\n");
        scanf("%d",&persona.dni);
    }

    pf("\nIngrese nombre de la persona:\n");
    fflush(stdin);
    gets(persona.nombre);

    pf("\nIngrese edad:\n");
    scanf("%d",&persona.edad);
    if(persona.edad < 1){
            pf("\nIngrese una edad valida:\n");
            scanf("%d",&persona.edad);
        }

    persona.estado=1;


    return persona;

}

//0 para vacio 1 para usado
void initPersona(EPersona persona[],int TAM){
int i;
if(persona != NULL && TAM>0 ){
    for(i=0;i<TAM;i++){
            persona[i].estado=0;
    }

}

}

void borrarPersona(EPersona lista[]){
    int dni=0;
    int indice=0;
    pf ("\nIngrese numero de DNI a borrar: \n ");
    scanf("%d",&dni);
    indice = buscarPorDni(lista,dni);
    if(indice!=-1  ){
            lista[indice].estado=0;
            printf("\nSe dio de baja la persona.\n");

    }



}

void ordenarPorNombre(EPersona lista[],int TAM){
int i,j;
EPersona aux;

    for(i=0;i<TAM-1;i++){
        for(j=i+1;j<TAM;j++){
            if((strcmp(lista[i].nombre,lista[j].nombre))>0 && lista[i].estado == 1){
            aux=lista[i];
            lista[i]=lista[j];
            lista[j]=aux;
            }
        }

    }


    for(i=0; i< TAM; i++){
        if(lista[i].estado ==1 )
            printf("\n%8d - %-16s - %6d",lista[i].dni, lista[i].nombre, lista[i].edad );
    }



}




void mostrarGrafico(EPersona lista[],int TAM){
int i;
int contMen18=0;
int cont19_35=0;
int contMayor35=0;
int maximo;

    for(i=0;i<TAM;i++){
            if(lista[i].edad < 18 && lista[i].estado == 1){
                contMen18++;
            }

            if(lista[i].edad>18 && lista[i].edad < 36 && lista[i].estado == 1){
                cont19_35++;
            }

            if(lista[i].edad>35 && lista[i].estado == 1){
                contMayor35++;
            }
    }


    if(contMen18 > (cont19_35 && contMayor35)){
        maximo = contMen18;
    }

    else if(cont19_35 > contMayor35){
        maximo = cont19_35;
    }
    else{
        maximo = contMayor35;
    }


    for(i=maximo;i>0;i--){
        if(i <= contMen18){
            printf("  *");
        }

        if(i <= cont19_35){
            printf("\t  *");
        }

        else{
            printf("\t");
        }

        if(i <= contMayor35){
            printf("\t  *");
        }

        printf("\n");
    }



}
