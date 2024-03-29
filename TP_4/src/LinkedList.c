#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

Node* ll_newNode(void* pElement)
{
	Node* newNode = NULL;

	newNode = (Node*) malloc(sizeof(Node));

	if(newNode != NULL)
	{
		newNode->pElement = pElement;
	}

	return newNode;
}

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this = NULL;

    this = (LinkedList*) malloc(sizeof(LinkedList));

    if(this != NULL)
    {
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
	int len;
	Node* pNode = NULL;

	if(this != NULL && nodeIndex >= 0)
	{
		len = ll_len(this);

		if(len != 0 && nodeIndex < len) //Lista no tiene que estar vacia y el indice tiene que ser menor a la cantidad de nodos.
		{								//Claramente por que indice != elementos, indice 2 = 3 elementos.
			 pNode = this->pFirstNode; //Direccion del primer nodo;

			 if(pNode != NULL)
			 {
				 for(int i = 0;i < len; i++) //Recorremos los nodos mediante direcciones de memorias. Guardados en pNextNode;
				 {
					 if(nodeIndex == i) //digamos indice = 2.. 0 -> primer nodo, pNode = 0x140 , 1-> pNode = 0x180 2-> break;
					 {					//Nos quedamos con la direccion memoria del indice 2 o el nodo 3.
						 break;
					 }else{
						 pNode = pNode->pNextNode;
					 }
				 }
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
static int addNode(LinkedList* this, int nodeIndex, void* pElement)
{
    int returnAux = -1;
    Node* pAnterior;
    Node* pSiguiente;
    Node* nuevoNodo;
    int len;

    if(this != NULL && nodeIndex >= 0)
    {
    	len = ll_len(this);

    	if(nodeIndex <= len)
    	{
    		nuevoNodo = ll_newNode(pElement);

    		if(nuevoNodo != NULL)
    		{
    			if(nodeIndex == 0)
    			{
    				pAnterior = this->pFirstNode; //pFirstNode inicializado en NULL. lo guardamos.
    				this->pFirstNode = nuevoNodo; //La cabecera apunta al nuevo nodo.
    				nuevoNodo->pNextNode = pAnterior; //El nuevo nodo apunta a NULL anterior.

    				this->size++;
    				returnAux = 0;
    			}else{
    				pAnterior = getNode(this, nodeIndex-1); //-1 Por que queremos conseguir el anterior al nuevo index.

    				if(pAnterior != NULL)
    				{
    					pSiguiente = pAnterior->pNextNode; //El puntero siguiente va a ser el al que apuntaba el anterior, en este caso NULL
    					pAnterior->pNextNode = nuevoNodo; //El nodo anterior apunta a nuestro nuevo Nodo.
    					nuevoNodo->pNextNode = pSiguiente; //Nuestro nuevo nodo apunta al puntero que apuntaba el anterior antes. o sea NULL.

    					this->size++;
    					returnAux = 0;
    				}
    			}
    		}
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
    int returnAux = -1;
    int len;

    if(this != NULL)
    {
    	len = ll_len(this);

    	returnAux = addNode(this, len, pElement);
    }

    return returnAux;
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
    int len;
    Node* pNode = NULL;

    if(this != NULL && index >= 0)
    {
    	len = ll_len(this);

    	if(index < len)
    	{
    		pNode = getNode(this, index);

    		if(pNode != NULL)
    		{
    			returnAux = pNode->pElement;
    		}
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
    int len;
    Node* pNode = NULL;

    if(this != NULL && index >= 0)
    {
    	len = ll_len(this);

    	if(index < len)
    	{
    		pNode = getNode(this, index);

    		if(pNode != NULL)
    		{
    			pNode->pElement = pElement;
    			returnAux = 0;
    		}
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
    int len;
    Node* nodoEliminar;
    Node* pAnterior;
    Node* pSiguiente;

    if(this != NULL && index >= 0)
    {
    	len = ll_len(this);

    	if(index < len)
    	{
    		nodoEliminar = getNode(this, index);

    		if(nodoEliminar != NULL)
    		{
    			if(index == 0)
    			{
    				pSiguiente = nodoEliminar->pNextNode;
    				this->pFirstNode = pSiguiente;
    				free(nodoEliminar);
    				this->size--;
    				returnAux = 0;
    			}else{
    				pAnterior = getNode(this, index-1);

    				if(pAnterior != NULL)
    				{
    					pAnterior->pNextNode = nodoEliminar->pNextNode;
    					free(nodoEliminar);
    					this->size--;
    					returnAux = 0;
    				}
    			}
    		}
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
    int len;
    int i;

    if(this != NULL)
    {
    	len = ll_len(this);
    	i = len;

    	while(ll_len(this) != 0)
    	{
    		ll_remove(this, i);
    		i--;
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
    	if(ll_clear(this) == 0)
    	{
    		free(this);
    		returnAux = 0;
    	}
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
    int len;
    Node* pNode = NULL;

    if(this != NULL)
    {
    	len = ll_len(this);

    	if(len > 0)
    	{
    		for(int i = 0; i < len; i++)
    		{
    			pNode = getNode(this, i);

    			if(pNode != NULL && pNode->pElement == pElement)
    			{
    				returnAux = i;
    				break;
    			}
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
    	if(ll_len(this) != 0)
    	{
    		returnAux = 0;
    	}else{
    		returnAux = 1;
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

    if(this != NULL && index >= 0)
    {
		if(addNode(this, index, pElement) == 0)
		{
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
void* ll_pop(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* pNode = NULL;

    if(this != NULL && index >= 0)
    {
    	pNode = getNode(this, index);

    	if(pNode != NULL)
    	{
    		returnAux = pNode->pElement;
    		ll_remove(this, index);
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
    int len;
    Node* pNode = NULL;

    if(this != NULL)
    {
    	returnAux = 0;
    	len = ll_len(this);

    	for(int i = 0; i < len; i++)
    	{
    		pNode = getNode(this, i);

    		if(pNode != NULL && pNode->pElement == pElement)
    		{
    			returnAux = 1;
    			break;
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
    int len2;
    Node* pNode2 = NULL;
    void* pElement = NULL;

    if(this != NULL && this2 != NULL)
    {
    	returnAux = 1;
    	len2 = ll_len(this2);

    	for(int i = 0; i < len2; i++)
    	{
    		pNode2 = getNode(this2, i);

    		if(pNode2 != NULL)
    		{
    			pElement = pNode2->pElement;

    			if(ll_contains(this, pElement) == 0)
				{
					returnAux = 0;
					break;
				}
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
    int len;
    void* pElement = NULL;

    if(this != NULL && from >= 0)
    {
    	len = ll_len(this);

    	if(from < to && to <= len)
    	{
    		cloneArray = ll_newLinkedList();

			if(cloneArray != NULL)
			{
				for(int i = from; i <= to; i++)
				{
					pElement = ll_get(this, i);
					ll_add(cloneArray, pElement);
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
	LinkedList* cloneArray = NULL;
	int len;
	void* pElement = NULL;

	if(this != NULL)
	{
		len = ll_len(this);
		cloneArray = ll_newLinkedList();

		if(cloneArray != NULL)
		{
			for(int i = 0; i < len; i++)
			{
				pElement = ll_get(this, i);
				ll_add(cloneArray, pElement);
			}
		}
	}

	return cloneArray;
    /*LinkedList* cloneArray = NULL;

    if(this != NULL)
    {
    	cloneArray = ll_newLinkedList();

    	if(cloneArray != NULL)
    	{
    		cloneArray = this;
    	}
    }

    return cloneArray;*/
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
    int returnAux = -1;
    int len;
    void* auxElement1;
    void* auxElement2;

    if(this != NULL && pFunc != NULL && (order == 1 || order == 0))
    {
    	len = ll_len(this);

    	for(int i = 0; i < len-1; i++)
    	{
    		for(int j = i+1; j < len; j++)
    		{
    			auxElement1 = ll_get(this, i);
    			auxElement2 = ll_get(this, j);

    			if(order)
    			{
    				if(pFunc(auxElement1, auxElement2) == 1)
    				{
    					ll_set(this, i, auxElement2);
    					ll_set(this, j, auxElement1);
    				}
    			}else{
    				if(pFunc(auxElement1, auxElement2) == -1)
					{
						ll_set(this, i, auxElement2);
						ll_set(this, j, auxElement1);
					}
    			}
    		}
    	}

    	returnAux = 0;
    }

    return returnAux;

}

