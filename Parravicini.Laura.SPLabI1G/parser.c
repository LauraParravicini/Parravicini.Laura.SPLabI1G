#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "pais.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPais LinkedList*
 * \return int
 *
 */
int parser_PaisFromText(FILE* pFile , LinkedList* pArrayListPais)
{
    ePais* paisAux = NULL;
    int cant;
    char buffer[5][128];
    int cargados = 0;
    if(pFile != NULL){
         cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);
         do{
            cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);

            if(cant < 5){
                break;
            }

            paisAux = newPaisStr(buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);

            if(paisAux != NULL){
                    ll_add(pArrayListPais,paisAux);
                    cargados++;

            }else{
                printf("-! Error generating new Pais object !-\n");
                break;
            }
        }while(!feof(pFile));
        if(cargados){
            printf(" -- Loaded sucessfully :) -- \n");
        }else{
            printf(" -- File is empty --\n");
        }
        fclose(pFile);
    }else{
        printf("Error opening file\n");
    }
    return cargados;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPais LinkedList*
 * \return int
 *
 */
int parser_PaisFromBinary(FILE* pFile , LinkedList* pArrayListPais)
{
    int cant;
    int cargados = 0;
    ePais auxPais;
    ePais* pPais;
    if(pFile != NULL){
         //cant = fread(auxEmpleado,sizeof(Pais),1,pFile);
         do{
            cant = fread(&auxPais,sizeof(ePais),1,pFile);
            pPais = newPais();
            if(cant == 1 && pPais != NULL){
                if( PaisSetId(pPais,auxPais.id) &&
                    PaisSetNombre(pPais,auxPais.nombre) &&
                    PaisSetvac2dosis(pPais,auxPais.vac2dosis) &&
                    PaisSetvac1dosis(pPais,auxPais.vac1dosis) &&
                    PaisSetsinVacunar(pPais,auxPais.sinVacunar) )
                {
                     ll_add(pArrayListPais,pPais);
                     cargados++;
                }else{
                    destroyPais(pPais);
                }
            }

        }while(!feof(pFile));
        if(cargados){
            printf(" -- Loaded sucessfully :) -- \n");
        }else{
            printf(" -- File is empty --\n");
        }
        fclose(pFile);
    }else{
        printf("Error opening file\n");
    }

    return cargados;
}
