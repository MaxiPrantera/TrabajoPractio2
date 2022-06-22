#include <iostream>
#include "Lista.h"
#include "tablero.h"
#include "casillero.h"
#define SIMBOLO_FICHA_VACIA ' '


Tablero::Tablero(unsigned int xMax, unsigned int yMax, unsigned int zMax) {
    if ((xMax < 2) || (yMax < 2) || (zMax < 2))
    {
        string DimensionInvalida = "dimensiones de tablero incorrectas";
        throw DimensionInvalida;
    }
    this->xMax=xMax;
    this->yMax=yMax;
    this->zMax=zMax; 
    this->casilleros = new Lista<Lista <Lista<Casillero *>*>*>();
    
    //Lista<Lista <Lista<Casillero *>*>*> * filas  = new Lista<Lista <Lista<Casillero *>*>*>;

    for(unsigned int x=0;  x<this->xMax; x++)
    {
        
        this->casilleros->agregar(new Lista<Lista <Casillero *>*>());
        //Lista<Lista <Casillero *>*> *columnas = new Lista<Lista <Casillero *>*>;
        for (unsigned int y=0; y<this->yMax; y++)
        {
            this->casilleros->get(x)->agregar(new Lista <Casillero*>());
            //Lista<Casillero *> * profundidad = new Lista<Casillero *>;

            for (unsigned int z = 0; z < this->zMax; z++)
            {
                this->casilleros->get(x)->get(y)->agregar(new Casillero());
                //Casillero* nuevoCasillero = new Casillero();
                //profundidad->agregar(nuevoCasillero);
            }
            //columnas->agregar(profundidad);
        }
        //filas->agregar(columnas);
    }
    //this->casilleros = filas;
}





Tablero::~Tablero() {


for(unsigned int x=0;  x<this->xMax; x++)
{
    for (unsigned int y=0; y<this->yMax; y++)
    {
        for (unsigned int z = 0; z < this->zMax; z++)
        {
            delete this->casilleros->get(x)->get(y)->get(z);
        }
        delete this->casilleros->get(x)->get(y);
    }
    delete this->casilleros->get(x);
}

delete this->casilleros;

}

/* DESTRUCTOR VIEJO
     Lista<Lista<Lista<Casillero *>*>*> * filas = this->casilleros;

     while(filas->avanzarCursor())
     {
        Lista<Lista <Casillero *>*> *columnas = this->casilleros->getCursor();
        while(columnas->avanzarCursor())
        {

            Lista<Casillero *> * profundidad = columnas->getCursor();
            while(profundidad->avanzarCursor())
            {
                delete profundidad->getCursor();

            }delete profundidad;

        }delete columnas;

     }delete filas;
*/  

    
/*
Pre: existe el tablero y el casillero solicitado
Post: devuelve el casillero ubicado en la posicion [fila][columna][profundidad]
*/

/*
Pre: existe el tablero y el casillero solicitado
Post: devuelve el casillero ubicado en la posicion [fila][columna][profundidad]
*/

Casillero * Tablero::getCasillero(unsigned int x, unsigned int y, unsigned int z) 
{ 
    if((x <= 0) || (y<= 0) || (z <=0) || (x>this->xMax) || (y>this->yMax) ||(z>this->zMax))
    {
        string CoordInvalidas = "coordenadas de casilleros invalidas";
        throw CoordInvalidas;
    }
    return this->casilleros->get(x)->get(y)->get(z);
}


/*
Pre: existe el casillero establecido y esta en el rango del tablero
Post:Establece la ficha del casillero ubicado en la posicion [fila][columna][profundidad] 
con el simbolo 'simboloFicha'*/
//void Tablero::setCasilla(unsigned int x, unsigned int y, unsigned int z, Ficha* simboloFicha) {
//
//    this->casilleros->get(x)->get(y)->get(z)->setFicha(simboloFicha);
//
//}

Lista<Lista<Lista<Casillero*>*>*>* Tablero::obtenerMatrizTablero()
{
    return this->casilleros;
}   

bool Tablero::existeLaCasilla(unsigned int x, unsigned int y, unsigned int z) {
    if(this->xMax < x ||this->yMax < y ||this->zMax < z ||
        x< 1 || y<1 || z<1){
        return false;
    }
    return true;
}

/*
Pre: existe el tablero
Post:Devuelve la cantidad de filas que posee el tablero
*/
unsigned int Tablero::getCantFilasTablero()
{
    return this->xMax;
}
/*
Pre: existe el tablero
Post:Devuelve la cantidad de columnas que posee el tablero
*/
unsigned int Tablero::getCantColumnasTablero()
{
    return this->yMax;
}
/*
Pre: existe el tablero
Post:Devuelve la profundidad que posee el tablero
*/
unsigned int Tablero::getCantProfundidadTablero()
{
    return this->zMax;
}

/*
 * Pre: ---
 * Post: Devuelve un casillero con coordenadas validas seleccionadas por el usuario.
 */
Casillero* Tablero::elegirCoordenadas(std::string msj, bool esPiso)
{
    unsigned int x = 0, y = 0, z = 0;
    cout << "Eliga las coordenadas para " << msj << endl;

    if(esPiso)
    {
        z = 1;
    }

    do
    {
        if(x == 0)
        {
            cout << "Ingrese la coordenada x: " << endl;
            cin >> x;
            if (x < 1 || x > this->getCantProfundidadTablero())
            {
                cout << "Coordenada seleccionada fuera de rango, ingresar un numero entre 1 y el limite del tablero." << endl;
                x = 0;
            }
        }
        else if (y == 0)
        {
            cout << "Ingrese la coordenada y: " << endl;
            cin >> y;
            if (y < 1 || y > this->getCantColumnasTablero())
            {
                cout << "Coordenada seleccionada fuera de rango, ingresar un numero entre 1 y el limite del tablero." << endl;
                y = 0;
            }
        }
        else if(z == 0)
        {
            cout << "Ingrese la coordenada z: " << endl;
            cin >> z;
            if (z < 1 || z > this->getCantFilasTablero())
            {
                cout << "Coordenada seleccionada fuera de rango, ingresar un numero entre 1 y el limite del tablero." << endl;
                z = 0;
            }
        }
    }while(x == 0 || y == 0 || z == 0);

    return this->getCasillero(x, y, z);
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
