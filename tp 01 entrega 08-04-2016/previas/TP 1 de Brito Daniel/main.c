#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include "funciones.h"

float CapturaNro();
unsigned int ValidaRtaSoN(void);
float ValidaDenominador(float nro);
float MayorIgual(int min,float x);

float Suma(float A,float B);
float Resta(float A,float B);
float Division(float A,float B);
float Multiplicacion(float A,float B);
float Factorial(float A);

int main()
{
    unsigned int opcion,rta=1;
    float x,y;

    printf("\n\n\n\n\n  ======  ");
    printf("CALCULADORA 1.0");
    printf("  ======  \n\n\n\n\n");
    printf("  ==  ENTER para opciones  ==  \n\n");

    getchar();
    system("cls");

    while(rta==1) // hacer do while
    {
        printf("1- Ingresar 1er operando (A=x)\n");
        printf("2- Ingresar 2do operando (B=y)\n");
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        printf("\nIngrese la opcion deseada\n\n");
        scanf("%d",&opcion);
        while((!(opcion>=1 && opcion<=9))) ////////////////  VALIDAR INGRES SOLO NUMERO, HACER !!!!!!!!!
        {
            printf("\n\nERROR!!!\n\nINGRESE UNA OPCION VALIDA\n\n");
            scanf("%d",&opcion);
        }

        switch(opcion)
        {
            case 1:
                system("cls");
                x=CapturaNro();
                system("cls");
                printf("\n\nPrimer operando ingresado : %.2f\n\n\n",x);
                break;
            case 2:
                system("cls");
                y=CapturaNro();
                system("cls");
                printf("\n\nSegundo operando ingresado : %.2f\n\n\n",y);
                break;
            case 3:
                system("cls");
                printf("\n\nEl resultado de la suma es : %.2f\n\n\n",Suma(x,y));
                break;
            case 4:
                system("cls");
                printf("\n\nEl resultado de la resta es : %.2f\n\n\n",Resta(x,y));
                break;
            case 5:
                system("cls");
                y=ValidaDenominador(y);
                system("cls");
                printf("\n\nEl resultado de la division es : %.2f\n\n\n",Division(x,y));
                break;
            case 6:
                system("cls");
                printf("\n\nEl resultado de la multiplicacion es : %.2f\n\n\n",Multiplicacion(x,y));
                break;
            case 7:
                system("cls");
                x=MayorIgual(1,x);
                system("cls");
                printf("\n\nEl factorial de %.2f  es : %.2f\n\n\n",x,Factorial(x));
                break;
            case 8:
                system("cls");
                y=ValidaDenominador(y);
                system("cls");
                x=MayorIgual(1,x);
                system("cls");
                printf("==================================\n");
                printf("\n\nEl resultado de la suma es : %.2f\n",Suma(x,y));
                printf("\n\nEl resultado de la resta es : %.2f\n",Resta(x,y));
                printf("\n\nEl resultado de la division es : %.2f\n\n",Division(x,y));
                printf("\n\nEl resultado de la multiplicacion es : %.2f\n",Multiplicacion(x,y));
                printf("\n\nEl factorial de %.2f  es : %.2f\n",x,Factorial(x));
                printf("\n==================================\n\n");
                break;
            case 9:
                return 0;

        } // FIN DE SWITCH



rta=ValidaRtaSoN(); /**< valida respuesta s o n */
if(rta==0)
{
return 0;
}

system("cls");

} // FIN DE WHILE

return 0;

} // fin de main

/** \brief pide y captura un float
 *
 * \param A valor capturado
 * \return A float
 *
 */

float CapturaNro()
{
    float A;

    printf("Ingrese un numero : \n\n");
    scanf("%f",&A);
    return A;
}

/** \brief suma dos numeros
 *
 * \param A primer sumando
 * \param B sesundo sumando
 * \return A+B suma de los dos float
 *
 */

float Suma(float A,float B)
{
    return A+B;
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */


float Resta(float A,float B)
{
    return A-B;
}

/** \brief divide dos numeros, valida denominador distinto de cero
 *
 * \param A numerador
 * \param B denominador
 * \return A/B
 *
 */


float Division(float A,float B)
{
    while(B==0) // RECOMENDABLE MANDAR DATO VALIDADO PARA EVITAR ESTO, USAR FUNCION float ValidaDenominador(float nro)
    {
    printf("ERROR!!!!!\nEL DENOMINADOR DEBE SER DISTINTO DE CERO\n\n");
    B=CapturaNro();
    system("cls");
    }

    return A/B;
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */


float Multiplicacion(float A,float B)
{
    return A*B;
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */


float Factorial(float A)
{
    int aux, fac=1;

    while(!(A>=1))
    {
    printf("ERROR!!!!!\n\n\nEL PRIMER OPERANDO DEBE SER MAYOR O IGUAL A CERO\n\n\n");
    A=CapturaNro();
    system("cls");
    printf("\n\nPrimer operando ingresado : %.2f\n\n\n",A);
    }

    for(aux=1;A>=aux;aux++)
    {
        fac=fac*aux;
    }

    return fac;
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

unsigned int ValidaRtaSoN(void)
{
char rta;    // ver de inicializar
printf("  s : para seguir   -   n : para salir\n\n");
rta=toupper(getche());
while(!((rta=='S')||(rta=='N')))
{
printf("\nERROR!!!\n\nINGRESE UNA RESPUESTA VALIDA");
rta=toupper(getche()); // tolower pasa a minuscula
}
return (rta=='S');
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

 float ValidaDenominador( float nro)
 {
    while(nro==0)
    {
        printf("\nERROR! DENOMINADOR IGUAL A CERO\n\nIngrese un numero distinto de cero : ");
        scanf("%f",&nro);
    }

return nro;
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

 float MayorIgual(int min,float x)
 {
       while(x<min)
    {
        printf("\nERROR! \n\nIngrese un numero mayor o igual a %d : ",min);
        scanf("%f",&x);
    }

return x;

}






