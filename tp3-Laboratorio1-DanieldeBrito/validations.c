#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include "validations.h"
#include "lib.h"

#define TAM 10


/** \brief Captura, valida  y chequea que un string este dentro de un rango de cantidad de caracteres con los limites incluidos
 *
 * \param input[] char Cadena a validar
 * \param mensajePedido[] char mensaje de pedido a mostrar
 * \param RangoMin char rango minimo de cantidad de caracteres
 * \param RangoMax char rango maximo de cantidad de caracteres
 * \return int (0) si esta ok, (-1) si hubo error
 *
 */
int capValidaYchequaRangoStr(char input[], char mensajePedido[],char RangoMin, char RangoMax)
{
    int retorno=0, i=0, flagSoloLetra=0,flagLargo=0;
    char auxstr[60];

    do
    {
        puts(mensajePedido);
        fflush(stdin);
        gets(auxstr);
        system("cls");
        flagLargo=0;
        flagSoloLetra=0;

        while(auxstr[i] != '\0')
        {
            if((auxstr[i] != ' ') && (auxstr[i] < 'a' || auxstr[i] > 'z') && (auxstr[i] < 'A' || auxstr[i] > 'Z'))
                flagSoloLetra=1;
            i++;
        }


        if(!(strlen(auxstr)>=RangoMin && strlen(auxstr)<=RangoMax))
        {
            flagLargo=1;
        }
        if(flagSoloLetra==1)
        {
            printf("ERROR!! debe ingresar solo letras\n");
            retorno=-1;
        }
        if(flagLargo==1)
        {
            printf("Error!! maximo %d , minimo %d caracteres\n",RangoMax,RangoMin);
            retorno=-1;
        }
    }
    while(flagLargo==1 || flagSoloLetra==1);

    strcpy(input,auxstr);

    return retorno;
}
/** \brief Captura, valida  y chequea que un string alfanumerico este dentro de un rango de cantidad de caracteres con los limites incluidos
 *
 * \param input[] char Cadena a validar
 * \param mensajePedido[] char mensaje de pedido a mostrar
 * \param RangoMin char rango minimo de cantidad de caracteres
 * \param RangoMax char rango maximo de cantidad de caracteres
 * \return int (0) si esta ok, (-1) si hubo error
 *
 */
int capValidaYchequaRangoStrAlfaNro(char input[], char mensajePedido[],char RangoMin, char RangoMax)
{
    int retorno=0, i=0, flagLargo=0,flagSoloLetra=0 ;
    char auxstr[255];

    do
    {
        puts(mensajePedido);
        printf("\n");
        fflush(stdin);
        gets(auxstr);
        system("cls");
        flagLargo=0;
        flagSoloLetra=0;

        while(auxstr[i] != '\0') /// recorre el array hasta el final '\0'
        {
            if((auxstr[i] != ' ') && (auxstr[i] < 'a' || auxstr[i] > 'z') && (auxstr[i] < 'A' || auxstr[i] > 'Z') && (auxstr[i] < '0' || auxstr[i] > '9'))
                flagSoloLetra=1;
            i++;
        } /// fin de while

        if(!(strlen(auxstr)>=RangoMin && strlen(auxstr)<=RangoMax))
        {
            flagLargo=1;
        }
        if(flagSoloLetra==1)
        {
            printf("ERROR!! debe ingresar solo letras o numeros\n");
            retorno=-1;
        }
        if(flagLargo==1)
        {
            printf("Error!! maximo %d , minimo %d caracteres\n",RangoMax,RangoMin);
            retorno=-1;
        }
    }
    while(flagLargo==1 || flagSoloLetra==1);

    strcpy(input,auxstr);

    return retorno;
}
/** \brief Captura, valida  y chequea que un int este dentro de un rango con los limites incluidos
 *
 * \param input int entero a validar
 * \param mensajePedido[] char mensaje de pedido a mostrar
 * \param RangoMin char rango minimo de cantidad de caracteres
 * \param RangoMax char rango maximo de cantidad de caracteres
 * \return int (0) si esta ok, (-1) si hubo error
 *
 */
