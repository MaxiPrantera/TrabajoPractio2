//En una clase del cuatri pasado el profe explica la parte externa del tablero con un TDA de BatallaCampal
#include "tablero.h"
#include "BatallaCampal.h"


BatallaCampal::BatallaCampal(){ 
    Tablero* tablero = new Tablero*(10, 10, 5);
}

BatallaCampal::~BatallaCampal(){ 

for(unsigned int x = 1;  x < this->xMax; x++)
{
    for (unsigned int y = 1; y < this->yMax; y++)
    {
        for (unsigned int z = 1; z < this->zMax; z++)
        {
            delete this->casilleros->get(x)->get(y)->get(z);
        }
        delete this->casilleros->get(x)->get(y);
    }
    delete this->casilleros->get(x);
}

delete this->casilleros;

}

void BatallaCampal::iniciarEscenarioUno(unsigned int xmax, unsigned int ymax, unsigned int zmax){ //para decir que es tierra y que es agua
    this->casilleros = new Tablero(xmax, ymax, zmax);

    for(unsigned int x=1;  x<this->xmax; x++){ //x = 1 seria tierra o agua
        for(unsigned int y=1; y<this->ymax; y++){
            for(unsigned int z=1; z<this->zmax; z++){
                //DEBATIR CON GRUPO SI ES Z O X
                if(x == 1){  
                    this->casilleros->getCasillero(unsigned int x, unsigned int y, unsigned int z)->setTerreno(tierra);
                }else{
                    this->casilleros->getCasillero(unsigned int x, unsigned int y, unsigned int z)->setTerreno(aire);
                }
            }   
        }
    }
}

void BatallaCampal::iniciarEscenarioDos(unsigned int xmax, unsigned int ymax, unsigned int zmax){ //mitad agua, mitad tierra
    this->casilleros = new Tablero(xmax, ymax, zmax);

    for(unsigned int x=1;  x<this->xmax; x++){
        for(unsigned int y=1; y<this->ymax; y++){
            for(unsigned int z=1; z<this->zmax; z++){
                //DEBATIR TODO CON GRUPO
                if(x == 1){  
                    if(y < z){
                        this->casilleros->getCasillero(unsigned int x, unsigned int y, unsigned int z)->setTerreno(tierra);
                    }else{
                        this->casilleros->getCasillero(unsigned int x, unsigned int y, unsigned int z)->setTerreno(agua);
                    }
                }else{
                    this->casilleros->getCasillero(unsigned int x, unsigned int y, unsigned int z)->setTerreno(aire);
                }
            }   
        }
    }
}

void BatallaCampal::iniciarEscenarioTres(unsigned int xmax, unsigned int ymax, unsigned int zmax){ //LAGUNA
    this->casilleros = new Tablero(xmax, ymax, zmax);

    for(unsigned int x=1;  x<this->xmax; x++){
        for(unsigned int y=1; y<this->ymax; y++){
            for(unsigned int z=1; z<this->zmax; z++){
                if(x == 1){  //EN UN MAPA DE 10X10 LOS PUNTOS DE LA LAGUNA SON DEL 4,4 AL 4,7 Y DEL 7,4 AL 7,7
                    if(y < z){
                        this->casilleros->getCasillero(unsigned int x, unsigned int y, unsigned int z)->setTerreno(tierra);
                    }else{
                        this->casilleros->getCasillero(unsigned int x, unsigned int y, unsigned int z)->setTerreno(agua);
                    }
                }else{
                    this->casilleros->getCasillero(unsigned int x, unsigned int y, unsigned int z)->setTerreno(aire);
                }
            }   
        }
    }
}