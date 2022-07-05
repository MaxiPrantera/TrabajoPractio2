#include "Lista.h"
#include "Constantes.h"
#include "MiBitmap.h"
#include "tablero.h"

using namespace std;


MiBitmap::MiBitmap(){
	this->filasAImprimir = new Lista<BMP>();
}

MiBitmap::~MiBitmap(){
	delete this->filasAImprimir;
}

void MiBitmap::dibujarTablero(){
    BMP casilleroVacio;
    casilleroVacio.ReadFromFile("casillero.bmp");
    
    for(unsigned int fila = 1; fila <= ALTO_TABLERO; fila++){

    	this->filasAImprimir->get(fila).SetSize(PROFUNDIDAD_TABLERO, ANCHO_TABLERO);
    	this->filasAImprimir->get(fila).SetBitDepth(8);


        for(unsigned int columna = 1; columna < ANCHO_TABLERO; columna++){
            for(unsigned int profundidad = 1; profundidad < PROFUNDIDAD_TABLERO; profundidad++){
            	RangedPixelToPixelCopy(casilleroVacio, 100 ,184, 600, 152, this->filasAImprimir->get(fila), columna*184, profundidad*152);
            }
        }
        
    }
}

void MiBitmap::dibujarTierra( BMP& InputImage ) //EscenarioUno
{
	int BitDepth = InputImage.TellBitDepth();
	if( BitDepth != 1 && BitDepth != 4 && BitDepth != 8 ){ 
		return; }
	int NumberOfColors = IntPow(2,BitDepth); 
	int i;
	ebmpBYTE StepSize;
	if( BitDepth != 1 )
		{ 
		StepSize = 255/(NumberOfColors-1); }
	else{ 
		StepSize = 255; }
	for( i=0 ; i < NumberOfColors ; i++)
	{
	RGBApixel Temp;
	Temp.Red = 67; //67 //19
	Temp.Green = 36; //36 //79
	Temp.Blue = 3; //3 //178
	Temp.Alpha = 0;
	InputImage.SetColor(i,Temp);
	}
}

void MiBitmap::dibujarAgua( BMP& InputImage ) //EscenarioDos
{
	int BitDepth = InputImage.TellBitDepth();
	if( BitDepth != 1 && BitDepth != 4 && BitDepth != 8 ){ 
		return; }
	int NumberOfColors = IntPow(2,BitDepth); 
	int i;
	ebmpBYTE StepSize;
	if( BitDepth != 1 )
		{ 
		StepSize = 255/(NumberOfColors-1); }
	else{ 
		StepSize = 255; }
	for( i=0 ; i < NumberOfColors ; i++)
	{
		RGBApixel Temp;
		Temp.Red = 19; //67 //19
		Temp.Green = 79; //36 //79
		Temp.Blue = 178; //3 //178
		Temp.Alpha = 0;
		InputImage.SetColor(i,Temp);
	}
}

void MiBitmap::dibujarLaguna() //EscenarioTres
{
    BMP AguaTierra;

    AguaTierra.SetBitDepth(8);
    AguaTierra.SetSize(600,600);

    int x ;
    int y ;
    for (x = 0; x < 600; x++){
	    for(y = 0; y < 600; y++){

		    AguaTierra(x,y)->Red = 19;
		    AguaTierra(x,y)->Green = 79;
		    AguaTierra(x,y)->Blue = 178;
		    AguaTierra(x,y)->Alpha = 0;
	
	    }
    }
    for (x = 0; x < 600; x++){
	    for(y = 0; y < 150; y++){

		    AguaTierra(x,y)->Red = 67;
		    AguaTierra(x,y)->Green = 36;
		    AguaTierra(x,y)->Blue = 3;
		    AguaTierra(x,y)->Alpha = 0;
	    }
    }
    for (x = 0; x < 600; x++){
	    for(y = 450; y < 600; y++){

		    AguaTierra(x,y)->Red = 67;
		    AguaTierra(x,y)->Green = 36;
		    AguaTierra(x,y)->Blue = 3;
		    AguaTierra(x,y)->Alpha = 0;
	    }
    }
}

void MiBitmap::quemarCasillero( BMP& InputImage )
{
	int BitDepth = InputImage.TellBitDepth();
	if( BitDepth != 1 && BitDepth != 4 && BitDepth != 8 ){ 
		return;
	}
	int NumberOfColors = IntPow(2,BitDepth); 
	int i;
	ebmpBYTE StepSize;
	if( BitDepth != 1 )
		{ 
		StepSize = 255/(NumberOfColors-1); }
	else{ 
		StepSize = 255; }
	for( i=0 ; i < NumberOfColors ; i++)
	{
		RGBApixel Temp;
		Temp.Red = i*StepSize; //67 //19
		Temp.Green = 0; //36 //79
		Temp.Blue = 0; //3 //178
		Temp.Alpha = 0;
		InputImage.SetColor(i,Temp);
	}
}

void MiBitmap::casilleroAnulado(){

	BMP Gris;
	Gris.ReadFromFile( "soldado.bmp" ); //Le paso como ejemplo la imagen del soldado

	for( int j=0 ; j < Gris.TellHeight() ; j++)
	{
		for( int i=0 ; i < Gris.TellWidth() ; i++)
		{
			int Temp = (int) floor( 0.299*Gris(i,j)->Red + 0.587*Gris(i,j)->Green + 0.114*Gris(i,j)->Blue );
			ebmpBYTE TempBYTE = (ebmpBYTE) Temp;
			Gris(i,j)->Red = TempBYTE;
			Gris(i,j)->Green = TempBYTE;
			Gris(i,j)->Blue = TempBYTE;
		}
	}
	// Creo Tabla de color gris
	if( Gris.TellBitDepth() < 16 )
	{ 
		CreateGrayscaleColorTable( Gris ); }
	
	Gris.WriteToFile( "gris.bmp" );

}

void MiBitmap::agregarEscudo(){
	
	BMP Soldado;
	Soldado.SetBitDepth(8);
	Soldado.ReadFromFile("soldado.bmp");
	BMP Escudo;
	Escudo.ReadFromFile("Escudo.bmp");

	RGBApixel TransparentColor;
	TransparentColor.Red = 255;
	TransparentColor.Green = 255;
	TransparentColor.Blue = 255;
	RangedPixelToPixelCopyTransparent(Soldado, 100, 600, 600, 100, Escudo, 100, 110, TransparentColor);
}

void MiBitmap::imprimirTablero(Tablero * tablero, unsigned int xMax, unsigned int yMax, unsigned int zMax){
	this->dibujarTablero();

    Tablero* = tablero->obtenerMatrizTablero();
    Casillero * casilleroActual = NULL;

    for(unsigned int x = 1; x < this->xMax; x++)
    {
        this->casilleros->agregar(Lista<Lista<Casillero> >());
        for (unsigned int y = 1; y < this->yMax; y++)
        {
            this->casilleros->get(x).agregar(Lista <Casillero>());
            for (unsigned int z = 1; z < this->zMax; z++)
            {
                this->casilleros->get(x).get(y).agregar(Casillero());
            }
        }
    }
    tablero.save_image("tablero.bmp");
}
