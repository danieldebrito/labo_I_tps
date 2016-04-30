/******************************************************************
*TP NRO 2 / Programación I – Laboratorio I
*
*Objetivo: Definir una estructura que represente a personas,
*          con los campos Nombre, Edad, DNI y flag de Estado.
*
*
*Version: 1.0 28/04/2016
*
*Autor: Daniel Ruben de Brito
*
*******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include "funciones.h"

#define TAM 20

int main()
{
    int opcion, seguir, nroValidoOk;
    EPersona persona[TAM];

    initCampo(persona, TAM);/**< Inicializa campo flag en (1) = vacio. [nota: (0)= lleno] */

    do{
    system("cls");
    printf("1- Agregar persona\n");
    printf("2- Borrar persona\n");
    printf("3- Imprimir lista ordenada por  nombre\n");
    printf("4- Imprimir grafico de edades\n\n");
    printf("5- Salir\n");

    do{
    nroValidoOk=capValidaYchequaRangoNro(&opcion,"\nIngrese la opcion del menu deseada: ","ERROR!!, NO es una opcion del menu valida",1,5);
    }while(nroValidoOk==-1);

    switch(opcion)
    {
        case 1:/**< agregar persona */
            system("cls");
            if(buscaPrimerVacio(persona, TAM) != (-1))
                {
                    addPersona(persona, buscaPrimerVacio(persona, TAM),TAM);
                }
            break;
        case 2:/**< borrar persona */
            system("cls");
            borraPersona(persona, TAM);
            break;
        case 3:/**< imprimir lista ordenada por nombre */
            system("cls");
            ordenaPersonaPorNombre(persona, TAM);
            imprimePersonas(persona, TAM);
            break;
        case 4:/**< imprimir grafico de edades */
            system("cls");
            graficaRangos(contadorPorRango(persona,TAM,1,18),contadorPorRango(persona,TAM,19,35),contadorPorRango(persona,TAM,36,100));
            break;
        case 5:/**< salir */
            system("cls");
            seguir=0;
            break;
    }///fin de switch
    if(seguir==0)
        break;
    }while((seguir=ValidaSeguirSoN("Error, ingrese correctamente: s o n")));
return 0;
}///fin de main
