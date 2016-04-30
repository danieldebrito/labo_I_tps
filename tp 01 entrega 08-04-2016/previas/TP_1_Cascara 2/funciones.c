#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include "funciones.h"

/** \brief Valida el ingreso de caracteres, para admitir solo S o N
 *
 * \param
 * \param
 * \return O si ingreso N, 1 si ingreso S
 *
 */


unsigned int ValidaSeguirSoN(void)
{
char rta;
printf("  s : para seguir   -   n : para salir\n\n");
rta=toupper(getche());
while(!((rta=='S')||(rta=='N')))
{
    printf("\nERROR!!!\n\nINGRESE UNA RESPUESTA VALIDA");
    rta=toupper(getche());
}
return (rta=='S');
}
/**************************************************/
float CapturaNro()
{
    float A;
    printf("Ingrese un numero : \n\n");
    scanf("%f",&A);
    return A;
}
/**************************************************/
float Suma(float A,float B)
{
    return A+B;
}
/**************************************************/
float Resta(float A,float B)
{
    return A-B;
}
/**************************************************/
float Division(float A,float B)
{
    while(B==0)
    {
        printf("ERROR!!!!!\nEl denominador debe ser distinto de cero\n\n");
        B=CapturaNro();
        system("cls");
    }
    return A/B;
}
/**************************************************/
float Multiplicacion(float A,float B)
{
    return A*B;
}
/**************************************************/
 float ValidaRango(float X, int Min, int Max)
 {
       while(!(X>=Min && X<=Max))
    {
        printf("Numero fuera de rango para realizar la operacion\n\n");
        X=CapturaNro();
    }
return X;
}
/**************************************************/
int ValidaCargaFlags(int FlagA, int FlagB)
{
int aux=1;

if(FlagA==0 || FlagB==0)
    {
        printf("ERROR\n\nFaltan cargar operadores\n\n");
        aux=0;
    }
return aux;
}
/**************************************************/
int Factorial(int A)
{
    int f;

    if(A!=1)
    {
        f=A*Factorial(A-1);
    }
    else
    {
        f=1;
    }
    return f;
}
/**************************************************/







