#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include "funciones.h"

int main()
{
    unsigned int seguir, opcion, flagA=0, flagB=0;
    int x=0, y=0;

    printf("\n\n\n\n\n  ====== ");
    printf("CALCULADORA");
    printf(" ======  \n\n\n\n\n");
    printf("=  ENTER para opciones  =\n\n");

    getchar();

    do{
        system("cls");

        if(flagA)
        {
        printf("1- Ingresar 1er operando (A = %d)\n",x);
        }
        else
        {
        printf("1- Ingresar 1er operando (A = no ingresado)\n");
        }
        if(flagB)
        {
        printf("2- Ingresar 2do operando (B = %d)\n",y);
        }
        else
        {
        printf("2- Ingresar 2do operando (B = no ingresado)\n");
        }
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        opcion=ValidaRango((opcion=CapturaNro()),1,9);

        switch(opcion)
        {
            case 1:
                system("cls");
                x=CapturaNro();
                flagA=1;
                system("cls");
                printf("\n\nPrimer operando ingresado : %d\n\n\n",x);
                break;
            case 2:
                system("cls");
                y=CapturaNro();
                flagB=1;
                system("cls");
                printf("\n\nSegundo operando ingresado : %d\n\n\n",y);
                break;
            case 3:
                system("cls");
                if(ValidaCargaFlags(flagA,flagB))
                {
                    printf("\n\n%d + %d = %.2f\n\n\n",x,y,Suma(x,y));
                }
                break;
            case 4:
                system("cls");
                if(ValidaCargaFlags(flagA,flagB))
                {
                    printf("\n\n%d - %d = %.2f\n\n\n",x,y,Resta(x,y));
                }
                break;
            case 5:
                system("cls");

                if(ValidaCargaFlags(flagA,flagB))
                {
                    while(y==0)
                    {
                        printf("ERROR!!!\nEl denominador debe ser distinto de cero\n");
                        y=CapturaNro();
                    }
                    printf("\n\n%d / %d es = %.2f\n\n\n",x,y,Division(x,y));
                }
                break;
            case 6:
                system("cls");
                if(ValidaCargaFlags(flagA,flagB))
                {
                    printf("\n\n%d * %d = %.2f\n\n\n",x,y,Multiplicacion(x,y));
                }
                break;
            case 7:
                system("cls");
                if(ValidaCargaFlags(flagA,flagA)) /// solo valida la carga de operando A
                {

                    x=ValidaRango(x,1,9999);
                    printf("\n\n%d! = %d\n\n\n",x,Factorial(x));
                }
                break;
            case 8:
                if(ValidaCargaFlags(flagA,flagB))
                {
                system("cls");
                while(y==0)
                {
                    printf("ERROR!!!\nEl denominador debe ser distinto de cero\n");
                    y=CapturaNro();
                }
                x=ValidaRango(x,1,9999);
                printf("\n**************************************************");
                printf("\n\n%d + %d = %.2f\n",x,y,Suma(x,y));
                printf("\n\n%d - %d = %.2f\n",x,y,Resta(x,y));
                printf("\n\n%d / %d es = %.2f\n",x,y,Division(x,y));
                printf("\n\n%d * %d = %.2f\n",x,y,Multiplicacion(x,y));
                printf("\n\n%d! = %d\n",x,Factorial(x));
                printf("\n**************************************************\n\n");
                }
                break;
            case 9:
                system("cls");
                break;
        } // fin de switch
        }while((seguir=ValidaSeguirSoN()));
    return 0;
} // fin de main

