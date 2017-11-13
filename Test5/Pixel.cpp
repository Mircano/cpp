#include "Pixel.h"
#include "Forme.h"
#include "Couleur.h"
#include "Point.h"
#include "BaseException.h"
#include <string.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

//Constructeur
Pixel::Pixel() : Forme() {}

Pixel::Pixel(const char* id, const Point& position) : Forme(position) 
{
	setId(id);
}

Pixel::Pixel(const char* id, const Point& position, const Couleur* couleur, int profondeur) : Forme(position, couleur, profondeur) 
{
	setId(id);
}

Pixel::Pixel(const Pixel& pixel) : Forme(pixel) 
{
	setId(pixel.getId());
}

//Destructeur
Pixel::~Pixel() {}

//Setter
void Pixel::setId(const char* id)
{
	int i = 1;
	if (id)
	{
		if (id[0] != 'P' || strlen(id) < 2)
			throw(BaseException("Identifiant Pixel invalide !"));

		while (id[i] != '\0')
		{
			if (!isdigit(id[i]))
				throw(BaseException("Identifiant Pixel invalide !"));
			i++;
		}
	}

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
		strcpy(_id, "P0");
	}
}


//Getteur
const char * Pixel::getInfos()
{
	int tailleChaine = 1;

	if (_infos)
		delete[] _infos;

	tailleChaine += strlen(getId());
	tailleChaine += nbrCaractEntier(getPosition().getX()) + nbrCaractEntier(getPosition().getY());
	tailleChaine += nbrCaractEntier(getProfondeur());

	if (getCouleur())
	{
		tailleChaine += nbrCaractEntier(getCouleur()->getRouge()) + nbrCaractEntier(getCouleur()->getVert()) + nbrCaractEntier(getCouleur()->getBleu());
		if (getCouleur()->getNom())
		{
			tailleChaine += strlen(getCouleur()->getNom());
			tailleChaine += strlen("[PIXEL : ID = , Position(, ), Couleur(, , , ), Profondeur = ]");
			
			_infos = new char[tailleChaine];
			sprintf(_infos, "[PIXEL : ID = %s, Position(%d, %d), Couleur(%d, %d, %d, %s), Profondeur = %d]", getId(), getPosition().getX(), getPosition().getY(), getCouleur()->getRouge(), getCouleur()->getVert(), getCouleur()->getBleu(), getCouleur()->getNom(), getProfondeur());
		}
		else
		{
			tailleChaine += strlen("[PIXEL : ID = , Position(, ), Couleur(, , , Pas de nom), Profondeur = ]");

			_infos = new char[tailleChaine];
			sprintf(_infos, "[PIXEL : ID = %s, Position(%d, %d), Couleur(%d, %d, %d, Pas de nom), Profondeur = %d]", getId(), getPosition().getX(), getPosition().getY(), getCouleur()->getRouge(), getCouleur()->getVert(), getCouleur()->getBleu(), getProfondeur());
		}
	}
	else
	{
		tailleChaine += strlen("[PIXEL : ID = , Position(, ), Couleur(Pas de couleur), Profondeur = ]");

		_infos = new char[tailleChaine];
		sprintf(_infos, "[PIXEL : ID = %s, Position(%d, %d), Couleur(Pas de couleur), Profondeur = %d]", getId(), getPosition().getX(), getPosition().getY(), getProfondeur());
	}

	return _infos;
}

ostream& operator<< (ostream& stream, Pixel& pixel)
{
	stream << pixel.getInfos();
	return stream;
}
