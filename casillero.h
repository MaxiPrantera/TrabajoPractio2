#ifndef CASILLLERO_H
#define CASILLLERO_H
#include "jugador.h"
#include "ficha.h"
#include <iostream>
using namespace std;

/*[TDA CASILLERO]
    .turnosRestantesDesbloqueo: es la cantidad de turnos antes de poder desbloquearse
    .casilleroAnulado: indica si  en ese casillero puede colocarse una ficha
*/
enum Terreno {agua,aire,tierra};
enum Estado {vacio,ocupado,inactivo};
///enum Ficha {avion, barco, soldado};

class Casillero{

private:

    Terreno terreno;
    Estado estado;
    unsigned int turnosRestantesDesbloqueo;
    Ficha *contenidoCasillero;
    int x;
    int y;
    int z;
  

public:
    Casillero();
    virtual ~Casillero();
    void setEstado(Estado estado);
    void setTerreno(Terreno terreno);
    int getX();
    int getY();
    int getZ();
    Estado getEstado();
    Terreno getTerreno();
///setear solo con la ficha que tiene el puntero a jugador
    void setTurnosRestantesDesbloqueo(unsigned int cantidadTurnos);
    unsigned int getTurnosRestantesDesbloqueo(); 
    void decrementarTurnosRestantesDesbloqueo();
    void copiarCasillero(Casillero* dest);
    Ficha* getContenidoCasillero();
    void setFicha(Ficha* ficha);
    void eliminarContenidoCasillero();
    void vaciarCasillero();
};

#endif