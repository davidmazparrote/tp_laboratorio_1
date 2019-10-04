#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>
#include "empleados.h"
#define TAME 100


int menuPrincpal();
int menuInformes();
void mostrarInformes(eEmpleados vecE[], int tamE);

int main()
{
    char salir='n';
    eEmpleados empleadosVec[TAME];
    inicializarEmpleado(empleadosVec, TAME);

    int id=500;
    do
    {
        switch(menuPrincpal())
        {
        case 1:
            if(altaEmpleado(empleadosVec,TAME,id))
            {

                id++;
            }
            break;

        case 2:
            if(buscarLibre(empleadosVec,TAME)==0)
            {
                printf("No hay empleados todavia");
            }
            else
            {
                bajaEmpleado(empleadosVec,TAME);
            }
            break;

        case 3:
            if(buscarLibre(empleadosVec,TAME)==0)
            {
                printf("No hay empleados todavia");
            }
            else
            {
                modificarEmpleado(empleadosVec,TAME);
            }

            break;

        case 4:
            if(buscarLibre(empleadosVec,TAME)==0)
            {
                printf("No hay empleados todavia\n\n");
            }
            else
            {
                mostrarEmpleados(empleadosVec,TAME);
            }
            break;

        case 5:
            menuInformes();
            mostrarInformes(empleadosVec,TAME);
            break;
        case 6:
            printf("Confirma salir?:");
            fflush(stdin);
            salir = getche();
            break;

        default:
            printf("\nOpcion Invalida!\n\n");
        }
        system("pause");

    }
    while(salir == 'n');

    return 0;


}
int menuPrincpal()
{
    int opcion;
    system("cls");
    printf("***ABM EMPLEADOS***\n\n\n\n");
    printf("1-Alta empleado\n");
    printf("2-Baja empleado\n");
    printf("3-Modificar empleado\n");
    printf("4-Listar empleados\n");
    printf("5-Informes empleados\n");
    printf("6-Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}


int menuInformes()
{
    int opcion;
    system("cls");
    printf("****** Informes de empleados*******\n\n");
    printf("1-ordenar empleados\n");
    printf("2-Total de los salarios\n");
    printf("3-Promedio de salarios\n");
    printf("4-Empleados que superen el promedio de salario\n");
    printf("5-Salir\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);


    return opcion;
}


void mostrarInformes(eEmpleados vecE[], int tamE)
{

    char salir = 'n';
    int criterioDeOrden;

    do
    {
        switch(menuInformes())
        {
        case 1:
            printf("Indique como desea ordenarlos: \n");
            printf("1-Por apellido: \n");
            printf("2-Por sector: \n");
            fflush(stdin);
            scanf("%d",&criterioDeOrden);
            ordenarEmpleados(vecE,tamE,criterioDeOrden);
            printf("Empleados ordenados");
            break;

        case 2:     //no llegue

            break;

        case 3: //no llegue

            break;

        case 4: //no llegue

            break;


        case 5:
            printf("Confirma salir?:");
            fflush(stdin);
            salir = getche();
            break;

        default:
            printf("\nOpcion Invalida!\n\n");
        }
        system("pause");
    }
    while(salir == 'n');
}


