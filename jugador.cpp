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

/*POST: Devuelve la cantidad de fichas del jugador*/
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

/*
 * Pre: ---
 * Post: Devuelve la cantidad de cartas que tiene el jugador.
 */
unsigned int Jugador::getCantidadCartas()
{return this->cartas->getTamanio();}

/*POST: Devuelve la ficha indicada del jugador*/
Ficha* Jugador::getFicha(unsigned int ficha)
{
	return &this->fichas->get(ficha);
}

/*
 * Pre: ---
 * Post: Devuelve el nombre de la carta en la posicion indicada.
 */
string Jugador::getNombreCarta(unsigned int carta)
{return this->cartas->get(carta).getNombre();}

/*
 * Pre: ---
 * Post: Devuelve una ficha valida seleccionada por el usuario.
 */
unsigned int Jugador::elegirFicha(string msj, bool ceroDefault, bool aceptaBarcos)
{
	unsigned int fichaSeleccionada;
	bool fichaValida = false;

	if(ceroDefault)
	{msj += " (Ingrese 0 para no elegir ninguna)";}

	cout << "Seleccione la ficha para " << msj << ":" << endl;
	for(unsigned int ficha = 1; ficha <= this->getCantidadFichas(); ficha++)
	{
		if (this->getFicha(ficha)->getEstado() == viva && (aceptaBarcos || this->getFicha(ficha)->getTipoFicha() != barco))
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

	do
	{
		cin >> fichaSeleccionada;

		if(fichaSeleccionada >= 1 && fichaSeleccionada <= this->getCantidadFichas())
			fichaValida = (this->getFicha(fichaSeleccionada)->getEstado() == viva && (aceptaBarcos || this->getFicha(fichaSeleccionada)->getTipoFicha() != barco));
		else if(fichaSeleccionada == 0)
		{
			fichaValida = ceroDefault;
		}

		if(!fichaValida)
		{
			cout << "La ficha seleccionada no es valida, por favor ingrese un número válido. " << endl;
		}
	}while(!fichaValida);

	return fichaSeleccionada;
}

/*
 * Pre: ---
 * Post: Agrega la ficha a la lista del jugador y la valida.
 * 		 En caso de agregarla sobre otra ficha elimina ambas.
 */
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

	//F: revisar esto con el tema del escudo.
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

/*
 * Pre: ---
 * Post: El jugador roba una carta para ser utilizada en alguno de sus turnos.
 */
void Jugador::robarCarta(Cola<Carta>* mazo)
{this->cartas->agregar(mazo->desacolar());}

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
			this->ponerEscudo();
			break;
		case TELETRANSPORTAR:
			this->teletransportar(tablero);
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
void Jugador::ponerEscudo()
{this->getFicha(this->elegirFicha("poner el escudo", false, true))->darEscudo();}

/*
 * Pre: ---.
 * Post: Teletransporta a la ficha indicada al casillero deseado.
 */
void Jugador::teletransportar(Tablero* tablero)
{
	unsigned int fichaNumero;
	bool fichaValida = false;
	do
	{
		fichaNumero = this->elegirFicha("teletransportar", false, false);
		if(fichaNumero != 0){
			if(this->getFicha(fichaNumero)->getTipoFicha() == barco){
				cout << "Los barcos son inamovibles, por favor seleccione otra ficha." << endl;
			}
			else{
				fichaValida = true;
			}
		}
		else{
			fichaValida = true;
		}
	}while(!fichaValida);

    Ficha* ficha = this->getFicha(fichaNumero);
    Casillero* casillero = tablero->elegirCoordenadas("teletransportar a la ficha", (ficha->getTipoFicha() != avion), false);
    casillero->setFicha(ficha);
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
