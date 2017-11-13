#ifndef PIXEL_H
#define PIXEL_H
#include "Forme.h"

class Pixel : public Forme
{
	//Operateur
	friend ostream& operator<< (ostream& stream, Pixel& pixel);

public:
	//Constructeur
	Pixel();
	Pixel(const char* id, const Point& position);
	Pixel(const char* id, const Point& position, const Couleur* couleur, int profondeur);
	Pixel(const Pixel& pixel);

	//Setteur
	void setId(const char* id);

	//Destructeur
	~Pixel();

	//Getteur
	const char* getInfos();


};

#endif
