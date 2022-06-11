/*
 * main.cpp
 *
 *  Created on: 16/05/2022
 *      Author: algo2
 */
#include <iostream>
#include "ficha.h"

using namespace std;


int main(){


	int respuesta;
	cout << "Cuantos soldados tendra cada jugador?" << endl;
	cin >> respuestaSoldados;
	int x,y;
	for(int j = 0; j < respuestaSoldados; j++){
		for(int i = 0; i < cantidadJugadores; i++){
			cout << "\nJugador "
				 << getListaJugador->get(i);
				 << " Te quedan: "
				 << soldadosRestantes
				 << " soldados"
				 << endl;
				 << "Elige una posicion en x: ";
			cin >> x;
			cout << "Elige una posicion en y: ";
			cin >> y;
			Casillero* casillero = tablero->getCasillero(x,y,1);
			if (casillero->getEstado() == vacio){
				Ficha* ficha = new Ficha(soldado, vivo, getListaJugador->get(i), casillero);
				getListaJugador->get(i)->agregarFicha(ficha);
			}
			else if (casillero->getEstado() == ocupado){
				Ficha* ficha = new Ficha(soldado, vivo, getListaJugador->get(i), casillero);
				getListaJugador->get(i)->vaciarCasillero();	
			}
		}
	}
	return 0;
	
	
	
	int x,y,z;
	int turno = 0
	while (!verificarGanador()){
		
		for (int i = 1; i =< cantidadJugadores; i++){
			if (getListaJugador->get(i)->getFichas() != 0){
				if (turno !=0 && getListaJugadores->get(i)->getCantCartas() < 5){
					getListaJugadores->get(i)->agarrarCarta();	
				}
				
				char respuestaMover;
				cout << "Quiere mover una ficha?" << endl;
				cin >> respuestaMover;
				if (respuesta == 's'){
					int respuestaFicha;
					cout << "Que ficha quiere mover?";
					for(int j = 1; j < (getListaJugadores->get(i)->getFichas() + 1); j++)
						cout << j << "." << getListaJugadores->get(i)->getListaFichas()->get(j)->getUbicacionX()
										 << "/";
							             << getListaJugadores->get(i)->getListaFichas()->get(j)->getUbicacionY()
							             << "/";
										 << getListaJugadores->get(i)->getListaFichas()->get(j)->getUbicacionZ()
										 << endl;
					cin > respuestaFicha;
					char direccion;
					cout << "w = arriba, a = izquierda, s = abajo, d = derecha\n"
    			  		 << "q = diagonal izquierda arriba, e diagonal derecha arriba, z = diagonal abajo izquierda, c = diagonal abajo derecha\n";
    			  	cin > direccion;
    			  	getListaJugadores->get(i)->getListaFichas()->get(respuestaFicha)->moverFicha(direccion);
    			}
					
				cout << "Eliga una posicion en x y z para disparar" << endl;
					cin >> x;
					cin >> y;
					cin >> z;
					getListaJugadores->get(i)->disparar(x,y,z);				
				
				char respuestaUsarCarta;
				cout << "Quiere usar una carta?" << endl;
				cin respuestaUsarCarta;
				if (respuestaCarta == 's'){
					int respuestaTirarCarta;
					for(int k = 1; k < (getListaJugadores->get(i)->getCantCartas() + 1); j++){
						cout << k << "." << getListaJugadores->get(i)->getListaCartas()->get(k)->getCarta();
					cin >> respuestaTirarCarta;
					getListaJugadores->get(i)->tirarCarta(respuestaTirarCarta);
					}	
			 	}
			}
		}
		imprimirMapa(nose);
		turno++;
	}	
}


	





























