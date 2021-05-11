#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "informes.h"

/** \brief limpia la consola y despliega un menu de opciones de informes
 *
 * \param void
 * \return int retorna la opcion elegida por el usuario
 *
 */
int menuInformes()
{
    system("cls");
    int opcion;
    printf("        INFORMES.\n\n");
    printf("1) ordenar listado por apellido y sector ascendente\n");
    printf("2) ordenar listado por apellido y sector descendente\n");
    printf("3) total y promedio de salarios\n");
    printf("4) listado de empleados que superan el promedio de salarios\n");
    printf("ingrese una opcion: ");
    scanf("%d",&opcion);
    return opcion;
}

/** \brief ordena los elementos del array de empleados
 * la ordenativa de ordenamiento intica si es ascendente o descendente
 * \param lista de empleados
 * \param int tamaño del array
 * \param int orden [1] indica ascendente o [0] indica descendente
 * \return retorna 0 si hubo un error y 1 si esta bien
 *
 */

int ordenarEmpleados(eEmpleado lista[],int tam,int orden)
{
    int todoOk=0;
    eEmpleado aux;
    if(lista!=NULL&&tam>0&&(!orden||orden))
    {
        for(int i=0; i<tam-1; i++)
        {
            for(int j=i+1; j<tam; j++)
            {
                todoOk=1;
                if(orden)
                {
                    if(strcmp(lista[i].apellido,lista[j].apellido)>0 ||
                            (strcmp(lista[i].apellido,lista[j].apellido)==0 && lista[i].sector>lista[j].sector))
                    {
                        aux=lista[i];
                        lista[i]=lista[j];
                        lista[j]=aux;

                    }
                }
                else
                {
                    if(strcmp(lista[i].apellido,lista[j].apellido)<0 ||
                            (strcmp(lista[i].apellido,lista[j].apellido)==0 && lista[i].sector<lista[j].sector))
                    {
                        aux=lista[i];
                        lista[i]=lista[j];
                        lista[j]=aux;
                    }
                }
            }
        }
    }
        return todoOk;
}


    /** \brief funcion creada para calcular la totalidad de todos los sueldos y su promedio
     *
     * \param array empleados
     * \param int tamaño del array de empleado
     * \return int retorna 0 si hubo un error (lista null o tamaño <0) y 1 si pudo realizar la funcion
     *
     */
    int calcularSalarios(eEmpleado lista[],int tam)
    {
        int todoOk=0;
        if(lista!=NULL&&tam>0)
        {
            float totalSueldos=0;
            float promedio;
            int contEmp=0;
            system("cls");
            printf("        Informe total sueldos.\n");
            printf("-------------------------------------------------------------\n");
            for(int i=0; i<tam; i++)
            {
                if(!lista[i].isEmpty)
                {
                    totalSueldos+= lista[i].salario;
                    contEmp++;
                    todoOk=1;
                }
            }
            printf("\nTotal sueldos $%.2f\n",totalSueldos);
            printf("-------------------------------------------------------------\n\n");

            printf("        Informe primedio de sueldos.\n");
            printf("-------------------------------------------------------------\n");
            promedio=totalSueldos/contEmp;
            printf("\nPromedio sueldos $%.2f\n",promedio);
            printf("-------------------------------------------------------------\n");

        }
        return todoOk;
    }

    /** \brief muestra el listado de empleados cuyo sueldo supera el promedio
     *
     * \param array de empleado
     * \param int tamaño del array de empleado
     * \return int retorna 0 si hubo un error en los datos pasados por parametro
     * \return int retorna 1 si pudo realizar la funcion
     */
    int mayorPromedioSalario(eEmpleado lista[],int tam)
    {
        int todoOk=0;
        if(lista!=NULL&&tam>0)
        {
            float totalSueldos=0;
            float promedio;
            int contEmp=0;
            int flag=0;
            system("cls");
            printf("        Listado de empleados que superan el promedio de salarios.\n");
            printf("---------------------------------------------------------------------\n");
            printf("ID    Apellido     Nombre     Salario    Sector\n");
            printf("---------------------------------------------------------------------\n");
            for(int i=0; i<tam; i++)
            {
                if(!lista[i].isEmpty)
                {
                    totalSueldos+= lista[i].salario;
                    contEmp++;
                }
            }
            promedio=totalSueldos/contEmp;
            for(int j=0; j<tam; j++)
            {
                if(!lista[j].isEmpty&&lista[j].salario>promedio)
                {
                    mostrarEmpleado(lista[j]);
                    flag=1;
                }
            }
            if(!flag)
            {
                printf("\nNo hay empleados que superen el promedio.\n\n");
            }
            todoOk=1;
        }
        return todoOk;
    }

