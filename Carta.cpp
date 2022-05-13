#include "Carta.h"
//DEBUG
#include <iostream>

using namespace std;

Carta::Carta(TipoDeCarta tipo)
{
    this->tipo = tipo;
    this->Nombre = this->tipoAString(this->tipo);
    //DEBUG
    cout<< "Instancia Carta con tipo de carta: " << this->Nombre << endl << "Constructor con argumento de tipo." << endl;
}

Carta::Carta(const Carta& carta)
{
    this->tipo = carta.tipo;
    this->Nombre = carta.Nombre;
    //DEBUG
    cout<< "Instancia carta con tipo: " << this->tipo << " - " << this->Nombre << endl << "Constructor copia." << endl;
}

Carta::~Carta()
{
    //DEBUG
    cout<< "Destruye carta con tipo: " << this->tipo << " - " << this->Nombre << endl;
}

TipoDeCarta Carta::getTipo()
{return this->tipo;}

string Carta::getNombre()
{return this->Nombre;}

string tipoAString(TipoDeCarta tipo)
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

Carta& Carta::operator=(const Carta& carta)
{
    this->tipo = carta.tipo;
    this->Nombre = carta.Nombre;
    return *this;
}