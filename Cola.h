#ifndef COLA_INCLUDED
#define COLA_INCLUDED

#include "Carta.h"
#include "Nodo.h"

template<class T>
class Cola
{
private:
    Nodo<T>* frente;
    Nodo<T>* ultimo;
    unsigned int tamanio;
public:
	Cola();
    Cola(const Cola<T>&);
    void acolar(const T&);
    void acolar(const Cola<T>&);
    T desacolar();
    unsigned int getTamanio();
    T& getFrente();
    T& getUltimo();
    bool estaVacia();
	virtual ~Cola();
};

/*
 * PRE: ---
 * POST: Inicializa la cola vacia.
 */ 
template<class T>
Cola<T>::Cola()
{
    this->frente = NULL;
    this->ultimo = NULL;
    this->tamanio = 0;
}

/*
 * PRE: ---
 * POST: Inicializa la cola identica a la pasada por parametros.
 */ 
template<class T>
Cola<T>::Cola(const Cola<T>& cola)
{
    this->frente = NULL;
    this->ultimo = NULL;
    this->tamanio = 0;
	this->acolar(cola);
}

/*
 * PRE: El elemento no es vacio.
 * POST: Agrega el elemento a lo ultimo de la cola.
 */
template<class T>
void Cola<T>::acolar(const T& elemento)
{
	Nodo<T>* nuevo = new Nodo<T>(elemento);
	if (this->estaVacia())
    {
        this->frente = nuevo;
	} 
    else
    {
        this->ultimo->setSiguiente(nuevo);
	}
	this->ultimo = nuevo;
    this->tamanio++;
}

/*
 * PRE: ---
 * POST: Agrega todos los elementos en orden a lo ultimo de la cola.
 */
template<class T>
void Cola<T>::acolar(const Cola<T>& cola)
{
	if(this->estaVacia())
    {
		this->frente = cola->frente;
	}
    else
    {
        this->ultimo->setSiguiente(cola->frente);
    }
    this->ultimo = cola->ultimo;
    this->tamanio += cola->tamanio;
}

/*
 * PRE: La cola tiene que tener al menos un elemento.
 * POST: Devuelve el elemento en el frente de la cola y lo remueve de la misma.
 */
template <class T>
T Cola<T>::desacolar()
{
    Nodo<T>* removido = this->frente;

    if (!this->estaVacia())
    {
        this->frente = removido->getSiguiente();
        this->tamanio--;
        if(this->tamanio == 0)
        {
            this->ultimo = NULL;
        }
        T elemento(removido->getValor());
        delete removido;
        return elemento;
    }
    else
    {
        throw "La cola no contiene ningun elemento";
    }
}

/*
 * PRE: ---
 * POST: Devuelve la cantidad de elementos que tiene la cola.
 */
template<class T>
unsigned int Cola<T>::getTamanio()
{return this->tamanio;}

/*
 * PRE: ---
 * POST: Devuelve el frente de la cola.
 */
template<class T>
T& Cola<T>::getFrente()
{return this->frente->getValor;}

/*
 * PRE: ---
 * POST: Devuelve el final de la cola.
 */
template<class T>
T& Cola<T>::getUltimo()
{return this->ultimo->getValor();}

/*
 * PRE: ---
 * POST: Indica si la cola esta vacia.
 */
template<class T>
bool Cola<T>::estaVacia()
{return (this->tamanio == 0);}

/*
 * PRE: ---
 * POST: Elimina la cola.
 */
template<class T>
Cola<T>::~Cola()
{
    while (!this->estaVacia())
    {
        this->desacolar();
    }
}

#endif /* COLA_INCLUDED */