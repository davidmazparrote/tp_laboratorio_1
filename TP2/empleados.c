#include "empleados.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inicializarEmpleado(eEmpleados vecE[], int tamE)
{
    for(int i = 0; i < tamE; i++)
    {
        vecE[i].isEmpty = 1;
    }
}


int buscarLibre(eEmpleados vecE[], int tamE)
{
    int indice = -1;

    for(int i=0; i < tamE; i++)
    {
        if( vecE[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}


int altaEmpleado(eEmpleados vecE[], int tamE, int id)
{
    int altaOk= 0;
    int indice;
    char nombre[51];
    char apellido[51];
    float salario;
    int sector;


    system("cls");

    printf("******Alta Empleado********\n\n");

    indice = buscarLibre(vecE, tamE);

    if( indice == -1)
    {
        printf("\nEl sistema esta completo\n\n");
    }
    else
    {
        fflush(stdin);
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(nombre);

        printf("Ingrese apellido: ");
        fflush(stdin);
        gets(apellido);

        printf("Ingrese salario: ");
        scanf("%f", &salario);

        printf("Ingrese sector: ");
        scanf("%d", &sector);

        vecE[indice] = newEmpleado(id,nombre,apellido,salario,sector);
        altaOk = 1;

        printf("**Alta exitosa!!**\n\n");
    }

    return altaOk;
}


eEmpleados newEmpleado(int id, char nombre[],char apellido[],float salario,int sector)
{
    eEmpleados emp;
    emp.id=id;
    strcpy( emp.nombre, nombre);
    strcpy( emp.apellido, apellido);
    emp.sector=sector;
    emp.salario=salario;
    emp.isEmpty=0;

    return emp;
}


void mostrarEmpleado(eEmpleados vecE,int tamE)
{

    printf("%d   %s      %s         %d       %3.2f",vecE.id,vecE.nombre,vecE.apellido,vecE.sector,vecE.salario);
    printf("\n\n");
}


void mostrarEmpleados(eEmpleados vecE[],int tamE)
{

    int flag = 0;
    system("cls");

    printf(" Id     Nombre  Apellido    Sector      Salario\n\n");

    for(int i=0; i < tamE; i++)
    {
        if( vecE[i].isEmpty == 0)
        {
            mostrarEmpleado(vecE[i],tamE);
            flag = 1;
        }
    }

    if( flag == 0)
    {
        printf("\nNo hay Empleados para mostrar\n");
    }

    printf("\n\n");
}

int buscarEmpleado(int id,eEmpleados vecE[], int tamE)
{
    int indice = -1;

    for(int i=0; i < tamE; i++)
    {
        if( vecE[i].id == id && vecE[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int bajaEmpleado(eEmpleados vecE[], int tamE)
{
    int bajaOk = 0;
    int id;
    int indice;
    char confirmaBaja;
    system("cls");
    printf("***** Baja Empleado *****\n\n");
    printf("Ingrese id: ");
    scanf("%d", &id);

    indice = buscarEmpleado(id, vecE, tamE);

    if( indice == -1)
    {
        printf("No existe un empleado con ese legajo\n\n");

    }
    else
    {
        mostrarEmpleado(vecE[indice],tamE);

        printf("\nConfirma baja?");
        fflush(stdin);
        scanf("%c", &confirmaBaja);

        if( confirmaBaja == 's')
        {
            vecE[indice].isEmpty = 1;
            bajaOk = 1;
            printf("Baja exitosa!!!");
        }
        else
        {
            printf("Se ha cancelado la operacion");
        }
    }
    return bajaOk;
}



int modificarEmpleado(eEmpleados vecE[], int tamE)
{

    int modOk = 0;
    int id;
    int indice;
    system("cls");
    printf("***** Modificar empleado *****\n\n");
    printf("Ingrese Id: ");
    scanf("%d", &id);
    int opcion;

    indice = buscarEmpleado(id,vecE,tamE);

    if( indice == -1)
    {
        printf("No existe un empleado con ese id\n\n");

    }
    else
    {

        mostrarEmpleado(vecE[indice],tamE);

        printf("\n\n1- Modificar nombre\n");
        printf("2- Modificar apellido\n");
        printf("3- Modificar sector\n");
        printf("4- Modificar salario\n");
        printf("5- Salir\n\n");
        printf("Ingrese opcion: ");
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:
            printf("Ingrese nuevo nombre: ");
            gets(vecE[indice].nombre);
            break;

        case 2:
            printf("Ingrese nuevo apellido: ");
            gets(vecE[indice].apellido);
            break;

        case 3:
            printf("Ingrese nuevo sector: ");
            scanf("%d", &vecE[indice].sector);
            break;

        case 4:
            printf("Ingrese nuevo salario: ");
            scanf("%f", &vecE[indice].salario);
            break;

        case 5:
            printf("Se ha cancelado la modificacion ");
            break;

        }
    }
    return modOk;
}

void ordenarEmpleados(eEmpleados vecE[], int tam,int criterioDeOrden)
{
    eEmpleados auxEmpleado;
    for(int i= 0; i < tam-1 ; i++)
    {
        for(int j= i+1; j <tam; j++)
        {
            if( vecE[i].apellido > vecE[j].apellido && criterioDeOrden==1)
            {
                auxEmpleado = vecE[i];
                vecE[i] = vecE[j];
                vecE[j] = auxEmpleado;
            }
            else if(vecE[i].sector > vecE[j].sector && criterioDeOrden==2)
            {

                auxEmpleado = vecE[i];
                vecE[i] = vecE[j];
                vecE[j] = auxEmpleado;

            }
        }
    }
    printf("Alumnos Ordenados\n\n");
}
