#include "EasyBMP.h"
#include "EasyBMP.cpp"
#include "Lista.h"
#include "tablero.h"


Bitmap::Bitmap(unsigned int xMax, unsigned int yMax, unsigned int zMax){
   	this->tablero = new Tablero(xmax, ymax, zmax);
	this->listaBitmap = new Lista<BMP*>();
	this->xMax=xMax;
    	this->yMax=yMax;
    	this->zMax=zMax; 
}

void Bitmap::dibujarTablero(Lista<BMP*> * capasTablero, unsigned int xMax, unsigned int yMax, unsigned int zMax){

    BMP casilleroVacio;
    std::string file_name("agua" + "tierra" + casillero.terrenoAString()+ ".bmp");
    
    for(unsigned int i = 1; i < zMax; i++){

        capasTablero->get(i)->SetSize(xMax, yMax);
        capasTablero->get(i)->SetBitDepth(8);


        for(unsigned int j = 1; j < yMax; j++){
            for(unsigned int k = 1; k < xMax; k++){

            RangedPixelToPixelCopy(casilleroVacio, 100 ,184, 600, 152,*capasTablero->get(i), j*184, 152*k);

            }
        }
        
    }
}

void Bitmap::dibujarTierra( BMP& InputImage ) //EscenarioUno
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

void Bitmap::dibujarAgua( BMP& InputImage ) //EscenarioDos
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

void Bitmap::dibujarLaguna() //EscenarioTres
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

void Bitmap::quemarCasillero( BMP& InputImage )
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

void Bitmap::casilleroAnulado(){

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


void Bitmap::imprimirTablero(Tablero * tablero, unsigned int xMax, unsigned int yMax, unsigned int zMax){

	this->tablero = new Tablero(xmax, ymax, zmax);

    Lista<BMP*> * capasTablero  = new Lista<BMP*>;
    for(unsigned int cantidadDeCapas = 0; cantidadDeCapas <zMax ;cantidadCapas++)
	{
		BMP * nuevoBitmap = new BMP;
		capasTablero->get(nuevoBitmap);
	}
    dibujarTablero(capasTablero, xMax, yMax, zMax)

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

    capasTablero->iniciarCursor();
	while(capasTablero->avanzarCursor())
	{
		delete capasTablero->obtenerCursor();
	}
	delete capasTablero;
}
