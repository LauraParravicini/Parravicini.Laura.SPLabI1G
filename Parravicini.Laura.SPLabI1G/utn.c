#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
// ---------- UTN Get Numero ---------
static int esNumerica(char* cadena);
static int getInt(int* pResultado);
static int myGets(char* cadena, int longitud);

static int myGets(char* cadena, int longitud){
	if(cadena != NULL && longitud > 0 && fgets(cadena,longitud,stdin) == cadena ){
		fflush(stdin);
		if(cadena[strlen(cadena)-1] == '\n'){
			cadena[strlen(cadena)-1] = '\0';
		}
		return 0;
	}
	return -1;
}

static int getInt(int* pResultado){
	int retorno = -1;
	char buffer[64];
	if(pResultado != NULL){
		if( myGets(buffer,sizeof(buffer)) == 0 && esNumerica(buffer) ){
			*pResultado = atoi(buffer);
			retorno = 0;
		}
	}
	return retorno;
}

static int esNumerica(char* cadena){
	int i = 0;
	int retorno = 1;
	if(cadena != NULL && strlen(cadena) > 0){
		while(cadena[i] != '\0'){
			if(cadena[i] < '0' || cadena[i] > '9'){
				retorno = 0;
				break;
			}
			i++;
		}
	}
	return retorno;
}

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos){
	int bufferInt;
	int retorno = -1;
	while(reintentos > 0){
		reintentos--;
		printf("%s",mensaje);
		fflush(stdin);
		if(getInt(&bufferInt) == 0){
			if(bufferInt >= minimo && bufferInt <= maximo){
				*pResultado = bufferInt;
				retorno = 1;
				break;
			}
		}
        printf("%s",mensajeError);
	}
	return retorno;
}
//--------------------------   UTN Get Caracter -------------------------------------

int utn_getCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos){
	int retorno = -1;
	char buffer;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos > 0){
		do{
			printf("%s",mensaje);
			scanf("%c",&buffer);
			if(buffer >= minimo && buffer <= maximo){
				*pResultado = buffer;
				retorno = 1;
				break;
			}
			printf("%s",mensajeError);
			reintentos--;

		}while(reintentos);
	}

	return retorno;
}
//----------------------------- UTN Get Fecha -----------------------
int utn_getFecha(int* dia,int* mes, int* anio, char* mensaje, char* msjeError,int reintentos){
    int retorno = -1;
    int bufDia, bufMes, bufAnio;
    if(dia != NULL && mes != NULL && anio != NULL && mensaje != NULL && msjeError != NULL && reintentos > 0){
        do{
            printf("%s", mensaje);
            scanf("%d/%d/%d", &bufDia, &bufMes, &bufAnio);
            if( bufDia >= 1 && ( ( (bufMes == 1 || bufMes == 3 || bufMes == 5 || bufMes == 7 || bufMes == 8 || bufMes == 10 || bufMes == 12) && bufDia <= 31)
                || ((bufMes == 4 || bufMes == 6 || bufMes == 9 || bufMes == 11) && bufDia <= 30)
                ||  (bufMes == 2 && bufDia <= 29) ) ){

                *dia = bufDia;
                *mes = bufMes;
                *anio = bufAnio;
                retorno = 1;
                break;
            }
            printf("%s",msjeError);
            reintentos--;
        }while(reintentos);
    }
    return retorno;
}

