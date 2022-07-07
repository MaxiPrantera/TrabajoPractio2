#include <iostream>
#include "Constantes.h"
#include "BatallaCampal.h"

using namespace std;

int main()
{
	//Variables auxiliares
	int respuestaUsuario;
    unsigned int jugadorActual = 1;

	//TDAs
	BatallaCampal* batallaCampal = new BatallaCampal();
    Jugador* ganador = new Jugador();

	cout << "Bienvenidos a Batalla Campal V2.0!!!" << endl;

	//Inicializacion de jugadores:
	cout << "Ingresar cantidad de jugadores" << endl;
    cin >> respuestaUsuario;
    string nombreJugador;
    for(int jugador = 0; jugador < respuestaUsuario;jugador++){
    	cout << "Ingresar nombre del jugador" << endl;
    	cin >> nombreJugador;
    	batallaCampal->getJugadores()->agregar(Jugador(nombreJugador));
    }


	//Inicializacion de Tablero:
	cout << "Se arma el campo de batalla, eliga que escenario quiere jugar (Entre 1 y 3): " << endl;
	cin >> respuestaUsuario;
	switch(respuestaUsuario){
	case 1:
	  batallaCampal->iniciarEscenarioUno();
	  break;
	case 2:
	  batallaCampal->iniciarEscenarioDos();
	  break;
	case 3:
	  batallaCampal->iniciarEscenarioTres();
	  break;
	default:
	  break;
	}


	//Inicializacion de Soldados:
	cout << "Recluta a tus tropas y posicionalas estrategicamente" << endl;
    cout << "Cuantos soldados tendra cada jugador?" << endl;
    cin >> respuestaUsuario;
    for(int soldados = 0; soldados < respuestaUsuario; soldados++){
	    for(unsigned int jugador = 1; jugador <= batallaCampal->getCantidadJugadores(); jugador++){
		    cout << "\nJugador " << batallaCampal->getNombreJugador(jugador) << endl;
		    batallaCampal->jugadorAgregarSoldado(jugador);
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
  		    //(4) Logica de mostrar tablero:
  		  	batallaCampal->mostrarTablero();

  			jugadorActual = 1;
  	  	}

  	  	if (batallaCampal->getJugador(jugadorActual)->getCantidadSoldadosVivos() != 0){
  		  	//Inicia el turno robando carta.
  		  	cout << "Es el turno de " << batallaCampal->getNombreJugador(jugadorActual) << " y roba una carta" << endl;
		  	batallaCampal->jugadorRobarCarta(jugadorActual);

  		    //(1) Logica de Movimiento:
  		    batallaCampal->jugadorMoverFicha(jugadorActual);

  		  	//(2) Logica de disparos:
  		  	batallaCampal->jugadorDisparar(jugadorActual); 
  
        	//(3) Logica de tirar carta:
  		    batallaCampal->jugadorTirarCarta(jugadorActual);
      	}

      	jugadorActual++;
    }


    //Finalizar el juego:
    cout << "Y el ganador es..." << endl;
    if(ganador->getNombre() == "")
    {
    	cout << "Todos los jugadores se quedaron sin soldados vivos, hubo empate :_(" << endl;
    }
    else
    {
    	cout << ganador->getNombre() << "!!!" << endl;
    }

    delete batallaCampal;
	delete ganador;

	cout << "fin del juego." << endl;

  	return 0;
}
