#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "LinkedList.h"
#include "pais.h"
#include "informes.h"
#include "utn.h"
int main()
{
    srand(time(NULL));
    int opcion;
	int cargados = 0;
	char path[20];
	int flagMap = 0;
	int flagCargado = 0;
	LinkedList* buffer = ll_newLinkedList();
	LinkedList* paises = NULL;
	LinkedList* paisesExitosos = NULL;
	LinkedList* paisesAlHorno;
    //--- Menu ----
    do{
        printf("\n---------- Bienvenido -------\n");
        if(flagMap){
            printf("1) Cargar Archivo \n2) Imprimir Lista \n3) Asignar Estadistica \n4) Filtrar por Paises Exitosos \n5) Filtrar por Paises al Horno \n6) Ordenar por nivel de vacunacion \n7) Mostrar mas castigado \n");
        }else{
            printf("1) Cargar Archivo \n3) Asignar Estadistica \n8) Salir\n");
        }

        if ( utn_getNumero(&opcion,"Ingrese opcion 1-8: ","-!- Opcion invalida -!-",1,8,10) ){

            switch(opcion){
                case 1:
                    printf("\t- Ingrese path de archivo a subir: ");
                    fflush(stdin);
                    scanf(" %s",path);
                    paises_loadFromText(path,buffer,&cargados);
                    flagCargado = 1;
                    break;
                case 2:
                    mostrarPaises(paises);
                    break;
                case 3:
                    paises = ll_map(buffer,asignarEstadisticas);
                    if(paises != NULL && flagCargado){
                        ll_deleteLinkedList(buffer);
                        mostrarPaises(paises);
                        flagMap = 1;
                    }else{
                        printf("-!- Aun no se cargo ningun archivo -!-\n");
                    }
                    break;
                case 4:
                    paisesExitosos = ll_filter(paises,filterPaisesExitosos);
                    printf("\t- Ingrese path de archivo a descargar: ");
                    fflush(stdin);
                    scanf(" %s",path);
                    informes_saveAsText(path,paisesExitosos,cargados);
                    break;
                case 5:
                    paisesAlHorno = ll_filter(paises,filterPaisesAlHorno);
                    printf("\t- Ingrese path de archivo a descargar: ");
                    fflush(stdin);
                    scanf(" %s",path);
                    informes_saveAsText(path,paisesAlHorno,cargados);
                    break;
                case 6:
                    ll_sort(paises,ordenarPorVacunacion,0);
                    mostrarPaises(paises);
                    break;
                case 7:
                    paisMasCastigado(paises);
                    break;
            }
        }
    }while(opcion != 8);

    return EXIT_SUCCESS;
}
