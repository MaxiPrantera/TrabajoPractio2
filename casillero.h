#ifndef CASILLLERO_H
#define CASILLLERO_H
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

    Jugador *contenidoCasillero;
    Terreno terreno;
    Estado estado;
    size_t turnosRestantesDesbloqueo;
    Ficha *contenidoCasillero;
    int x;
    int y;
    int z;
  

public:
    Casillero(int x, int y, int z);
    virtual ~Casillero();
    void setEstado(Estado estado);
<<<<<<< Updated upstream
=======
    void setTerreno(Terreno terreno);
>>>>>>> Stashed changes
    int getX();
    int getY();
    int getZ();
    Estado getEstado();
<<<<<<< Updated upstream
///setear solo con la ficha que tiene el puntero a jugador
    void vaciarCasillero();
    void setTurnosRestantesDesbloqueo(size_t cantidadTurnos);
    size_t getTurnosRestantesDesbloqueo(); 
    void decrementarTurnosRestantesDesbloqueo();
    Ficha* obtenerContenidoCasillero();
    void anularCasillero();
    void setTerreno(Terreno tipoTerreno);
    void eliminarContenidoCasillero();
    void copiarCasillero(Casillero* dest);
    


    ///void bloquearFichaDelCasillero();
=======
    Terreno getTerreno();
///setear solo con la ficha que tiene el puntero a jugador
    void setTurnosRestantesDesbloqueo(size_t cantidadTurnos);
    size_t getTurnosRestantesDesbloqueo(); 
    void decrementarTurnosRestantesDesbloqueo();
    void copiarCasillero(Casillero* dest);
    Ficha* obtenerContenidoCasillero();
>>>>>>> Stashed changes
    void setFicha(Ficha* ficha);
    void eliminarContenidoCasillero();
    void vaciarCasillero();
};

#endif