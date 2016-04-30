#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include "funciones.h"

/***********************************************************************************************************************/
/** \brief Valida el ingreso de un char de respuesta, para admitir solo 's' 'S' como "SI", y 'n', o 'N' como "NO".
 *
 * \param mensajeError[] char el mensaje a mostrar en caso de error
 * \return unsigned int  (O) Si el usuario ingreso 'n' o 'N'; (1) si el usuario ingresó 'S' o 's'.
 *
 */
unsigned int ValidaSeguirSoN(char mensajeError[])
{
    char rta;

    printf("\n\n  s : para seguir   -   n : para salir\n\n");
    rta=toupper(getche());
    while(!((rta=='S')||(rta=='N')))
    {
        puts(mensajeError);
        rta=toupper(getche());
    }
    return (rta=='S');
}

/***********************************************************************************************************************/
/** \brief Pide un int al usuario, valida que sea solo numero y chequea un rango con los limites incluidos
 *
 * \param imput int* la dir de memoria de la variable a validar
 * \param mensajePedido[] char mensaje de pedido de numero
 * \param mensajeError[] char mensaje de error
 * \param RangoMin int limite inferior incluyendolo del rango a validar
 * \param RangoMax int limite superior incluyendolo del rango a validar
 * \return int (0) SI ES VALIDO, (-1) SI NO ES VALIDO
 *
 */
int capValidaYchequaRangoNro(int* imput, char mensajePedido[],char mensajeError[],int RangoMin, int RangoMax)
{
    int retorno=0,validoScanf, valor;
    puts(mensajePedido);
    fflush(stdin);
    validoScanf=scanf("%d",&valor); ///valida retorno de scanf si ingreso tipo de dato correcto o no de acuerdo a la mascara

    if((validoScanf!=1)||(!(valor>=RangoMin && valor<=RangoMax)))
    {
        puts(mensajeError);
        retorno=-1;
    }
    else
    {
        *imput=valor;
    }
    return retorno;
}
/***********************************************************************************************************************/
/** \brief Pide un string al usuario, valida que sea solo letras y chequea un rango con los limites incluidos
 *
 * \param input[] char
 * \param mensajePedido[] char mensaje de pedido de numero
 * \param mensajeError[] char mensaje de error
 * \param RangoMin char limite inferior incluyendolo del rango a validar
 * \param RangoMax char limite superior incluyendolo del rango a validar
 * \return int (0) SI ES VALIDO, (-1) SI NO ES VALIDO
 *
 */
int capValidaYchequaRangoStr(char input[], char mensajePedido[],char mensajeError[],char RangoMin, char RangoMax)
{

    int retorno=0, validoScanf, largo;
    char auxstr[60];
    puts(mensajePedido);
    fflush(stdin);
    validoScanf=scanf("%s",auxstr); ///valida retorno de scanf si ingreso tipo de dato correcto o no de acuerdo a la mascara
    largo=strlen(auxstr);

    if((validoScanf==1)&&(largo>=RangoMin && largo<=RangoMax))
    {
        strcpy(input,auxstr);
    }
    else
    {
        puts(mensajeError);
        retorno=-1;
    }
    return retorno;
}
/***********************************************************************************************************************/
/** \brief Inicializacion logica de campo persona[i].estado a modo de flag, asignandole (1) =  vacio (nota: (0) = lleno)
 *
 * \param persona EPersona* la posicion de memoria inicial del array de estructuras
 * \param tamanio int tamaño del array de estructuras
 * \return void
 *
 */
void initCampo(EPersona* persona, int tamanio)
{
    int i;

    if(tamanio>0 && persona!=NULL)  ///chequea tamaño correcto y posicion de memoria valida
    {
        for(i=0;i<tamanio;i++)
        {
            persona[i].estado=1;
        }
    }
}
/***********************************************************************************************************************/
/** \brief Busqueda logica de la primera posicion vacia en campo persona[i].estado
 *         que funciona a modo de flag, (1) = vacio, (0) = lleno.
 *
 * \param persona EPersona* la posicion de memoria inicial del array de estructuras
 * \param tamanio int  tamaño del array de estructuras
 * \return int (i) Indice de primera posicion de memoria vacia del array de estructuras,
 *                (-1) si el array esta completamente lleno.
 *
 */
int buscaPrimerVacio(EPersona* persona, int tamanio)
{
    int i, retorno=-1;

    if(tamanio>0 && persona!=NULL)
    {
        for(i=0;i<tamanio;i++)
        {
            if(persona[i].estado==1)
            {
                retorno=i;
                break;  /// sale de la iteracion en caso de encontrar vacio.
            }
        }
        if(retorno==-1)
            printf("No hay espacio para agregar datos\n");
    }
    return retorno;
}
/***********************************************************************************************************************/
/** \brief Solicita al usuario nombre y apellido, luego lo acomoda a la forma Apellido, Nombre
 *          Soporta nombre y apellido de 50 caracteres contando espacio y coma.
 *
 * \param persona EPersona* posicion de memoria inicial del array de estructuras
 * \param j int indice del array de estructuras donde cargar la cadena en el campo persona[j].nombre.
 * \return void
 *
 */
