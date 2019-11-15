#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


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
    LinkedList* this= NULL;
    this = (LinkedList*)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
        this->size = 0;
        this->pFirstNode = NULL;
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
    if(this != NULL)
    {
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
    Node* pNode = NULL;
    if(this != NULL)
    {
        if(nodeIndex >=0 && nodeIndex <= ll_len(this))//si mi size es 3 el index esta entre 0,1 o 2
        {

            pNode = this->pFirstNode;



            while(nodeIndex>0)
            {
                pNode = pNode->pNextNode;//le va a asignar el pNode la direccion de memoria del siguiente hasta que nodeIndex llegue a 0
                nodeIndex--;//va a restarle hasta que llegue a 0 y ahi termina
            }
        }

    }
    return pNode;
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
    Node* pNode;
    if(this != NULL)
    {

        if(nodeIndex >=0 && nodeIndex < ll_len(this)+1)//si mi size es 3 el index esta entre 0,1 o 2 o podria ser <=lllen
        {
            pNode = (Node*)malloc(sizeof(Node));//cree un nuevo nodo
            pNode->pElement = pElement;

            if(nodeIndex == 0)//en este if el que era el primer nodo(posicion 0)pasa a ser 1 y el pNode(que estaba como flotando por ahi)ocupa el lugar en donde estaba el primer nodo
            {
                pNode->pNextNode = this->pFirstNode;
                this->pFirstNode = pNode;
            }
            else
            {
                pNode->pNextNode = getNode(this,nodeIndex -1)->pNextNode;//nodeIndex es igual al pNode y pNextNode es el siguiente al pNode entonces si al nodeIndex le resto uno su siguiente seria el pNode original,con esta linea estoy llenando el pNextNode con lo que estaria en el pNode
                getNode(this,nodeIndex -1)->pNextNode =  pNode;
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
int ll_add(LinkedList* this, void* pElement)//el ll_add solo agrega un elemento al final
{
    return addNode(this,ll_len(this),pElement);//el addNode agrega un elemento en cualquier parte
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
    Node* pNode = NULL;
    if(this != NULL)
    {
        if(index >= 0 && index < ll_len(this))
        {
            pNode = getNode(this,index); // con esto agarro la posicion del node
            returnAux = pNode->pElement; // con esto tomo el elemento del node
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
    if(this != NULL)
    {
        if(index >= 0 && index <= ll_len(this))
        {
            getNode(this,index)->pElement = pElement;
            returnAux = 0;
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
    int indice = 0;
    Node* nodeActual;
    Node* nodeNext;
    if(this != NULL)
    {

        if(index >=0 && index < ll_len(this))
        {
            nodeActual = this->pFirstNode;//nodo actual es el primer nodo
            nodeNext = nodeActual->pNextNode;//next es el que le sigue
            if(index == 0)
            {
                this->pFirstNode = nodeNext; // aca next se vuelve el primer nodo
                free(nodeActual); // y libero el actual que era el primero
            }
            else
            {
                while(indice < index-1)//mientras index no llegue a 0
                {
                    nodeActual = nodeActual->pNextNode; //node actual va a ser el que le sigue
                    nodeNext = nodeNext->pNextNode; // y next va a ser el que le sigue tambien
                    indice++;
                }
                nodeActual->pNextNode = nodeNext->pNextNode; // el que le sigue al actual va a ser el que le sigue al next
                free(nodeNext); //  y libero el next
            }

            this->size--;
            returnAux = 0;
        }

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
        while(ll_len(this) > 0)
        {
            ll_remove(this,0);//va a aplicarle un remove a la posicion 0 osea que si saco la posicion 0 la que le sigue se volvera 0 y asi hasta que no hayan mas
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
    if(this != NULL)
    {
        while(ll_len(this) > 0)
        {
            ll_remove(this,0);//va a aplicarle un remove a la posicion 0 osea que si saco la posicion 0 la que le sigue se volvera 0 y asi hasta que no hayan mas
            free(this);//elimina la lista pero primero se debe eliminar todo lo que la lista contenia por eso el remove
        }
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
    for(i = 0; i < ll_len(this); i++)
    {
        Node* pNode = ll_get(this,i);
        if(pElement == pNode)
        {
            returnAux = i;
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
        if(ll_len(this) == 0)
        {
            returnAux = 1;
        }
        else
        {
            returnAux = 0;
        }

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
    int returnAux = -1;
    if(this != NULL)
    {
        if(index >= 0 && index < ll_len(this)+1)
        {
            addNode(this,index,pElement);
            returnAux = 0;
        }
    }
    return returnAux;
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
    if(this != NULL)
    {
        if(index >= 0 && index < ll_len(this)+1)
        {
            returnAux = ll_get(this,index);
            ll_remove(this,index);
        }
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
    void* aux;
    int i = 0;
    if(this != NULL)
    {
        if(i >= 0)
        {
            for(i = 0;  i < ll_len(this); i++)
            {
                aux = ll_get(this,i);
                if(pElement == aux)
                {
                    returnAux = 1;
                    break;
                }

            }
            if(returnAux != 1)
            {
                returnAux = 0;
            }
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
    int r;
    void* auxDos;
    int i;
    if(this != NULL && this2 != NULL)
    {

        for(i = 0;  i < ll_len(this); i++)
        {
            auxDos = ll_get(this2,i);
            r = ll_contains(this,auxDos);
            if(r != 1)
            {
                returnAux = 0;
                break;
            }

        }
        if(returnAux != 0)
        {
            returnAux = 1;
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
    void* aux;
    if(this != NULL)
    {
        if(from >= 0 && from <= ll_len(this) && to >= from && to <= ll_len(this))
        {
            cloneArray = ll_newLinkedList();
            for(i = from; i < to; i++)
            {
                aux = ll_get(this,i);
                ll_add(cloneArray,aux);
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
    LinkedList* cloneArray = NULL;
    if(this != NULL)
    {
        cloneArray = ll_subList(this,0,ll_len(this));

    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order)
{
    int returnAux = -1;
    int i;
    int j;
    void* aux1;
    void* aux2;
    if(this != NULL && pFunc != NULL)
    {
        if(order == 1 || order == 0)
        {
            if(order > 0)
            {
                for(i = 0; i < ll_len(this)-1; i++)
                {
                    for(j = i+1; j < ll_len(this); j++)
                    {
                        aux1 = ll_get(this,i);
                        aux2 = ll_get(this,j);
                        if(pFunc(aux1,aux2) > 0)
                        {
                            ll_set(this,i,aux2);
                            ll_set(this,j,aux1);
                        }
                    }
                }
            }
            else
            {
                for(i = 0; i < ll_len(this)-1; i++)
                {
                    for(j = i+1; j < ll_len(this); j++)
                    {
                        aux1 = ll_get(this,i);
                        aux2 = ll_get(this,j);
                        if(pFunc(aux1,aux2) < 0)
                        {
                            ll_set(this,i,aux2);
                            ll_set(this,j,aux1);
                        }
                    }
                }
            }
            returnAux = 0;
        }

    }

    return returnAux;

}

