#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Forme.h"

class Rectangle : public Forme
{
	//Operateur
	friend ostream& operator<< (ostream& stream, Rectangle& rectangle);

private:
	int _dimX;
	int _dimY;
	bool _rempli;

public:
	//Constructeur
	Rectangle();
	Rectangle(const char* id, const Point& position);
	Rectangle(const char* id, const Point& position, const Couleur* couleur, int profondeur);
	Rectangle(const char* id, const Point& position, int dimX, int dimY, bool rempli);
	Rectangle(const char* id, const Point& position, int dimX, int dimY, bool rempli, const Couleur* couleur, int profondeur);
	Rectangle(const Rectangle& rectangle);

	//Destructeur
	~Rectangle();

	//Setteur
	void setId(const char* id);
	void setDimX(int dimX);
	void setDimY(int dimY);
	void setRempli(bool rempli);

	//Getteur
	int getDimX() const;
	int getDimY() const;
	bool getRempli() const;
	const char* getInfos();

	//Methode
	bool isRempli() const;
};

#endif
