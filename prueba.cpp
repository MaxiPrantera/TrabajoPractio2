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
	soldadosTotales =  respuesta * cantdidadJugadores;
	Ficha soldados[soldadosTotales];
	soldadoActual = 0
	soldadosRestantes = respuesta;
	int x,y;
	while (soldadosTotales != 0){
		for (int i = 0; i < cantidadJugadores; i++){
			cout << "\nJugador "
			     << jugadores[i]
				 << " Te quedan: "
				 << soldadosRestantes
				 << " soldados"
				 << endl;
				 << "Elige una posicion en x: ";
			cin >> x;
			x--;
			cout << "Elige una posicion en y: ";
			cin >> y;
			y--;
			if (casillero.estado == vacio){
				casillero.estado = ocupado;
				soldado[soldadoActual](soldado, vivo, jugadores[i], casillero);
			else{
				casillero.ficha.eliminarFicha();
				soldado[soldadoActual](soldado, muerto, jugadores[i], casillero);
			}
		soldadoActual++;
		soldadosRestantes--;
		}

	return 0;


}


