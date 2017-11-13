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
	//cout << endl << "Forme: Debut du constructueur par default" << endl;

	_id = NULL;
	setPosition(Point());
	setCouleur(NULL);
	setProfondeur(0);
	_infos = NULL;

	_compteur++;

	//cout << endl << "Forme: Fin du constructueur par default" << endl;
}

Forme::Forme(const Point& position)
{
	//cout << endl << "Forme: Debut du constructueur d'initialisation partiel" << endl;

	_id = NULL;
	setPosition(position);
	setCouleur(NULL);
	setProfondeur(0);
	_infos = NULL;

	_compteur++;

	//cout << endl << "Forme: Fin du constructueur d'initialisation partiel" << endl;
}

Forme::Forme(const Point& position, const Couleur* couleur, int profondeur)
{
	//cout << endl << "Forme: Debut du constructueur d'initialisation complet" << endl;

	_id = NULL;
	setPosition(position);
	setCouleur(couleur);
	setProfondeur(profondeur);
	_infos = NULL;

	_compteur++;

	//cout << endl << "Forme: Fin du constructueur d'initialisation complet" << endl;
}

Forme::Forme(const Forme& forme)
{
	//cout << endl << "Forme: Debut du constructueur de copie" << endl;

	_id = NULL;
	setPosition(forme.getPosition());
	setCouleur(forme.getCouleur());
	setProfondeur(forme.getProfondeur());
	_infos = NULL;

	_compteur++;

	//cout << endl << "Forme: Fin du constructueur de copie" << endl;
}

//Destructeur
Forme::~Forme()
{
	//cout << endl << "Forme: Debut du destructeur" << endl;

	if (_id)
		delete[] _id;

	if (_infos)
		delete[] _infos;

	_compteur--;

	//cout << endl << "Forme: Fin du destructeur" << endl;
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

//Methode
int Forme::nbrCaractEntier(int nbr)
{
	if (nbr == 0)
		return 1;

	if (nbr < 0)
	{
		nbr *= -1;
		return ((int)log10((double)nbr) + 2);
	}

	return ((int)log10((double)nbr)+1);
}
