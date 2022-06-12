//En una clase del cuatri pasado el profe explica la parte externa del tablero con un TDA de BatallaCampal
#include "BatallaCampal.h"
#include "Lista.h"
#include "Cola.h"
#include "tablero.h"
#include "jugador.h"


BatallaCampal::BatallaCampal(){ 
    this->tablero = new Tablero(10, 10, 5);
    this->listaJugadores = new Lista<Jugador>();
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
    delete this->listaJugadores;
    delete this->mazo;
}

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

Lista<Jugador>* BatallaCampal::getListaJugadores(){
    return this->listaJugadores;
}

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

void BatallaCampal::elegirCoordenadas(unsigned int* x, unsigned int* y, unsigned int* z, std::string msj, bool esPiso)
{
    bool xValida = false, yValida = false, zValida = false;
    cout << "Eliga las coordenadas para " << msj << endl;

    if(esPiso)
    {
        *z = 1;
        zValida = true;
    }

    do
    {
        if(!xValida) 
        {
            cout << "Ingrese la coordenada x: " << endl;
            cin >> *x;
            if (*x < 1 || *x > this->tablero->getCantProfundidadTablero())
            {
                cout << "Coordenada seleccionada fuera de rango, ingresar un numero entre 1 y el limite del tablero." << endl;
            }
            else
            {
                xValida = true;
            }
        }
        else if (!yValida)
        {
            cout << "Ingrese la coordenada y: " << endl;
            cin >> *y;
            if (*y < 1 || *y > this->tablero->getCantColumnasTablero())
            {
                cout << "Coordenada seleccionada fuera de rango, ingresar un numero entre 1 y el limite del tablero." << endl;
            }
            else
            {
                yValida = true;
            }
        }
        else if(!zValida)
        {
            cout << "Ingrese la coordenada z: " << endl;
            cin >> *z;
            if (*z < 1 || *z > this->tablero->getCantFilasTablero())
            {
                cout << "Coordenada seleccionada fuera de rango, ingresar un numero entre 1 y el limite del tablero." << endl;
            }
            else
            {
                zValida = true;
            }
        }        
    }while(!xValida || !yValida || !zValida);
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
    this->listaJugadores->reiniciarCursor();
    while(this->listaJugadores->avanzarCursor()){
        if(this->listaJugadores->getCursor().getFichas() > 0){
            cantidadDeJugadores++;
        }
        if(cantidadDeJugadores == 1){
            jugadorGanador = &this->listaJugadores->getCursor();
        }
    }
    
    return cantidadDeJugadores == 1;
}

Jugador* BatallaCampal::getJugador(unsigned int jugador){
	return this->listaJugadores->get(jugador);
}

unsigned int BatallaCampal::getCantidadFichasJugador(unsigned int){
	return getJugador(jugador)->getFichas;
}

Ficha* BatallaCampal::getFicha(unsigned int jugador,unsigned int ficha){
	return getJugador(jugador)->getListaFichas()->get(ficha);
}

void BatallaCampal::jugadorAgregarFicha(unsigned int jugador,Ficha* ficha){
	 getJugador(jugador)->agregarFicha(ficha);
}

void BatallaCampal::jugadorMueveFicha(Jugador* jugador){
	int respuesta;
    std::cout << "Que ficha quiere mover?(Responda 0 si no quiere mover nada)";
    
    for(int ficha = 1; ficha < (getCantidadFichasJugador(jugador) + 1); ficha++){
        if (getFicha(jugador, ficha)->getEstado() == vivo){
        	std::cout << ficha << "." << getFicha(jugador, ficha)->getUbicacionX()
             	 	  << "/";
             		  << getFicha(jugador, ficha)->getUbicacionY()
             	 	  << "/";
             		  << getFicha(jugador, ficha)->getUbicacionZ()
             	 	  << endl;
    	}
	}
    std::cin >> respuesta;
    char direccion;
    std::cout << "w = arriba, a = izquierda, s = abajo, d = derecha\n"
         	  << "q = diagonal izquierda arriba, e diagonal derecha arriba, z = diagonal abajo izquierda, c = diagonal abajo derecha\n";
    std::cin >> direccion;
    getFicha(jugador,respuesta)->moverFicha(direccion);	
}
