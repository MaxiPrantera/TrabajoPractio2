#ifndef CASILLLERO_H
#define CASILLLERO_H
#include <iostream>
using namespace std;

/*[TDA CASILLERO]
    .turnosRestantesDesbloqueo: es la cantidad de turnos antes de poder desbloquearse
    .casilleroAnulado: indica si  en ese casillero puede colocarse una ficha
*/
enum Terreno {mar,aire,tierra};

class Casillero{

private:

    Jugador *contenidoCasillero;
    Terreno terreno;
    size_t turnosRestantesDesbloqueo;
    bool casilleroAnulado;
    bool casilleroVacio;
    void vaciarCasillero();
   
  

public:
    Casillero();
    virtual ~Casillero();

    bool estaCasilleroVacio();
    bool estaCasilleroAnulado();
    void setTurnosRestantesDesbloqueo(size_t cantidadTurnos);
    size_t getTurnosRestantesDesbloqueo(); 
    void decrementarTurnosRestantesDesbloqueo();
    void bloquearFichaDelCasillero();
    void setJugadorEnCasillero(Jugador jugadorId);
    void moverJugadorEnCasillero(Casillero* dest);
    void insertarJugadorEnCasillero(Jugador* jugador);
    char obtenerIdDelCasillero();
    void anularCasillero();
    void desbloquearCasillero();

};

#endif 
