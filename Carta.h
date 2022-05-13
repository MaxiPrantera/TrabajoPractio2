#ifndef CARTA_INCLUDED
#define CARTA_INCLUDED

    #include "Constantes.h"
    #include <string>

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

    public:
        //''Que constructores necesito???
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
        void tirarCarta();

        /*
         * Pre: Igualar dos variables del tipo carta.
         * Post: Iguala las caracteristicas de la primer carta a las de la segunda.
        */
        Carta& operator = (const Carta&);
    };

#endif // CARTA_INCLUDED
