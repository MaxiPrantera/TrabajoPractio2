#ifndef BATALLACAMPAL_INCLUDED
#define BATALLACAMPAL_INCLUDED
#include "tablero.h"

class BatallaCampal{

private:
    Tablero* tablero;

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