#ifndef NODO_INCLUDED
#define NODO_INCLUDED

template<class T> 
class Nodo
{
private:
	T dato;
	Nodo<T>* siguiente;
public:
	Nodo(const T&);
	bool haySiguiente();
	Nodo<T>* getSiguiente();
	void setSiguiente(Nodo<T>*);
	T& getValor();
	void setValor(const T&);
	~Nodo();
};


template<class T>
Nodo<T>::Nodo(const T& valor)
{
	this->dato = valor;
	this->siguiente = 0;
}

template<class T> 
bool Nodo<T>::haySiguiente()
{
	return (this->siguiente != 0);
}

template<class T>
Nodo<T>* Nodo<T>::getSiguiente()
{
	return (this->siguiente);
}

template<class T>
void Nodo<T>::setSiguiente(Nodo<T>* nuevoSig)
{
	this->siguiente = nuevoSig;
}

template<class T>
T& Nodo<T>::getValor()
{
	return (this->dato);
}

template<class T>
void Nodo<T>::setValor(const T& nuevoValor)
{
	this->dato = nuevoValor;
}

template<class T>
Nodo<T>::~Nodo(){}

#endif /* NODO_INCLUDED */
