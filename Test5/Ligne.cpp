#include "Ligne.h"
#include "Forme.h"
#include "Couleur.h"
#include "Point.h"
#include "BaseException.h"
#include <string.h>
#include <iostream>
#include <stdlib.h>

using namespace std;


//Constructeur
Ligne::Ligne() : Forme() 
{
	setExtremite(Point());
}

Ligne::Ligne(const char* id, const Point& position) : Forme(position) 
{
	setId(id);
	setExtremite(Point());
}

Ligne::Ligne(const char* id, const Point& position, const Couleur* couleur, int profondeur) : Forme(position, couleur, profondeur) 
{
	setId(id);
	setExtremite(Point());
}

Ligne::Ligne(const char* id, const Point& position, const Point& extremite) : Forme(position) 
{
	setId(id);
	setExtremite(extremite);
}

Ligne::Ligne(const char* id, const Point& position, const Point& extremite, const Couleur* couleur, int profondeur) : Forme(position, couleur, profondeur)
{
	setId(id);
	setExtremite(extremite);
}

Ligne::Ligne(const Ligne& ligne) : Forme(ligne) 
{
	setId(ligne.getId());
	setExtremite(ligne.getExtremite());
}

//Destructeur
Ligne::~Ligne() {}

//Setteur
void Ligne::setId(const char* id)
{
	int i = 1;

	if (id)
	{
		if (id[0] != 'L' || strlen(id) < 2)
			throw(BaseException("Identifiant Ligne invalide !"));

		while (id[i] != '\0')
		{
			if (!isdigit(id[i]))
				throw(BaseException("Identifiant Ligne invalide !"));
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
		strcpy(_id, "L0");
	}
}


//Getteur
const char * Ligne::getInfos()
{
	int tailleChaine = 1;

	if (_infos)
		delete[] _infos;

	tailleChaine += strlen(getId());
	tailleChaine += nbrCaractEntier(getPosition().getX()) + nbrCaractEntier(getPosition().getY());
	tailleChaine += nbrCaractEntier(getProfondeur());
	tailleChaine += nbrCaractEntier(getExtremite().getX()) + nbrCaractEntier(getExtremite().getY());

	if (getCouleur())
	{
		tailleChaine += nbrCaractEntier(getCouleur()->getRouge()) + nbrCaractEntier(getCouleur()->getVert()) + nbrCaractEntier(getCouleur()->getBleu());

		if (getCouleur()->getNom())
		{
			tailleChaine += strlen(getCouleur()->getNom());
			tailleChaine += strlen("[LIGNE : ID = , Position(, ), Extremite(, ), Couleur(, , , ), Profondeur = ]");

			_infos = new char[tailleChaine];
			sprintf(_infos, "[LIGNE : ID = %s, Position(%d, %d), Extremite(%d, %d), Couleur(%d, %d, %d, %s), Profondeur = %d]", getId(), getPosition().getX(), getPosition().getY(), getExtremite().getX(), getExtremite().getY(), getCouleur()->getRouge(), getCouleur()->getVert(), getCouleur()->getBleu(), getCouleur()->getNom(), getProfondeur());
		}
		else
		{
			tailleChaine += strlen("[LIGNE : ID = , Position(, ), Extremite(, ), Couleur(, , , Pas de nom), Profondeur = ]");

			_infos = new char[tailleChaine];
			sprintf(_infos, "[LIGNE : ID = %s, Position(%d, %d), Extremite(%d, %d), Couleur(%d, %d, %d, Pas de nom), Profondeur = %d]", getId(), getPosition().getX(), getPosition().getY(), getExtremite().getX(), getExtremite().getY(), getCouleur()->getRouge(), getCouleur()->getVert(), getCouleur()->getBleu(), getProfondeur());
		}
	}
	else
	{
		tailleChaine += strlen("[LIGNE : ID = , Position(, ), Extremite(, ), Couleur(Pas de couleur), Profondeur = ]");

		_infos = new char[tailleChaine];
		sprintf(_infos, "[LIGNE : ID = %s, Position(%d, %d), Extremite(%d, %d), Couleur(Pas de couleur), Profondeur = %d]", getId(), getPosition().getX(), getPosition().getY(), getExtremite().getX(), getExtremite().getY(), getProfondeur());
	}
	return _infos;
}

const Point& Ligne::getExtremite() const
{
	return _extremite;
}

void Ligne::setExtremite(const Point& extremite)
{
	_extremite.setX(extremite.getX());
	_extremite.setY(extremite.getY());
}


ostream& operator<< (ostream& stream, Ligne& ligne)
{
	stream << ligne.getInfos();
	return stream;
}
