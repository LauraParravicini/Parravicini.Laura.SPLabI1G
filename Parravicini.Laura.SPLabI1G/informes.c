#include "informes.h"


/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPais LinkedList*
 * \return int
 *
 */
int informes_saveAsText(char* path , LinkedList* pArrayListPais,int loaded)
{
    FILE* f = fopen(path,"w");
    ePais* aux = NULL;

    int id;
    char nombre[128];
    int vac1dosis;
    int vac2dosis;
    int sinVacunar;

    int ingresado;
    int flag = 0;

    char confirmacion;
    if(f != NULL){

            printf("\n Esta accion reescribira el archivo, desea continuar? s/n :  ");
            fflush(stdin);
            scanf(" %c",&confirmacion);
            if(confirmacion == 's'){
                fprintf(f,"id,nombre,vac1dosis,vac2dosis,sinVacunar\n");
                for(int i = 0; i < ll_len(pArrayListPais) ; i++){
                    aux = (ePais*) ll_get(pArrayListPais,i);
                    if(aux != NULL){

                        PaisGetId(aux,&id);
                        PaisGetNombre(aux,nombre);
                        PaisGetvac1dosis(aux,&vac1dosis);
                        PaisGetvac2dosis(aux,&vac2dosis);
                        PaisGetsinVacunar(aux,&sinVacunar);


                        ingresado = fprintf(f,"%d,%s,%d,%d,%d\n",id,nombre,vac1dosis,vac2dosis,sinVacunar);
                        if(ingresado < 5){
                            flag = 1;
                            break;
                        }
                    }
                }

                if(flag){
                    printf("-!- Error saving Paiss in text file -!-\n");
                }else{
                    printf(" --- Saved successfully :) --- \n");
                }

            }else{
                printf("-- Data save canceled --\n");
            }


            fclose(f);
    }else{
        printf("-!- Error opening file -!-\n");
    }
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPais LinkedList*
 * \return int
 *
 */
int informes_saveAsBinary(char* path , LinkedList* pArrayListPais)
{
    FILE* f = fopen(path,"wb");
    ePais* aux = NULL;

    int ingresado;
    int flag = 0;
    char confirmacion;
    if(f != NULL){

        printf("\n Esta accion reescribira el archivo, desea continuar? s/n :  ");
        fflush(stdin);
        scanf(" %c",&confirmacion);
        if(confirmacion == 's'){

            for(int i = 0; i < ll_len(pArrayListPais) ; i++){
                aux = (ePais*) ll_get(pArrayListPais,i);
                if(aux != NULL){

                    ingresado = fwrite( aux , sizeof(ePais),1,f);
                    if(ingresado < 1){
                        flag = 1;
                        break;
                    }
                }
            }

            if(flag){
                printf("-!- Error saving Paiss in binary file -!-\n");
            }else{
                printf(" --- Saved successfully :) --- \n");
            }
        }else{
                printf("-- Data save canceled --\n");
        }
        fclose(f);

    }else{
        printf("-!- Error opening file -!-\n");
    }

    return 1;
}


int filterPaisesExitosos(void* a){
    int status = 0;
    ePais* Pais1 = NULL;
    if(a != NULL){
        //Casteo lo que estaba en void a empleado
        Pais1 = (ePais*) a;
        if(Pais1->vac2dosis > 30){
            status = 1;
        }
    }
    return status;
}


int filterPaisesAlHorno(void* a){
    int status = 0;
    ePais* Pais1 = NULL;
    if(a != NULL){
        //Casteo lo que estaba en void a empleado
        Pais1 = (ePais*) a;
        if(Pais1->sinVacunar > ( Pais1->vac1dosis + Pais1->vac2dosis ) ){
            status = 1;
        }
    }
    return status;
}

int ordenarPorVacunacion(void* a,void* b){
    int status = 0;
    ePais* Pais1 = NULL;
    ePais* Pais2 = NULL;
    if(a != NULL && b != NULL){
        //Casteo lo que estaba en void a empleado
        Pais1 = (ePais*) a;
        Pais2 = (ePais*) b;
        if(Pais1->vac1dosis > Pais2->vac1dosis){
            status = 1;
        }else{
            status = -1;
        }
    }

    return status;
}

int paisMasCastigado(LinkedList* paises){
    ePais* aux;
    int maximo = 0;
    int flag = 1;
    if(paises->size != 0){
        for(int i = 0; i < ll_len(paises); i++ ){
            aux = ll_get(paises,i);
            if( (aux != NULL && aux->sinVacunar > maximo) || flag){
                maximo = aux->sinVacunar;
                flag = 0;
            }
        }

        printf("\n--- Pais/es Mas Castigado ----- \n");
        printf(" - Porcentaje mayor de no vacunados: %d \n\n", maximo);
        printf("   ID -      Nombre    - Vacunados 1 Dosis - Vacunados 2 dosis - Sin vacunar\n");
        for (int i = 0; i < ll_len(paises); i++){
            aux = ll_get(paises,i);
            if ( aux->sinVacunar == maximo){
                mostrarPais(aux);
            }
        }
    }else{
        printf("--!-- Lista Vacia --!--\n");
    }
    return maximo;
}

void* asignarEstadisticas(void* pais){
    ePais* aux = NULL;
    if(pais != NULL){
        aux = (ePais*) pais;
        //rand() % (max-min +1) +min
        aux->vac1dosis = rand() % (60 - 1 +1) + 1;
        aux->vac2dosis = rand() % (40 - 1 +1) + 1;
        aux->sinVacunar = 100 - (aux->vac1dosis + aux->vac2dosis);
    }
    return aux;
}
