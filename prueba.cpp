/*
 * main.cpp
 *
 *  Created on: 16/05/2022
 *      Author: algo2
 */
#include <iostream>
#include "ficha.h"

using namespace std;


int main()

	int respuesta;
	cout << "Cuantos soldados tendra cada jugador?" << endl;
	cin >> respuesta;
	for(int j = 0; j < respuesta; j++){
		for(int i = 0; i < cantidadJugadores; i++){
			cout << "\nJugador "
				 << jugadores[i]
				 << " Te quedan: "
				 << soldadosRestantes
				 << " soldados"
				 << endl;
				 << "Elige una posicion en x: ";
			cin >> x;
			cout << "Elige una posicion en y: ";
			cin >> y;
			casillero = tablero.getCasillero(x,y,1);
			if (casillero.getEstado() == vacio){
				listaJugador[i]->agregarFicha(soldado, vivo, listaJugador[i], casillero);
				casillero.setEstado(ocupado);
			}
			else if (casillero.getEstado() == ocupado){
				casillero.eliminarFicha()
				listaJugador[i]->agregarFicha(soldado, muerto, listaJugador[i], casillero);
				casillero.setEstado(inactivo);		
			}
			else{	
			}
		}
	}
	return 0;


}


