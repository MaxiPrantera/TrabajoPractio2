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
  /*
  * Pregunta cuantos soldados van a ser
  * Valida (Igual que tablero) **Opcional
  * Pregunta la posicion del primer soldado de cada jugador en orden y lo instancia correspondientemente
  * Repite por cada soldado
  */

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
