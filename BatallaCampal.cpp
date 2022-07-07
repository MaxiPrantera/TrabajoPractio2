#include <cstdlib>
#include "BatallaCampal.h"

using namespace std;

BatallaCampal::BatallaCampal(){ 
    this->jugadores = new Lista<Jugador>();
    this->mazo = new Cola<Carta>();
    this->tablero = new Tablero(PROFUNDIDAD_TABLERO, ANCHO_TABLERO, ALTO_TABLERO);
    this->graficos = new Visualizador();
}

BatallaCampal::~BatallaCampal(){
    delete this->jugadores;
    delete this->mazo;
    delete this->tablero;
    delete this->graficos;
}



//=======Jugador=======
Lista<Jugador>* BatallaCampal::getJugadores()
{return this->jugadores;}

unsigned int BatallaCampal::getCantidadJugadores()
{return this->jugadores->getTamanio();}

std::string BatallaCampal::getNombreJugador(unsigned int jugador)
{return this->getJugador(jugador)->getNombre();}

Jugador* BatallaCampal::getJugador(unsigned int jugador)
{return &this->jugadores->get(jugador);}

unsigned int BatallaCampal::getCantidadCartasJugador(unsigned int jugador)
{return this->getJugador(jugador)->getCantidadCartas();}

unsigned int BatallaCampal::getCantidadFichasJugador(unsigned int jugador)
{return this->getJugador(jugador)->getCantidadFichas();}

std::string BatallaCampal::getCartaJugador(unsigned int jugador, unsigned int carta)
{return this->getJugador(jugador)->getNombreCarta(carta);}

Ficha* BatallaCampal::getFichaJugador(unsigned int jugador,unsigned int ficha)
{return this->getJugador(jugador)->getFicha(ficha);}

void BatallaCampal::jugadorAgregarSoldado(unsigned int jugador)
{getJugador(jugador)->agregarFicha(soldado, this->getTablero());}

void BatallaCampal::jugadorRobarCarta(unsigned int jugador)
{getJugador(jugador)->robarCarta(this->getMazo());}

void BatallaCampal::jugadorTirarCarta(unsigned int jugador)
{
	bool inputValido = false;
	unsigned int respuesta  = 0;
	do
	{
		cout << this->getJugador(jugador)->getNombre() << " que carta vas a tirar? (0 para no tirar carta): " << endl;
		for(unsigned int carta = 1; carta <= this->getCantidadCartasJugador(jugador); carta++){
			cout << carta << ". " << getCartaJugador(jugador, carta) << endl;
		}
		cin >> respuesta;

		if (respuesta >= 0 && respuesta <= this->getCantidadCartasJugador(jugador))
		{
			inputValido = true;
			if (respuesta != 0)
			{
				this->getJugador(jugador)->tirarCarta(respuesta, this->getTablero());
			}
		}
		else
		{
			cout << "Número de carta fuera del rango válido, intenta elegir un número entre 0 y tu cantidad de cartas" << endl;
		}
	}while(!inputValido);
}

