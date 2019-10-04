#ifndef EMPLEADOS_H_INCLUDED
#define EMPLEADOS_H_INCLUDED
typedef struct
{
    int id;
    char nombre[51];
    char apellido[51];
    float salario;
    int sector;
    int isEmpty;
    float promedio;

} eEmpleados;



#endif // EMPLEADOS_H_INCLUDED

int buscarLibre(eEmpleados vecE[], int tam);
void mostrarEmpleado(eEmpleados vecE,int tamE);
int buscarLibre(eEmpleados vecE[], int tam);
int altaEmpleado(eEmpleados vecE[], int tamE, int id);
eEmpleados newEmpleado(int id, char nombre[],char apellido[],float salario,int sector);
void mostrarEmpleados(eEmpleados vecE[],int tamE);
void inicializarEmpleado(eEmpleados vecE[], int tamE);
int bajaEmpleado(eEmpleados vecE[], int tamE);
int modificarEmpleado(eEmpleados vecE[], int tamE);
void ordenarEmpleados(eEmpleados vecE[], int tam,int criterioDeOrden);
