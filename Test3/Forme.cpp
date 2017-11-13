#include "Forme.h"
#include "Couleur.h"
#include "Point.h"
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

int Forme::_compteur = 0;

//Constructeur
Forme::Forme()
{
	cout << endl << "Forme: Debut du constructueur par default" << endl;

	_id = NULL;
	setId("F0");
	setPosition(Point());
	setCouleur(NULL);
	setProfondeur(0);

	_compteur++;

	cout << endl << "Forme: Fin du constructueur par default" << endl;
}

Forme::Forme(const char* id, const Point& position)
{
	cout << endl << "Forme: Debut du constructueur d'initialisation partiel" << endl;

	_id = NULL;
	setId(id);
	setPosition(position);
	setCouleur(NULL);
	setProfondeur(0);
	
	_compteur++;

	cout << endl << "Forme: Fin du constructueur d'initialisation partiel" << endl;
}

Forme::Forme(const char* id, const Point& position, const Couleur* couleur, int profondeur)
{
	cout << endl << "Forme: Debut du constructueur d'initialisation complet" << endl;

	_id = NULL;
	setId(id);
	setPosition(position);
	setCouleur(couleur);
	setProfondeur(profondeur);

	_compteur++;

	cout << endl << "Forme: Fin du constructueur d'initialisation complet" << endl;
}

Forme::Forme(const Forme& forme)
{
	cout << endl << "Forme: Debut du constructueur de copie" << endl;

	_id = NULL;
	setId(forme.getId());
	setPosition(forme.getPosition());
	setCouleur(forme.getCouleur());
	setProfondeur(forme.getProfondeur());

	_compteur++;

	cout << endl << "Forme: Fin du constructueur de copie" << endl;
}

//Destructeur
Forme::~Forme()
{
	cout << endl << "Forme: Debut du destructeur" << endl;

	if (_id)
		delete[] _id;

	_compteur--;

	cout << endl << "Forme: Fin du destructeur" << endl;
}

//Getteur
const char* Forme::getId() const
{
	return _id;
}

const Point& Forme::getPosition() const
{
	return _position;
}

const Couleur* Forme::getCouleur() const
{
	return _couleur;
}

int Forme::getProfondeur() const
{
	return _profondeur;
}

int Forme::getCompteur()
{
	return _compteur;
}

//Setteur
void Forme::setId(const char* id)
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
		strcpy(_id, "F0");
	}
}
void Forme::setPosition(const Point& position)
{
	_position.setX(position.getX());
	_position.setY(position.getY());
}

void Forme::setCouleur(const Couleur* couleur)
{
	_couleur = couleur;
}

void Forme::setProfondeur(int profondeur)
{
	_profondeur = profondeur;
}

//Affiche
void Forme::Affiche() const
{
	cout	<< "[FORME: Id = " << getId()
		<< ", Position = ";
	getPosition().Affiche();

	if (getCouleur())
	{
		cout << ", Couleur = ";
		getCouleur()->Affiche();
	}
	else
		cout << ", Couleur = Pas de couleur";

	cout << ", Profondeur = " << getProfondeur() << "]";
}
