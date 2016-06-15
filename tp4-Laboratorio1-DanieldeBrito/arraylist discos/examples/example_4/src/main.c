#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "../inc/ArrayList.h"
#include "../inc/Employee.h"
#include "../inc/validation.h"

#define TAM 5


int run2(void); ///harcodea 4 empleados

int main()
{
    int opcion, seguir, nroValidoOk;
    ArrayList* lista = al_newArrayList();

    do{
    system("cls");
    printf("1. Agregar empleado\n");
    printf("2. Borrar empleado\n");
    printf("3. Imprimir lista ordenada por nombre\n");
    printf("4. \n\n");
    printf("5. Salir\n");

    do{
    nroValidoOk=capValidaYchequaRangoInt(&opcion,"\nIngrese la opcion del menu deseada: ","ERROR!!, NO es una opcion del menu valida",1,5);
    }while(nroValidoOk==-1);

    switch(opcion)
    {
        case 1:/**< agregar empleado */
            system("cls");

            lista->add(lista,);




            /// if(buscaPrimerVacio(persona, TAM) != (-1))
            ///     {
            ///         addPersona(persona, buscaPrimerVacio(persona, TAM),TAM);
            ///     }
            break;
        case 2:/**< borrar persona */
            system("cls");
            ///borraPersona(persona, TAM);
            break;
        case 3:/**< imprimir lista ordenada por nombre */
            system("cls");
            ///ordenaPersonaPorNombre(persona, TAM);
            ///imprimePersonas(persona, TAM);
            break;
        case 4:/**< */
            system("cls");

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
