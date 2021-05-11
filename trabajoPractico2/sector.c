#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sector.h"

int cargarDescripcionSector(int id, eSector sectores[], int tam, char desc[])
{
    int todoOk=0;

    if(id >500 && id <=504 && sectores != NULL && tam >0 && desc !=NULL)
    {
        for(int i=0; i<tam; i++)
        {
            if(sectores[i].idSector == id)
            {
                strcpy(desc, sectores[i].descripcion);
                todoOk=1;
                break;
            }
        }
    }

    return todoOk;

}
void mostrarSectores(eSector sectores[],int tamsec){
    printf("        Lista de sectores.\n\n");
    printf("Id    Descripcion\n");
for(int i=0;i<tamsec;i++){
    mostrarSector(sectores[i]);
}
}
void mostrarSector(eSector unSector){
printf("%d   %10s\n",unSector.idSector,unSector.descripcion);
}

int validarIdSector(int idSector,eSector sectores(),int tamSec){
int todoOk=0;
if(idSector>=500&&idSector<=504&&sectores!=NULL&&tamSec>0){
    todoOk=1;
}
return todoOk;
}


