#include <iostream>
#include "Lista.h"
#include "Cola.h"
#include "Constantes.h"
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
	//respuestaUsuario = 2;
    string nombreJugador;
    for(int jugador = 0; jugador < respuestaUsuario;jugador++){
    	cout << "Ingresar nombre del jugador" << endl;
    	cin >> nombreJugador;
    	batallaCampal->getJugadores()->agregar(Jugador(nombreJugador));
    }


	//Inicializacion de Tablero:
	cout << "Se arma el campo de batalla, eliga que escenario quiere jugar (Entre 1 y 3): " << endl;
	cin >> respuestaUsuario;
	//respuestaUsuario = 1;
	switch(respuestaUsuario){
	case 1:
	  batallaCampal->iniciarEscenarioUno(20, 20, 5);
	  break;
	case 2:
	  batallaCampal->iniciarEscenarioDos(20, 20, 5);
	  break;
	case 3:
	  batallaCampal->iniciarEscenarioTres(20, 20, 5);
	  break;
	default:
	  break;
	}


	//Inicializacion de Soldados:
	cout << "Recluta a tus tropas y posicionalas estrategicamente" << endl;
    cout << "Cuantos soldados tendra cada jugador?" << endl;
    cin >> respuestaUsuario;
    //respuestaUsuario = 1;
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
  		    batallaCampal->jugadorTirarCarta(jugadorActual);
  
  
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
