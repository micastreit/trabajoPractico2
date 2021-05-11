#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"

/** \brief limpia la pantalla y muestra un menu de opciones
 * \param void
 * \return int retorna el numero de opcion que teclee el usuario
 */

int menu()
{
system("cls");
int opcion;
printf("        Menu de opciones.\n\n");
printf("1) Alta de empleado.\n");
printf("2) Modificar empleado.\n");
printf("3) Baja de empleado.\n");
printf("4) Informar.\n");
printf("5) salir.\n");
printf("\nElija una opcion: ");
scanf("%d", &opcion);
return opcion;
}

/** \brief esta funcion indica que todas las posiciones del array estan vacias.
 * Esa funcion pone la bandera isEmpty en true en todas las posiciones del array
 * \param lista empleado para el array de empleado
 * \param int tamaño del array
 * \return int retorna (0) si hay error y 1 si esta bien
 */

int inicializarEmpleado(eEmpleado lista[], int tam)
{
    int todoOk=0;
if(lista!= NULL&& tam > 0){

for(int i=0; i<tam; i++){
    lista[i].isEmpty=1;
}
todoOk=1;
}
return todoOk;
}

/** \brief agrega a una existente lista de empleados los valores recibidos en la primer posicion libre
 *
 * \param lista empleado
 * \param int tamaño
 * \param int id
 * \return retorna 0 si hay error el los datos ingresados por parametro o no hay mas lugar en el array de empleados
 * \return retorna 1 si se realiza el alta
 */

int altaEmpleado(eEmpleado lista[], int tam, int* pId)
{
int todoOk=0;

system("cls");
printf("    Alta de empleado:\n\n");
printf("ID: %d\n",*pId);

eEmpleado nuevoEmpleado;
int indice;
if(lista!= NULL&& tam> 0&& pId !=NULL){
    indice=buscarLibre(lista, tam);
    if(indice==-1){
printf("No hay mas lugar en el sistema.\n");
    }else{

    printf("\nIngrese nombre: ");
    fflush(stdin);
    gets(nuevoEmpleado.nombre);

    printf("\nIngrese apellido: ");
    fflush(stdin);
    gets(nuevoEmpleado.apellido);

    printf("\nIngrese salario: ");
    scanf("%f",&nuevoEmpleado.salario);
    while(nuevoEmpleado.salario<0){
        printf("\nSalario invalido. Reingrese salario: ");
    scanf("%f",&nuevoEmpleado.salario);
    }

    printf("\nIngrese numero de sector: ");
    scanf("%d",&nuevoEmpleado.sector);
    while(nuevoEmpleado.sector<0){
        printf("\nSector invalido. Reingrese id del sector: ");
    scanf("%d",&nuevoEmpleado.sector);
    }

    nuevoEmpleado.id= *pId;
    nuevoEmpleado.isEmpty=0;
    (*pId)++;
    lista[indice]=nuevoEmpleado;
    todoOk=1;
    }
    }
return todoOk;
}

 /** \brief busca la primer posicion libre del array de empleados
  *
  * \param lista empleado
  * \param int tamaño
  * \return retorna el indice del primer lugas libre o -1 si no hay posiciones libres
  *
  */

int buscarLibre(eEmpleado lista[],int tam)
{
int indice=-1;
for(int i=0; i< tam; i++){
    if(lista[i].isEmpty){
        indice=i;
        break;
    }
}
return indice;
}

/** \brief busca un empleado recibiendo como parametro de busqueda el ID
 *
 * \param lista empleados
 * \param int tamaño
 * \param int id
 * \return retorna el indice de la posicion del empleado buscado o (-1) si no se encontro
 *
 */
int buscarEmpleado(eEmpleado lista[], int tam, int id)
{
    int indice=-1;
for(int i=0; i< tam; i++){
    if(id== lista[i].id&& !lista[i].isEmpty){
        indice=i;
        break;
    }
}
return indice;
}

/** \brief muestra el contenido del array de empleados activos
 * \param lista empleados
 * \param int tamaño del array de empleados
 * \return retorna o si hay error (tamaño invalido o lista null) y 1 si esta bien
 *
 */

int mostrarEmpleados(eEmpleado lista[],int tam)
{
    int todoOk=0;
    if(lista!= NULL&&tam >0){

    int flag=1;
    printf("\n                ***Nomina de empleados***\n");
    printf("ID      Apellido     Nombre       Salario    Sector\n");
    printf("---------------------------------------------------------\n");
    for(int i=0; i< tam; i++)
    {   if(!lista[i].isEmpty){
        mostrarEmpleado(lista[i]);
    flag=0;
    }
    }
    printf("\n\n");

    if(flag){
        printf("            No hay empleados que mostrar.\n");
        printf("\n\n");
    }
    todoOk=1;
    }
return todoOk;
}

/** \brief muestra un solo empleado
 * \param estructura de un empleado
 * \return void
 *
 */

void mostrarEmpleado(eEmpleado unEmpleado)
{
    printf("%d   %-10s   %-10s   %.2f    %d\n"
           ,unEmpleado.id
           ,unEmpleado.apellido
           ,unEmpleado.nombre
           ,unEmpleado.salario
           ,unEmpleado.sector
          );
}