int capValidaYchequaRangoInt(int* input, char mensajePedido[],char mensajeError[],int RangoMin, int RangoMax)
{
    int i=0, retorno=0, flagSoloNro=0, flagLargo=0;
    int auxInt;
    char auxStr[250];

    do
    {

        puts(mensajePedido);
        fflush(stdin);
        gets(auxStr);
        system("cls");
        flagLargo=0;
        flagSoloNro=0;

        while(auxStr[i] != '\0')
        {
            if(auxStr[i] < '0' || auxStr[i] > '9')
                flagSoloNro=1;
            i++;
        }
        if(flagSoloNro==1)
        {
            printf("ERROR!! debe ingresar solo numeros\n");
            retorno=-1;
            break;
        }
        auxInt = atoi(auxStr);
        if(!(auxInt>=RangoMin && auxInt<=RangoMax))
        {
            flagLargo=1;
        }
        if(flagLargo==1)
        {
            printf("Error!! maximo %d , minimo %d\n",RangoMax,RangoMin);
            retorno=-1;
        }
    }
    while(flagLargo==1 || flagSoloNro==1);

    *input=auxInt;

    return retorno;
}
/** \brief Captura, valida  y chequea que un float este dentro de un rango con los limites incluidos
 *
 * \param input float entero a validar
 * \param mensajePedido[] char mensaje de pedido a mostrar
 * \param RangoMin char rango minimo de cantidad de caracteres
 * \param RangoMax char rango maximo de cantidad de caracteres
 * \return int (0) si esta ok, (-1) si hubo error
 *
 */
int capValidaYchequaRangoFloat(float* input, char mensajePedido[],char mensajeError[],int RangoMin, int RangoMax)
{
    int i=0, retorno=0, flagSoloNro=0, flagLargo=0,cantidadPuntos=0;;
    float auxFloat;
    char auxStr[250];

    do
    {
        puts(mensajePedido);
        fflush(stdin);
        gets(auxStr);
        system("cls");
        flagLargo=0;
        flagSoloNro=0;

        while(auxStr[i] != '\0')
        {
            if (auxStr[i] == '.' && cantidadPuntos == 0)
            {
                cantidadPuntos++;
                i++;
                continue;
            }
            if(auxStr[i] < '0' || auxStr[i] > '9')
                flagSoloNro=1;
            i++;
        }
        if(flagSoloNro==1)
        {
            printf("ERROR!! debe ingresar solo numeros\n");
            retorno=-1;
            break;
        }
        auxFloat = atof(auxStr);
        if(!(auxFloat>=RangoMin && auxFloat<=RangoMax))
        {
            flagLargo=1;
        }
        if(flagLargo==1)
        {
            printf("Error!! maximo %d , minimo %d\n",RangoMax,RangoMin);
            retorno=1;
        }
    }
    while(flagLargo==1 || flagSoloNro==1);

    *input=auxFloat;

    return retorno;
}
/** \brief Solicita al  usuario una despuesta entre s o n para continuar
 *
 * \param mensaje[] char mensaje a mostrar para decidir 's' o 'n'
 * \return unsigned int  (1) para si 's' o 'S' - (0) para no 'n' o 'N'
 *
 */
unsigned int ValidaSeguirSoN(char mensaje[])
{
    char rta;

    printf("\n");
    puts(mensaje);
    rta=toupper(getche());
    system("cls");
    while(!((rta=='S')||(rta=='N')))
    {
        printf(" ERROR!! debe ingresar solo s o n\n");
        puts(mensaje);
        rta=toupper(getche());
        system("cls");
    }
    return (rta=='S');
}
/** \brief Valida si un numero  igresado tiene el fornmato de numero de telefono basico
 *
 * \param input[] char numero telefonico a validar
 * \param mensajePedido[] char Mensaje de pedido de numero de telefono
 * \param mensajeError[] char mensaje de error de numero de telefono mal ingresado
 * \return int (0) si esta ok (-1) si hubo error
 *
 */
