#include "BatallaCampal.h"

/*
BatallaCampal::BatallaCampal(){ 
}

BatallaCampal::~BatallaCampal(){ 
}
*/
void BatallaCampal::iniciarEscenarioUno(size_t cantFilas, size_t cantColumnas, size_t cantEnProfundidad){ //para decir que es tierra y que es agua
    this->tablero = new Tablero(cantFilas, cantColumnas, cantEnProfundidad);

    for(size_t fila=1;  fila<this->cantFilas; fila++){ //fila = 1 seria tierra o agua
        for(size_t columna=1; columna<this->cantColumnas; columna++){
            for(size_t profundidad=1; profundidad<this->cantEnProfundidad; profundidad++){
                if(fila == 1){  
                    this->tablero->getCasillero(size_t fila, size_t columna, size_t columna)->setTerreno(tierra);
                }else{
                    this->tablero->getCasillero(size_t fila, size_t columna, size_t columna)->setTerreno(aire);
                }
            }   
        }
    }
}

void BatallaCampal::iniciarEscenarioUno(size_t cantFilas, size_t cantColumnas, size_t cantEnProfundidad){ //mitad agua, mitad tierra
    this->tablero = new Tablero(cantFilas, cantColumnas, cantEnProfundidad);

    for(size_t fila=1;  fila<this->cantFilas; fila++){
        for(size_t columna=1; columna<this->cantColumnas; columna++){
            for(size_t profundidad=1; profundidad<this->cantEnProfundidad; profundidad++){
                if(fila == 1){  
                    if(columna < profundidad){
                        this->tablero->getCasillero(size_t fila, size_t columna, size_t profundidad)->setTerreno(tierra);
                    }else{
                        this->tablero->getCasillero(size_t fila, size_t columna, size_t profundidad)->setTerreno(agua);
                    }
                }else{
                    this->tablero->getCasillero(size_t fila, size_t columna, size_t profundidad)->setTerreno(aire);
                }
            }   
        }
    }
}
