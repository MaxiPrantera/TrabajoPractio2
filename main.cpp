#include <iostream>
#include <cstdlib>
#include "Lista.h"
#include "Cola.h"
#include "Constantes.h"
#include "ficha.h"
#include "BatallaCampal.h"

using namespace std;

int main()
{
	//Variables auxiliares
	int respuestaUsuario;
    unsigned int turno = 1, jugadorActual = 1;

	//TDAs
	BatallaCampal* batallaCampal = new BatallaCampal();
    Jugador* ganador = NULL;

	//F:DEBUG
	bool inputValido;
	unsigned int jugador;


	cout << "Bienvenidos a Batalla Campal V2.0!!!" << endl;

	//Inicializacion de jugadores:
	cout << "Ingresar cantidad de jugadores" << endl;
    cin >> respuestaUsuario;

    string nombreJugador;
    for(int jugador = 0; jugador < respuestaUsuario;jugador++){
    	cout << "Ingresar nombre del jugador" << endl;
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

    for(int soldados = 0; soldados < respuestaUsuario; soldados++){
	    for(unsigned int jugador = 1; jugador <= batallaCampal->getCantidadJugadores(); jugador++){
		    cout << "\nJugador " << batallaCampal->getNombreJugador(jugador) << endl;
		    Casillero* casillero = batallaCampal->getTablero()->elegirCoordenadas("posicionar el soldado", true);
		    while (casillero->getEstado() == inactivo){
		    	cout << "El casillero esta inactivo, volve a elegir las coordenadas." << endl;
		   	    casillero = batallaCampal->getTablero()->elegirCoordenadas("posicionar el soldado", true);
		    }
		    unsigned int x = casillero->getX();
		    unsigned int y = casillero->getY();
		    unsigned int z = casillero->getZ();
		    Ficha* ficha = new Ficha(soldado, x, y, z);
		    batallaCampal->jugadorAgregarFicha(ficha, jugador);
		    if (casillero->getEstado() == ocupado){
				casillero->eliminarFicha();
		  	    ficha->eliminarFicha();
		  	    cout << "Ambas fiuchas eliminadas";

		    }
		    else{
		  	    casillero->setFicha(ficha);
	        }
	    }
    }

  	//Reparte las cartas:
  	cout << "Mezclando y repartiendo..." << endl;
  	batallaCampal->inicializarMazo();
  	for(unsigned int jugador = 1; jugador <= batallaCampal->getCantidadJugadores(); jugador++)
  	{
	  	for(unsigned int i = 1; i <= CANTIDAD_CARTAS_INICIALES; i++)
	  	{
		  	batallaCampal->jugadorRobarCarta(jugador);
	  	}
  	}


    //Loop de logica principal:
    cout << "Que comienze el juego!!!" << endl;
	
    while (!batallaCampal->verificarGanador(ganador)){
  		if (jugadorActual > batallaCampal->getCantidadJugadores())
  	  	{
  			jugadorActual = 1;
  	  	}

  	  	if (batallaCampal->getCantidadFichasJugador(jugadorActual) != 0){
  		  	cout << batallaCampal->getNombreJugador(jugadorActual) << " te toca" << endl;
  
  		  	//Inicia el turno robando carta.
  		  	cout << batallaCampal->getNombreJugador(jugadorActual) << " robaste la carta " << batallaCampal->getCartaARobar() << endl;
		  	batallaCampal->jugadorRobarCarta(jugadorActual);
  
  		    //(2) Logica de Movimiento:
  		    batallaCampal->jugadorMoverFicha(jugadorActual);
  
  
  //		  //(1) Logica de disparos:
  //		  int x, y, z;
  //		  cout << "Eliga una posicion en x y z para disparar" << endl;
  //		  cin >> x;
  //		  cin >> y;
  //		  cin >> z;
  //		  batallaCampal->jugadorDispara(x, y, z);
  

        	//(3) Logica de tirar carta:
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
  
  
  //      //(4) Logica de mostrar tablero:
  
      	}
      	turno++;
      	jugadorActual++;
    }


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
