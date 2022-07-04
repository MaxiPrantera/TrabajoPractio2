//En una clase del cuatri pasado el profe explica la parte externa del tablero con un TDA de BatallaCampal
#include <cstdlib>
#include "BatallaCampal.h"
#include "Lista.h"
#include "Cola.h"
#include "tablero.h"
#include "jugador.h"

using namespace std;

BatallaCampal::BatallaCampal(){ 
    this->jugadores = new Lista<Jugador>();
    this->tablero = new Tablero(10, 10, 5);
    this->mazo = new Cola<Carta>();
}

BatallaCampal::~BatallaCampal(){
    delete this->tablero;
    delete this->jugadores;
    delete this->mazo;
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
{return getJugador(jugador)->getCantidadFichas();}

std::string BatallaCampal::getCartaJugador(unsigned int jugador, unsigned int carta)
{return getJugador(jugador)->getNombreCarta(carta);}

void BatallaCampal::jugadorAgregarSoldado(unsigned int jugador)
{getJugador(jugador)->agregarFicha(soldado, this->getTablero());}

void BatallaCampal::jugadorRobarCarta(unsigned int jugador)
{
     getJugador(jugador)->robarCarta(this->getMazo());
}

void BatallaCampal::jugadorTirarCarta(unsigned int jugador)
{
	bool inputValido = false;
	int carta  = 0;
	do
	{
		cout << this->getJugador(jugador)->getNombre() << " que carta vas a tirar? (0 para no tirar carta): " << endl;
		for(unsigned int carta = 1; carta < (getCantidadCartasJugador(jugador) + 1); carta++){
			cout << carta << ". " << getCartaJugador(jugador, carta) << endl;
		}
		cin >> carta;

		if (carta >= 0 && carta <= this->getJugador(jugador)->getCantidadCartas())
		{
			inputValido = true;
			if (carta != 0)
			{
				cout << "Utilizaste tu carta " << this->getJugador(jugador)->getNombreCarta(carta) << endl;
				this->getJugador(jugador)->tirarCarta(carta, this->getTablero());
			}
		}
		else
		{
			cout << "Número de carta fuera del rango válido, intenta elegir un número entre 0 y tu cantidad de cartas" << endl;
		}
	}while(!inputValido);

}

void BatallaCampal::jugadorMoverFicha(unsigned int jugador){
	unsigned int respuesta;
	bool validacion = false;
    cout << "Que ficha quiere mover?(Responda 0 si no quiere mover nada)" << endl;

    for(unsigned int ficha = 1; ficha < (getCantidadFichasJugador(jugador) + 1); ficha++){
        if (getFicha(jugador, ficha)->getEstado() == viva and getFicha(jugador, ficha)->getTipoFicha() != barco ){
        	cout << ficha << ". " << getFicha(jugador, ficha)->getTipoFichaStr() << " - "
        	     << getFicha(jugador, ficha)->getUbicacionX()
             	 << "/"
                 << getFicha(jugador, ficha)->getUbicacionY()
             	 << "/"
             	 << getFicha(jugador, ficha)->getUbicacionZ()
             	 << endl;
    	}
	}
    cin >> respuesta;
    //respuesta = 1;
    if (respuesta != 0){
		cout << "Elija una Direccion"
			 << endl
			 << "w = adelante, a = izquierda, s = atras, d = derecha\n"
		     << "q = diagonal izquierda adelante, e diagonal derecha adelante, z = diagonal atras izquierda, c = diagonal atras derecha" << endl;
		if (getFicha(jugador,respuesta)->getTipoFicha() == avion){
			cout << "r = arriba, f = abajo" << endl;
		}
		this->tablero->moverFicha(getFicha(jugador,respuesta));
    }
}

void BatallaCampal::jugadorDisparar(unsigned int jugador)
{  
	this->tablero->disparar(this->tablero->elegirCoordenadas("disparar", false, true));
	for(unsigned int ficha = 1; ficha <= this->getJugador(jugador)->getCantidadFichas(); ficha++){
		if(this->getFicha(jugador, ficha)->getEstado() == viva){
			if(this->getFicha(jugador, ficha)->getTipoFicha() == avion){
				this->tablero->disparar(this->tablero->elegirCoordenadas("que el avion dispare", false, true));
				this->tablero->disparar(this->tablero->elegirCoordenadas("que el avion dispare", false, true));
			}else if(this->getFicha(jugador, ficha)->getTipoFicha() == barco){
				this->tablero->tirarMisil(this->tablero->elegirCoordenadas("que el barco tire el misil", false, true));
			}
		}
	}
}

//Revisar esta funcion porque si ningun jugador sobrevivio sigue el juego y no tiene sentido. Aparte creo que asigna mal el ganador.
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
    //Se puede mejorar asegurando siempre que haya misma cantidad de cartas por tipo.
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
            this->mazo->acolar(Carta(REVIVIR));
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

void BatallaCampal::iniciarEscenarioUno(unsigned int xmax, unsigned int ymax, unsigned int zmax){ //para decir que es tierra y que es agua
    this->tablero = new Tablero(xmax, ymax, zmax);

    for(unsigned int x=1;  x < this->tablero->getCantidadFilas(); x++){ //x = 1 seria tierra o agua
        for(unsigned int y=1; y < this->tablero->getCantidadColumnas(); y++){
            for(unsigned int z=1; z < this->tablero->getCantidadProfundidad(); z++){
                //DEBATIR CON GRUPO SI ES Z O X
                if(x == 1){  
                    this->tablero->getCasillero(x, y, z)->setTerreno(tierra);
                }else{
                    this->tablero->getCasillero(x, y, z)->setTerreno(aire);
                }
            }   
        }
    }
}

void BatallaCampal::iniciarEscenarioDos(unsigned int xmax, unsigned int ymax, unsigned int zmax){ //mitad agua, mitad tierra
    this->tablero = new Tablero(xmax, ymax, zmax);

    for(unsigned int x=1;  x<this->tablero->getCantidadFilas(); x++){
        for(unsigned int y=1; y<this->tablero->getCantidadColumnas(); y++){
            for(unsigned int z=1; z<this->tablero->getCantidadProfundidad(); z++){
                //DEBATIR TODO CON GRUPO
                if(x == 1){  
                    if(y < z){
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

void BatallaCampal::iniciarEscenarioTres(unsigned int xmax, unsigned int ymax, unsigned int zmax){ //LAGUNA
    this->tablero = new Tablero(xmax, ymax, zmax);

    for(unsigned int x=1;  x<this->tablero->getCantidadFilas(); x++){
        for(unsigned int y=1; y<this->tablero->getCantidadColumnas(); y++){
            for(unsigned int z=1; z<this->tablero->getCantidadProfundidad(); z++){
                if(x == 1){  //EN UN MAPA DE 10X10 LOS PUNTOS DE LA LAGUNA SON DEL 4,4 AL 4,7 Y DEL 7,4 AL 7,7
                    if(y < z){
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



Ficha* BatallaCampal::getFicha(unsigned int jugador,unsigned int ficha){
	return getJugador(jugador)->getFicha(ficha);
}

Casillero* BatallaCampal::getCasillero(unsigned int x, unsigned int y, unsigned int z)
{
	return 0;
}
