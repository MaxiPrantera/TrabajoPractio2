#include "Carta.h"
#include "tablero.h"
#include "jugador.h"
//DEBUG
#include <iostream>

using namespace std;



Carta::Carta()
{
    this->tipo = MISIL;
    this->Nombre = this->tipoAString(this->tipo);
    //DEBUG
    //cout<< "Instancia Carta con tipo de carta: " << this->Nombre << endl << "Constructor sin argumentos." << endl;
}

Carta::Carta(TipoDeCarta tipo)
{
    this->tipo = tipo;
    this->Nombre = this->tipoAString(this->tipo);
    //DEBUG
    //cout<< "Instancia Carta con tipo de carta: " << this->Nombre << endl << "Constructor con argumento de tipo." << endl;
}

Carta::Carta(const Carta& carta)
{
    this->tipo = carta.tipo;
    this->Nombre = carta.Nombre;
    //DEBUG
    //cout<< "Instancia carta con tipo: " << this->tipo << " - " << this->Nombre << endl << "Constructor copia." << endl;
}

Carta::~Carta()
{
    //DEBUG
    //cout<< "Destruye carta con tipo: " << this->tipo << " - " << this->Nombre << endl;
}

TipoDeCarta Carta::getTipo()
{return this->tipo;}

string Carta::getNombre()
{return this->Nombre;}

Carta& Carta::operator=(const Carta& carta)
{
    this->tipo = carta.tipo;
    this->Nombre = carta.Nombre;
    return *this;
}

string Carta::tipoAString(TipoDeCarta tipo)
{
    switch(tipo)
    {
        case MISIL:
            return "Misil";
        case AVION:
            return "Avion";
        case BARCO:
            return "Barco";
        case MOLOTOV:
            return "Molotov";
        case ESCUDO:
            return "Escudo";
        case REVIVIR:
            return "Revivir";
    }
}


void Carta::tirarCarta(Tablero* tablero, Jugador* jugador)
{
    switch(this->tipo)
    {
        case MISIL:
            tirarMisil(tablero);
        case AVION:
            ponerAvion(tablero, jugador);
        case BARCO:
            ponerBarco(tablero, jugador);
        case MOLOTOV:
            tirarMolotov(tablero);
        case ESCUDO:
            ponerEscudo(jugador);
        case REVIVIR:
            revivir(jugador);
    }
}

void Carta::tirarMisil(Tablero* tablero)
{
    string mensaje = "tirar el misil";
    unsigned int x, y, z;
    //Pide las coordenadas con el mensaje.
    //Hacer tres for anidados desde la respectiva coordenada menos uno hasta la misma mas uno
    //Dentro de los for anidados con el tablero pide el casillero en las coordenadas.
    //El casillero tendra una funcion "caeTiro()" la ejecuta.
    //A todo esto tener en cuenta que el casillero que pidio este en rango valido pero si esta en el
    // borde algunos vecinos no existiran, en esos casos el getCasillero de tablero me deberia 
    // devolver false y con eso yo ya se que no ejecuto el tiro ahi pero no constituye un error.
}

void Carta::ponerAvion(Tablero* tablero, Jugador* jugador)
{
    string mensaje = "poner el avion";
    unsigned int x, y, z;
    //Pide las coordenadas con el mensaje.
    //Pedir el casillero en las coordenadas al tablero.
    //Si el casillero no es tipo aire o esta inhabilitado volver a pedir.
    //Agregarle a la lista de fichas del jugador una ficha tipo avion en el casillero indicado.
    // decirle a tomio que se encargue del constructor y que en el mismo si se puso en un casillero
    // con otra ficha ya ahi, matarlas a las dos y hacer lo que tenga que hacer, sugerencia para eso
    // matarlas con pegar tiro.
}

void Carta::ponerBarco(Tablero* tablero, Jugador* jugador)
{
    string mensaje = "poner el barco";
    unsigned int x, y, z;
    //analogo a avion pero tiene que estar en el agua, la funcion de pedir coordenadas
    // podria tener un bool cuando solo quiero pedir piso y que siempre devuelva 0 en la z.
}

void Carta::tirarMolotov(Tablero* tablero)
{
    string mensaje = "tirar la molotov";
    unsigned int x, y, z;
    //analogo a misil pero solo lo puede tirar en piso y tipo terreno que no sea agua
    // ademas solo tendria que hacer dos for anidados para la x e y con z constante en 0
    // si el casillero fuese agua en alguna iteracion seguir adelante sin nada.
    //Revisar como es el estado quemado del casillero con mija con el tema de los turnos y eso.
}

void Carta::ponerEscudo(Jugador* jugador)
{
    //Hacer elegir a la ficha, hacer funcion analoga a pedir coordenada pero para fichas???
    //Si la ficha esta muerta volver a pedir.
    //setear alguna variable bool en tda ficha que haga que cuando le cae un misil o disparo
    // en vez de matarlo poner esa variable en false y ya la siguiente si moriria.
}

void Carta::revivir(Jugador* jugador)
{
    //Hacer elegir a la ficha, hacer funcion analoga a pedir coordenada pero para fichas???
    //Si la ficha esta viva volver a pedir.
    //hacer que vuelva a estar vivo y que el casillero vuelva a esta habilitado.
    // pensar casos cuando en el casillero hay otra ficha muerta (murieron por "colision").
    // pensar casos cuando en el casillero hay una molotov activa.
}