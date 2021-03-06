#include <iostream>
#include "Lista.h"
#include "tablero.h"
#include "casillero.h"
#define SIMBOLO_FICHA_VACIA ' '


Tablero::Tablero(size_t cantFilas, size_t cantColumnas, size_t cantEnProfundidad) {
    if ((cantFilas < 2) || (cantColumnas<2) || (cantEnProfundidad<2))
    {
        string DimensionInvalida = "dimensiones de tablero incorrectas";
        throw DimensionInvalida;
    }
    this->cantFilas=cantFilas;
    this->cantColumnas=cantColumnas;
    this->cantEnProfundidad=cantEnProfundidad; 
    Lista<Lista <Lista<Casillero *>*>*> * filas  = new Lista<Lista <Lista<Casillero *>*>*>;

    for(size_t i=0;  i<this->cantFilas; i++)
    {
        Lista<Lista <Casillero *>*> *columnas = new Lista<Lista <Casillero *>*>;
        for (size_t j=0; j<this->cantColumnas; j++)
        {
            Lista<Casillero *> * profundidad = new Lista<Casillero *>;

            for (size_t k = 0; k < this->cantEnProfundidad; k++)
            {
                Casillero* nuevoCasillero = new Casillero(SIMBOLO_FICHA_VACIA);
                profundidad->agregar(nuevoCasillero);
            }
            columnas->agregar(profundidad);
        }
        filas->agregar(columnas);
    }
    this->casilleros = filas;
}





Tablero::~Tablero() {

     Lista<Lista <Lista<Casillero *>*>*> * filas = this->casilleros;

     while(filas->avanzarCursor())
     {
        Lista<Lista <Casillero *>*> *columnas = this->casilleros->obtenerCursor();
        while(columnas->avanzarCursor())
        {

            Lista<Casillero *> * profundidad = columnas->obtenerCursor();
            while(profundidad->avanzarCursor())
            {
                delete profundidad->obtenerCursor();

            }delete profundidad;

        }delete columnas;

     }delete filas;
   
}
    
/*
Pre: existe el tablero y el casillero solicitado
Post: devuelve el casillero ubicado en la posicion [fila][columna][profundidad]
*/

/*
Pre: existe el tablero y el casillero solicitado
Post: devuelve el casillero ubicado en la posicion [fila][columna][profundidad]
*/

Casillero * Tablero::getCasillero(size_t fila, size_t columna, size_t profundidad) 
{ 
    if((fila <= 0) || (columna<= 0) || (profundidad <=0) || (fila>this->cantFilas) || (columna>this->cantColumnas) ||(profundidad>this->cantEnProfundidad))
    {
        string CoordInvalidas = "coordenadas de casilleros invalidas";
        throw CoordInvalidas;
    }
    return this->casilleros->obtener(fila)->obtener(columna)->obtener(profundidad);
}


/*
Pre: existe el casillero establecido y esta en el rango del tablero
Post:Establece la ficha del casillero ubicado en la posicion [fila][columna][profundidad] 
con el simbolo 'simboloFicha'*/
void Tablero::setCasilla(size_t fila, size_t columna, size_t profundidad, char simboloFicha) {
    this->casilleros->obtener(fila)->obtener(columna)->obtener(profundidad)->setSimboloFichaDelCasillero(simboloFicha);

}

Lista<Lista<Lista<Casillero*>*>*>* Tablero::obtenerMatrizTablero()
{
    return this->casilleros;
}   

bool Tablero::existeLaCasilla(size_t m, size_t n, size_t l) {
    if(this->cantFilas < m ||this->cantColumnas < n ||this->cantEnProfundidad < l ||
        m< 1 || n<1 || l<1){
        return false;
    }
    return true;
}

/*
Pre: existe el tablero
Post:Devuelve la cantidad de filas que posee el tablero
*/
size_t Tablero::getCantFilasTablero()
{
    return this->cantFilas;
}
/*
Pre: existe el tablero
Post:Devuelve la cantidad de columnas que posee el tablero
*/
size_t Tablero::getCantColumnasTablero()
{
    return this->cantColumnas;
}
/*
Pre: existe el tablero
Post:Devuelve la profundidad que posee el tablero
*/
size_t Tablero::getCantProfundidadTablero()
{
    return this->cantEnProfundidad;

}






















































/*void Tablero::crearMatrizVecinos(int cantFilas, int cantColumnas, int cantEnProfundidad) {

   Casillero *casilla;

    for (int i = 0; i < this->cantFilas; i++) {
        for (int j = 0; j < this->cantColumnas; j++) {
            for (int k = 0; k < this->cantEnProfundidad; k++) {

                casilla = this->getCasilla(i,j,k);
                Casillero**** matrizVecinal = new Casillero***();

                for (int l = 0; l <3; l++) {
                    //Casillero *** columna = new Casillero**();
                    matrizVecinal[l] = new Casillero** ();
                    for (int m = 0; m < 3; m++) {
                        matrizVecinal[l][m] = new Casillero*();
                        for (int n = 0; n < 3; n++) {
                            //matrizVecinal[l][m][n] = new Casillero();
                            matrizVecinal[l][m][n] = NULL;
                        }
                    }
                }
                casilla->asignarMatrizVecinos(matrizVecinal);
            }
        }
    }
}*/




//ASIGNO LOS VECINOS
// edit matriz vecinos // Algoritmo que Asigna la matriz de vecinos //falta implementar existeLaCasilla
/*
    for (int i = 0; i < this->cantColumnas; i++) { //el primer for me agarra la primer columna
        for (int j = 0; j < this->cantFilas; j++) { //el segundo for me define la fila
            for (int k = 0; k < this->cantEnProfundidad; k++) { //el 3er for la profundidad
                Casillero* casillero = this->getCasilla(i,j,k);
                for (int l = -1; l < 2; l++) {
                    for (int m = -1; m < 2; m++) {
                        for (int n = -1; n < 2; n++) {
                            if (existeLaCasilla(i + l, j + m, k + n)) {   //Implementar existeLaCasilla (>0, <ancho, <alto, <profundo)
                            //Con este if resolvemos la parte imaginaria(osea los que estarian en NULL porq estan por fuera del tablero)
                            Casillero *casilleroVecino = this->getCasilla(i + l, j + m, k +n); //SI NO EXISTE LA CASILLA, getCasilla tendria q devolver excepcoion
                            casilleroVecino->asignarVecino(l, m, n, casilleroVecino);
                            }
                        }
                    }
                }
            }
        }
    }
}

//edit matriz vecinos
//edit matriz vecinos

//edit matriz vecinos //TERMINAR!!
//Algoritmo que verifica el ganador
bool Tablero::hayTateti(Casillero *casilleroOrigen, direccion) { //casilleroOrigen es donde estoy parado(revisar que seria)
   casilleroOrigen->getVecinos();
   int longitudesAdyacentes[3][3][3];

   for (int i = 0; i <3 ; i++) {
       for (int j = 0; j <3 ; j++) {
           for (int k = 0; k <3 ; k++) {
               longitudesAdyacentes[i][j][k] = casilleroOrigen->getLongitud(i,j,k); //Devuelve la longitud de los casiilrros usados x la misma ficha
           }
       }
   }
   for (int i = 0; i <3 ; i++) {
       for (int j = 0; j <3 ; j++) {
           for (int k = 0; k <3 ; k++) {
               longitudesAdyacentes[i][j][k];

           }
       }
   }
}
*/
//edit matriz vecinos
