#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    char nombre[50];
    int edad;
    int estado;
    int dni;
}EPersona;

int capValidaYchequaRangoNro(int* imput, char mensajePedido[],char mensajeError[],int RangoMin, int RangoMax);
int capValidaYchequaRangoStr(char input[], char mensajePedido[],char mensajeError[],char RangoMin, char RangoMax);
unsigned int ValidaSeguirSoN(char mensajeError[]);
void pideYacomodaApellidoNombre(EPersona* persona,int i);
void initCampo(EPersona* unaPersona, int tamanio);
int buscaPrimerVacio(EPersona* persona, int tamanio);
void addPersona(EPersona* persona, int i, int tamanio);
void borraPersona(EPersona* persona, int tamanio);
int ordenaPersonaPorNombre(EPersona* persona, int tamanio);
void imprimePersonas(EPersona* persona, int tamanio);
int contadorPorRango(EPersona* persona, int tamanio, int RangoMin, int RangoMax );
void graficaRangos(int cont1, int cont2, int cont3);









/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible, (-1)
 */
///int obtenerEspacioLibre(EPersona lista[]);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
///int buscarPorDni(EPersona lista[], int dni);


#endif // FUNCIONES_H_INCLUDED

