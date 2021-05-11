#include "sector.h"
#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

typedef struct
{
    int id;   //pk
    char nombre[52];
    char apellido[52];
    float salario;
    int sector;
    int isEmpty;
} eEmpleado;

#endif // EMPLEADO_H_INCLUDED

int menu();
int inicializarEmpleado(eEmpleado lista[], int tam);
int altaEmpleado(eEmpleado lista[], int tam, int* pId,eSector sectores[],int tamsec);
int buscarLibre(eEmpleado lista[],int tam);
int buscarEmpleado(eEmpleado lista[], int tam, int id);
int mostrarEmpleados(eEmpleado lista[],int tam, eSector sectores[], int tamsec);
void mostrarEmpleado(eEmpleado unEmpleado, eSector sectores[],int tamsec);
int menuModificar();
int modificarEmpleado(eEmpleado lista[], int tam, eSector sectores[], int tamsec);
int bajaEmpleado(eEmpleado lista[],int tam,eSector sectores[],int tamsec);