int validaNroTelefono(char input[], char mensajePedido[], char mensajeError[])
{
    int i=0, retorno=0, contadorGuiones=0;
    char str[15];

    puts(mensajePedido);
    fflush(stdin);
    gets(str);

    do
    {
        while(str[i] != '\0')
        {
            if((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9'))
            {
                retorno=-1;
                puts(mensajeError);
                break;
            }
            if(str[i] == '-')
                contadorGuiones++;
            i++;
        }
        if(contadorGuiones==1) // debe tener un guion
            retorno=0;
    }
    while(retorno==-1);

    strcpy(input,str);

    return retorno;
}
/** \brief Valida si una direccion de mail igresado tiene el fornmato valido basico
 *
 * \param input[] char direccion de mail a validar
 * \param mensajePedido[] char Mensaje de pedido de numero de telefono
 * \param mensajeError[] char mensaje de error de numero de telefono mal ingresado
 * \return int (0) si esta ok  (-1) si hubo error
 *
 */
int validaMail(char input[], char mensajePedido[], char mensajeError[])
{
    int i=0, retorno=0, contadorArroba=0, contadorPuntos=0;
    char str[15];

    puts(mensajePedido);
    fflush(stdin);
    gets(str);

    do
    {
        while(str[i] != '\0')
        {
            if((str[i] != ' ') && (str[i] != '@') && (str[i] != '.') && (str[i] < '0' || str[i] > '9'))
            {
                retorno=-1;
                puts(mensajeError);
                break;
            }
            if(str[i] == '@')
                contadorArroba++;
            if(str[i] == '.')
                contadorPuntos++;

            i++;
        }
        if(contadorArroba==1) // debe tener un arroba
            retorno=0;
        if(contadorPuntos>=1) // debe tener por lo menos un punto
            retorno=0;
    }
    while(retorno==-1);

    strcpy(input,str);

    return retorno;
}
/** \brief Solicita al usuario patra luego dar formato de la sigioente manera:  Apellido, Nombre.
 *
 * \param apellNomb[] char cadena donde guardar el apellido y nombre con formato
 * \return void
 *
 */
void pideYacomodaApellidoNombre(char apellNomb[])
{
    int i, auxIsapha;
    char nombre[20];
    char apellido[28];
    char auxCaptura[250];
    char auxiliar[50];

    printf("Ingrese nombre: \n");
    fflush(stdin);
    gets(auxCaptura);

    for(i=0; auxCaptura[i]!= '\0'; i++)
    {
        if(isalpha(auxCaptura[i])==0)
        {
            auxIsapha=0;
        }
        else
        {
            auxIsapha=1;
        }
    }

    while((strlen(auxCaptura)>20) || auxIsapha==0)
    {
        printf("ERROR!!! el nombre debe tener solo caracteres con un maximo 20\n");
        printf("Ingrese nombre: \n");
        fflush(stdin);
        gets(auxCaptura);
        for(i=0; auxCaptura[i]!= '\0'; i++)
        {
            if(isalpha(auxCaptura[i])==0)
            {
                auxIsapha=0;
            }
            else
            {
                auxIsapha=1;
            }
        }
    }
    strcpy(nombre,auxCaptura);

    printf("\nIngrese apellido: \n");
    fflush(stdin);
    gets(auxCaptura);

    for(i=0; auxCaptura[i]!= '\0'; i++)
    {
        if(isalpha(auxCaptura[i])==0)
        {
            auxIsapha=0;
        }
        else
        {
            auxIsapha=1;
        }
    }

    while(strlen(auxCaptura)>28 || auxIsapha==0)
    {
        printf("ERROR!!! el apellido debe tener solo caracteres con un maximo 28\n");
        printf("\nIngrese apellido: \n");
        fflush(stdin);
        gets(auxCaptura);
        for(i=0; auxCaptura[i]!= '\0'; i++)
        {
            if(isalpha(auxCaptura[i])==0)
            {
                auxIsapha=0;
            }
            else
            {
                auxIsapha=1;
            }
        }
    }
    strcpy(apellido,auxCaptura);

    strcpy(auxiliar, apellido);///asigna apellido a auxiliar
    strcat(auxiliar, ", ");///concatena la coma y un espacio
    strcat(auxiliar, nombre);///concatena el nombre

    strlwr(auxiliar); ///pasa todo a minuscula

    auxiliar[0] = toupper(auxiliar[0]);///pasa la primer letra a mayuscula

    for(i=0; auxiliar[i]!= '\0'; i++)///recorre hasta que encuentre el fin del array
    {
        if(auxiliar[i] == ' ')///busca un espacio vacio
        {
            auxiliar[i+1] = toupper(auxiliar[i+1]);///paso a mayuscula la letra siguiente, seria la inicial del nombre o apellido
        }
    }
    strcpy(apellNomb,auxiliar); /// asigna al campo de la estructura la cadena validada y formateada

    system("cls");
}
/** \brief Captura, valida  y chequea que un string alfanumerico este dentro de un rango de cantidad de caracteres con los limites incluidos
 *
 * \param input[] char Cadena a validar
 * \param mensajePedido[] char mensaje de pedido a mostrar
 * \param RangoMin char rango minimo de cantidad de caracteres
 * \param RangoMax char rango maximo de cantidad de caracteres
 * \return int (0) si esta ok, (-1) si hubo error
 *
 */
int capValidaYchequaRangoStrLibre(char input[], char mensajePedido[],char RangoMin, char RangoMax)
{
    int retorno=0, flagLargo=0;
    char auxstr[255];

    do
    {
        puts(mensajePedido);
        printf("\n");
        fflush(stdin);
        gets(auxstr);
        system("cls");
        flagLargo=0;

        if(!(strlen(auxstr)>=RangoMin && strlen(auxstr)<=RangoMax))
        {
            flagLargo=1;
        }

        if(flagLargo==1)
        {
            printf("Error!! maximo %d , minimo %d caracteres\n",RangoMax,RangoMin);
            retorno=-1;
        }
    }
    while(flagLargo==1);

    strcpy(input,auxstr);

    return retorno;
}

