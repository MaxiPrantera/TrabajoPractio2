#ifndef CASILLLERO_H
#define CASILLLERO_H
#include <iostream>
#include "jugador.h"
using namespace std;

/*[TDA CASILLERO]
    .turnosRestantesDesbloqueo: es la cantidad de turnos antes de poder desbloquearse
    .casilleroAnulado: indica si  en ese casillero puede colocarse una ficha
*/
enum Terreno {mar,aire,tierra};
enum Estado {vacio,ocupado,inactivo};
///enum Ficha {avion, barco, soldado};

class Casillero{

private:

    Jugador *contenidoCasillero;
    Terreno terreno;
    Estado estado;
    size_t turnosRestantesDesbloqueo;
    Ficha *contenidoCasillero;
    unsigned int x;
    unsigned int y;
    unsigned int z;
  

public:
    Casillero();
    virtual ~Casillero();
    //USAMOS GET DE LISTA.H
    int retornarX();
    int retornarY();
    int retornarZ();
    //setear solo con la ficha que tiene el puntero a jugador
    void vaciarCasillero();
    void setTurnosRestantesDesbloqueo(unsigned int cantidadTurnos);
    unsigned int getTurnosRestantesDesbloqueo(); 
    void decrementarTurnosRestantesDesbloqueo();
    void bloquearFichaDelCasillero();
    void anularCasillero();
    void desbloquearCasillero();
    void copiarCasillero(Casillero* dest);
    ///void bloquearFichaDelCasillero();
    void setFicha(Ficha* ficha);
    void anularCasillero();
};

#endif 
