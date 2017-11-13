#include "Rectangle.h"
#include "Forme.h"
#include "Couleur.h"
#include "Point.h"
#include <string.h>
#include <iostream>
#include <stdlib.h>

using namespace std;


//Constructeur
Rectangle::Rectangle() : Forme() 
{
	setId("R0");
	setDimX(0);
	setDimY(0);
	setRempli(false);
}

Rectangle::Rectangle(const char* id, const Point& position) : Forme(position)
{
	setId(id);
	setDimX(0);
	setDimY(0);
	setRempli(false);
}

Rectangle::Rectangle(const char* id, const Point& position, const Couleur* couleur, int profondeur) : Forme(position, couleur, profondeur)
{
	setId(id);
	setDimX(0);
	setDimY(0);
	setRempli(false);
}

Rectangle::Rectangle(const char* id, const Point& position, int dimX, int dimY, bool rempli) : Forme(position)
{
	setId(id);
	setDimX(dimX);
	setDimY(dimY);
	setRempli(rempli);
}

Rectangle::Rectangle(const char* id, const Point& position, int dimX, int dimY, bool rempli, const Couleur* couleur, int profondeur) : Forme(position, couleur, profondeur) 
{
	setId(id);
	setDimX(dimX);
	setDimY(dimY);
	setRempli(rempli);
}

Rectangle::Rectangle(const Rectangle& rectangle) : Forme(rectangle) 
{
	setId(rectangle.getId());
	setDimX(rectangle.getDimX());
	setDimY(rectangle.getDimY());
	setRempli(rectangle.getRempli());
}

//Destructeur
Rectangle::~Rectangle() {}

//Setteur
void Rectangle::setId(const char* id)
{
	if (_id)
		delete[] _id;

	if (id)
	{
		_id = new char[strlen(id) + 1];
		strcpy(_id, id);
	}
	else
	{
		_id = new char[3];
		strcpy(_id, "R0");
	}
}


void Rectangle::setDimX(int dimX)
{
	_dimX = dimX;
}

void Rectangle::setDimY(int dimY)
{
	_dimY = dimY;
}

void Rectangle::setRempli(bool rempli)
{
	_rempli = rempli;
}

//Getteur
int Rectangle::getDimX() const
{
	return _dimX;
}

int Rectangle::getDimY() const
{
	return _dimY;
}

bool Rectangle::getRempli() const
{
	return _rempli;
}

const char * Rectangle::getInfos()
{
	int tailleChaine = 1;

	if (_infos)
		delete[] _infos;

	tailleChaine += strlen(getId());
	tailleChaine += nbrCaractEntier(getPosition().getX()) + nbrCaractEntier(getPosition().getY());
	tailleChaine += nbrCaractEntier(getProfondeur());
	tailleChaine += nbrCaractEntier(getDimX());
	tailleChaine += nbrCaractEntier(getDimY());
	tailleChaine += 1; //Valeur Rempli

	if (getCouleur())
	{
		tailleChaine += nbrCaractEntier(getCouleur()->getRouge()) + nbrCaractEntier(getCouleur()->getVert()) + nbrCaractEntier(getCouleur()->getBleu());

		if (getCouleur()->getNom())
		{
			tailleChaine += strlen(getCouleur()->getNom());
			tailleChaine += strlen("[RECTANGLE : ID = , Position(, ), DimX = , DimY = , Rempli = , Couleur(, , , ), Profondeur = ]");

			_infos = new char[tailleChaine];
			sprintf(_infos, "[RECTANGLE : ID = %s, Position(%d, %d), DimX = %d, DimY = %d, Rempli = %d, Couleur(%d, %d, %d, %s), Profondeur = %d]", getId(), getPosition().getX(), getPosition().getY(), getDimX(), getDimY(), getRempli(), getCouleur()->getRouge(), getCouleur()->getVert(), getCouleur()->getBleu(), getCouleur()->getNom(), getProfondeur());
		}
		else
		{
			tailleChaine += strlen("[RECTANGLE : ID = , Position(, ), DimX = , DimY = , Rempli = , Couleur(, , , Pas de nom), Profondeur = ]");

			_infos = new char[tailleChaine];
			sprintf(_infos, "[RECTANGLE : ID = %s, Position(%d, %d), DimX = %d, DimY = %d, Rempli = %d, Couleur(%d, %d, %d, Pas de nom), Profondeur = %d]", getId(), getPosition().getX(), getPosition().getY(), getDimX(), getDimY(), getRempli(), getCouleur()->getRouge(), getCouleur()->getVert(), getCouleur()->getBleu(), getProfondeur());
		}
	}
	else
	{
		tailleChaine += strlen("[RECTANGLE : ID = , Position(, ), DimX = , DimY = , Rempli = , Couleur(Pas de couleur), Profondeur = ]");

		_infos = new char[tailleChaine];
		sprintf(_infos, "[RECTANGLE : ID = %s, Position(%d, %d), DimX = %d, DimY = %d, Rempli = %d, Couleur(Pas de couleur), Profondeur = %d]", getId(), getPosition().getX(), getPosition().getY(), getDimX(), getDimY(), getRempli(), getProfondeur());
	}

	return _infos;
}

ostream& operator<< (ostream& stream, Rectangle& rectangle)
{
	stream << rectangle.getInfos();
	return stream;
}

//Methode
bool Rectangle::isRempli() const
{
	return _rempli;
}
