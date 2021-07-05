#include "pais.h"

ePais* newPaisStr(char* id, char* nombre, char* vac1dosis, char* vac2dosis, char* sinVacunar){
    ePais* pEmp = newPais();
    if(pEmp != NULL){
        if( !(PaisSetId(pEmp, atoi(id) )
           && PaisSetNombre(pEmp,nombre)
           && PaisSetvac2dosis(pEmp, atoi(vac2dosis) )
           && PaisSetvac1dosis(pEmp, atoi(vac1dosis) )
           && PaisSetsinVacunar(pEmp, atoi(sinVacunar) )    ) ) {
                //Libero memoria en caso de que algun parametro este mal
                free(pEmp);
                pEmp = NULL;

        }

    }

    return pEmp;

}

int mostrarPais(ePais* p){
    int status = 0;
    int id;
    char nombre[20];
    int vac1dosis;
    int vac2dosis;
    int sinVacunar;

    if(p != NULL &&
       PaisGetId(p,&id) &&
       PaisGetNombre(p, nombre) &&
       PaisGetvac1dosis(p,&vac1dosis) &&
       PaisGetvac2dosis(p,&vac2dosis) &&
       PaisGetsinVacunar(p,&sinVacunar) ){

        printf("%3d   %20s   %6d   %10d  %20d \n",id,nombre,vac1dosis,vac2dosis,sinVacunar);
        status = 1;
       }
    return status;
}


ePais* newPais(){
    //Asigno memoria
    ePais* pPais = (ePais*) malloc(sizeof(ePais));
    if(pPais != NULL){
        pPais->id = 0;
        strcpy(pPais->nombre, "");
        pPais->vac1dosis = 0;
        pPais->vac2dosis = 0;
        pPais->sinVacunar = 0;
    }
    return pPais;
}

ePais* newPaisParam(int id, char* nombre, int vac1dosis, int vac2dosis, int sinVacunar){
    ePais* pPais = newPais();
    if(pPais != NULL){
        // ---- Llamo a todos los setters para cargar los campos, si falla alguno va a dar falso, negado entra
        if( !(PaisSetId(pPais,id)
           && PaisSetNombre(pPais,nombre)
           && PaisSetvac2dosis(pPais,vac2dosis)
           && PaisSetvac1dosis(pPais,vac1dosis)
           && PaisSetsinVacunar(pPais,sinVacunar) ) ){
                //Libero memoria en caso de que algun parametro este mal
                free(pPais);
                pPais = NULL;

        }

    }

    return pPais;
}

int destroyPais(ePais* pais){
    int status = 0;
    if(pais != NULL){
        free(pais);
        status = 1;
    }
    return status;
}

int PaisSetId(ePais* pais, int id){
    int status = 0;
    if(pais != NULL && id > 0){
        pais->id = id;
        status = 1;
    }
    return status;
}

int PaisSetNombre(ePais* pais, char* nombre){
    int status = 0;
    if(pais != NULL && nombre != NULL && strlen(nombre) > 0 && strlen(nombre) < 20){
        strcpy(pais->nombre,nombre);
        status = 1;
    }
    return status;
}

int PaisSetvac1dosis(ePais* pais, int vac1dosis){
    int status = 0;
    if(pais != NULL && vac1dosis >= 0){
        pais->vac1dosis = vac1dosis;
        status = 1;
    }
    return status;
}

int PaisSetvac2dosis(ePais* pais, int vac2dosis){
    int status = 0;
    if(pais != NULL && vac2dosis >= 0){
        pais->vac2dosis = vac2dosis;
        status = 1;
    }
    return status;
}

int PaisSetsinVacunar(ePais* pais, int sinVacunar){
    int status = 0;
    if(pais != NULL && sinVacunar >= 0){
        pais->sinVacunar = sinVacunar;
        status = 1;
    }
    return status;
}


int PaisGetId(ePais* pais, int* pId){
    int status = 0;
    if(pais != NULL && pId != NULL){
        (*pId) = pais->id;
        status = 1;
    }
    return status;
}

int PaisGetNombre(ePais* pais, char* nombre){
    int status = 0;
    if(pais != NULL && nombre != NULL){
        strcpy(nombre,pais->nombre);
        status = 1;
    }
    return status;
}

int PaisGetvac1dosis(ePais* pais, int* pvac1dosis){
    int status = 0;
    if(pais != NULL && pvac1dosis != NULL){
        (*pvac1dosis) = pais->vac1dosis;
        status = 1;
    }
    return status;
}


int PaisGetvac2dosis(ePais* pais, int* pvac2dosis){
    int status = 0;
    if(pais != NULL && pvac2dosis != NULL){
        (*pvac2dosis) = pais->vac2dosis;
        status = 1;
    }
    return status;
}

int PaisGetsinVacunar(ePais* pais, int* psinVacunar){
    int status = 0;
    if(pais != NULL && psinVacunar != NULL){
        (*psinVacunar) = pais->sinVacunar;
        status = 1;
    }
    return status;
}


int mostrarPaises(LinkedList* pArrayListPais)
{
    ePais* PaisAux = NULL;
    int status = 0;
    int len = ll_len(pArrayListPais);
    if(pArrayListPais->size != 0){
        if(pArrayListPais != NULL){
            printf("--- Pais List ---\n");
            printf("   ID -      Nombre    - Vacunados 1 Dosis - Vacunados 2 dosis - Sin vacunar\n");
            for(int i = 0; i < len; i++){
                PaisAux = ll_get(pArrayListPais,i);
                if( PaisAux != NULL ) {

                    mostrarPais(PaisAux);
                }
            }
        }
    }else{
        printf(" --!-- Lista Vacia --!--\n\n");
    }
    return status;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int paises_loadFromText(char* path , LinkedList* pArrayListEmployee, int* loaded)
{
    FILE* p;

    if(path != NULL && pArrayListEmployee != NULL){
        p = fopen(path,"r");
        (*loaded) = parser_PaisFromText(p,pArrayListEmployee);
        (*loaded)++;

    }
    return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int paises_loadFromBinary(char* path , LinkedList* pArrayListEmployee, int* loaded)
{
    FILE* p;

    if(path != NULL && pArrayListEmployee != NULL){
        p = fopen(path,"rb");
        (*loaded) = parser_PaisFromBinary(p,pArrayListEmployee);

    }
    return 1;
}


