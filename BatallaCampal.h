#ifndef BATALLACAMPAL_INCLUDED
#define BATALLACAMPAL_INCLUDED
#include "tablero.h"
#include "Lista.h"
#include "Cola.h"

class BatallaCampal{

private:
    Tablero* tablero;
    Lista<Jugador>* listaJugadores;
    Cola<Carta>* mazo;
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
     * Pre: La posicion es valida.
     * Post: Devuelve el casillero en la posicion indicada.
     */
    Casillero* getCasillero(unsigned int, unsigned int, unsigned int);

    /*
     * Pre: El mazo debe estar vacío
     * Post: Agrega las cartas de manera random al mazo.
     */
    void inicializarMazo();

    /*
     * Pre: ---
     * Post: Devuelve las coordenadas validas seleccionadas por el usuario del tablero.
     */
    void elegirCoordenadas(unsigned int*, unsigned int*, unsigned int*, std::string, bool);

    /*
     * Pre: ---
     * Post: Indica si un jugador gano el juego y lo devuelve.
     */
    bool verificarGanador();

    /*
     * Pre: ---
     * Post: Indica si un jugador gano el juego y lo devuelve.
     */
    bool verificarGanador(Jugador* jugadorGanador);

    /*
     * Pre: ---
     * Post: Devuelve la lista de jugadores.
     */
    Lista<Jugador>* getListaJugadores();

    /*
     * Pre: ---
     * Post: Devuelve la cantidad de jugadores.
     */
    unsigned int getCantidadJugadores();

    /*
     * Pre: El numero de jugador debe ser valido (Dentro del rango).
     * Post: Devuelve el nombre del jugador indicado.
     */
    std::string getNombreJugador(unsigned int);

    /*
     * Pre: El numero de jugador debe ser valido (Dentro del rango).
     * Post: Devuelve el puntero a jugador indicado.
     */
    Jugador* getJugador(unsigned int);

    /*
     * Pre: El numero de jugador debe ser valido (Dentro del rango).
     * Post: Devuelve la cantidad de cartas del jugador indicado.
     */
    unsigned int getCantidadCartasJugador(unsigned int);

    /*
     * Pre: El numero de jugador debe ser valido (Dentro del rango).
     * Post: Devuelve la cantidad de fichas del jugador indicado.
     */
    unsigned int getCantidadFichasJugador(unsigned int);

    /*
     * Pre: El numero de jugador debe ser valido (Dentro del rango).
     * Post: Devuelve la carta del jugador indicado.
     */
    std::string getCartaJugador(unsigned int, unsigned int);

    /*
     * Pre: El numero de jugador debe ser valido (Dentro del rango).
     * Post: El jugador indicado agrega una ficha.
     */
    void jugadorAgregarFicha(Ficha*, unsigned int);

    /*
     * Pre: El numero de jugador debe ser valido (Dentro del rango).
     * Post: El indicado jugador roba una carta.
     */
    void jugadorRobaCarta(unsigned int);

    /*
     * Pre: El numero de jugador debe ser valido (Dentro del rango).
     * Post: El jugador indicado tira una carta.
     */
    void jugadorTiraCarta(unsigned int, unsigned int);

    /*
     * Pre: El numero de jugador debe ser valido (Dentro del rango).
     * Post: El jugador indicado mueve una ficha.
     */
    void jugadorMueveFicha(unsigned int, unsigned int, char);

    /*
     * Pre: El numero de jugador debe ser valido (Dentro del rango).
     * Post: El jugador indicado dispara.
     */
    void jugadorDispara(unsigned int, unsigned int, unsigned int);

    /*
     * Pre: ---
     * Post: Devuelve el mazo.
     */
    Cola<Carta>* getMazo();

    /*
     * Pre: ---
     * Post: Devuelve la carta a robar.
     */
    Carta& getCartaARobar();

    /*
    * pre: Batalla campal inicializado
    * post: Elimina Batalla Campal
    */
    virtual ~BatallaCampal();
};
#endif