/** \brief funcion que permite modificar los datos de un empleado dado de alta
 * muestra la nomina de empleados con sus respectivos ID y solicita el ID del empleado a modificar
 * \param lista empleados
 * \param int tamaño del array de empleados
 * \return retorna -2 si hay error en el tamaño o lista recibido por parametro
 * \return retorna -1 si hay error en el id
 * \return retorna 0 si se cancela mediante usuario
 * \return retorna 1 si se selecciono alguna modificacion
 */

int modificarEmpleado(eEmpleado lista[], int tam)
{
int todoOk=-2;
if(lista!=NULL&&tam>0){

int id;
int indice;
char confirmar;
char confmodificacion;
char nombre[52];
char apellido[52];
float salario;
int sector;

    system("cls");
    printf("        Modificar empleado\n\n");
    mostrarEmpleados(lista,tam);
    printf("\n Ingrese el ID del empleado a modificar: ");
    scanf("%d",&id);
    indice=buscarEmpleado(lista,tam,id);
    if(indice==-1){
        printf("\nNo hay ningun empleado con el ID %d\n",id);
        todoOk=-1;
    }else{
    mostrarEmpleado(lista[indice]);
    printf("\nDesea modificar este empleado? (s/n) :");
    fflush(stdin);
    scanf("%c",&confirmar);
    if (confirmar=='s'||confirmar=='S'){
    switch(menuModificar()){
    case 1:
    printf("\nIngrese nuevo nombre: ");
    fflush(stdin);
    gets(nombre);
    printf("Nuevo nombre: %s\n",nombre);
    printf("\nConfirma modificacion? (s/n) :");
    fflush(stdin);
    scanf("%c",&confmodificacion);
    if (confmodificacion=='s'||confmodificacion=='S')
    {
    strcpy(lista[indice].nombre,nombre);
    }else
    {
    printf("\nModificacion cancelada por el usuario.\n");
    todoOk=0;
    }
        break;
    case 2:
    printf("\nIngrese nuevo apellido: ");
    fflush(stdin);
    gets(apellido);
    printf("Nuevo apellido: %s\n",apellido);
    printf("\nConfirma modificacion? (s/n) :");
    fflush(stdin);
    scanf("%c",&confmodificacion);
    if (confmodificacion=='s'||confmodificacion=='S')
    {
    strcpy(lista[indice].apellido,apellido);
    }else
    {
    printf("\nModificacion cancelada por el usuario.\n");
    todoOk=0;
    }
    break;
    case 3:
    printf("\nIngrese nuevo salario:");
    scanf("%f",&salario);
    while(salario<0)
    {
        printf("\nSalario invalido. Reingrese nuevo salario:");
        scanf("%f",&salario);
    }
    printf("Nuevo salario: %.2f\n",salario);
    printf("\nConfirma modificacion? (s/n) :");
    fflush(stdin);
    scanf("%c",&confmodificacion);
    if (confmodificacion=='s'||confmodificacion=='S')
    {
    lista[indice].salario=salario;
    }else
    {
    printf("\nModificacion cancelada por el usuario.\n");
    todoOk=0;
    }
    break;
    case 4:
    printf("\nIngrese ID del nuevo sector:");
    scanf("%d",&sector);
    while(sector<0){
        printf("\nSector invalido. Reingrese id del sector:");
        scanf("%d",&sector);
    }
    printf("Nuevo sector: %d\n",sector);
    printf("\nConfirma modificacion? (s/n) :");
    fflush(stdin);
    scanf("%c",&confmodificacion);
    if (confmodificacion=='s'||confmodificacion=='S')
    {
    lista[indice].sector=sector;
    }else
    {
    printf("\nModificacion cancelada por el usuario.\n");
    todoOk=0;
    }
    break;
    default:
        printf("\n Opcion invalida\n");
        break;
    }
    todoOk=1;
    }else {
    printf("\nModificacion cancelada por el usuario.\n");
    todoOk=0;
    }
    }
}
return todoOk;
}

/** \brief muestra un menu de opciones para la modificacion
 * \param void
 * \return int retorna la opcion ingresada por el usuario
 */

int menuModificar()
{
    int opcion;
    printf("\n\n");
    printf("1) Modificar nombre.\n");
    printf("2) Modificar apellido.\n");
    printf("3) Modificar salario.\n");
    printf("4) Modificar sector.\n");
    printf("Ingrese una opcion: ");
    scanf("%d",&opcion);
    return opcion;
}

/** \brief elimina de manera logica un empleado recibiendo como parametro su id
 *
 * \param lista empleado
 * \param int tamaño de array de empleados
 * \return retorna 0 si hubo un error y 1 si se efectuo la baja con exito
 *
 */

int bajaEmpleado(eEmpleado lista[],int tam)
{
int todoOk=0;
int id;
int indice;
char confirma;
if(lista!=NULL&&tam>0){
system("cls");
printf("        Baja de empleados.\n");
mostrarEmpleados(lista,tam);
printf("\nIngrese el ID que desea dar de baja: ");
scanf("%d",&id);
indice=buscarEmpleado(lista, tam, id);
if(indice==-1){
    printf("\nNo hay ningun empleado con el ID %d\n",id);
}
else{
    mostrarEmpleado(lista[indice]);
    printf("\nConfirma baja?: ");
    fflush(stdin);
    scanf("%c",&confirma);
    if(confirma=='s'){
        lista[indice].isEmpty=1;
        todoOk=1;
    }else{
    printf("\nBaja cancelada por el usuario.\n");
    }
}
}
    return todoOk;
}
