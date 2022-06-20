#include "Carta.h"
#include "tablero.h"
#include "jugador.h"
#include "ficha.h"

//DEBUG
#include <iostream>

using namespace std;


Carta::Carta()
{
    this->tipo = MISIL;
    this->Nombre = this->tipoAString(this->tipo);
}

Carta::Carta(TipoCarta tipo)
{
    this->tipo = tipo;
    this->Nombre = this->tipoAString(this->tipo);
}

Carta::Carta(const Carta& carta)
{
    this->tipo = carta.tipo;
    this->Nombre = carta.Nombre;
}

Carta::~Carta(){}

TipoCarta Carta::getTipo()
{return this->tipo;}

string Carta::getNombre()
{return this->Nombre;}

Carta& Carta::operator=(const Carta& carta)
{
    this->tipo = carta.tipo;
    this->Nombre = carta.Nombre;
    return *this;
}

string Carta::tipoAString(TipoCarta tipo)
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


void Carta::tirarCarta(Tablero* tablero)
{
    switch(this->tipo)
    {
        case MISIL:
            tirarMisil(tablero);
        case AVION:
            ponerAvion(tablero);
        case BARCO:
            ponerBarco(tablero);
        case MOLOTOV:
            tirarMolotov(tablero);
        case ESCUDO:
            ponerEscudo(tablero);
        case REVIVIR:
            revivir(tablero);
    }
}

void Carta::tirarMisil(Tablero* tablero)
{
//    unsigned int* posX;
//    unsigned int* posY;
//    unsigned int* posZ;
//    batallaCampal->elegirCoordenadas(posX, posY, posZ, "tirar el misil", false);
//
//    for(int x = *posX - 1; x <= *posX + 1; x++)
//    {
//        for(int y = *posY - 1; y <= *posY; y++)
//        {
//            for(int z = *posZ - 1; z <= *posZ; z++)
//            {
//                batallaCampal->jugadorDispara(x, y, z);
//            }
//        }
//    }
}

void Carta::ponerAvion(Tablero* tablero)
{
//    bool casilleroValido = false;
//    unsigned int* posX;
//    unsigned int* posY;
//    unsigned int* posZ;
//    Ficha* nuevoAvion;
//
//    do
//    {
//        batallaCampal->elegirCoordenadas(posX, posY, posZ, "poner el avion", false);
//        if(batallaCampal->getCasillero(*posX, *posY, *posZ)->getEstado() == inactivo || batallaCampal->getCasillero(*posX, *posY, *posZ)->getTerreno() != aire )
//        {
//            cout << "El casillero no pued tener un avion o porque esta inactivo o porque no esta en el aire" << endl;
//        }
//        else
//        {
//            casilleroValido = true;
//        }
//    }while (!casilleroValido);
//
//    nuevoAvion = new Ficha(avion, batallaCampal->getJugador(jugador), batallaCampal->getCasillero(*posX, *posY, *posZ));
//    batallaCampal->jugadorAgregarFicha(nuevoAvion, jugador);
}

void Carta::ponerBarco(Tablero* tablero)
{
//    string mensaje = "poner el barco";
//    unsigned int x, y, z;
//    //analogo a avion pero tiene que estar en el agua, la funcion de pedir coordenadas
//    // podria tener un bool cuando solo quiero pedir piso y que siempre devuelva 0 en la z.
}

void Carta::tirarMolotov(Tablero* tablero)
{
//    string mensaje = "tirar la molotov";
//    unsigned int x, y, z;
//    //analogo a misil pero solo lo puede tirar en piso y tipo terreno que no sea agua
//    // ademas solo tendria que hacer dos for anidados para la x e y con z constante en 0
//    // si el casillero fuese agua en alguna iteracion seguir adelante sin nada.
//    //Revisar como es el estado quemado del casillero con mija con el tema de los turnos y eso.
}

void Carta::ponerEscudo(Tablero* tablero)
{
//    Hacer elegir a la ficha, hacer funcion analoga a pedir coordenada pero para fichas???
//    Si la ficha esta muerta volver a pedir.
//    setear alguna variable bool en tda ficha que haga que cuando le cae un misil o disparo
//     en vez de matarlo poner esa variable en false y ya la siguiente si moriria.
}

void Carta::revivir(Tablero* tablero)
{
    //Hacer elegir a la ficha, hacer funcion analoga a pedir coordenada pero para fichas???
    //Si la ficha esta viva volver a pedir.
    //hacer que vuelva a estar vivo y que el casillero vuelva a esta habilitado.
    // pensar casos cuando en el casillero hay otra ficha muerta (murieron por "colision").
    // pensar casos cuando en el casillero hay una molotov activa.
}
