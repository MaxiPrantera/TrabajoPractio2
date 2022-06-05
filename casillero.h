#ifndef CASILLLERO_H
#define CASILLLERO_H
#include <iostream>
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
    bool casilleroAnulado;
    Ficha *contenidoCasillero;
    int x;
    int y;
    int z;
  

public:
    Casillero(int x, int y, int z);
    virtual ~Casillero();
    int retornarX();
    int retornarY();
    int retornarZ();
    bool estaCasilleroVacio();
    bool estaCasilleroAnulado();
///setear solo con la ficha que tiene el puntero a jugador
    void vaciarCasillero();
    void setTurnosRestantesDesbloqueo(size_t cantidadTurnos);
    size_t getTurnosRestantesDesbloqueo(); 
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
