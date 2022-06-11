#include <iostream>
#include "Constantes.h"
#include "jugador.h"
#include "Carta.h"
#include "Lista.h"
#include "Cola.h"
#include "BatallaCampal.h"

using namespace std;

int main()
{
  BatallaCampal* batallaCampal = new BatallaCampal();
  Cola<Carta>* mazo = new Cola<Carta>();
  //DEBUG
  bool inputValido;
  int respuestaUsuario;
  unsigned int jugador;
  
  cout << "Bienvenidos a Batalla Campal V2.0!!!" << endl;

  //Inicializacion de jugadores:
  cout << "Tu Nombre???" << endl;
  /*
    * Pregunta cuantos juegan y luego...
    * Instancia cada jugador con su nombre.
    * El id se reemplaza con el indice en el que se encuentra en la lista de Jugadores global.
    * Cada jugador va a tener una lista de cartas, una vector de soldados y quiza listas de barcos y demas.
    * Todas estas se instancian por ahora vacias escepto el nombre logicamente
    * Ademas las listas son punteros a, no el propio TDA.
    */

  //Inicializacion de Tablero:
  cout << "Se arma el campo de batalla" << endl;
  /*
   * Pregunta las dimensiones
   * Valida que las dimensiones sean coherentes (Ej, si hay tres jugadores no puede ser 3x3x3 y demas giladas) **Opcional
   * Instancia el tablero con todos los casilleros vacios y con el piso y cielo.
   */

  //Inicializacion de Soldados:
  cout << "Recluta a tus tropas y posicionalas estrategicamente" << endl;
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
  
  

  //Reparte las cartas:
  cout << "Mezclando y repartiendo..." << endl;
  batallaCampal->inicializarMazo(mazo);
  for(int jugador = 1; jugador <= batallaCampal->getListaJugadores()->getTamanio(); jugador++)
  {
    for(int i = 1; i <= CANTIDAD_CARTAS_INICIALES; i++)
    {
      batallaCampal->getListaJugadores()->get(jugador).robarCarta(mazo);
    }
  }

  //Hasta aca ya tenemos la parte inicial, jugadores con nombres, soldados y cartas, tablero creado.
  //Ahora viene la parte del juego en si.

  //Loop de logica principal:
  cout << "Que comienze el juego!!!" << endl;
  
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
					for(int j = 1; j < (getListaJugadores->get(i)->getFichas() + 1); j++){
						if (getListaJugadores->get(i)->getListaFichas()->get(j)->getEstado() == vivo){
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
  
  /*
  * Un loop que se repite mientras que no haya un solo jugador con soldados
  * Se indica a que jugador le toca y
  * Primero el jugador saca una carta del mazo (desencola) y se muestra por pantalla cual fue
  * Logica de disparos (1) 
  * Logica de Moviemiento (2)
  * Logica de tirar carta (3)
  * Logica de Mostar estado del tablero (4)
  */

  //(1) Logica de disparos:
  /*
  * 
  */

  //(2) Logica de Movimiento:
  /*
  * 
  */

  //(3) Logica de tirar carta:

  inputValido = false;
  do
  {
    cout << batallaCampal->getListaJugadores()->get(jugador).getNombreJugador() << " que carta vas a tirar? (0 para no tirar ninguna): ";
    cin >> respuestaUsuario;
    if (respuestaUsuario > 0 && respuestaUsuario <= batallaCampal->getListaJugadores()->get(jugador).getCantidadCartas())
    {
      inputValido = true;
      if (respuestaUsuario != 0)
      {
        cout << "Utilizaste tu carta " << batallaCampal->getListaJugadores()->get(jugador).getNombreCarta(respuestaUsuario) << endl;
        batallaCampal->getListaJugadores()->get(jugador).tirarCarta(respuestaUsuario);
      }
    }
    else
    {
      cout << "Número de carta fuera del rango válido, intenta elegir un número entre 0 y tu cantidad de cartas" << endl;
    }
  }while(!inputValido);

  //(4) Logica de Mostar estado del tablero:
  /*
  * 
  */

  //Finalizar el juego:
  cout << "Y el ganador es..." << endl;
  /*
  * A esta altura ya salio del loop principal con lo que tenemos ganador
  * Muestra por pantalla el nombre del ganador
  * Ejecuta Delete de las variables correspondientes
  * termina la ejecucion, aprobamos el TP, nos vamos a tomar una birrita para festejar :)
  */

  return 0;
}
