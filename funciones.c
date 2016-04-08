#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include "funciones.h"

/******************************************************************************/

/** \brief Valida el ingreso de un char, para admitir solo 's', 'n', 'S' o 'N'.
 *
 * \return O Si el usuario ingreso 'n' o 'N', 1 si el usuario ingresó 'S' o 's'.
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

/******************************************************************************/

/** \brief Captura un numero ingresado por el usuario
 *
 * \return Numero ingresado por el usuario
 *
 */
int CapturaNro()
{
    int A;
    printf("Ingrese un numero : \n\n");
    scanf("%d",&A);
    return A;
}
/******************************************************************************/

/** \brief Suma dos int
 *
 * \param A primer operando
 * \param B segundo operando
 * \return suma de los operandos
 *
 */
int Suma(int A,int B)
{
    return A+B;
}
/******************************************************************************/

/** \brief Resta dos int
 *
 * \param A primer operando
 * \param B segundo operando
 * \return resta de los operandos
 *
 */
int Resta(int A,int B)
{
    return A-B;
}
/******************************************************************************/

/** \brief Divide dos float
 *
 * \param A primer operando
 * \param B segundo operando
 * \return divicion de los operandos
 *
 */
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
/******************************************************************************/

/** \brief Multiplica dos int
 *
 * \param A primer operando
 * \param B segundo operando
 * \return producto de los operandos
 *
 */
int Multiplicacion(int A,int B)
{
    return A*B;
}
/******************************************************************************/

/** \brief Calcula el factorial de un numero
 *
 * \param A operando
 * \return factorial del operando
 *
 */
int Factorial(int A)
{
    int f;

    if(A!=0)
    {
        f=A*Factorial(A-1);
    }
    else
    {
        f=1;
    }
    return f;
}
/******************************************************************************/

 /** \brief Valida si un numero esta dentro de un rango determinado incluyendo los extremos
 *
 * \param Min extremo inferior
 * \param Max extremo superior
 * \return 0 si esta fuera de rango, 1 si esta dentro del rango
 *
 */
 int ValidaRango(int X, int Min, int Max)
 {
    int retorno=0;

    if(!(X>=Min && X<=Max))
    {
        retorno =1;
    }
return retorno;
}
/******************************************************************************/

/** \brief Valida si dos flags tienen asignado el valor 1
 *
 * \param FlagA primer flag
 * \param FlagB segundo flag
 * \return 0 si uno de los dos flag esta en cero, 1 si los dos flag estan en uno
 *
 */
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
/******************************************************************************/

