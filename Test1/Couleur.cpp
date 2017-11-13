#include "Couleur.h"
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

//Constructeurs
Couleur::Couleur()
{
	cout << endl << "Couleur: Debut du constructueur par default" << endl;

	setRouge(0);
	setVert(0);
	setBleu(0);
	_nom = NULL;

	cout << endl << "Couleur: Fin du constructueur par default" << endl;
}

Couleur::Couleur(int rouge, int vert, int bleu,const char* nom)
{
	cout << endl << "Couleur: Debut du constructueur d'initialisation complet" << endl;

	setRouge(rouge);
	setVert(vert);
	setBleu(bleu);
	_nom = NULL;
	setNom(nom);

	cout << endl << "Couleur: Fin du constructueur d'initialisation complet" << endl;
}

Couleur::Couleur(int rouge, int vert, int bleu)
{
	cout << endl << "Couleur: Debut du constructueur d'initialisation partiel" << endl;

	setRouge(rouge);
	setVert(vert);
	setBleu(bleu);
	_nom = NULL;

	cout << endl << "Couleur: Fin du constructueur d'initialisation partiel" << endl;
}

Couleur::Couleur(const Couleur& couleur)
{
	cout << endl << "Couleur: Debut du constructueur de copie" << endl;

	setRouge(couleur.getRouge());
	setVert(couleur.getVert());
	setBleu(couleur.getBleu());
	_nom = NULL;
	setNom(couleur.getNom());

	cout << endl << "Couleur: Fin du constructueur de copie" << endl;
}

//Destructeur
Couleur::~Couleur()
{
	cout << endl << "Couleur: Debut du destructeur" << endl;

	if (_nom)
	{
		delete[] _nom;
	}

	cout << endl << "Couleur: Fin du destructeur" << endl;
}

//Setteur
void Couleur::setRouge(int rouge)
{
	if (rouge <= 255 && rouge >= 0)
		_rouge = rouge;
	else
		_rouge = -1;
}

void Couleur::setVert(int vert)
{
	if (vert <= 255 && vert >= 0)
		_vert = vert;
	else
		_vert = -1;
}

void Couleur::setBleu(int bleu)
{
	if (bleu <= 255 && bleu >= 0)
		_bleu = bleu;
	else
		_bleu = -1;
}

void Couleur::setNom(const char* nom)
{
	if (_nom)
		delete[] _nom;

	if (nom)
	{
		_nom = new char[strlen(nom) + 1];
		strcpy(_nom, nom);
	}
	else
		_nom = NULL;
}

//Getteur
int Couleur::getRouge() const
{
	return _rouge;
}

int Couleur::getVert() const
{
	return _vert;
}

int Couleur::getBleu() const
{
	return _bleu;
}

const char* Couleur::getNom() const
{
	return _nom;
}

//Affiche
void Couleur::Affiche() const
{
	cout<< "[COULEUR: Rouge = " << getRouge()
		<< ", Vert = " << getVert() 
		<< ", Bleu = " << getBleu()
		<< ", Nom = ";

	if (getNom())
	{
		cout << getNom();
	}
	else
	{
		cout << "Pas de nom";
	}
	cout << ']';
}

