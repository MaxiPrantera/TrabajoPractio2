//En una clase del cuatri pasado el profe explica la parte externa del tablero con un TDA de BatallaCampal
#include <cstdlib>
#include "BatallaCampal.h"
#include "Lista.h"
#include "Cola.h"
#include "tablero.h"
#include "jugador.h"


BatallaCampal::BatallaCampal(){ 
    this->jugadores = new Lista<Jugador>();
    this->tablero = new Tablero(10, 10, 5);
    this->mazo = new Cola<Carta>();
}

BatallaCampal::~BatallaCampal(){ 
/*
for(unsigned int x = 1;  x < this->tablero->getCantFilasTablero(); x++)
{
    for (unsigned int y = 1; y < this->tablero->getCantColumnasTablero(); y++)
    {
        for (unsigned int z = 1; z < this->tablero->getCantProfundidadTablero(); z++)
        {
            delete this->tablero->getCasillero(x, y, z);
        }
        //delete this->casilleros->get(x)->get(y);
    }
    //delete this->casilleros->get(x);
}
*/

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
{return "hola";}

Jugador* BatallaCampal::getJugador(unsigned int jugador)
{return &this->jugadores->get(jugador);}

unsigned int BatallaCampal::getCantidadCartasJugador(unsigned int jugador)
{/*return this->listaJugadores->get(jugador).getCantidadCartas();*/}

//Cambiar nombre de funcion getFichas por getCantidadFichas o algo asi y adentro simplemente retornar el getTamanio.
unsigned int BatallaCampal::getCantidadFichasJugador(unsigned int jugador)
{return getJugador(jugador)->getFichas();}

std::string BatallaCampal::getCartaJugador(unsigned int jugador, unsigned int carta)
{/*return getJugador(jugador)->getNombreCarta(carta);*/}

void BatallaCampal::jugadorAgregarFicha(Ficha* ficha, unsigned int jugador){
	 getJugador(jugador)->agregarFicha(ficha);
}

void BatallaCampal::jugadorRobarCarta(unsigned int jugador)
{

}

void BatallaCampal::jugadorTirarCarta(unsigned int jugador, unsigned int carta)
{

}

void BatallaCampal::jugadorMoverFicha(unsigned int jugador){
	int respuesta;
    std::cout << "Que ficha quiere mover?(Responda 0 si no quiere mover nada)";

    for(unsigned int ficha = 1; ficha < (getCantidadFichasJugador(jugador) + 1); ficha++){
        if (getFicha(jugador, ficha)->getEstado() == viva){
        	std::cout << ficha << "." << getFicha(jugador, ficha)->getUbicacionX()
             	 	  << "/"
             		  << getFicha(jugador, ficha)->getUbicacionY()
             	 	  << "/"
             		  << getFicha(jugador, ficha)->getUbicacionZ()
             	 	  << endl;
    	}
	}
    std::cin >> respuesta;
    char direccion;
    std::cout << "w = arriba, a = izquierda, s = abajo, d = derecha\n"
         	  << "q = diagonal izquierda arriba, e diagonal derecha arriba, z = diagonal abajo izquierda, c = diagonal abajo derecha\n";
    std::cin >> direccion;
//    getFicha(jugador,respuesta)->moverFicha(direccion, this->tablero);
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

Carta& BatallaCampal::getCartaARobar()
{return this->mazo->getFrente();}


//======Tablero======
Tablero* BatallaCampal::getTablero()
{return this->tablero;}

void BatallaCampal::iniciarEscenarioUno(unsigned int xmax, unsigned int ymax, unsigned int zmax){ //para decir que es tierra y que es agua
    this->tablero = new Tablero(xmax, ymax, zmax);

    for(unsigned int x=1;  x < this->tablero->getCantFilasTablero(); x++){ //x = 1 seria tierra o agua
        for(unsigned int y=1; y < this->tablero->getCantColumnasTablero(); y++){
            for(unsigned int z=1; z < this->tablero->getCantProfundidadTablero(); z++){
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

    for(unsigned int x=1;  x<this->tablero->getCantFilasTablero(); x++){
        for(unsigned int y=1; y<this->tablero->getCantColumnasTablero(); y++){
            for(unsigned int z=1; z<this->tablero->getCantProfundidadTablero(); z++){
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

    for(unsigned int x=1;  x<this->tablero->getCantFilasTablero(); x++){
        for(unsigned int y=1; y<this->tablero->getCantColumnasTablero(); y++){
            for(unsigned int z=1; z<this->tablero->getCantProfundidadTablero(); z++){
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

void BatallaCampal::jugadorDispara(unsigned int x, unsigned int y, unsigned int z)
{
    this->tablero->getCasillero(x, y, z)->setEstado(inactivo);
    if(this->tablero->getCasillero(x, y, z)->getEstado() == ocupado){
        this->tablero->getCasillero(x, y, z)->eliminarFicha();
    }
}

bool BatallaCampal::verificarGanador(Jugador* jugadorGanador){
    int cantidadDeJugadores = 0;
    this->jugadores->reiniciarCursor();
    while(this->jugadores->avanzarCursor()){
        if(this->jugadores->getCursor().getFichas() > 0){
            cantidadDeJugadores++;
        }
        if(cantidadDeJugadores == 1){
            jugadorGanador = &this->jugadores->getCursor();
        }
    }
    
    return cantidadDeJugadores == 1;
}

Ficha* BatallaCampal::getFicha(unsigned int jugador,unsigned int ficha){
	return getJugador(jugador)->getFichaAux(ficha);
}

Casillero* BatallaCampal::getCasillero(unsigned int x, unsigned int y, unsigned int z)
{
	return 0;
}
