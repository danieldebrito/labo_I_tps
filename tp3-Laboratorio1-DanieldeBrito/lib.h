#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    char titulo[150];
    char genero[20];
    int duracion;
    char descripcion[1024];
    int puntuacion;
    char link[128];
    int isEmpty;
} EMovies;

/// funciones de array
void inicializa_isEmpty(EMovies* movie, int longitud);
int buscaPrimerVacio(EMovies* movie, int longitud);
int verificaSiExisteMovie(EMovies* movie,char existe[],char noExiste[], char auxTitulo[], int longitud);
void nuevaMovie(EMovies* movie, int indiceVacio, int longitud);
void baja(EMovies* movie, int longitud);
int verificaPeliculaExistente(EMovies* movie, int longitud);
void editMovie(EMovies* movie, int length);


/// funciones de archivo
int saveBin(EMovies* movie, int length);
int loadlengthToFile(EMovies* movie, int length);
void createHTML(EMovies* movie, int length);
int loadFromFile(EMovies* movie, int length);

/// validaciones ##############################################################
int capValidaYchequaRangoStr(char input[], char mensajePedido[],char RangoMin, char RangoMax);
int capValidaYchequaRangoStrAlfaNro(char input[], char mensajePedido[],char RangoMin, char RangoMax);
int capValidaYchequaRangoInt(int* input, char mensajePedido[],char mensajeError[],int RangoMin, int RangoMax);
int capValidaYchequaRangoFloat(float* input, char mensajePedido[],char mensajeError[],int RangoMin, int RangoMax);
unsigned int ValidaSeguirSoN(char mensaje[]);
int validaNroTelefono(char input[], char mensajePedido[], char mensajeError[]);
void pideYacomodaApellidoNombre(char apellNomb[]);
void validaFormatoHora(char input[]);
int capValidaYchequaRangoStrLibre(char input[], char mensajePedido[],char RangoMin, char RangoMax);


#endif // FUNCIONES_H_INCLUDED
