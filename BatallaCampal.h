#ifndef BATALLACAMPAL_INCLUDED
#define BATALLACAMPAL_INCLUDED

#include "Lista.h"
#include "Cola.h"
#include "casillero.h"
#include "tablero.h"
#include "Carta.h"
#include "jugador.h"
#include "ficha.h"
#include "Visualizador.h"

class BatallaCampal{

private:
    Lista<Jugador>* jugadores;
    Cola<Carta>* mazo;
    Tablero* tablero;
    Visualizador* graficos;
public:
    /*
     * pre:
     * post:
     */
    BatallaCampal();

    /*
    * pre: Batalla campal inicializado
    * post: Elimina Batalla Campal
    */
    virtual ~BatallaCampal();



    //=======Jugador=======
    /*
	 * Pre: ---
	 * Post: Devuelve la lista de jugadores.
	 */
	Lista<Jugador>* getJugadores();

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
	 * Pre: El numero de la ficha debe ser valido (Dentro del rango).
	 * Post: Devuelve el puntero a ficha indicado.
  	 */
	Ficha* getFichaJugador(unsigned int, unsigned int);

    /*
     * Pre: El numero de jugador debe ser valido (Dentro del rango).
     * Post: El jugador indicado agrega una ficha.
     */
    void jugadorAgregarSoldado(unsigned int);

    /*
     * Pre: El numero de jugador debe ser valido (Dentro del rango).
     * Post: El indicado jugador roba una carta.
     */
    void jugadorRobarCarta(unsigned int);

    /*
     * Pre: El numero de jugador debe ser valido (Dentro del rango).
     * Post: El jugador indicado tira una carta.
     */
    void jugadorTirarCarta(unsigned int);

    /*
     * Pre: El numero de jugador debe ser valido (Dentro del rango).
     * Post: El jugador indicado mueve una ficha.
     */
    void jugadorMoverFicha(unsigned int);
    
    /*
     * Pre: El numero de jugador debe ser valido (Dentro del rango).
     * Post: El jugador indicado dispara.
     */
    void jugadorDisparar(unsigned int jugador);

    /*
     * Pre: ---
     * Post: Indica si un jugador gano el juego y lo devuelve.
     */
    bool verificarGanador(Jugador*);



    //=======Mazo=======
    /*
	 * Pre: El mazo debe estar vacío
	 * Post: Agrega las cartas de manera random al mazo.
	 */
	void inicializarMazo();

	/*
	 * Pre: ---
	 * Post: Devuelve el mazo.
	 */
	Cola<Carta>* getMazo();

	/*
	 * Pre: ---
	 * Post: Devuelve la carta a robar.
	 */
	std::string getCartaARobar();



    //=======Tablero=======
    /*
     * Pre: ---
     * Post: Devuelve el tablero.
     */
    Tablero* getTablero();

    /*
    * pre: x, y, z deben estar en rango
    * post: inicia el tablero en el escenario 1 ya configurado
    */
    void iniciarEscenarioUno();

    /*
    * pre: x, y, z deben estar en rango
    * post: inicia el tablero en el escenario 2 ya configurado
    */
    void iniciarEscenarioDos();

    /*
    * pre: x, y, z deben estar en rango
    * post: inicia el tablero en el escenario 3 ya configurado
    */
    void iniciarEscenarioTres();

    /*
	 * pre: ---
	 * post: Exporta el tablero en imagenes bmp para visualizar.
	 */
    void mostrarTablero();
};
#endif
