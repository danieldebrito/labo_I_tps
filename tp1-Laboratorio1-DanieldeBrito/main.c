/******************************************************************
*TP NRO 1 / Laboratorio 1 - Calculadora
*
*Objetivo: realizar varias operaciones a partir de dos operandos ingresados
*          Suma, Resta,Multiplicación, división, factorial.
*
*
*
*Version: 1.0 07/04/2016
*
*Autor: Daniel Ruben de Brito
*
*******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include "funciones.h"

int main()
{
    unsigned int seguir, opcion, flagA=0, flagB=0;
    int x=0, y=0;

    printf("\n=====================\n");
    printf("=====================\n");
    printf("=                   =\n");
    printf("= CALCULADORA v1.0  =\n");
    printf("=                   =\n");
    printf("=====================\n\n");
    printf("ENTER para opciones\n\n");

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

        opcion=CapturaNro();
        while(ValidaRango(opcion,1,9))
        {
            printf("El numero ingresado no es una opcion del menu valida\n");
            opcion=CapturaNro();
        }

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
                    printf("\n\n%d + %d = %d\n\n\n",x,y,Suma(x,y));
                }
                break;
            case 4:
                system("cls");
                if(ValidaCargaFlags(flagA,flagB))
                {
                    printf("\n\n%d - %d = %d\n\n\n",x,y,Resta(x,y));
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
                    printf("\n\n%d / %d = %.2f\n\n\n",x,y,Division(x,y));
                }
                break;
            case 6:
                system("cls");
                if(ValidaCargaFlags(flagA,flagB))
                {
                    printf("\n\n%d * %d = %d\n\n\n",x,y,Multiplicacion(x,y));
                }
                break;
            case 7:
                system("cls");
                if(ValidaCargaFlags(flagA,flagA)) /// solo valida la carga de operando A
                {
                while(ValidaRango(x,0,9999))
                    {
                        printf("El valor ingresado no es valido\nPara resolver Factorial debe ser >=0\n");
                        x=CapturaNro();
                    }
                printf("\n\n%d! = %d\n\n\n",x,Factorial(x));
                }
                break;
            case 8:
                system("cls");
                if(ValidaCargaFlags(flagA,flagB))
                {
                    while(y==0)
                    {
                        printf("ERROR!!!\nEl denominador debe ser distinto de cero\n");
                        y=CapturaNro();
                    }
                    while(ValidaRango(x,0,9999))
                    {
                        printf("El valor ingresado no es valido\nPara resolver Factorial debe ser >=0\n");
                        x=CapturaNro();
                    }
                        system("cls");
                        printf("\n**************************************************");
                        printf("\n\n%d + %d = %d\n",x,y,Suma(x,y));
                        printf("\n\n%d - %d = %d\n",x,y,Resta(x,y));
                        printf("\n\n%d / %d = %.2f\n",x,y,Division(x,y));
                        printf("\n\n%d * %d = %d\n",x,y,Multiplicacion(x,y));
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
