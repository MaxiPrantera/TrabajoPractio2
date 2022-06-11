#ifndef CARTA_INCLUDED
#define CARTA_INCLUDED

    #include "Constantes.h"
    #include <string>
    #include "tablero.h"
    #include "jugador.h"

    class Carta
    {
    private:
        TipoDeCarta tipo;
        std::string Nombre;

        /*
		 * Pre: Pasar por parametros una variable TipoDeCarta.
		 * Post: Devuelve el tipo de carta respresentado en un string.
		 */
		std::string tipoAString(TipoDeCarta);

        /*
		 * Pre: ---.
		 * Post: Tira un misil a un casillero el cual lo inhabilita y a todos los vecinos (3x3x3).
		 */
		void tirarMisil(Tablero*);

        /*
		 * Pre: ---.
		 * Post: Posiciona una ficha tipo avion en un casillero indicado.
		 */
		void ponerAvion(Tablero*, Jugador*);

        /*
		 * Pre: ---.
		 * Post: Posiciona una ficha tipo barco en un casillero valido indicado.
		 */
		void ponerBarco(Tablero*, Jugador*);

        /*
		 * Pre: ---.
		 * Post: Tira una molotov a un casillero el cual lo inhabilita y a todos los vecinos en horizontal por 3 turnos.
		 */
		void tirarMolotov(Tablero*);

        /*
		 * Pre: ---.
		 * Post: Le pone un escudo a una ficha y la protege del siguiente ataque directo (Misil o disparo).
		 */
		void ponerEscudo(Jugador*);

        /*
		 * Pre: ---.
		 * Post: Revive a la ficha indicada y habilita su casillero en el que murio.
		 */
		void revivir(Jugador*);
    public:
        /*
		 * Pre: ---
		 * Post: Instancia una carta del tipo MISIL.
		 */
		Carta();

        /*
         * Pre: Indicar el tipo de carta a ser instanciada.
         * Post: Instancia una carta del tipo indicado por parametros.
        */
        Carta(TipoDeCarta);
        
        /*
         * Pre: Pasar por parametros una instancia de carta existente.
         * Post: Instancia una carta nueva con las caracteristicas de la carta pasada por parametros.
        */
        Carta(const Carta&);

        /*
         * Pre: ---
         * Post: Destruye la instancia de carta.
        */
        virtual ~Carta();

        /*
         * Pre: ---
         * Post: Devuelve el tipo de carta.
        */
        TipoDeCarta getTipo();

        /*
         * Pre: ---
         * Post: Devuelve el nombre de la carta.
        */
        std::string getNombre();

        /*
         * Pre: ---
         * Post: Tira la carta y hace la accion correspondiente.
        */
        void tirarCarta(Tablero*, Jugador*);

        /*
         * Pre: Igualar dos variables del tipo carta.
         * Post: Iguala las caracteristicas de la primer carta a las de la segunda.
        */
        Carta& operator = (const Carta&);
    };

#endif // CARTA_INCLUDED
