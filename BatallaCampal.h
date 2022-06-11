#ifndef BATALLACAMPAL_INCLUDED
#define BATALLACAMPAL_INCLUDED
#include "tablero.h"
#include "Lista.h"

class BatallaCampal{

private:
    Tablero* tablero;
    Lista<Jugador>* listaJugadores;

public:
    /*
    * pre:
    * post: 
    */
    BatallaCampal();

    /*
    * pre: x, y, z deben estar en rango
    * post: inicia el tablero en el escenario 1 ya configurado
    */

    void iniciarEscenarioUno(unsigned int xMax, unsigned int yMax, unsigned int zMax);

    /*
    * pre: x, y, z deben estar en rango
    * post: inicia el tablero en el escenario 2 ya configurado
    */

    void iniciarEscenarioDos(unsigned int xMax, unsigned int yMax, unsigned int zMax);

    /*
    * pre: x, y, z deben estar en rango
    * post: inicia el tablero en el escenario 3 ya configurado
    */

    void iniciarEscenarioTres(unsigned int xMax, unsigned int yMax, unsigned int zMax);

    /*
     * Pre: El mazo debe estar vacío
     * Post: Agrega las cartas de manera random al mazo.
     */
    void inicializarMazo(Cola<Carta>*);

    /*
     * Pre: ---
     * Post: Devuelve las coordenadas validas seleccionadas por el usuario del tablero.
     */
    void elegirCoordenadas(unsigned int*, unsigned int*, unsigned int*, std::string);

    Lista<Jugador>* getListaJugadores();
    /*
    * pre: Batalla campal inicializado
    * post: Elimina Batalla Campal
    */
    virtual ~BatallaCampal();
};
/*
int main(){

    BatallaCampal * batallaCampal = new BatallaCampal();
    batallaCampal->incializar();
    batallaCampal->jugar();

    delete batallaCampal;
}
*/
#endif