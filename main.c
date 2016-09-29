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
    //int dni;
    //int flag1erPersona =0;

    initPersona(persona,TAM);


    while(seguir=='s')
    {
        printf("\n1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:


                indice = obtenerEspacioLibre(persona);
 /*               if(flag1erPersona == 1){
                        pf("\n Ingrese DNI:\n");
                        scanf("%d",&dni);
                        if((buscarPorDni(persona,dni))!=-1){
                            pf("\nEl DNI de la persona ya se encuentra cargado en el programa.\n");
                            break;
                        }
                        else{
                            persona[indice].dni = dni;
                        }
                }

*/
                persona[indice] = nuevaPersona (indice);

                //flag1erPersona = 1;


                //SOLO PARA PROBAR

                int i;
                for(i=0;i<TAM;i++){
                        if(persona[i].estado==1){
                        pf("\nDNI CARGADO %d",persona[i].dni);
                        pf("\nNOMBRE CARGADO %s",persona[i].nombre);
                        pf("\nEDAD %d",persona[i].edad);
                        pf("\n\n");
                        }

                }
                 //SOLO PARA PROBAR FIN /

                break;

            case 2:
                borrarPersona(persona);
                break;

            case 3:
                printf("\n  DNI    -      Nombre      -     Edad    ");
                ordenarPorNombre(persona,TAM);
                break;

            case 4:
                mostrarGrafico(persona,TAM);

                printf(" <18 \t18-35\t>35\n");
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}

//<>
