#ifndef SECTOR_H_INCLUDED
#define SECTOR_H_INCLUDED

typedef struct{
int idSector;
char descripcion[20];
}eSector;

#endif // SECTOR_H_INCLUDED
int cargarDescripcionSector(int id, eSector sectores[], int tam, char desc[]);
void mostrarSectores(eSector sectores[],int tamsec);
void mostrarSector(eSector unSector);
int validarIdSector(int idSector,eSector sectores(),int tamSec);
