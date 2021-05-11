#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"
#include "sector.h"
#define TAM 5
#define TAMSEC 5
#define EMPLEADO 1
#define SECTOR 0
#define UP 1
#define DOWN 0


int main()
{
    int nextId=47500;
    eEmpleado nomina[TAM];
    inicializarEmpleado(nomina,TAM);
    eSector sectores[TAMSEC]={
                    {500,"Sistemas"},
                    {501,"Legales"},
                    {502,"RRHH"},
                    {503,"Contable"},
                    {504,"Ventas"},
                    };

    char salir;
    do
    {
        switch (menu())
        {
        case 1:
            if(altaEmpleado(nomina, TAM, &nextId,sectores,TAMSEC))
            {
                printf("\nAlta exitosa!\n\n");
            }
            else
            {
                printf("\nHubo un problema al realizar el alta.\n\n");
            }
            break;
        case 2:
            if(modificarEmpleado(nomina, TAM,sectores,TAMSEC)==1)
            {
                printf("\nModificacion exitosa!\n\n");
            }
            else
            {
                printf("\nNo se pudo realizar la modificacion.\n\n");
            }
            break;
        case 3:
            if(bajaEmpleado(nomina, TAM,sectores,TAMSEC))
            {
                printf("Baja exitosa.\n\n");
            }
            else
            {
                printf("No se pudo realizar la baja.\n\n");
            }
            break;
        case 4:
            switch(menuInformes()){
        case 1:
            ordenarEmpleados(nomina,TAM,EMPLEADO,UP);
            mostrarEmpleados(nomina,TAM,sectores,TAMSEC);
            break;
           case 2:
            ordenarEmpleados(nomina,TAM,EMPLEADO,DOWN);
            mostrarEmpleados(nomina,TAM,sectores,TAMSEC);
            break;
            case 3:
            ordenarEmpleados(nomina,TAM,SECTOR,UP);
            mostrarEmpleados(nomina,TAM,sectores,TAMSEC);
            break;
           case 4:
            ordenarEmpleados(nomina,TAM,SECTOR,DOWN);
            mostrarEmpleados(nomina,TAM,sectores,TAMSEC);
            break;
           default:
            printf("Opcion invalida.\n");
            break;

            }
            break;
        case 5:
            printf("\nConfirme salida (s/n): ");
            fflush(stdin);
            salir=getchar();
            break;
        default:
            printf("Opcion invalida.\n");
        }
        system("pause");
    }
    while(salir!='s');
    return 0;
}

int menuInformes(){
    system("cls");
    int opcion;
printf("        INFORMES.\n\n");
printf("1) ordenar listado por apellido ascendente\n");
printf("2) ordenar listado por apellido descendente\n");
printf("3) ordenar listado por sector ascendente\n");
printf("4) ordenar listado por sector descendente\n");
printf("ingrese una opcion: ");
scanf("%d",&opcion);
}

/** \brief ordena los elementos del array de empleados
 * la ordenativa de ordenamiento intica si es ascendente o descendente
 * \param lista de empleados
 * \param int tamaño del array
 * \param int clasificacion [1] indica empleados [0] indica sector
 * \param int orden [1] indica ascendente o [0] indica descendente
 * \return retorna 0 si hubo un error y 1 si esta bien
 *
 */

int ordenarEmpleados(eEmpleado lista[],int tam,int clasificacion,int orden)
{
    int todoOk=0;
    eEmpleado aux;
    if(lista!=NULL&&tam>0&&(!clasificacion||clasificacion)&&(!orden||orden))
    {

        for(int i=0; i<tam-1; i++)
        {
            for(int j=i+1; j<tam; j++)
            {
                if(clasificacion&&orden)
                {

                    if(strcmp(lista[i].apellido,lista[j].apellido)>0 || (strcmp(lista[i].apellido,lista[j].apellido)==0 && strcmp(lista[i].nombre,lista[j].nombre)>0))
                    {
                        aux=lista[i];
                        lista[i]=lista[j];
                        lista[j]=aux;

                    }
                }
                else if(clasificacion&&!orden)
                {
                    if(strcmp(lista[i].apellido,lista[j].apellido)<0 || (strcmp(lista[i].apellido,lista[j].apellido)==0 && strcmp(lista[i].nombre,lista[j].nombre)<0))
                    {
                        aux=lista[i];
                        lista[i]=lista[j];
                        lista[j]=aux;

                    }
                }
                else if(!clasificacion&&orden)
                {
                    if(lista[i].sector > lista[j].sector|| (lista[i].sector==lista[j].sector&& strcmp(lista[i].apellido,lista[j].apellido)>0))
                    {
                        aux=lista[i];
                        lista[i]=lista[j];
                        lista[j]=aux;

                    }
                }
                else
                {
                    if(lista[i].sector < lista[j].sector|| (lista[i].sector==lista[j].sector&& strcmp(lista[i].apellido,lista[j].apellido)>0))
                    {
                        aux=lista[i];
                        lista[i]=lista[j];
                        lista[j]=aux;

                    }
                }

            }

        }
    }

}
