#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include "validations.h"
#include "lib.h"

#define TAM 100


/** \brief Inicializa el campo isEmpty del array de estructuas EMovies
 *
 * \param movie EMovies* direccion de memoria inicial del array de estructuras EMovies
 * \param longitud int longitud del array de estructuras
 * \return void
 *
 */
void inicializa_isEmpty(EMovies* movie, int longitud)
{
    int i;

    for(i=0; i<longitud; i++)
    {
        movie[i].isEmpty=1;
    }
}
/** \brief Busca la primer posicion vacia del array de estructuras
 *
 * \param movie EMovies* posicion de memoria inicial del array de estructuras
 * \param tamanio int tamanio int tamaño del array de estructuras
 * \return int (-1) si esta lleno (i) el indice de la posicion vacia
 *
 */
int buscaPrimerVacio(EMovies* movie, int longitud)
{
    int i, retorno=-1;

    if(longitud>0 && movie!=NULL)
    {
        for(i=0; i<longitud; i++)
        {
            if(movie[i].isEmpty==1)
            {
                retorno=i;
                break;
            }
        }
        if(retorno==-1)
            printf("No hay espacio para agregar datos\n");
    }
    return retorno;
}
/** \brief Verifica si hay alguna pelicula cargada en el array de estructuras
 *
 * \param movie EMovies* posicion de memoria inicial del array de estructuras
 * \param tamanio int tamanio int tamaño del array de estructuras
 * \return int (0) si hay pelicula (-1) si no hay peliculas
 *
 */
