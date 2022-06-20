#ifndef LISTA_INCLUDED
#define LISTA_INCLUDED

#include "Nodo.h"

template<class T> 
class Lista
{
private:
	Nodo<T>* primero;
	unsigned int tamanio;
	Nodo<T>* cursor;
    
	Nodo<T>* getNodo(unsigned int);
    bool posicionValida(unsigned int);
public:
	Lista();
	Lista(const Lista<T>&);
	bool vacia();
	unsigned int getTamanio();
	void agregar(const T&);
	void agregar(const T&, unsigned int);
	void agregar(Lista<T>*);
	T& get(unsigned int);
	void asignar(const T&, unsigned int);
	void remover(unsigned int);
	void reiniciarCursor();
	bool avanzarCursor();
	T& getCursor();
	~Lista();
};


/*
 * Pre: ---
 * Post: lista vacia.
 */
template<class T> 
Lista<T>::Lista()
{
	this->primero = 0;
	this->tamanio = 0;
	this->cursor = 0;
}

/*
 * Pre: ---
 * Post: lista igual a la pasada por parametros.
 */
template<class T> 
Lista<T>::Lista(const Lista<T>& lista)
{
	this->primero = 0;
	this->tamanio = 0;
	this->cursor = 0;
	this->agregar(lista);
}

/*
 * Pre: ---
 * Post: Indica si la lista esta vacia o no.
 */
template<class T>
bool Lista<T>::vacia()
{
	return (this->tamanio == 0);
}

/*
 * Pre: ---
 * Post: Devuelve el tamaño de la lista.
 */
template<class T>
unsigned int Lista<T>::getTamanio()
{
	return (this->tamanio);
}

/*
 * Pre: ---
 * Post: Agrega un nodo al final de la lista.
 */
template<class T>
void Lista<T>::agregar(const T& elemento)
{
	this->agregar(elemento, this->tamanio + 1);
}

/*
 * Pre: La posicion indicada se debe encontrar dentro de los limites de la lista (1 y tamanio + 1)
 * Post: Agrega un nodo en la posicion pasada por parametros.
 */
template<class T>
void Lista<T>::agregar(const T& elemento, unsigned int posicion)
{
    //Valida la posición.
	if((posicionValida(posicion)) || (posicion == this->tamanio + 1))
    { 
		Nodo<T>* nuevoNodo = new Nodo<T>(elemento);
		if(posicion == 1)
        {
			nuevoNodo->setSiguiente(this->primero);
			this->primero = nuevoNodo;
		} 
        else
        {
			Nodo<T>* nodoAnterior = this->getNodo(posicion - 1);
			nuevoNodo->setSiguiente(nodoAnterior->getSiguiente());
			nodoAnterior->setSiguiente(nuevoNodo);
		}
		this->tamanio++;
		this->reiniciarCursor();
	}
}

/*
 * Pre: ---
 * Post: Agrega la lista pasada por parametros al final de esta lista.
 */
template<class T>
void Lista<T>::agregar(Lista<T>* lista)
{
	lista->reiniciarCursor();
	while(lista->avanzarCursor())
    {
		this->agregar(lista->getCursor());
	}
}

/*
 * Pre: La posicion indicada se debe encontrar dentro de los limites de la lista (1 y tamanio)
 * Post: Devuelve el Nodo en la posicion pasada por parametros.
 */
template<class T>
T& Lista<T>::get(unsigned int posicion)
{
	if(not posicionValida(posicion))
    {
		throw "POSICION INVALIDA";
	}
	return (this->getNodo(posicion)->getValor());
}

/*
 * Pre: La posicion indicada se debe encontrar dentro de los limites de la lista (1 y tamanio)
 * Post: Modifica el nodo en la posicion indicada por el valor pasado por parametros.
 */
template<class T>
void Lista<T>::asignar(const T& elemento, unsigned int posicion)
{
	if(posicionValida(posicion))
    {
		this->getNodo(posicion)->setValor(elemento);
	}
}

/*
 * Pre: La posicion indicada se debe encontrar dentro de los limites de la lista (1 y tamanio)
 * Post: Elimina el nodo en la posicion indicada.
 */
template<class T>
void Lista<T>::remover(unsigned int posicion)
{
	if(posicionValida(posicion))
    {
		Nodo<T>* nodoRemovido;
		if(posicion == 1)
        {
			nodoRemovido = this->primero;
			this->primero = this->primero->getSiguiente();
		} 
        else
        {
			Nodo<T>* nodoAnterior = this->getNodo(posicion - 1);
			nodoRemovido = nodoAnterior->getSiguiente();
			nodoAnterior->setSiguiente(nodoRemovido->getSiguiente());
		}
		delete nodoRemovido;
		this->tamanio--;
		this->reiniciarCursor();
	}
}

/*
 * Pre: ---
 * Post: Reinicia el cursor para una nueva iteración.
 */
template<class T>
void Lista<T>::reiniciarCursor()
{
	this->cursor = 0;
}

/*
 * Pre: La iteracion ya fue inicializada con el metodo reiniciarCursor()
 *      y ningun elemento fue agregado ni removido desde entonces.
 * Post: Mueve el cursor hacia el siguiente nodo.
 *       Ademas indica si el mismo es nulo (se termino la iteracion o es una lista vacia).
 */
template<class T>
bool Lista<T>::avanzarCursor()
{
	if(this->cursor == 0)
    {
		this->cursor = this->primero;
	} 
    else
    {
		this->cursor = this->cursor->getSiguiente();
	}
	return (this->cursor != 0);
}

/*
 * Pre: El cursor se encuentra sobre un elemento valido de la lista (no nulo).
 * Post: Devuelve el valor del nodo sobre el que esta posicionado el cursor.
 */
template<class T>
T& Lista<T>::getCursor()
{
	if(this->cursor == 0)
    {
		throw "CURSOR ESTA 0";
	}
	return (this->cursor->getValor());
}

/*
 * Pre: ---
 * Post: Destruye la lista.
 */
template<class T>
Lista<T>::~Lista()
{
	for(unsigned int i = 1; i <= this->tamanio; i++)
    {
        this->remover(1);
    }
}

/*
 * Pre: La posicion indicada se debe encontrar dentro de los limites de la lista (1 y tamanio)
 * Post: Devuelve un puntero al nodo en la posicion indicada.
 */
template<class T>
Nodo<T>* Lista<T>::getNodo(unsigned int posicion)
{
    if (posicionValida(posicion))
    {
        Nodo<T>* nodoActual = this->primero;
        for(unsigned int i = 1; i < posicion; i++)
        {
            nodoActual = nodoActual->getSiguiente();
        }
        return nodoActual;
    }
	else
	{
		throw "Posicion Fuera del rango de la lista.";
	}
}

/*
 * Pre: ---
 * Post: Devuelve si la posicion indicada se encuentra dentro de los limites de la lista (1 y tamanio).
 */
template <class T>
bool Lista<T>::posicionValida(unsigned int posicion)
{
    return ((posicion > 0) && (posicion <= this->tamanio));
}


#endif /* LISTA_INCLUDED */
