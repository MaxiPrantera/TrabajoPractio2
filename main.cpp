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

  switch(rand()%4){
    case 0:
      batallaCampal->iniciarEscenarioUno(20, 20, 5);
      break;
    case 1:
      batallaCampal->iniciarEscenarioDos(20, 20, 5);
      break;
    case 2:
      batallaCampal->iniciarEscenarioTres(20, 20, 5);
      break;
    default:
      break;
  }

  //Inicializacion de Soldados:
    cout << "Recluta a tus tropas y posicionalas estrategicamente" << endl;
	cout << "Cuantos soldados tendra cada jugador?" << endl;
	cin >> respuestaUsuario;
	unsigned int* x;
	unsigned int* y;
	unsigned int* z;

	for(unsigned int soldados = 0; soldados < respuestaUsuario; soldados++){
		for(unsigned int jugador = 1; jugador <= batallaCampal->getCantidadJugadores(); jugador++){
			cout << "\nJugador " << batallaCampal->getNombreJugador(jugador);
      		batallaCampal->elegirCoordenadas(x, y, z, "posicionar el soldado", true);
			Casillero* casillero = batallaCampal->getCasillero(*x,*y,*z);
			while (casillero->getEstado() == inactivo){
				batallaCampal->elegirCoordenadas(x, y, z, "posicionar el soldado", true);
				Casillero* casillero = batallaCampal->getCasillero(*x,*y,*z);
			}
			Ficha* ficha = new Ficha(soldado, batallaCampal->getJugador(jugador), casillero);
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
      batallaCampal->jugadorRobaCarta(jugador);
    }
  }


  //Loop de logica principal:
  cout << "Que comienze el juego!!!" << endl;
	int turno = 1;
  unsigned int jugadorActual = 1;
	while (!batallaCampal->verificarGanador()){
		if (jugadorActual > batallaCampal->getCantidadJugadores())
    {
      jugadorActual = 0;
    }

    if (batallaCampal->getCantidadFichasJugador(jugadorActual) != 0){
      cout << batallaCampal->getNombreJugador(jugadorActual) << " te toca" << endl;

      //Inicia el turno robando carta.
      cout << batallaCampal->getNombreJugador(jugadorActual) << " roobaste la carta "
           << batallaCampal->getCartaARobar().getNombre() << endl;
      batallaCampal->jugadorRobaCarta(jugadorActual);
      
      //(2) Logica de Movimiento:
      //Preguntar por numero de ficha directo, si es cero, quiere decir que no mueve
      //preguntar la direccion
      //en cada caso validar minimamente
      //ejecutar funcion en batalla campal "jugadorMueveFicha" con los datos obtenidos.
      /*
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
      }
      */

      //(1) Logica de disparos:
      //Pedir coordenadas
      //Ejecutar "jugadorDispara" de batallaCampal.
      int x, y, z;
      cout << "Eliga una posicion en x y z para disparar" << endl;
        cin >> x;
        cin >> y;
        cin >> z;
        batallaCampal->jugadorDispara(x, y, z);
      


      //(3) Logica de tirar carta:
      inputValido = false;
      do
      {
        cout << batallaCampal->getNombreJugador(jugador) << " que carta vas a tirar? (0 para no tirar ninguna): ";
        cin >> respuestaUsuario;
        if (respuestaUsuario > 0 && respuestaUsuario <= batallaCampal->getCantidadCartasJugador(jugador))
        {
          inputValido = true;
          if (respuestaUsuario != 0)
          {
            cout << "Utilizaste tu carta " << batallaCampal->getCartaJugador(jugadorActual, respuestaUsuario) << endl;
            batallaCampal->jugadorTiraCarta(jugador, respuestaUsuario);
          }
        }
        else
        {
          cout << "Número de carta fuera del rango válido, intenta elegir un número entre 0 y tu cantidad de cartas" << endl;
        }
      }while(!inputValido);

      //(4) Logica de mostrar tablero:
      
    }
    turno++;
    jugadorActual++;
  }


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