void pideYacomodaApellidoNombre(EPersona* persona, int j)
{
    int i, auxIsapha;
    char nombre[20];
    char apellido[28];
    char auxCaptura[250];
    char auxiliar[50]; ///necesito un array de 48 + es espacio + la coma => 50

    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(auxCaptura);

    for(i=0; auxCaptura[i]!= '\0'; i++)  /// recorre la cadena hasta encontrar el indicador de fin
    {
        if(isalpha(auxCaptura[i])==0) /// chequea que todos sean caracteres no numericos
        {
            auxIsapha=0;
        }
        else
        {
            auxIsapha=1;
        }
    }

    while((strlen(auxCaptura)>20) || auxIsapha==0) /// chequea el largo de la cadena y el flag de isalpha
    {
        printf("ERROR!!! el nombre debe tener solo caracteres con un maximo 20\n");
        printf("Ingrese nombre: ");
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
    strcpy(nombre,auxCaptura); /// asigna la cadena validada a "nombre"

    printf("\nIngrese apellido: ");
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
        printf("\nIngrese apellido: ");
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
    strcpy(persona[j].nombre,auxiliar); /// asigna al campo de la estructura la cadena validada y formateada
}
/***********************************************************************************************************************/
/** \brief Baja logica de la posicion buscada mediante el nro de DNI comparado con el campo persona[i].dni
 *         si encuentra coincidencia asigna al campo persona[i].estado el valor 1
 *         que funciona a modo de flag, 1 indica vacio, (nota: 0 lleno).
 *
 * \param persona EPersona* la posicion de memoria inicial del array.
 * \param tamanio int Tamaño del array de estructuras.
 * \return void
 *
 */
void borraPersona(EPersona* persona, int tamanio)
{
    int i, dni, nroValidoOk, flag=0;

    if(tamanio>0 && persona!=NULL)
    {
        do{
        nroValidoOk=capValidaYchequaRangoNro(&dni,"Ingrese el DNI de la persona a borar: ","ERROR!!, El numero ingresado no es un DNI valido\n",1000000,99999999);
        }while(nroValidoOk==-1);   /// valida numero y rango correcto

        for(i=0;i<tamanio;i++)
            {
                if(persona[i].dni==dni)
                {
                    if(persona[i].estado==0)
                    {
                        persona[i].estado=1;  ///cambia el flag de estado a vacio.
                        printf("El DNI fue borrado exitosamente");
                        flag=1;
                    }
                }
            }
            if(flag==0)
            {
                printf("El DNI ingresado no existe");
            }
    }
}
/***********************************************************************************************************************/
/** \brief Ordenamiento por burbujeo del campo persona[i].nombre en forma creciente.
 *
 *
 * \param persona EPersona* la posicion de memoria inicial del array.
 * \param tamanio int Tamaño del array de estructuras.
 * \return int (-1) si hay error (0) si no hay error.
 *
 */
int ordenaPersonaPorNombre(EPersona* persona, int tamanio)
{
    EPersona aux;
    int i, j, result=-1;

    if(tamanio>0&&persona!=NULL)
    {
        for(i=0;i<tamanio-1;i++)
        {
            for(j=i+1;j<tamanio;j++)
            {
                if(strcmp(persona[i].nombre,persona[j].nombre)>0)
                {
                    aux=persona[i];
                    persona[i]=persona[j];
                    persona[j]=aux;
                }
            }
        }
        result=0;
    }
    return result;
}
/***********************************************************************************************************************/
/** \brief  Imprime en pantalla el array de estructuras completo.
 *
 * \param persona EPersona* la posicion de memoria inicial del array.
 * \param tamanio int Tamaño del array de estructuras.
 * \return void
 *
 */
void imprimePersonas(EPersona* persona, int tamanio)
{
    int i;

    if(tamanio>0&&persona!=NULL)
    {
        for(i=0;i<tamanio;i++)
        {
            if(persona[i].estado==0)  /// imprime solo los indices del array de estructuras con el flag de estado indicando lleno
            {
                printf("\n  Apellido y Nombre:\t%s\n",persona[i].nombre);
                printf("               Edad:\t%d\n",persona[i].edad);
                printf("                DNI:\t%d\n\n",persona[i].dni);
            }
        }
    }
}
/***********************************************************************************************************************/
/** \brief Busca y chequea si un DNI a ingresar ya esta en uso.
 *
 * \param Epersona *persona: Puntero tipo estructura con la posicion de memoria inicial del array.
 * \param tamanio int: Tamaño del array de estructuras.
 * \param dni int: numero de DNI a chequear si esta en uso.
 * \return int (0) si no esta en uso, (1) si estaba en uso.
 *
 */
int buscaDniEnUso(EPersona* persona, int tamanio, int dni)
{
    int i, retorno=0;

    if(tamanio>0&&persona!=NULL)
    {
        for(i=0;i<tamanio;i++)
        {
            if(persona[i].dni==dni && persona[i].estado==0)  /// busca en los indices con el flag de estado (0) indicando lleno
            {
                retorno=1;
                break;
            }
        }
    }
    return retorno;
}
/***********************************************************************************************************************/
/** \brief Solicita al usuario los datos a ingresar en cada campo de la estructura en la posicion indicada
 *
 * \param persona EPersona* : Puntero tipo structura con la posicion de memoria inicial.
 * \param i int: Indice de la posicion del array donde se cargaran todos los datos.
 * \param tamanio int: Tamaño del array de estructuras.
 * \return void
 *
 */
void addPersona(EPersona* persona, int i, int tamanio)
{
    int auxDni, edad, dniOk=0, nroValidoOk;

    if(tamanio>0&&persona!=NULL)
    {

    while(dniOk==0) /// para salir del case en el swicth y volver al menu en caso de dni ya usado
    {
        do{
        nroValidoOk=capValidaYchequaRangoNro(&auxDni,"Ingrese el DNI: ","Error, El numero ingresado no es un DNI valido\n",1000000,99999999);
        }while(nroValidoOk==-1);

        if(buscaDniEnUso(persona, tamanio, auxDni)==0)
        {
            persona[i].dni=auxDni;
            persona[i].estado=0;
            dniOk=1;  /// cambia estado al falg para salir del do while
        }
        else
        {
            puts("\nATENCION!!\nEl DNI ingresado ya esta en uso\nNo es posible utilizarlo nuevamente\n");
            persona[i].estado=1;
            break;  /// para salir del case en el swicth y volver al menu
        }

    pideYacomodaApellidoNombre(persona,i);

    do{
    nroValidoOk=capValidaYchequaRangoNro(&edad,"Ingrese la edad: ","Error, El numero ingresado no es una edad valida\n",1,100);
    }while(nroValidoOk==-1);
    persona[i].edad=edad;
    }
    }
}
/***********************************************************************************************************************/
/** \brief recorre el campo persona[i].edad==1, y genera un contador de veces que un int esta incluido en rango parametrizado.
 *
 * \param persona EPersona* posicion de memoria inicial del array de estructuras
 * \param tamanio int: Tamaño del array de estructuras.
 * \param RangoMin int limite inferior del rango incluyendolo
 * \param RangoMax int limite superior del rango incluyendolo
 * \return int (-1) para error
 *
 */
int contadorPorRango(EPersona* persona, int tamanio, int RangoMin, int RangoMax)
{
    int i, cont=0;

    if(tamanio>0)
    {
        for(i=0;i<tamanio;i++)
        {
            if(persona[i].estado==0 && (persona[i].edad>=RangoMin && persona[i].edad<=RangoMax))  /// cuenta solo si el campo flag estado indica lleno
            {
                cont++;
            }
        }
    }
    return cont;
}
/***********************************************************************************************************************/
/** \brief Genera un grafico de barras, donde el eje marca la cantidad de personas pertenecientes a un grupo,  detallado en eje x.
 *
 * \param cont1 int  primer grupo de edades pertenecientes al rango >18
 * \param cont2 int  segundo grupo de edades pertenecientes al rango 19-35
 * \param cont3 int  tercer grupo de edades pertenecientes al rango <36
 *
 */
void graficaRangos(int cont1, int cont2, int cont3)
{
    int i, max;
    char asterisco='*', espacio=' '; /// variables pre cargadas con asterisco y espacio
    char print1, print2, print3;

    if(cont1>=cont2 && cont1>=cont3)  /// busca el maximo para establecer el tamaño del indice
    {
        max=cont1;
    }
    else
    {
        if(cont2>=cont1 && cont2>=cont3)
        {
            max=cont2;
        }
        else
        {
            max=cont3;
        }
    }

    for(i=max;i>=1;i--)  /// compara cada contador que indica cant de personas en el grupo y lo compara con el indice=max, asignando espacio o asterisco
    {
        if(cont1>=i)
            print1=asterisco;
        else
            print1=espacio;

        if(cont2>=i)
            print2=asterisco;
        else
            print2=espacio;

        if(cont3>=i)
            print3=asterisco;
        else
            print3=espacio;
    printf("%02d\t%c\t%c\t%c\t\n",i, print1,print2,print3);  /// imprime las barras con tantas filas como el indice lo indique
    }///for

    printf("\n       <18    19-35    >35\n\n");
}
/***********************************************************************************************************************/