int verificaPeliculaExistente(EMovies* movie, int longitud)
{
    int i, retorno=-1;

    if(longitud>0 && movie!=NULL)
    {
        for(i=0; i<longitud; i++)
        {
            if(movie[i].isEmpty==0)
            {
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}
/** \brief Verifica si existe un avion cargado de acuerdo a si ya existe la matricula
 *
 * \param movie EMovies* posicion de memoria inicial del array de estructuras
 * \param existe[] char mensaje a mostrar si existe
 * \param noExiste[] char mensaje a mostrar si no existe
 * \param strNuevo[] char
 * \param longitud int longitud del array de estructuras
 * \return int (-1) si no existe, (i) el indice donde se repite movie[i].titulo
 *
 */
int verificaSiExisteMovie(EMovies* movie,char existe[],char noExiste[], char auxTitulo[], int longitud)
{
    int i, retorno=-1;

    for(i=0; i<longitud; i++)
    {
        if(movie[i].isEmpty==0 && (strcmp(movie[i].titulo,auxTitulo)==0))
        {
            puts(existe);
            retorno=i;
            break;
        }
    }
    if(retorno==-1)
    {
        puts(noExiste);
    }
    return retorno;
}
/** \brief Alta de un avion en un array de estructuras a partir de una matricula nueva no existente
 *
 * \param movie EMovies* posicion de memoria inicial del array de estructuras
 * \param indiceVacio int  posicion vacia del array de estructuras donde cargar los datos
 * \param longitud int longitud del array de estructuras
 * \return void
 *
 */
void nuevaMovie(EMovies* movie, int indiceVacio, int longitud)
{
    char auxTitulo[150];
    int temp;

    if(longitud>0 && movie!=NULL)
    {

        do
        {
            do
            {
                capValidaYchequaRangoStrLibre(auxTitulo,"Ingrese el titulo de la pelicula",2,150);
            }
            while(temp==-1);
            temp=verificaSiExisteMovie(movie,"La pelicula ingresada ya existe","Pelicula ingresada correctamente",auxTitulo,longitud);
        }
        while(temp!=-1);

        strcpy(movie[indiceVacio].titulo,auxTitulo);
        do
        {
            temp=capValidaYchequaRangoStr(movie[indiceVacio].genero,"Ingrese el genero",1,20);
        }
        while(temp==-1);

        do
        {
            temp=capValidaYchequaRangoInt(&movie[indiceVacio].duracion,"Ingrese la duracion de la pelicula en minutos","ERROR ingrese los minutos correctamente, maximo 300 min",1,300);
        }
        while(temp==-1);

        do
        {
            temp=capValidaYchequaRangoInt(&movie[indiceVacio].puntuacion,"Ingrese puntuacion de 1 a 5","ERROR solo evaluar de 1 a 5",1,5);
        }
        while(temp==-1);

        do
        {
            temp=capValidaYchequaRangoStrLibre(movie[indiceVacio].link,"Ingrese el link de la imagen",2,128);
        }
        while(temp==-1);

        do
        {
            temp=capValidaYchequaRangoStrLibre(movie[indiceVacio].descripcion,"Ingrese la descripcion de la pelicula",2,255);
        }
        while(temp==-1);

        movie[indiceVacio].isEmpty=0;
    }
}
/** \brief Baja logica de un avion a partir de una matricula existente, cambiendo el capo estado a 1
 *
 * \param movie EMovies* posicion de memoria inicial del array de estructuras
 * \param longitud int longitud del array de estructuras
 * \return void
 *
 */
void baja(EMovies* movie, int longitud)
{
    int temp;
    char auxStr[150];

    if(longitud>0 && movie!=NULL)
    {
        do
        {
            capValidaYchequaRangoStrAlfaNro(auxStr,"Ingrese la pelicula a borrar",2,150);
            temp=verificaSiExisteMovie(movie,"La matricula ingresada correctamente","La Matricula no existe",auxStr,TAM);
        }
        while(temp==-1);
        printf("Confirma baja ???");
        if(ValidaSeguirSoN("s para modificar, n para continuar"))
            movie[temp].isEmpty=1;
    }
}
/** \brief Guarda la informacion en un archivo binario
 *
 * \param movie EMovies* posicion de memoria inicial del array de estructuras
 * \return int
 *
 */
int saveBin(EMovies* movie, int length)
{
    FILE *f;

    f=fopen("bin.dat","wb");
    if(f == NULL)
    {
        return 1;
    }

    fwrite(movie,sizeof(EMovies),length,f);
    fclose(f);

    return 0;
}
/** \brief Contador de posiciones en archivo
 *
 * \param movie EMovies* posicion de memoria inicial del array de estructuras
 * \param length int longitud del array de estructuras
 * \return int el numero usado como cantidad de elementos del array
 *
 */
int loadlengthToFile(EMovies* movie, int length)
{
    int flag=0, retorno=1;
    FILE *f;

    f=fopen("bin.dat", "rb");
    if(f==NULL)
    {
        f= fopen("bin.dat", "wb");
        if(f==NULL)
        {
            retorno=1;
        }

        flag=1;
    }

    if(flag==0)
    {
        fread(movie,sizeof(EMovies),length,f);
        retorno=0;
    }

    fclose(f);
    return retorno;
}
/** \brief Carga el array de estructuras con los datos del archivo binarios bin.dat
 *
 * \param movie EMovies* posicion de memoria inicial del array de estructuras
 * \param length int longitud del array de estructuras
 * \return int
 *
 */
int loadFromFile(EMovies* movie, int length)
{
    int flag = 0, auxReturn=0;
    FILE *f;

    f=fopen("bin.dat", "rb");
    if(f==NULL)
    {
        f= fopen("bin.dat", "wb");
        if(f==NULL)
        {
            auxReturn=1;
        }
        flag=1;
    }

    if(flag ==0)
    {
        fread(movie,sizeof(EMovies),length,f);
        auxReturn=0;
        printf("Archivo cargado con exito\nEnter para continuar...");
        getche();
    }
    fclose(f);
    return auxReturn;

}
/** \brief crea el html de las peliculas
 *
 * \param movie EMovies* posicion de memoria inicial del array de estructuras
 * \param length int longitud del array de estructuras
 * \return void
 *
 */
void createHTML(EMovies* movie, int length)
{
    int i;
    FILE *f;
    f=fopen("movies.html", "w");

    if(f == NULL)
    {
        printf("No se pudo abrir el archivo\n");
    }
    else
    {
        fprintf(f,"<!DOCTYPE html>\n");
        fprintf(f,"<!-- Template by Quackit.com -->\n");
        fprintf(f,"<html lang='en'>\n");
        fprintf(f,"<head>\n");
        fprintf(f,"    <meta charset='utf-8'>\n");
        fprintf(f,"    <meta http-equiv='X-UA-Compatible' content='IE=edge'>\n");
        fprintf(f,"    <meta name='viewport' content='width=device-width, initial-scale=1'>\n");
        fprintf(f,"    <!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->\n");
        fprintf(f,"    <title>Lista peliculas</title>\n");
        fprintf(f,"    <!-- Bootstrap Core CSS -->\n");
        fprintf(f,"    <link href='css/bootstrap.min.css' rel='stylesheet'>\n");
        fprintf(f,"    <!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles -->\n");
        fprintf(f,"    <link href='css/custom.css' rel='stylesheet'>\n");
        fprintf(f,"    <!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->\n");
        fprintf(f,"    <!-- WARNING: Respond.js doesn't work if you view the page via file:// -->\n");
        fprintf(f,"    <!--[if lt IE 9]>\n");
        fprintf(f,"        <script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script>\n");
        fprintf(f,"        <script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script>\n");
        fprintf(f,"    <![endif]-->\n");
        fprintf(f,"</head>\n");
        fprintf(f,"<body>\n");
        fprintf(f,"    <div class='container'>\n");
        fprintf(f,"        <div class='row'>\n");

        ///==================parte distinta por cada pelicula ==================
        for(i=0; i<length; i++)
        {
            if(movie[i].isEmpty==0)
            {
                fprintf(f,"            <article class='col-md-4 article-intro'>\n");
                fprintf(f,"                <a href='#'>\n");
                fprintf(f,"                    <img class='img-responsive img-rounded' src='%s' alt=''>\n",movie[i].link);
                fprintf(f,"                </a>\n");
                fprintf(f,"                <h3>\n");
                fprintf(f,"                    <a href='#'>%s</a>\n",movie[i].titulo);
                fprintf(f,"                </h3>\n");
                fprintf(f,"                                <ul>\n");
                fprintf(f,"                                        <li>Genero:%s</li>\n",movie[i].genero);
                fprintf(f,"                                        <li>Puntaje:%d</li>\n",movie[i].puntuacion);
                fprintf(f,"                                        <li>Duracion:%d min</li>                                   \n",movie[i].duracion);
                fprintf(f,"                                </ul>\n");
                fprintf(f,"                <p>%s</p>\n",movie[i].descripcion);
                fprintf(f,"            </article>\n");
            }
        }

        ///========================================================================

        fprintf(f,"        </div>\n");
        fprintf(f,"        <!-- /.row -->\n");
        fprintf(f,"    </div>\n");
        fprintf(f,"    <!-- /.container -->\n");
        fprintf(f,"    <!-- jQuery -->\n");
        fprintf(f,"    <script src='js/jquery-1.11.3.min.js'></script>\n");
        fprintf(f,"    <!-- Bootstrap Core JavaScript -->\n");
        fprintf(f,"    <script src='js/bootstrap.min.js'></script>\n");
        fprintf(f,"        <!-- IE10 viewport bug workaround -->\n");
        fprintf(f,"        <script src='js/ie10-viewport-bug-workaround.js'></script>\n");
        fprintf(f,"        <!-- Placeholder Images -->\n");
        fprintf(f,"        <script src='js/holder.min.js'></script>\n");
        fprintf(f,"</body>\n");
        fprintf(f,"</html>\n");
    }


    fclose(f);

    printf("Listado creado con exito\n");
    system("pause");
}
