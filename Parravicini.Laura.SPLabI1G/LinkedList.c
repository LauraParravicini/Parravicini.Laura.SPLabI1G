#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= (LinkedList*) malloc(sizeof(LinkedList));
    if(this != NULL){
            this->pFirstNode = NULL;
            this->size = 0;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL){
        returnAux = this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* node = NULL;
    if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this) ){
        node = this->pFirstNode;
        for(int i = 0; i < nodeIndex; i++){
            if(node != NULL){
                    node = node->pNextNode;
            }else{
                break;
            }
        }
    }

    return node;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* node = NULL;
    Node* aux = NULL;
    if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this) ){

        //Creo el nodo nuevo
        node = (Node*) malloc(sizeof(Node));
        if(node != NULL){
            //Asigno la carga
            node->pElement = pElement;
            //El nuevo nodo va a puntar al que estaba en esa posicion pasada antes
            node->pNextNode = getNode(this,nodeIndex);
            if(nodeIndex == 0){
                 this->pFirstNode = node;
            }else{
                //Si voy a poner en el medio me traigo la direccion de memoria del anterior y lo hago que apunte al nuevo
                aux = getNode(this, nodeIndex-1);
                aux->pNextNode = node;
            }
            this->size++;
            returnAux = 0;
        }
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    //Add node ya valida el this y devuelve 0 y -1 como esta funcion
    return addNode(this, ll_len(this), pElement);
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node *pAux = NULL;
    if(this != NULL && index >= 0 && index < ll_len(this) )
    {
        pAux = getNode(this, index);
        if(pAux != NULL)
        {
            returnAux = pAux->pElement;
        }
    }
    return returnAux;
}

/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* pAux = NULL;
    if(this != NULL && index >= 0 && index <= ll_len(this) )
    {
        //Si quiere meter en la ult posicion seria como un add
        if(index < ll_len(this)){
            pAux = getNode(this, index);
            if(pAux != NULL)
            {
                pAux->pElement = pElement;
                returnAux = 0;
            }
        }else{
            ll_add(this,pElement);
        }
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node *pAux = NULL;
    Node *pCurrent = NULL;
    if(this != NULL && index >= 0 && index < ll_len(this) )
    {
            pCurrent = getNode(this, index);
            if(pCurrent != NULL){
                if(index != 0)
                {
                    pAux = getNode(this, index - 1);
                    if(pAux != NULL)
                    {
                        pAux->pNextNode = pCurrent->pNextNode;
                    }
                }else if(index == 0)
                {
                    this->pFirstNode = pCurrent->pNextNode;
                }
            }
            free(pCurrent);
            this->size--;
            returnAux = 0;

    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
        while(ll_len(this) != 0 ){
            ll_remove(this,0);
        }
        returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(! ll_clear(this) ){
        free(this);
        returnAux = 0;
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int i;
    if(this != NULL)
    {
        for(i=0;i<ll_len(this);i++)
        {
            if(ll_get(this,i) == pElement)
            {
                returnAux = i;
                break;
            }
        }
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
        returnAux = ll_len(this) == 0; //Devuelve 1 en True y 0 en False
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    return addNode(this, index, pElement);
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;

    returnAux = ll_get(this,index);
    //Pregunto xq no se si quiso borrar una carga valida valor NULL
    if( ll_remove(this, index) ){
        returnAux = NULL;
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this != NULL){
        returnAux = 0;
        if( ll_indexOf(this,pElement) != -1 ){
            returnAux = 1;
        }
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int length;
    void* pElement;
    if(this != NULL && this2 != NULL)
    {
        length = ll_len(this2);
        returnAux = 1;
        for(int i = 0; i < length; i++)
        {
            pElement = ll_get(this2, i);
            if( !ll_contains(this, pElement) )
            {
                returnAux = 0;
                break;
            }
        }
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int i;
    void* pElement;
    if(this != NULL && from >= 0 && to >= from && to <= ll_len(this) )
    {
        cloneArray = ll_newLinkedList();
        if(cloneArray != NULL){
                for(i = from; i < to;i++)
                {
                    pElement = ll_get(this, i);
                    if( ll_add(cloneArray, pElement) == -1){
                        ll_deleteLinkedList(cloneArray);
                        cloneArray = NULL;
                        break;
                    }

                }
        }
    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    return ll_subList(this, 0, ll_len(this));
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;

    void* pElement1;
    void* pElement2;

    int length;

    if(this!=NULL && (order == 0 || order == 1) && pFunc != NULL)
    {
        length = ll_len(this);
        for(int i = 0; i < length -1; i++){
            for(int j = i+1; j < length; j++){
                pElement1 = ll_get(this, i);
                pElement2 = ll_get(this, j);
                if( ((pFunc(pElement1, pElement2) < 0) && !order) ||
                    ((pFunc(pElement1, pElement2) > 0) && order) )
                {
                     ll_set(this, i, pElement2);
                     ll_set(this, j, pElement1);
                }
            }
        }

        returnAux=0;
    }
    return returnAux;

}

/** \brief Devuelve un nuevo linkedList con los elementos que hacen que la funcion retorne 1
 *
 * \param LinkedList* this Lista a filtrar
 * \param int (*pFunc) (void*) Funcion filtro
 * \return LinkedList* Lista nueva ya filtrada
 *
 */
LinkedList* ll_filter(LinkedList* this, int (*pFunc) (void*) ){
    LinkedList* filteredList = NULL;
    void* pElement = NULL;
    int length;
    if(this != NULL && pFunc != NULL){

        filteredList = ll_newLinkedList();
        if(filteredList != NULL){
            length = ll_len(this);
            for(int i = 0; i < length ; i++ ){
                pElement = ll_get(this,i);
                if( pFunc(pElement) ){
                    if( ll_add(filteredList, pElement) == -1){
                        ll_deleteLinkedList(filteredList);
                        filteredList = NULL;
                        break;
                    }
                }
            }
        }
    }
    return filteredList;
}

/** \brief Devuelve un nuevo linkedList con los elementos que hacen que la funcion retorne 1
 *
 * \param LinkedList* this Lista a filtrar
 * \param int (*pFunc) (void*) Funcion filtro
 * \return LinkedList* Lista nueva ya filtrada
 *
 */
LinkedList* ll_map(LinkedList* this, void* (*pFunc) (void*) ){
    LinkedList* mappedList = NULL;
    void* pElement = NULL;
    void* aux = NULL;
    int length;
    if(this != NULL && pFunc != NULL){

        mappedList = ll_newLinkedList();
        if(mappedList != NULL){
            length = ll_len(this);
            for(int i = 0; i < length ; i++ ){
                pElement = ll_get(this,i);
                if(pElement != NULL) aux = pFunc(pElement);
                if( aux != NULL && ll_add(mappedList, pElement) == -1){
                    ll_deleteLinkedList(mappedList);
                    mappedList = NULL;
                    break;
                }

            }
        }
    }
    return mappedList;
}
