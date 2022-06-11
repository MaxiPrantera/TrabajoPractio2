//En una clase del cuatri pasado el profe explica la parte externa del tablero con un TDA de BatallaCampal
#include "tablero.h"
#include "BatallaCampal.h"
#include "Lista.h"
#include "jugador.h"


BatallaCampal::BatallaCampal(){ 
    this->tablero = new Tablero(10, 10, 5);
    this->listaJugadores = new Lista<Jugador>();
}

BatallaCampal::~BatallaCampal(){ 

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

//delete this->casilleros;

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
    return listaJugadores;
}