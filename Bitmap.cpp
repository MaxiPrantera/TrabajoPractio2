#include "bitmap_image.hpp"
#include "Lista.h"
#include "tablero.h"

using namespace std;

Bitmap::Bitamp(){
    Lista<BMP*>* listaBitmap = new Lista<BMP*>();
    this->listaBitmap = listaBitmap;
}

void dibujarTablero(Lista<BMP*> * capasTablero, unsigned int xMax, unsigned int yMax, unsigned int zMax){

    std::string file_name("agua" + "tierra" + casillero.terrenoAString()+ ".bmp");
    bitmap_image image(file_name);
    bitmap_image image(600, 400);

    const rgb_t* colormap[1] = 
    {
        gray_colormap,
    };

    for(unsigned int i = 0; i < xMax; i++){
        for(unsigned int j = 0; j < yMax; j++){
            capasTablero->get(i)->SetBitDepth(32);
            draw.pen_color(colormap[j][i].red, colormap[j][i].green, colormap[j][i].blue);
            draw.vertical_line_segment(j * 20, (j+1) * 20, i);
            RangedPixelToPixelCopy(image, 0 ,184, 0, 152,*capasTablero->get(i), j*184, 152*k);
        }
        
    }
void dibujarTierra(){

    const int width  = 600;
    const int height = 400;
    cartesian_canvas tierra(width,height);
    {
    const rgb_t* colormap[9] = {
                                    autumn_colormap,
                                    copper_colormap,
                                    gray_colormap,
                                    hot_colormap,
                                    hsv_colormap,
                                    jet_colormap,
                                    prism_colormap,
                                    vga_colormap,
                                    yarg_colormap
                                };
    const double x = 0.7;
    const double y = 0.7;
    const double c1 = 0.3;
    const double c2 = 0.3;
    const double c3 = 0.2;
    const double c4 = 0.2;

    ::srand(0xB6BB6BB6);

    plasma(tierra.image(), x, y, width, height, c1, c2, c3, c4, 0.9, copper_colormap);

    }
    tierra.image().save_image("tierra.bmp");

}

void dibujarAgua(){
    const int width  = 600;
    const int height = 400;
    cartesian_canvas agua(width,height);

    {
    const double x = 0.7;
    const double y = 0.7;
    const double c1 = 0.3;
    const double c2 = 0.3;
    const double c3 = 0.2;
    const double c4 = 0.2;

    ::srand(0xA5AA5AA5);

    plasma(agua.image(), x, y, width, height, c1, c2, c3, c4, 0.2, jet_colormap);

    }
    agua.image().save_image("agua.bmp");
}

void dibujarFuego(){
    bitmap_image fuego(600,400);

    image.clear();

    double c1 = 0.9;
    double c2 = 0.5;
    double c3 = 0.3;
    double c4 = 0.7;

    ::srand(0xA5AA5AA5);
    plasma(image,0,0,image.width(),image.height(),c1,c2,c3,c4,3.0,jet_colormap);
    fuego.save_image("fuego.bmp");
}



void imprimirTablero(Tablero * tablero, unsigned int xMax, unsigned int yMax, unsigned int zMax){

    Lista<BMP*> * capasTablero  = new Lista<BMP*> ;
    for(unsigned int cantidadDeCapas = 0; cantidadDeCapas <zMax ;cantidadCapas++)
	{
		BMP * nuevoBitmap = new BMP;
		capasTablero->get(nuevoBitmap);
	}
    dibujarTablero(capasTablero, xMax, yMax, zMax)

    Tablero* = tablero->obtenerMatrizTablero();
    Casillero * casilleroActual = NULL;

	for(unsigned int z = 1 ;z <= zMax; z++)
	{		
		for(unsigned int y = 1; y <= yMax; y++)
		{
			for(unsigned int x = 1; x <= xMax;fil++)
			{

                casilleroActual = Casillero->getCasillero(x, y, z);
                char fichaActual = casilleroActual->Ficha(const Ficha&);
            }
        }

    tablero.save_image("tablero.bmp");

    //libero memoria dinamica de los bitmaps
    capasTablero->iniciarCursor();
	while(capasTablero->avanzarCursor())
	{
		delete capasTablero->obtenerCursor();
	}
	delete capasTablero;
    }
}