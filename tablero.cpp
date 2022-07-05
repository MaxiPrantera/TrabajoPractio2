#include <iostream>
#include <cstdlib>
#include "Lista.h"
#include "tablero.h"
#include "casillero.h"

using namespace std;

//F: Falta pre y post.
Tablero::Tablero(unsigned int cantProfundidad, unsigned int cantColumnas, unsigned int cantFilas) {

    if ((cantProfundidad < 2) || (cantColumnas < 2) || (cantFilas < 2))
    {
        string DimensionInvalida = "dimensiones de tablero incorrectas";
        throw DimensionInvalida;
    }

    this->profundidad=cantProfundidad;
    this->ancho=cantColumnas;
    this->alto=cantFilas; 
    this->casilleros = new Lista<Lista<Lista<Casillero> > >();

    for(unsigned int x=1;  x<=this->profundidad; x++)
    {
        this->casilleros->agregar(Lista<Lista<Casillero> >());
        for (unsigned int y=1; y<=this->ancho; y++)
        {
            this->casilleros->get(x).agregar(Lista <Casillero>());
            for (unsigned int z = 1; z <= this->alto; z++)
            {
                this->casilleros->get(x).get(y).agregar(Casillero(x, y, z));
            }
        }
    }
}

Tablero::~Tablero() {
    delete this->casilleros;
} 

/*
Pre: existe el tablero y el casillero solicitado
Post: devuelve el casillero ubicado en la posicion [profundidad][columna][fila]
*/
Casillero* Tablero::getCasillero(unsigned int x, unsigned int y, unsigned int z)
{ 
    if(!this->existeLaCasilla(x, y, z))
    {
        string CoordInvalidas = "coordenadas de casilleros invalidas";
        throw CoordInvalidas;
    }
    return &this->casilleros->get(x).get(y).get(z);
}

/*
Pre: existe el tablero
Post:Devuelve la profundidad que posee el tablero
*/
unsigned int Tablero::getCantidadProfundidad()
{
    return this->profundidad;
} 

/*
Pre: existe el tablero
Post:Devuelve la cantidad de columnas que posee el tablero
*/
unsigned int Tablero::getCantidadColumnas()
{
    return this->ancho;
}

/*
Pre: existe el tablero
Post:Devuelve la cantidad de filas que posee el tablero
*/
unsigned int Tablero::getCantidadFilas()
{
    return this->alto;
}

/*
Pre: existe el tablero
Post: Indica si las coordenadas pasadas son validas y estan dentro del rango del tablero.
*/
bool Tablero::existeLaCasilla(unsigned int x, unsigned int y, unsigned int z) {
    return ((x > 0) && (y > 0) && (z > 0) && (x <= this->profundidad) && (y <= this->ancho) && (z <= this->alto));
}

/*
 * Pre: ---
 * Post: Devuelve un casillero con coordenadas validas seleccionadas por el usuario.
 */
Casillero* Tablero::elegirCoordenadas(std::string msj, bool esPiso, bool aceptaInactivos)
{
    unsigned int x = 0, y = 0, z = 0;
    cout << "Elija las coordenadas para " << msj << endl;
    if(esPiso)
    {
        z = 1;
    }

    do
    {
        if(x == 0)
        {
            cout << "Ingrese la coordenada x: " << endl;
            cin >> x;
            if (x < 1 || x > this->getCantidadProfundidad())
            {
                cout << "Coordenada seleccionada fuera de rango, ingresar un numero entre 1 y el limite del tablero." << endl;
                x = 0;
            }
        }
        else if (y == 0)
        {
            cout << "Ingrese la coordenada y: " << endl;
            cin >> y;
            if (y < 1 || y > this->getCantidadColumnas())
            {
                cout << "Coordenada seleccionada fuera de rango, ingresar un numero entre 1 y el limite del tablero." << endl;
                y = 0;
            }
        }
        else if(z == 0)
        {
            cout << "Ingrese la coordenada z: " << endl;
            cin >> z;
            if (z < 1 || z > this->getCantidadFilas())
            {
                cout << "Coordenada seleccionada fuera de rango, ingresar un numero entre 1 y el limite del tablero." << endl;
                z = 0;
            }
        }

        if (x != 0 && y != 0 && z != 0)
        {
            if (this->getCasillero(x, y, z)->getEstado() == inactivo && !aceptaInactivos)
            {
            	x = 0;
            	y = 0;
            	if (!esPiso)
            	{
                	z = 0;
            	}
                cout << "El casillero seleccionado esta inactivo, por favor seleccionar otro." << endl;
            }
        }
    }while(x == 0 || y == 0 || z == 0);

    return this->getCasillero(x, y, z);
}

