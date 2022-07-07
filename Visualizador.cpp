#include "Visualizador.h"
#include <sstream>
#include "Constantes.h"
#include "Lista.h"
#include "tablero.h"

using namespace std;


Visualizador::Visualizador()
{
	this->capa.SetBitDepth(8);
	this->capa.SetSize(ANCHO_TABLERO * PIXELES_POR_CASILLERO, PROFUNDIDAD_TABLERO * PIXELES_POR_CASILLERO);
}

Visualizador::~Visualizador()
{}

void Visualizador::dibujarCapa(Tablero* tablero, unsigned int altura)
{
	Casillero* casilleroActual;

    for(unsigned int profundidad = 1; profundidad <= tablero->getCantidadProfundidad(); profundidad++)
    {
    	for(unsigned int columna = 1; columna <= tablero->getCantidadColumnas(); columna++)
    	{
    		casilleroActual = tablero->getCasillero(profundidad, columna, altura);

    		this->dibujarTerreno(profundidad, columna, casilleroActual->getTerreno());

    		switch(casilleroActual->getEstado())
    		{
    			case inactivo:
    				this->dibujarInactivo(profundidad, columna);
    				break;
    			case ocupado:
    				this->dibujarFicha(profundidad, columna, casilleroActual->getFicha()->getTipoFichaStr());
					break;
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
			rojo =  77;
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

	for(unsigned int x = inicioX; x < (inicioX + PIXELES_POR_CASILLERO); x++)
	{
		for(unsigned int y = inicioY; y < (inicioY + PIXELES_POR_CASILLERO); y++)
		{
			this->capa(x,y)->Red = rojo;
			this->capa(x,y)->Green = verde;
			this->capa(x,y)->Blue = azul;
			this->capa(x,y)->Alpha = alpha;
		}
	}
}

void Visualizador::dibujarInactivo(unsigned int profundidad, unsigned int columna)
{
	unsigned int inicioX = ((profundidad - 1) * PIXELES_POR_CASILLERO);
	unsigned int inicioY = ((columna - 1) * PIXELES_POR_CASILLERO);

	for(unsigned int x = inicioX; x < (inicioX + PIXELES_POR_CASILLERO); x++)
	{
		for(unsigned int y = inicioY; y < (inicioY + PIXELES_POR_CASILLERO); y++)
		{
			if(x == y || x == ((inicioY + PIXELES_POR_CASILLERO) - y - 1))
			{
				this->capa(x,y)->Red = 250;
				this->capa(x,y)->Green = 0;
				this->capa(x,y)->Blue = 0;
				this->capa(x,y)->Alpha = 0;
			}
		}
	}
}

void Visualizador::dibujarFicha(unsigned int profundidad, unsigned int columna, string tipoFicha)
{
	RGBApixel TransparentColor;
	TransparentColor.Red = 255;
	TransparentColor.Green = 255;
	TransparentColor.Blue = 255;

	BMP imagenFicha;
	string archivo = tipoFicha + ".bmp";
	imagenFicha.ReadFromFile(archivo.c_str());
	imagenFicha.SetBitDepth(8);
	imagenFicha.SetSize(PIXELES_POR_CASILLERO, PIXELES_POR_CASILLERO);

	unsigned int posicionX = ((profundidad - 1) * PIXELES_POR_CASILLERO);
	unsigned int posicionY = ((columna - 1) * PIXELES_POR_CASILLERO);

	RangedPixelToPixelCopyTransparent(imagenFicha, posicionX ,PIXELES_POR_CASILLERO, PIXELES_POR_CASILLERO, posicionY, this->capa, 600, 600, TransparentColor);
}

void Visualizador::exportarImagen(unsigned int altura)
{
	string nombreArchivo = "Tablero_Altura_";
	stringstream alturaStr;
	alturaStr << altura;
	nombreArchivo = nombreArchivo + alturaStr.str() + ".bmp";

	this->capa.WriteToFile(nombreArchivo.c_str());
}

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
