/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;                 //puntero al elemento (persona, empleado, etc.)
    struct Node* pNextNode;         //puntero al prox nodo
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;                       //cada vez que agrego o elimino un elemento size++/--
}typedef LinkedList;
#endif



//Publicas
/** \brief Crea y devuelve una nueva linked list
 *
 * \param void
 * \return LinkedList*
 *
 */
LinkedList* ll_newLinkedList(void);

/** \brief Devuelve el tamaño de la linked list
 *
 * \param this LinkedList*
 * \return int
 *
 */
int ll_len(LinkedList* this);

/** \brief Usada para testeo de getNode
 *
 * \param this LinkedList*
 * \param nodeIndex int
 * \return Node*
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex);

/** \brief Usada para testeo de addNode
 *
 * \param this LinkedList*
 * \param nodeIndex int
 * \param pElement void*
 * \return int
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Añade un elemento a la lista.
 *
 * \param this LinkedList*
 * \param pElement void*
 * \return int
 *
 */
int ll_add(LinkedList* this, void* pElement);

/** \brief Devuelte un elemento de la lista en el indice enviado
 *
 * \param this LinkedList*
 * \param index int
 * \return void*
 *
 */
void* ll_get(LinkedList* this, int index);

/** \brief Escribe un elemento de la lista en el indice indicado
 *
 * \param this LinkedList*
 * \param index int
 * \param pElement void*
 * \return int
 *
 */
int ll_set(LinkedList* this, int index,void* pElement);

/** \brief  Elimina un elemento de la lista en el indice indicado
 *
 * \param this LinkedList*
 * \param index int
 * \return int
 *
 */
int ll_remove(LinkedList* this,int index);

/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList*
 * \return int
 *
 */
int ll_clear(LinkedList* this);

/** \brief Elimina la linked list
 *
 * \param this LinkedList*
 * \return int
 *
 */
int ll_deleteLinkedList(LinkedList* this);

/** \brief Devuelve el indice de posicion del elemento indicado
 *
 * \param this LinkedList*
 * \param pElement void*
 * \return int
 *
 */
int ll_indexOf(LinkedList* this, void* pElement);

/** \brief Devuelve si la lista esta vacia
 *
 * \param this LinkedList*
 * \return int
 *
 */
int ll_isEmpty(LinkedList* this);

/** \brief Inserta un elemento en un indice reasignando el puntero
 *
 * \param this LinkedList*
 * \param index int
 * \param pElement void*
 * \return int
 *
 */
int ll_push(LinkedList* this, int index, void* pElement);

/** \brief Devuelve un elemento de la lista en el indice indicado y lo elimina de ella
 *
 * \param this LinkedList*
 * \param index int
 * \return void*
 *
 */
void* ll_pop(LinkedList* this,int index);                           //elimina un elemento (los enlaces a ese elemento) y devuelve un puntero a ese elemento

/** \brief Devuelve verdadero o falso segun si un elemento esta en la lista
 *
 * \param this LinkedList*
 * \param pElement void*
 * \return int
 *
 */
int ll_contains(LinkedList* this, void* pElement);

/** \brief Devuelve verdadero si todos los elementos de dos listas coinciden
 *
 * \param this LinkedList*
 * \param this2 LinkedList*
 * \return int
 *
 */
int ll_containsAll(LinkedList* this,LinkedList* this2);

/** \brief Devuelve una sublista de menor cant de elementos de una lista
 *
 * \param this LinkedList*
 * \param from int
 * \param to int
 * \return LinkedList*
 *
 */
LinkedList* ll_subList(LinkedList* this,int from,int to);

/** \brief Devuelve una nueva linked list copia de la original
 *
 * \param this LinkedList*
 * \return LinkedList*
 *
 */
LinkedList* ll_clone(LinkedList* this);

/** \brief Ordena la linked list usando el criterio de la funcion y el orden indicado
 *
 * \param void*
 * \param void*
 * \return int ll_sort(LinkedList* this, int
 *
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);

/** \brief Devuelve una nueva linked list con los elementos que cumplen con el critero de la funcion indicada
 *
 * \param this LinkedList*
 * \param (*pFunc int
 * \return LinkedList*
 *
 */
LinkedList* ll_filter(LinkedList* this, int (*pFunc) (void*) );

/** \brief Recorre todos los elementos de la lista y realiza sobre sus elementos lo pasado en la funcion indicada
 *
 * \param this LinkedList*
 * \param (*pFunc void*
 * \return LinkedList*
 *
 */
LinkedList* ll_map(LinkedList* this, void* (*pFunc) (void*) );
