#include <stdio.h>
#include <stdlib.h>
#include <operacionesMatBasicas.h>

int main()

{

    float num1, num2;
    char opcion;

    do
    {
        printf("\n** Ingresar 1er operando: **\n ");
        scanf("%f",&num1);
        fflush(stdin);
        printf("** Ingresar 2do operando: **\n" );
        scanf("%f",&num2);
        fflush(stdin);
        printf("\nX: %.2f\n",num1);
        printf("Y: %.2f\n",num2);
        printf("\na-sumar");
        printf("\nb-restar");
        printf("\nc-dividir");
        printf("\nd-multiplicar");
        printf("\ne-factorial");
        printf("\nf-salir\n");
        fflush(stdin);
        scanf("%c",&opcion);

        switch(opcion)
        {

        case 'a':
            printf("\nEl resultado de: %.2f %c %.2f %s %.2f",num1,'+',num2,"es:",sumador(num1,num2));
            break;
        case 'b':
            printf("\nEl resultado de: %.2f %c %.2f %s %.2f",num1,'-',num2,"es:",restador(num1,num2));

            break;
        case 'c':
            if(num2==0)
            {
                printf("\nERROR. no se puede dividir por cero");
            }
            else
            {
                printf("\nEl resultado de: %.2f %c %.2f %s %.2f",num1,'/',num2,"es:",divisor(num1,num2));
            }

            break;
        case 'd':
            printf("\nEl resultado de: %.2f %c %.2f %s %.2f",num1,'*',num2,"es:",multiplicador(num1,num2));
            break;
        case 'e':
            if(num1>34){
                printf("ERROR. numero muy grande para calcular el factorial\n");
            }else{
            printf("\nEl factorial de %.1f %s %.1f ",num1,"es:",factorializadorNumero(num1));
            }
            if(num2>34){
                printf("ERROR. numero muy grande para calcular el factorial");
            }else{
            printf(" y El factorial de %.1f %s %.1f",num2,"es:",factorializadorNumero(num2));
            }
        case 'f':
            break;

        default:
            printf("\nIngrese una opcion valida ");
            break;

        }

    }
    while(opcion!='f');
    return 0;
}