/*
 * Pre: ---
 * Post: Mueve la ficha indicada a la direccion seleccionada por el usuario.
 */
void Tablero::moverFicha(Ficha* ficha){
	char direccion;
	bool validacion = false;
	do
	{

		cout << "Elija una Direccion"
			 << endl
			 << "w = adelante, a = izquierda, s = atras, d = derecha\n"
		     << "q = diagonal izquierda adelante, e diagonal derecha adelante, z = diagonal atras izquierda, c = diagonal atras derecha" << endl;
		if (ficha->getTipoFicha() == avion){
			cout << "r = arriba, f = abajo" << endl;
		}

		do
		{
			cin >> direccion;
			if (direccion != 'w' && direccion != 'a' && direccion != 's' && direccion != 'd' && direccion != 'q' && direccion != 'e' && direccion != 'z' && direccion != 'c' && direccion != 'r' && direccion != 'f'){
				cout << "Direccion invalida, seleccione otra" << endl;
			}
			else{
				validacion = true;
			}
		}
		while(!validacion);

		unsigned int x = ficha->getUbicacionX();
		unsigned int y = ficha->getUbicacionY();
		unsigned int z = ficha->getUbicacionZ();

		Casillero* casillero = getCasillero(x,y,z);
		casillero->setEstado(vacio);
		casillero->setFicha(0);

		switch (direccion){
			case IZQUIERDA:
				y--;
				break;

			case ADELANTE:
				x--;
				break;

			case DERECHA:
				y++;
				break;

			case ATRAS:
				x++;
				break;

			case DIAGONAL_IZQUERDA_ADELANTE:
				x--;
				y--;
				break;

			case DIAGONAL_DERECHA_ADELANTE:
				x--;
				y++;
				break;

			case DIAGONAL_IZQUERDA_ATRAS:
				x++;
				y--;
				break;

			case DIAGONAL_DERECHA_ATRAS:
				x++;
				y++;
				break;

			case ARRIBA:
				if (ficha->getTipoFicha() == avion){
					z++;
				}
				break;

			case ABAJO:
				if (ficha->getTipoFicha() == avion){
					z--;
				}
				break;
		}

		if (this->existeLaCasilla(x, y, z)){
			casillero = getCasillero(x,y,z);
			if (casillero->getEstado() == inactivo){
				cout << "Casillero inactivo no puedes moverte ahi, seleccione otro" << endl;
				validacion = false;
			}
			else
			{
				casillero->setFicha(ficha);
			}
		}
		else{
			cout << "Casillero fuera de rango, no puedes moverte ahi, seleccione otro" << endl;
			validacion = false;
		}
	}while(!validacion);
}

/*
 * Pre: ---
 * Post: Pega un disparo en el casillero indicado.
 */
void Tablero::disparar(Casillero* casillero)
{
    if(casillero->getEstado() == ocupado){
        casillero->eliminarFicha();
    }
    casillero->setEstado(inactivo);
}

/*
 * Pre: ---
 * Post: Tira un misil que explota en la posicion indicada y todos sus vecinos (3x3x3).
 */
void Tablero::tirarMisil(Casillero* casillero)
{
    for(unsigned int x = casillero->getX() - 1; x <= casillero->getX() + 1; x++)
    {
        for(unsigned int y = casillero->getY() - 1; y <= casillero->getY() + 1; y++)
        {
            for(unsigned int z = casillero->getZ() - 1; z <= casillero->getZ() + 1; z++)
            {
            	if(this->existeLaCasilla(x, y, z))
				{
					this->disparar(this->getCasillero(x, y, z));
				}
            }
        }
    }
}

/*
 * Pre: ---
 * Post: Tira una molotov que incendia el piso indicado y sus arlededores esceptuando los casilleros de agua (3x3).
 */
void Tablero::tirarMolotov(Casillero* casillero)
{
    for(unsigned int x = casillero->getX() - 1; x <= casillero->getX() + 1; x++)
    {
        for(unsigned int y = casillero->getY() - 1; y <= casillero->getY() + 1; y++)
        {
            if(this->existeLaCasilla(x, y, casillero->getZ()))
			{
            	if(this->getCasillero(x, y, casillero->getZ())->getTerreno() != agua)
				{
					this->disparar(this->getCasillero(x, y, casillero->getZ()));
				}
            }
        }
    }
}
