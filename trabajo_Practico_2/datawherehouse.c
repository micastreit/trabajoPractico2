#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datawherehouse.h"

int harcodearEmpleados(eEmpleado lista[], int tam, int cant, int* pId){
int cantidad=0;
if (lista!=NULL&&tam>0&&cant>=0&&cant<=tam&&pId!=NULL){
for(int i=0;i<cant;i++){
    lista[i].id=*pId;
    (*pId)++;
    strcpy(lista[i].nombre,nombres[i]);
    strcpy(lista[i].apellido,apellidos[i]);
    lista[i].salario=salarios[i];
    lista[i].isEmpty=0;
    lista[i].sector=idsectores[i];
    cantidad++;
}

}
return cantidad;
}
