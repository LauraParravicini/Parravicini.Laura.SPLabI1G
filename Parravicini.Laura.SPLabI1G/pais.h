#ifndef PAIS_H_INCLUDED
#define PAIS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "parser.h"

typedef struct{
    int id;
    char nombre[20];
    int vac1dosis;
    int vac2dosis;
    int sinVacunar;
}ePais;


/** \brief Constructor: asigna memoria e inicializa un nuevo pais
 *
 * \return ePais*
 *
 */
ePais* newPais();


/** \brief Contructor con data: inicializa, valida y asigna valores a un pais
 *
 * \param id int
 * \param nombre char*
 * \param vac1dosis int
 * \param vac2dosis int
 * \param sinVacunar int
 * \return ePais*
 *
 */
ePais* newPaisParam(int id, char* nombre, int vac1dosis, int vac2dosis, int sinVacunar);


/** \brief Contructor con data en formato cadena de caracteres: castea, inicializa, valida y asigna valores a un pais
 *
 * \param id char*
 * \param nombre char*
 * \param vac1dosis char*
 * \param vac2dosis char*
 * \param sinVacunar char*
 * \return ePais*
 *
 */
ePais* newPaisStr(char* id, char* nombre, char* vac1dosis, char* vac2dosis, char* sinVacunar);

/** \brief Destructor de un pais
 *
 * \param pais ePais*
 * \return int
 *
 */
int destroyPais(ePais* pais);

/** \brief Setter para el atributo ID
 *
 * \param pais ePais*
 * \param id int
 * \return int
 *
 */
int PaisSetId(ePais* pais, int id);

/** \brief Setter para el atributo Nombre
 *
 * \param Pais ePais*
 * \param nombre char*
 * \return int
 *
 */
int PaisSetNombre(ePais* Pais, char* nombre);

/** \brief Setter para el atributo vac1dosis
 *
 * \param Pais ePais*
 * \param vac1dosis int
 * \return int
 *
 */
int PaisSetvac1dosis(ePais* Pais, int vac1dosis);

/** \brief Setter para el atributo vac2dosis
 *
 * \param Pais ePais*
 * \param vac2dosis int
 * \return int
 *
 */
int PaisSetvac2dosis(ePais* Pais, int vac2dosis);

/** \brief Setter para el atributo sinVacunar
 *
 * \param Pais ePais*
 * \param sinVacunar int
 * \return int
 *
 */
int PaisSetsinVacunar(ePais* Pais, int sinVacunar);


/** \brief Getter para el atributo ID
 *
 * \param Pais ePais*
 * \param pId int*
 * \return int
 *
 */
int PaisGetId(ePais* Pais, int* pId);

/** \brief Getter para el atributo Nombre
 *
 * \param Pais ePais*
 * \param nombre char*
 * \return int
 *
 */
int PaisGetNombre(ePais* Pais, char* nombre);

/** \brief Getter para el atributo vac1dosis
 *
 * \param Pais ePais*
 * \param pvac1dosis int*
 * \return int
 *
 */
int PaisGetvac1dosis(ePais* Pais, int* pvac1dosis);

/** \brief Getter para el atributos vac2dosis
 *
 * \param Pais ePais*
 * \param pvac2dosis int*
 * \return int
 *
 */
int PaisGetvac2dosis(ePais* Pais, int* pvac2dosis);

/** \brief Getter para el atributo sinVacunar
 *
 * \param Pais ePais*
 * \param psinVacunar int*
 * \return int
 *
 */
int PaisGetsinVacunar(ePais* Pais, int* psinVacunar);


/** \brief Muestra un pais por pantalla
 *
 * \param p ePais*
 * \return int
 *
 */
int mostrarPais(ePais* p);

/** \brief Muestra los paises de una lista por pantalla
 *
 * \param pArrayListPais LinkedList*
 * \return int
 *
 */
int mostrarPaises(LinkedList* pArrayListPais);

/** \brief Carga desde un archivo binario pasado por path a la linked list
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \param loaded int*
 * \return int
 *
 */
int paises_loadFromBinary(char* path , LinkedList* pArrayListEmployee, int* loaded);

/** \brief Carga desde un archivo de texto pasado por path a la linked list
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \param loaded int*
 * \return int
 *
 */
int paises_loadFromText(char* path , LinkedList* pArrayListEmployee, int* loaded);


#endif // PAIS_H_INCLUDED