int utn_getFloat(char * cadena){
    int allRight = 1; //inicia en verdadero, y de no cumplir algun requisito la funcion le asignara el 0
    int contadorPunto = 0;
    int stop = 0;
    if (cadena != NULL && strlen(cadena) > 0){ //si el puntero cadena no apunta al vacio y su largo es mayor a 0
        for (int x = 0; x < strlen(cadena) && !stop ; x++){
            if (cadena[x] < '0' || cadena[x] > '9') //si el caracter no es numerico
            {
                switch(cadena[x]){
                    case '.':
                        if (contadorPunto > 1 || x == 0 || x == strlen(cadena)-1 || (x == 1 && cadena[0]== '-')) //si hay mas de un punto, o si este esta al final o al principio, o si prosigue a un signo negativo
                        {
                            allRight = 0;
                            stop = 1; //finaliza la iteracion (utilizar break entraria en conflicto con el switch)
                        }
                    break;
                    case '-':
                        if (x != 0 || strlen(cadena) == 1) //si el signo negativo no se encuentra al principio o si la cadena tiene solo 1 elemento
                        {
                            allRight = 0;
                            stop = 1;
                        }
                    break;
                    default:
                        allRight = 0;
                        stop = 1;
                }
            }
        }
    }
    return allRight;
}

int getFloat (float *numeroIngresado, char* mensaje, char* mensajeError){
    float number;
    int ret=-1;
    printf("%s",mensaje);
    if(scanf("%f",&number)==1)
    {
        fflush(stdin);
        *numeroIngresado =number;
        ret=0;
    }
    else
    {
        fflush(stdin);
        printf("%s",mensajeError);
    }
    return ret;
}

int getString(char* msg, char* msgError, int min, int max, int* reintentos, char* resultado)
{
    int retorno=-1;
    char bufferStr[max+10];

    if(msg!=NULL && msgError!=NULL && min<=max && reintentos>=0 && resultado!=NULL)
    {
        do
        {
            printf("%s",msg);   //no poner salto de linea, se va a pasar en el mensaje por valor
            //fflush(stdin);
            fflush(stdin);
            fgets(bufferStr,sizeof(bufferStr),stdin);
            bufferStr[strlen(bufferStr)-1]='\0';

            if(strlen(bufferStr)>=min && strlen(bufferStr)<max)    // tamaño (max) =cantidad de elementos (strlen) + 1(\0)
            {
                strncpy(resultado,bufferStr,max);
                retorno=0;
                break;
            }
            printf("%s 1",msgError);
            (*reintentos)--;
        }
        while((*reintentos)>=0);
    }
    return retorno;
}
//------------------------------
int utn_getName(char* msg, char* msgError, int min, int max, int reintentos, char* resultado)
{
    int retorno=-1;
    char bufferStr[max];

    if(msg!=NULL && msgError!=NULL && min<=max && reintentos>=0 && resultado!=NULL)
    {
        do
        {
            if(!getString(msg,msgError,min,max,&reintentos,bufferStr)) //==0
            {
                if(isValidName(bufferStr)==1)
                {
                    strncpy(resultado,bufferStr,max);
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s 2",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

int isValidName(char* stringRecibido)   //si fuera un numero podrìa necesitar parametros para validar max y min
{
    int retorno=1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        //printf("%d",i);
        if(stringRecibido[i]<'A' || (stringRecibido[i]>'Z' && stringRecibido[i]<'a') || stringRecibido[i]>'z')// o ((stringRecibido[i]<'A' || (stringRecibido[i]>'Z') && (stringRecibido[i]<'a' || stringRecibido[i]>'z'))
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}

int utn_getTelefono(char* msg, char* msgError, int minSize, int maxSize, int min, int max, int reintentos, char* input)
{
    int retorno=-1;
    char bufferStr[maxSize];

    if(msg!=NULL && msgError!=NULL && minSize<maxSize && min<max && reintentos>=0 && input!=NULL)
    {
        do
        {
            if(!getString(msg,msgError,minSize,maxSize,&reintentos,bufferStr)) //==0 sin errores !0
            {
                if(isValidTelephone(bufferStr)==1)
                {
                    strncpy(input,bufferStr,maxSize);
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s 2",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

int isValidTelephone(char* stringRecibido)
{
    int retorno=1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if((stringRecibido[i]<'0' || stringRecibido[i]>'9') && (stringRecibido[i]!='-' || stringRecibido[i]!=' '))
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}
