#include <iostream>
#include <cstdlib>
#include "Lista.h"
#include "tablero.h"
#include "casillero.h"

using namespace std;

Tablero::Tablero(unsigned int xMax, unsigned int yMax, unsigned int zMax) {

	//Revisar este if.
    if ((xMax < 2) || (yMax < 2) || (zMax < 2))
    {
        string DimensionInvalida = "dimensiones de tablero incorrectas";
        throw DimensionInvalida;
    }

    this->xMax=xMax;
    this->yMax=yMax;
    this->zMax=zMax; 
    this->casilleros = new Lista<Lista<Lista<Casillero> > >();
    
    //Lista<Lista <Lista<Casillero *>*>*> * filas  = new Lista<Lista <Lista<Casillero *>*>*>;

    for(unsigned int x=1;  x<=this->xMax; x++)
    {
        
        this->casilleros->agregar(Lista<Lista<Casillero> >());
        //Lista<Lista <Casillero *>*> *columnas = new Lista<Lista <Casillero *>*>;
        for (unsigned int y=1; y<=this->yMax; y++)
        {
            this->casilleros->get(x).agregar(Lista <Casillero>());
            //Lista<Casillero *> * profundidad = new Lista<Casillero *>;

            for (unsigned int z = 1; z <= this->zMax; z++)
            {
                this->casilleros->get(x).get(y).agregar(Casillero(x, y, z));
                //Casillero* nuevoCasillero = new Casillero();
                //profundidad->agregar(nuevoCasillero);
            }
            //columnas->agregar(profundidad);
        }
        //filas->agregar(columnas);
    }
    //this->casilleros = filas;
}

Tablero::~Tablero() {
//for(unsigned int x=0;  x<this->xMax; x++)
//{
//    for (unsigned int y=0; y<this->yMax; y++)
//    {
//        for (unsigned int z = 0; z < this->zMax; z++)
//        {
//            delete this->casilleros->get(x)->get(y)->get(z);
//        }
//        delete this->casilleros->get(x)->get(y);
//    }
//    delete this->casilleros->get(x);
//}

delete this->casilleros;
}

/* DESTRUCTOR VIEJO
     Lista<Lista<Lista<Casillero *>*>*> * filas = this->casilleros;

     while(filas->avanzarCursor())
     {
        Lista<Lista <Casillero *>*> *columnas = this->casilleros->getCursor();
        while(columnas->avanzarCursor())
        {

            Lista<Casillero *> * profundidad = columnas->getCursor();
            while(profundidad->avanzarCursor())
            {
                delete profundidad->getCursor();

            }delete profundidad;

        }delete columnas;

     }delete filas;
*/  

    
/*
Pre: existe el tablero y el casillero solicitado
Post: devuelve el casillero ubicado en la posicion [fila][columna][profundidad]
*/
Casillero* Tablero::getCasillero(unsigned int x, unsigned int y, unsigned int z)
{ 
    if((x <= 0) || (y<= 0) || (z <=0) || (x>this->xMax) || (y>this->yMax) ||(z>this->zMax))
    {
        string CoordInvalidas = "coordenadas de casilleros invalidas";
        throw CoordInvalidas;
    }
    return &this->casilleros->get(x).get(y).get(z);
}


/*
Pre: existe el casillero establecido y esta en el rango del tablero
Post:Establece la ficha del casillero ubicado en la posicion [fila][columna][profundidad] 
con el simbolo 'simboloFicha'*/
//void Tablero::setCasilla(unsigned int x, unsigned int y, unsigned int z, Ficha* simboloFicha) {
//
//    this->casilleros->get(x)->get(y)->get(z)->setFicha(simboloFicha);
//
//}

Lista<Lista<Lista<Casillero> > >* Tablero::obtenerMatrizTablero()
{
    return this->casilleros;
}   

bool Tablero::existeLaCasilla(unsigned int x, unsigned int y, unsigned int z) {
    if(this->xMax < x ||this->yMax < y ||this->zMax < z ||
        x< 1 || y<1 || z<1){
        return false;
    }
    return true;
}

/*
Pre: existe el tablero
Post:Devuelve la cantidad de filas que posee el tablero
*/
unsigned int Tablero::getCantidadFilas()
{
    return this->xMax;
}

/*
Pre: existe el tablero
Post:Devuelve la cantidad de columnas que posee el tablero
*/
unsigned int Tablero::getCantidadColumnas()
{
    return this->yMax;
}

/*
Pre: existe el tablero
Post:Devuelve la profundidad que posee el tablero
*/
unsigned int Tablero::getCantidadProfundidad()
{
    return this->zMax;
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
            //x = rand()%19 + 1;
            if (x < 1 || x > this->getCantidadFilas())
            {
                cout << "Coordenada seleccionada fuera de rango, ingresar un numero entre 1 y el limite del tablero." << endl;
                x = 0;
            }
        }
        else if (y == 0)
        {
            cout << "Ingrese la coordenada y: " << endl;
            cin >> y;
            //y = rand()%19 + 1;
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
            //z = rand()%5 + 1;
            if (z < 1 || z > this->getCantidadProfundidad())
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

void Tablero::moverFicha(Ficha* ficha){
	
	char direccion;
	bool validacion = false;
	do
	{
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

		switch (direccion){
			case IZQUIERDA:
				x--;
				break;

			case ADELANTE:
				y--;
				break;

			case DERECHA:
				x++;
				break;

			case ATRAS:
				y++;
				break;

			case DIAGONAL_IZQUERDA_ADELANTE:
				x--;
				y--;
				break;

			case DIAGONAL_DERECHA_ADELANTE:
				x++;
				y--;
				break;

			case DIAGONAL_IZQUERDA_ATRAS:
				x--;
				y++;
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
			validacion = true;
			casillero->setEstado(vacio);
			casillero = getCasillero(x,y,z);
			if (casillero->getEstado() == vacio){
				ficha->setPosicion(x, y, z);
				casillero->setFicha(ficha);
			}
			else if (casillero->getEstado() == ocupado){
				if (ficha->getEscudo() == true && casillero->obtenerContenidoCasillero()->getEscudo() == true){
					casillero->obtenerContenidoCasillero()->quitarEscudo();
					ficha->quitarEscudo();
				}
				casillero->eliminarFicha();
				ficha->eliminarFicha();
				if (ficha->getEstado() == viva){
					ficha->setPosicion(x, y, z);
					casillero->setFicha(ficha);
				}
				if (casillero->obtenerContenidoCasillero()->getEstado() == viva){
					casillero->setEstado(ocupado);
				}
			}
			else{
				cout << "Casillero inactivo no puedes moverte ahi, seleccione otro" << endl;
				validacion = false;
			}
		}
		else{
			cout << "Casillero fuera de rango, no puedes moverte ahi, seleccione otro" << endl;
			validacion = false;
		}
	}while(!validacion);
}

void Tablero::disparar(Casillero* casillero)
{
    if(casillero->getEstado() == ocupado){
        casillero->eliminarFicha();
    }
    casillero->setEstado(inactivo);
}


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

void Tablero::tirarMolotov(Casillero* casillero)
{
    for(unsigned int x = casillero->getX() - 1; x <= casillero->getX() + 1; x++)
    {
        for(unsigned int y = casillero->getY() - 1; y <= casillero->getY() + 1; y++)
        {
            if(this->existeLaCasilla(x, y, 1))
			{
            	if(this->getCasillero(x, y, 1)->getTerreno() != agua)
				{
					this->disparar(this->getCasillero(x, y, 1));
				}
            }
        }
    }
}