void BatallaCampal::jugadorMoverFicha(unsigned int jugador){
	unsigned int ficha;
	bool fichaValida = false;
	do
	{
		ficha = this->getJugador(jugador)->elegirFicha("mover", true, false);
		if(ficha != 0){
			if(this->getFichaJugador(jugador,ficha)->getTipoFicha() == barco){
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

    if (ficha != 0){
		this->tablero->moverFicha(getFichaJugador(jugador,ficha));
    }
}

void BatallaCampal::jugadorDisparar(unsigned int jugador)
{
	this->tablero->disparar(this->tablero->elegirCoordenadas("disparar", false, true));
	for(unsigned int ficha = 1; ficha <= this->getJugador(jugador)->getCantidadFichas(); ficha++){
		if(this->getFichaJugador(jugador, ficha)->getEstado() == viva){
			if(this->getFichaJugador(jugador, ficha)->getTipoFicha() == avion){
				this->tablero->disparar(this->tablero->elegirCoordenadas("que el avion dispare", false, true));
				this->tablero->disparar(this->tablero->elegirCoordenadas("que el avion dispare", false, true));
			}else if(this->getFichaJugador(jugador, ficha)->getTipoFicha() == barco){
				this->tablero->tirarMisil(this->tablero->elegirCoordenadas("que el barco tire el misil", false, true));
			}
		}
	}
}

bool BatallaCampal::verificarGanador(Jugador* ganador){
    int cantidadDeJugadores = 0;
    *ganador = Jugador();

    this->jugadores->reiniciarCursor();
    while(this->jugadores->avanzarCursor()){
        if(this->jugadores->getCursor().getCantidadSoldadosVivos() > 0){
        	cantidadDeJugadores++;
            *ganador = this->jugadores->getCursor();
        }
    }

    return (cantidadDeJugadores <= 1);
}



//=======Mazo=======
void BatallaCampal::inicializarMazo()
{
    for(unsigned int carta = 0; carta < CANTIDAD_CARTAS_MAZO; carta++)
    {
        switch (rand()%6)
        {
        case 0:
            this->mazo->acolar(Carta(MISIL));
            break;
        case 1:
            this->mazo->acolar(Carta(AVION));
            break;
        case 2:
            this->mazo->acolar(Carta(BARCO));
            break;
        case 3:
            this->mazo->acolar(Carta(MOLOTOV));
            break;
        case 4:
            this->mazo->acolar(Carta(ESCUDO));
            break;
        case 5:
            this->mazo->acolar(Carta(TELETRANSPORTAR));
            break;
        default:
            break;
        }
    }
}

Cola<Carta>* BatallaCampal::getMazo()
{return this->mazo;}

string BatallaCampal::getCartaARobar()
{return this->mazo->getFrente().getNombre();}



//======Tablero======
Tablero* BatallaCampal::getTablero()
{return this->tablero;}

void BatallaCampal::iniciarEscenarioUno(){
	//Escenario completamente de tierra.
    for(unsigned int x=1;  x <= this->tablero->getCantidadProfundidad(); x++){
        for(unsigned int y=1; y <= this->tablero->getCantidadColumnas(); y++){
            for(unsigned int z=1; z <= this->tablero->getCantidadFilas(); z++){ //z = 1 seria tierra o agua
                if(z == 1){
                    this->tablero->getCasillero(x, y, z)->setTerreno(tierra);
                }else{
                    this->tablero->getCasillero(x, y, z)->setTerreno(aire);
                }
            }   
        }
    }
}

void BatallaCampal::iniciarEscenarioDos(){
	//Escenario con la mitad de agua y la otra mitad de tierra.
    for(unsigned int x=1;  x <= this->tablero->getCantidadProfundidad(); x++){
        for(unsigned int y=1; y <= this->tablero->getCantidadColumnas(); y++){
            for(unsigned int z=1; z <= this->tablero->getCantidadFilas(); z++){
                if(z == 1){
                    if(y <= x){
                        this->tablero->getCasillero(x, y, z)->setTerreno(tierra);
                    }else{
                        this->tablero->getCasillero(x, y, z)->setTerreno(agua);
                    }
                }else{
                    this->tablero->getCasillero(x, y, z)->setTerreno(aire);
                }
            }   
        }
    }
}

void BatallaCampal::iniciarEscenarioTres(){
	//Un mapa con una laguna que cruza toda la diagonal del medio (y == x).
    for(unsigned int x=1;  x <= this->tablero->getCantidadProfundidad(); x++){
        for(unsigned int y=1; y <= this->tablero->getCantidadColumnas(); y++){
            for(unsigned int z=1; z <= this->tablero->getCantidadFilas(); z++){
                if(z == 1){
                    if(y == x){
                        this->tablero->getCasillero(x, y, z)->setTerreno(agua);
                    }else{
                        this->tablero->getCasillero(x, y, z)->setTerreno(tierra);
                    }
                }else{
                    this->tablero->getCasillero(x, y, z)->setTerreno(aire);
                }
            }   
        }
    }
}

void BatallaCampal::mostrarTablero()
{
	for(unsigned int z = 1; z <= this->tablero->getCantidadFilas(); z++)
	{
		this->graficos->dibujarCapa(this->tablero, z);
		this->graficos->exportarImagen(z);
	}
}
