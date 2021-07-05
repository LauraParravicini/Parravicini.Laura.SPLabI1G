#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include "pais.h"

/** \brief Guarda en un archivo de texto el contenido de la linked list
 *
 * \param path char*
 * \param pArrayListPais LinkedList*
 * \param loaded int
 * \return int
 *
 */
int informes_saveAsText(char* path , LinkedList* pArrayListPais,int loaded);

/** \brief Guarda en un archivo binario el contenido de la linked list
 *
 * \param path char*
 * \param pArrayListPais LinkedList*
 * \return int
 *
 */
int informes_saveAsBinary(char* path , LinkedList* pArrayListPais);

/** \brief Muestra el/los paises con menor cantidad de vacunados
 *
 * \param paises LinkedList*
 * \return int
 *
 */
int paisMasCastigado(LinkedList* paises);

/** \brief Devuelve verdadero donde el/los paises cuya cantidad de no vacunados es mayor a la de vacunados
 *
 * \param a void*
 * \return int
 *
 */
int filterPaisesAlHorno(void* a);

/** \brief Devuelve verdadero donde los paises tengan mayor de 30% el porcentaje de vacunados
 *
 * \param a void*
 * \return int
 *
 */
int filterPaisesExitosos(void* a);

/** \brief Devuelve verdadero o falso segun cual pais esta mas vacunado.
 *
 * \param a void*
 * \param b void*
 * \return int
 *
 */
int ordenarPorVacunacion(void* a,void* b);

/** \brief Devuelve un puntero void con los campos asignados
 *
 * \param pais void*
 * \return void*
 *
 */
void* asignarEstadisticas(void* pais);
#endif // INFORMES_H_INCLUDED
