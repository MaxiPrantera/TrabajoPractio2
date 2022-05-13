#ifndef CASILLLERO_H
#define CASILLLERO_H
#include <iostream>
using namespace std;

/*[TDA CASILLERO]
    .contenidoCasillero : Es la ficha almacenada por el casillero
    .turnosRestantesDesbloqueo: es la cantidad de turnos antes de poder desbloquearse
    .casilleroAnulado: indica si  en ese casillero puede colocarse una ficha
    .matrizDeVecinos: posee la matriz de vecinos del casillero
*/

class Casillero{

private:

    Ficha *contenidoCasillero;
    size_t turnosRestantesDesbloqueo;
    bool casilleroAnulado;
    void vaciarCasillero();
   
  

public:
    Casillero(char simboloFicha);
    virtual ~Casillero();

    bool estaCasilleroVacio();
    bool estaCasilleroAnulado();
    void copiarCasillero(Casillero* dest);
    void setTurnosRestantesDesbloqueo(size_t cantidadTurnos);
    size_t getTurnosRestantesDesbloqueo(); 
    void decrementarTurnosRestantesDesbloqueo();
    void bloquearFichaDelCasillero();
    void setSimboloFichaDelCasillero(char simboloFicha);
    char obtenerSimboloFichaDelCasillero();
    void anularCasillero();
    void desbloquearCasillero();

};

#endif 
