#include "jugador.h"

using namespace std;

/*
POST: Crea un jugador con atributos por default.
*/
Jugador::Jugador()
{
	this->nombre = "";
	this->fichas = new Lista<Ficha>();
	this->cartas = new Lista<Carta>();
}

/*
POST: Crea un jugador con un nombre
*/
Jugador::Jugador(string nombre)
{
	this->nombre = nombre;
	this->fichas = new Lista<Ficha>();
	this->cartas = new Lista<Carta>();
}

/**/
Jugador::~Jugador()
{
	delete this->fichas;
	delete this->cartas;
}

/*POST: Devuelve el nombre del jugador*/
string Jugador::getNombre()
{
	return this->nombre;
}

//F: Agregar post.
void Jugador::agregarFicha(TipoFicha tipo, Tablero* tablero){
	bool inputValido = false;
	Casillero* casillero;
	do
	{
		casillero = tablero->elegirCoordenadas("posicionar la ficha", (tipo != avion), false);
		if(casillero->getTerreno() != agua and tipo == barco)
		{
			cout << "Los barcos solo se pueden posicionar en el agua" << endl;
		}
		else
		{
			inputValido = true;
		}
	}while(!inputValido);

	this->fichas->agregar(Ficha(tipo, casillero->getX(), casillero->getY(), casillero->getZ(), this->nombre));
    if (casillero->getEstado() == ocupado){
		casillero->eliminarFicha();
		this->getFicha(this->getCantidadFichas())->eliminarFicha();
  	    cout << "Ambas fichas eliminadas" << endl;
    }
    else{
  	    casillero->setFicha(this->getFicha(this->getCantidadFichas()));
    }
}

//F: Agregar post.
unsigned int Jugador::getCantidadFichas(){
	return this->fichas->getTamanio();
}

/*
 * Pre: ---
 * Post: Devuelve la cantidad de fichas de tipo soldado vivas.
 */
unsigned int Jugador::getCantidadSoldadosVivos()
{
	unsigned int contadorFichas = 0;
	this->fichas->reiniciarCursor();
	while(this->fichas->avanzarCursor())
	{
		if(this->fichas->getCursor().getTipoFicha() == soldado && this->fichas->getCursor().getEstado() == viva)
		{
			contadorFichas++;
		}
	}
	return contadorFichas;
}

//F: Agregar post.
Ficha* Jugador::getFicha(unsigned int ficha)
{
	return &this->fichas->get(ficha);
}

/*
 * Pre: ---
 * Post: El jugador roba una carta para ser utilizada en alguno de sus turnos.
 */
void Jugador::robarCarta(Cola<Carta>* mazo)
{this->cartas->agregar(mazo->desacolar());}

/*
 * Pre: ---
 * Post: Devuelve la cantidad de cartas que tiene el jugador.
 */
unsigned int Jugador::getCantidadCartas()
{return this->cartas->getTamanio();}

/*
 * Pre: ---
 * Post: Devuelve el nombre de la carta en la posicion indicada.
 */
string Jugador::getNombreCarta(unsigned int carta)
{return this->cartas->get(carta).getNombre();}

/*
 * Pre: ---
 * Post: El jugador roba una carta para ser utilizada en alguno de sus turnos.
 */
void Jugador::tirarCarta(unsigned int carta, Tablero* tablero)
{
	switch(this->cartas->get(carta).getTipo())
	{
		case MISIL:
			this->tirarMisil(tablero);
			break;
		case AVION:
			this->ponerAvion(tablero);
			break;
		case BARCO:
			this->ponerBarco(tablero);
			break;
		case MOLOTOV:
			this->tirarMolotov(tablero);
			break;
		case ESCUDO:
			this->ponerEscudo(tablero);
			break;
		case REVIVIR:
			this->revivir(tablero);
			break;
	}

	this->cartas->remover(carta);
}

/*
 * Pre: ---.
 * Post: Tira un misil a un casillero el cual lo inhabilita y a todos los vecinos (3x3x3).
 */
void Jugador::tirarMisil(Tablero* tablero)
{tablero->tirarMisil(tablero->elegirCoordenadas("tirar el misil", false, true));}

/*
 * Pre: ---.
 * Post: Posiciona una ficha tipo avion en un casillero indicado.
 */
void Jugador::ponerAvion(Tablero* tablero)
{this->agregarFicha(avion, tablero);}

/*
 * Pre: ---.
 * Post: Posiciona una ficha tipo barco en un casillero valido indicado.
 */
void Jugador::ponerBarco(Tablero* tablero)
{this->agregarFicha(barco, tablero);}

/*
 * Pre: ---.
 * Post: Tira una molotov a un casillero el cual lo inhabilita y a todos los vecinos en horizontal por 3 turnos.
 */
void Jugador::tirarMolotov(Tablero* tablero)
{tablero->tirarMolotov(tablero->elegirCoordenadas("tirar la molotov", true, true));}

/*
 * Pre: ---.
 * Post: Le pone un escudo a una ficha y la protege del siguiente ataque directo (Misil o disparo o molotov).
 */
void Jugador::ponerEscudo(Tablero* tablero)
{
	//Funcion jodida, habria que cambiar varias otras funciones para controlar la muerte de las fichas
	//Atencion: funcion eliminarFicha.
	int fichaSeleccionada;

	cout << "A que ficha le quiere poner escudo?" << endl;

	for(unsigned int ficha = 1; ficha <= this->getCantidadFichas(); ficha++)
	{
		if (this->fichas->get(ficha).getEstado() == viva)
		{
			cout << ficha << ". " << this->fichas->get(ficha).getTipoFichaStr() << " - ";
			cout << this->fichas->get(ficha).getUbicacionX()
				 << "/"
				 << this->fichas->get(ficha).getUbicacionY()
				 << "/"
				 << this->fichas->get(ficha).getUbicacionZ()
				 << endl;
		}
	}

	cin >> fichaSeleccionada;
	this->fichas->get(fichaSeleccionada).darEscudo();
}

//Cambiar a teletransportarse.
/*
 * Pre: ---.
 * Post: Revive a la ficha indicada y habilita su casillero en el que murio.
 */
void Jugador::revivir(Tablero* tablero)
{
    //Hacer elegir a la ficha, hacer funcion analoga a pedir coordenada pero para fichas???
    //Si la ficha esta viva volver a pedir.
    //hacer que vuelva a estar vivo y que el casillero vuelva a esta habilitado.
    // pensar casos cuando en el casillero hay otra ficha muerta (murieron por "colision").
    // pensar casos cuando en el casillero hay una molotov activa.
}

/*
 * Pre: Igualar dos variables del tipo jugador.
 * Post: Iguala las caracteristicas de la primer carta a las de la segunda.
*/
Jugador& Jugador::operator=(const Jugador& jugador)
{
    this->nombre = jugador.nombre;
    delete this->fichas;
	this->fichas = new Lista<Ficha>();
    this->fichas->agregar(jugador.fichas);
    delete this->cartas;
	this->cartas = new Lista<Carta>();
    this->cartas->agregar(jugador.cartas);
    return *this;
}
