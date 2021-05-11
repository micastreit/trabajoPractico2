#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"
#define TAM 1000
#define UP 1
#define DOWN 0

int main()
{
        int nextId=47500;
    eEmpleado nomina[TAM];
    inicializarEmpleado(nomina,TAM);
//    harcodearEmpleados(nomina,TAM,8,&nextId);
    char salir;
    int flagAlta=0;
    do
    {
        switch (menu())
        {
        case 1:
            if(altaEmpleado(nomina, TAM, &nextId))
            {
                printf("\nAlta exitosa!\n\n");
                flagAlta=1;
            }
            else
            {
                printf("\nHubo un problema al realizar el alta.\n\n");
            }
            break;
        case 2:
            if(!flagAlta)
            {
                printf("No puede acceder a la opcion modificar hasta que de alta un empleado.\n");
            }else
            {
            if(modificarEmpleado(nomina, TAM)==1)
            {
                printf("\nModificacion exitosa!\n\n");
            }
            else
            {
                printf("\nNo se pudo realizar la modificacion.\n\n");
            }
            }
            break;
        case 3:
            if(!flagAlta)
            {
                printf("No puede acceder a la opcion baja empleado hasta que de alta un empleado.\n");
            }else
            {
            if(bajaEmpleado(nomina, TAM))
            {
                printf("Baja exitosa.\n\n");
            }
            else
            {
                printf("No se pudo realizar la baja.\n\n");
            }
            }
            break;
        case 4:
            if(!flagAlta)
            {
                printf("No puede acceder a la opcion informes hasta que de alta un empleado.\n");
            }else
            {
            switch(menuInformes()){
            case 1:
            ordenarEmpleados(nomina,TAM,UP);
            mostrarEmpleados(nomina,TAM);
            break;
           case 2:
            ordenarEmpleados(nomina,TAM,DOWN);
            mostrarEmpleados(nomina,TAM);
            break;
            case 3:
                if(!calcularSalarios(nomina,TAM))
                {
                    printf("Hubo un error al calcular el total y los promedios de los salarios.\n\n");
                }
            break;
            case 4:
                if(!mayorPromedioSalario(nomina,TAM))
                {
                    printf("Hubo un error\n\n.");
                }
            break;
           default:
            printf("Opcion invalida.\n");
            break;
            }
            }
            break;
        case 5:
            printf("\nConfirme salida (s/n): ");
            fflush(stdin);
            salir=getchar();
            break;
        default:
            printf("Opcion invalida.\n");
            break;
        }
        system("pause");
    }
    while(salir!='s');
    return 0;
}
