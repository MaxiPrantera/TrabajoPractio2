#include "Carta.h"

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
        case TELETRANSPORTAR:
            return "Teletransportar";
    }
}

Carta& Carta::operator=(const Carta& carta)
{
    this->tipo = carta.tipo;
    this->Nombre = carta.Nombre;
    return *this;
}