/******************************************************************
* TP 3  LABORATORIO 1
*
* Objetivo: Realizar un programa que permita agregar,
*           borrar y modificar peliculas en un archivo binario.
*
*
* Version: 1.0 27/05/2016
*
* Autor: Daniel Ruben de Brito  1ºEº
*
*******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include "validations.h"
#include "lib.h"

#define TAM 100


int main()

{
    int opcion, seguir;

    EMovies movie[TAM];

    inicializa_isEmpty(movie,TAM);
    loadFromFile(movie,TAM);

    do
    {
        do
        {
            system("cls");
            printf("1- Agregar Pelicula\n");
            printf("2- Borrar Pelicula\n");
            printf("3- Modificar Pelicula\n");
            printf("4- Generar Pagina Web y guardar cambios\n");
            printf("5- Salir\n");
        }
        while(capValidaYchequaRangoInt(&opcion,"\nIngrese la opcion del menu deseada: ","ERROR!!, NO es una opcion del menu valida",1,5)==1);

        switch(opcion)
        {
        case 1:/**< Agregar Pelicula */
            system("cls");
            if(buscaPrimerVacio(movie, TAM) != (-1))
                nuevaMovie(movie,buscaPrimerVacio(movie,TAM),TAM);
            break;
        case 2:/**< Borrar Pelicula */
            system("cls");
            if((verificaPeliculaExistente(movie,TAM))==0)
                baja(movie,TAM);
            else
                printf("No hay ninguna pelicula ingresada");
            break;
        case 3:/**< Modificar Pelicula */
            system("cls");
            if((verificaPeliculaExistente(movie,TAM))==0)
                editMovie(movie,TAM);
            else
                printf("No hay ninguna pelicula ingresada");
            break;
        case 4:/**< Generar Pagina Web */
            system("cls");
            if((verificaPeliculaExistente(movie,TAM))==0)
            {
                saveBin(movie,TAM);
                createHTML(movie,TAM);
            }
            else
                printf("No hay ninguna pelicula ingresada");
            break;
        case 5:/**< salir */
            system("cls");
            seguir=0;
            break;
        }///fin de switch
        if(seguir==0)
            break;
    }
    while((seguir=ValidaSeguirSoN("Ingrese  s:  retornar menu - n:  para salir")));

    return 0;
}

