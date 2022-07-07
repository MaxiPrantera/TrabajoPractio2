#include "Visualizador.h"
#include <sstream>
#include "Constantes.h"
#include "Lista.h"
#include "tablero.h"

using namespace std;


Visualizador::Visualizador()
{
}

Visualizador::~Visualizador()
{}

void Visualizador::dibujarCapa(Tablero* tablero, unsigned int altura){
	//RangedPixelToPixelCopy(casilleroVacio, 100 ,184, 600, 152, this->filasAImprimir->get(fila), columna*184, profundidad*152);
	Casillero* casilleroActual;

	BMP imagen;
	imagen.ReadFromFile("soldado.bmp");
	imagen.SetSize(ANCHO_TABLERO * PIXELES_POR_CASILLERO, PROFUNDIDAD_TABLERO * PIXELES_POR_CASILLERO);
	imagen.SetBitDepth(8);

	string nombreArchivo = "Tablero_Altura_";
	stringstream alturaStr;
	alturaStr << altura;
	nombreArchivo = nombreArchivo + alturaStr.str() + ".bmp";

    for(unsigned int profundidad = 1; profundidad <= tablero->getCantidadProfundidad(); profundidad++)
    {
    	for(unsigned int columna = 1; columna <= tablero->getCantidadColumnas(); columna++)
    	{
    		casilleroActual = tablero->getCasillero(profundidad, columna, altura);

    		this->dibujarTerreno(profundidad, columna, casilleroActual->getTerreno());

    		switch(casilleroActual->getEstado())
    		{
    			case inactivo:
    				break;
    			case ocupado:
					break;
    		}

    		if (this->imagen.WriteToFile(nombreArchivo.c_str()))
    		{
    		  	cout << "Capa guardada corretamente" << endl;
    		}
    		else
    		{
    		  	cout << "Error al guardar" << endl;
    		}
    	}
    }
}

void Visualizador::dibujarTerreno(unsigned int profundidad, unsigned int columna, Terreno tipoTerreno)
{
	unsigned int inicioX = ((profundidad - 1) * PIXELES_POR_CASILLERO);
	unsigned int inicioY = ((columna - 1) * PIXELES_POR_CASILLERO);
	unsigned int rojo, verde, azul, alpha;

	switch(tipoTerreno)
	{
		case agua:
			rojo = 19;
			verde = 79;
			azul = 178;
			alpha = 0;
			break;
		case tierra:
			rojo = 77;
			verde = 39;
			azul = 4;
			alpha = 0;
			break;
		case aire:
			rojo = 198;
			verde = 197;
			azul = 196;
			alpha = 400;
			break;
	}

	for(unsigned int x = inicioX; x <= (inicioX + PIXELES_POR_CASILLERO); x++)
	{
		for(unsigned int y = inicioY; y <= (inicioY + PIXELES_POR_CASILLERO); y++)
		{
			this->imagen(x,y)->Red = rojo;
			this->imagen(x,y)->Green = verde;
			this->imagen(x,y)->Blue = azul;
			this->imagen(x,y)->Alpha = alpha;
		}
	}
}

//void Visualizador::imprimirTablero(Tablero * tablero, unsigned int xMax, unsigned int yMax, unsigned int zMax)
//{
//    tablero.save_image("tablero.bmp");
//}

//void MiBitmap::casilleroAnulado(){
//
//	BMP Gris;
//	Gris.ReadFromFile( "soldado.bmp" ); //Le paso como ejemplo la imagen del soldado
//
//	for( int j=0 ; j < Gris.TellHeight() ; j++)
//	{
//		for( int i=0 ; i < Gris.TellWidth() ; i++)
//		{
//			int Temp = (int) floor( 0.299*Gris(i,j)->Red + 0.587*Gris(i,j)->Green + 0.114*Gris(i,j)->Blue );
//			ebmpBYTE TempBYTE = (ebmpBYTE) Temp;
//			Gris(i,j)->Red = TempBYTE;
//			Gris(i,j)->Green = TempBYTE;
//			Gris(i,j)->Blue = TempBYTE;
//		}
//	}
//	// Creo Tabla de color gris
//	if( Gris.TellBitDepth() < 16 )
//	{
//		CreateGrayscaleColorTable( Gris ); }
//
//	Gris.WriteToFile( "gris.bmp" );
//
//}
//
//void MiBitmap::agregarEscudo(){
//
//	BMP Soldado;
//	Soldado.SetBitDepth(8);
//	Soldado.ReadFromFile("soldado.bmp");
//	BMP Escudo;
//	Escudo.ReadFromFile("Escudo.bmp");
//
//	RGBApixel TransparentColor;
//	TransparentColor.Red = 255;
//	TransparentColor.Green = 255;
//	TransparentColor.Blue = 255;
//	RangedPixelToPixelCopyTransparent(Soldado, 100, 600, 600, 100, Escudo, 100, 110, TransparentColor);
//}
