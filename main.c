#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define TAM 5
#define pf printf

int main()
{
    char seguir='s';
    int opcion=0;
    EPersona persona [TAM];
    int indice=0;
    int dni;

    initPersona(persona,TAM);


    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                indice = obtenerEspacioLibre(persona);

                persona[indice] = nuevaPersona (indice);

                int i;
                for(i=0;i<TAM;i++){
                        if(persona[i].estado==1){
                        pf("\nNOMBRE CARGADO %s",persona[i].nombre);
                        pf("\nDNI CARGADO %d",persona[i].dni);
                        pf("\nEDAD %d",persona[i].edad);
                        pf("\n\n");
                        }

                }

                pf ("\n ingrese nro dni a buscar \n ");
                scanf("%d",&dni);
                indice = buscarPorDni(persona, dni);
                pf("\n indice -%d",indice);
                pf("\n\n");


                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}

//<>
