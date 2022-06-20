#include <iostream>
#include <cstdlib>
#include "Lista.h"
#include "Cola.h"
#include "Constantes.h"
#include "Carta.h"
#include "ficha.h"
#include "jugador.h"
#include "BatallaCampal.h"

using namespace std;

int main()
{
	//Variables auxiliares
	int respuestaUsuario;

	//TDAs
	BatallaCampal* batallaCampal = new BatallaCampal();

	//DEBUG
	bool inputValido;
	unsigned int jugador;


	cout << "Bienvenidos a Batalla Campal V2.0!!!" << endl;

	//Inicializacion de jugadores:
	cout << "Ingresar cantidad de jugadores" << endl;
    cin >> respuestaUsuario;

    string nombreJugador;
    for(unsigned int jugador = 0; jugador < respuestaUsuario;jugador++){
    	cout << "ingresar nombre del jugador" << endl;
    	cin>>nombreJugador;
    	batallaCampal->getJugadores()->agregar(Jugador(nombreJugador));
    }

//  //Inicializacion de Tablero:
//  cout << "Se arma el campo de batalla" << endl;
//  switch(rand()%4){
//    case 0:
//      batallaCampal->iniciarEscenarioUno(20, 20, 5);
//      break;
//    case 1:
//      batallaCampal->iniciarEscenarioDos(20, 20, 5);
//      break;
//    case 2:
//      batallaCampal->iniciarEscenarioTres(20, 20, 5);
//      break;
//    default:
//      break;
//  }

  //Inicializacion de Soldados:
  cout << "Recluta a tus tropas y posicionalas estrategicamente" << endl;
  cout << "Cuantos soldados tendra cada jugador?" << endl;
  cin >> respuestaUsuario;

  for(unsigned int soldados = 0; soldados < respuestaUsuario; soldados++){
	  for(unsigned int jugador = 1; jugador <= batallaCampal->getCantidadJugadores(); jugador++){
		  cout << "\nJugador " << batallaCampal->getNombreJugador(jugador);
		  Casillero* casillero = batallaCampal->getTablero()->elegirCoordenadas("posicionar el soldado", true);
		  while (casillero->getEstado() == inactivo){
			  casillero = batallaCampal->getTablero()->elegirCoordenadas("posicionar el soldado", true);
		  }
		  Ficha* ficha = new Ficha(soldado, casillero);
		  batallaCampal->jugadorAgregarFicha(ficha, jugador);
	  }
  }

  //Reparte las cartas:
  cout << "Mezclando y repartiendo..." << endl;
  batallaCampal->inicializarMazo();
  for(int jugador = 1; jugador <= batallaCampal->getCantidadJugadores(); jugador++)
  {
	  for(int i = 1; i <= CANTIDAD_CARTAS_INICIALES; i++)
	  {
		  batallaCampal->jugadorRobarCarta(jugador);
	  }
  }


//  //Loop de logica principal:
//  cout << "Que comienze el juego!!!" << endl;
//  int turno = 1;
//  unsigned int jugadorActual = 1;
//  Jugador* jugadorGanador = NULL;
//  while (!batallaCampal->verificarGanador(jugadorGanador)){
//	  if (jugadorActual > batallaCampal->getCantidadJugadores())
//	  {
//		  jugadorActual = 0;
//	  }
//
//	  if (batallaCampal->getCantidadFichasJugador(jugadorActual) != 0){
//		  cout << batallaCampal->getNombreJugador(jugadorActual) << " te toca" << endl;
//
//		  //Inicia el turno robando carta.
//		  cout << batallaCampal->getNombreJugador(jugadorActual) << " roobaste la carta "
//				  << batallaCampal->getCartaARobar().getNombre() << endl;
//		  batallaCampal->jugadorRobaCarta(jugadorActual);
//
//		  //(2) Logica de Movimiento:
//		  //Preguntar por numero de ficha directo, si es cero, quiere decir que no mueve
//		  //preguntar la direccion
//		  //en cada caso validar minimamente
//		  //ejecutar funcion en batalla campal "jugadorMueveFicha" con los datos obtenidos.
//		  batallaCampal->jugadorMueveFicha(jugadorActual);
//
//
//		  //(1) Logica de disparos:
//		  int x, y, z;
//		  cout << "Eliga una posicion en x y z para disparar" << endl;
//		  cin >> x;
//		  cin >> y;
//		  cin >> z;
//		  batallaCampal->jugadorDispara(x, y, z);
//
//      //(3) Logica de tirar carta:
//      inputValido = false;
//      do
//      {
//        cout << batallaCampal->getNombreJugador(jugador) << " que carta vas a tirar? (0 para no tirar ninguna): ";
//        cin >> respuestaUsuario;
//        if (respuestaUsuario > 0 && respuestaUsuario <= batallaCampal->getCantidadCartasJugador(jugador))
//        {
//          inputValido = true;
//          if (respuestaUsuario != 0)
//          {
//            cout << "Utilizaste tu carta " << batallaCampal->getCartaJugador(jugadorActual, respuestaUsuario) << endl;
//            batallaCampal->jugadorTiraCarta(jugador, respuestaUsuario);
//          }
//        }
//        else
//        {
//          cout << "Número de carta fuera del rango válido, intenta elegir un número entre 0 y tu cantidad de cartas" << endl;
//        }
//      }while(!inputValido);
//
//      //(4) Logica de mostrar tablero:
//
//    }
//    turno++;
//    jugadorActual++;
//  }
//
//
//  //Finalizar el juego:
//  cout << "Y el ganador es..." << endl;
//  /*
//  * A esta altura ya salio del loop principal con lo que tenemos ganador
//  * Muestra por pantalla el nombre del ganador
//  * Ejecuta Delete de las variables correspondientes
//  */
//  cout << "fin del juego." << endl;
  return 0;
}
