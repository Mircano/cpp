#include "Couleur.h"
#include "InvalidColorException.h"
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

const Couleur Couleur::ROUGE(255, 000, 000, "Rouge");
const Couleur Couleur::VERT(000, 255, 000, "Vert");
const Couleur Couleur::BLEU(000, 000, 255, "Bleu");

int Couleur::_compteur = 0;

//Constructeurs
Couleur::Couleur()
{
	//cout << endl << "Couleur: Debut du constructueur par default" << endl;

	setRouge(0);
	setVert(0);
	setBleu(0);
	_nom = NULL;

	_compteur++;

	//cout << endl << "Couleur: Fin du constructueur par default" << endl;
}

Couleur::Couleur(int rouge, int vert, int bleu,const char* nom)
{
	//cout << endl << "Couleur: Debut du constructueur d'initialisation complet" << endl;
	
	testCouleur(rouge, vert, bleu);

	setRouge(rouge);
	setVert(vert);
	setBleu(bleu);
	_nom = NULL;
	setNom(nom);

	_compteur++;

	//cout << endl << "Couleur: Fin du constructueur d'initialisation complet" << endl;
}

Couleur::Couleur(int rouge, int vert, int bleu)
{
	//cout << endl << "Couleur: Debut du constructueur d'initialisation partiel" << endl;
	
	testCouleur(rouge, vert, bleu);

	setRouge(rouge);
	setVert(vert);
	setBleu(bleu);
	_nom = NULL;

	_compteur++;

	//cout << endl << "Couleur: Fin du constructueur d'initialisation partiel" << endl;
}

Couleur::Couleur(const Couleur& couleur)
{
	//cout << endl << "Couleur: Debut du constructueur de copie" << endl;

	testCouleur(couleur.getRouge(), couleur.getVert(), couleur.getBleu());

	setRouge(couleur.getRouge());
	setVert(couleur.getVert());
	setBleu(couleur.getBleu());
	_nom = NULL;
	setNom(couleur.getNom());

	_compteur++;

	//cout << endl << "Couleur: Fin du constructueur de copie" << endl;
}

//Destructeur
Couleur::~Couleur()
{
	//cout << endl << "Couleur: Debut du destructeur" << endl;

	if (_nom)
	{
		delete[] _nom;
	}

	_compteur--;

	//cout << endl << "Couleur: Fin du destructeur" << endl;
}

//Setteur
void Couleur::setRouge(int rouge)
{
	if (rouge <= 255 && rouge >= 0)
		_rouge = rouge;
	else
		throw(InvalidColorException("Modification Couleur Impossible !", 0, 1, 1));
}

void Couleur::setVert(int vert)
{
	if (vert <= 255 && vert >= 0)
		_vert = vert;
	else
		throw(InvalidColorException("Modification Couleur Impossible !", 1, 0, 1));
}

void Couleur::setBleu(int bleu)
{
	if (bleu <= 255 && bleu >= 0)
		_bleu = bleu;
	else
		throw(InvalidColorException("Modification Couleur Impossible !", 1, 1, 0));
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

int Couleur::getCompteur()
{
	return _compteur;
}

int Couleur::getLuminance() const
{
	return (int)round((getRouge() + getVert() + getBleu()) / 3.0);
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
	cout << ", Luminance = " << getLuminance() << "]";

}

//Opérateur
Couleur& Couleur::operator=(const Couleur& couleur)
{
	setRouge(couleur.getRouge());
	setVert(couleur.getVert());
	setBleu(couleur.getBleu());
	setNom(couleur.getNom());

	return *this;
}

Couleur& Couleur::operator++()
{
	if (getRouge() + 10 <= 255)
		setRouge(getRouge() + 10);
	else
		setRouge(255);

	if (getVert() + 10 <= 255)
		setVert(getVert() + 10);
	else
		setVert(255);

	if (getBleu() + 10 <= 255)
		setBleu(getBleu() + 10);
	else
		setBleu(255);

	return *this;
}

Couleur& Couleur::operator--()
{
	if (getRouge() - 10 >= 0)
		setRouge(getRouge() - 10);
	else
		setRouge(0);

	if (getVert() - 10 >= 0)
		setVert(getVert() - 10);
	else
		setVert(255);

	if (getBleu() - 10 >= 0)
		setBleu(getBleu() - 10);
	else
		setBleu(0);

	return *this;
}

Couleur Couleur::operator++(int)
{
	Couleur couleurTemp(*this);

	if (getRouge() + 10 <= 255)
		setRouge(getRouge() + 10);
	else
		setRouge(255);

	if (getVert() + 10 <= 255)
		setVert(getVert() + 10);
	else
		setVert(255);

	if (getBleu() + 10 <= 255)
		setBleu(getBleu() + 10);
	else
		setBleu(255);

	return couleurTemp;
}

Couleur Couleur::operator--(int)
{
	Couleur couleurTemp(*this);

	if (getRouge() - 10 >= 0)
		setRouge(getRouge() - 10);
	else
		setRouge(0);

	if (getVert() - 10 >= 0)
		setVert(getVert() - 10);
	else
		setVert(255);

	if (getBleu() - 10 >= 0)
		setBleu(getBleu() - 10);
	else
		setBleu(0);

	return couleurTemp;
}

Couleur Couleur::operator+ (const Couleur& couleur) const
{
	Couleur couleurTemp;
	int add;
	int tailleBuff;
	char* buff = NULL;

	add = getRouge() + couleur.getRouge();
	if (add <= 255)
		couleurTemp.setRouge(add);
	else
		couleurTemp.setRouge(255);

	add = getVert() + couleur.getVert();
	if (add <= 255)
		couleurTemp.setVert(add);
	else
		couleurTemp.setVert(255);

	add = getBleu() + couleur.getBleu();
	if (add <= 255)
		couleurTemp.setBleu(add);
	else
		couleurTemp.setBleu(255);

	if (getNom() && couleur.getNom())
	{
		tailleBuff = strlen(getNom()) + strlen(couleur.getNom()) + 19;
		buff = new char[tailleBuff];
		sprintf(buff, "Melange de %s et de %s", getNom(), couleur.getNom());
		couleurTemp.setNom(buff);
	}
	else
		couleurTemp.setNom("Melange inconnu");

	if (buff)
		delete buff;

	return couleurTemp;
}

Couleur operator+ (int entier, const Couleur& couleur)
{
	Couleur couleurTemp;
	int add;
	int tailleBuff;
	char* buff = NULL;

	add = couleur.getRouge() + entier;
	if (add <= 255)
		couleurTemp.setRouge(add);
	else
		couleurTemp.setRouge(255);

	add = couleur.getVert() + entier;
	if (add <= 255)
		couleurTemp.setVert(add);
	else
		couleurTemp.setVert(255);

	add = couleur.getBleu() + entier;
	if (add <= 255)
		couleurTemp.setBleu(add);
	else
		couleurTemp.setBleu(255);

	if (couleur.getNom())
	{
		tailleBuff = strlen(couleur.getNom() + 8 + 1 + 3);
		buff = new char[tailleBuff];
		sprintf(buff, "%s fonce(%d)", couleur.getNom(), couleurTemp.getLuminance() - couleur.getLuminance());
		couleurTemp.setNom(buff);
	}
	else
		couleurTemp.setNom(NULL);

	if (buff)
		delete buff;

	return couleurTemp;
}

Couleur operator+ (const Couleur& couleur, int entier)
{
	Couleur couleurTemp;
	int add;
	int tailleBuff;
	char* buff = NULL;

	add = couleur.getRouge() + entier;
	if (add <= 255)
		couleurTemp.setRouge(add);
	else
		couleurTemp.setRouge(255);

	add = couleur.getVert() + entier;
	if (add <= 255)
		couleurTemp.setVert(add);
	else
		couleurTemp.setVert(255);

	add = couleur.getBleu() + entier;
	if (add <= 255)
		couleurTemp.setBleu(add);
	else
		couleurTemp.setBleu(255);

	if (couleur.getNom())
	{
		tailleBuff = strlen(couleur.getNom() + 8 + 1 + 3);
		buff = new char[tailleBuff];
		sprintf(buff, "%s fonce(%d)", couleur.getNom(), couleurTemp.getLuminance() - couleur.getLuminance());
		couleurTemp.setNom(buff);
	}
	else
		couleurTemp.setNom(NULL);

	if (buff)
		delete buff;

	return couleurTemp;
}

Couleur operator- (int entier, const Couleur& couleur)
{
	Couleur couleurTemp;
	int sou;
	int tailleBuff;
	char* buff = NULL;

	sou = couleur.getRouge() - entier;
	if (sou <= 255)
		couleurTemp.setRouge(sou);
	else
		couleurTemp.setRouge(255);

	sou = couleur.getVert() - entier;
	if (sou <= 255)
		couleurTemp.setVert(sou);
	else
		couleurTemp.setVert(255);

	sou = couleur.getBleu() - entier;
	if (sou <= 255)
		couleurTemp.setBleu(sou);
	else
		couleurTemp.setBleu(255);

	if (couleur.getNom())
	{
		tailleBuff = strlen(couleur.getNom() + 8 + 1 + 3);
		buff = new char[tailleBuff];
		sprintf(buff, "%s clair(%d)", couleur.getNom(), couleur.getLuminance() - couleurTemp.getLuminance());
		couleurTemp.setNom(buff);
	}
	else
		couleurTemp.setNom(NULL);

	if (buff)
		delete buff;

	return couleurTemp;
}

Couleur operator- (const Couleur& couleur, int entier)
{
	Couleur couleurTemp;
	int sou;
	int tailleBuff;
	char* buff = NULL;

	sou = couleur.getRouge() - entier;
	if (sou <= 255)
		couleurTemp.setRouge(sou);
	else
		couleurTemp.setRouge(255);

	sou = couleur.getVert() - entier;
	if (sou <= 255)
		couleurTemp.setVert(sou);
	else
		couleurTemp.setVert(255);

	sou = couleur.getBleu() - entier;
	if (sou <= 255)
		couleurTemp.setBleu(sou);
	else
		couleurTemp.setBleu(255);

	if (couleur.getNom())
	{
		tailleBuff = strlen(couleur.getNom() + 8 + 1 + 3);
		buff = new char[tailleBuff];
		sprintf(buff, "%s clair(%d)", couleur.getNom(), couleur.getLuminance() - couleurTemp.getLuminance());
		couleurTemp.setNom(buff);
	}
	else
		couleurTemp.setNom(NULL);

	if (buff)
		delete buff;

	return couleurTemp;
}

bool Couleur::operator> (const Couleur& couleur) const
{
	if (getLuminance() > couleur.getLuminance())
		return true;
	else
		return false;
}

bool Couleur::operator< (const Couleur& couleur) const
{
	if (getLuminance() < couleur.getLuminance())
		return true;
	else
		return false;
}

bool Couleur::operator== (const Couleur& couleur) const
{
	if (getLuminance() == couleur.getLuminance())
		return true;
	else
		return false;
}

ostream& operator<< (ostream& stream, const Couleur& couleur)
{
	if (couleur.getNom())
		stream << couleur.getRouge() << ", " << couleur.getVert() << ", " << couleur.getBleu() << " (" << couleur.getNom() << ")";
	else
		stream << couleur.getRouge() << ", " << couleur.getVert() << ", " << couleur.getBleu() << " (Pas de nom)";
	return stream;
}

istream& operator >> (istream& stream, Couleur& couleur)
{
	char buff[200];
	int rouge, vert, bleu;
	int i, j;

	int debut;
	int fin = 0;
	int etape = 1;

	stream.getline(&buff[0], 200, '\n');

	while (etape < 5)
	{
		debut = fin;
		if (etape < 4)
		{
			while (buff[fin] != '\0' && buff[fin] != ' ') { fin++; }

			if (buff[fin] == '\0')
			{
				if (etape == 3)
					etape = 5;
				else
					etape = 6;
			}

			if (buff[fin] == ' ')
				buff[fin] = '\0';
		}

		switch (etape)
		{
		case 1:
			if (!Couleur::estNombre(&buff[debut]))
				etape = 6;
			else
			{
				rouge = atoi(&buff[debut]);
				if (rouge < 0 || rouge > 255)
					etape = 6;
			}
			break;

		case 2:
			if (!Couleur::estNombre(&buff[debut]))
				etape = 6;
			else
			{
				vert = atoi(&buff[debut]);
				if (vert < 0 || vert > 255)
					etape = 6;
			}
			break;

		case 3:
			if (!Couleur::estNombre(&buff[debut]))
				etape = 6;
			else
			{
				bleu = atoi(&buff[debut]);
				if (bleu < 0 || bleu > 255)
					etape = 6;
			}
			break;

		case 4:

			couleur.setRouge(rouge);
			couleur.setVert(vert);
			couleur.setBleu(bleu);

			if (strlen(&buff[debut]) != 0)
				couleur.setNom(&buff[debut]);
			else
				couleur.setNom(NULL);
			break;

		case 5:

			if (!Couleur::estNombre(&buff[debut]))
				break;
			else
			{
				bleu = atoi(&buff[debut]);
				if (bleu < 0 || bleu > 255)
					break;
			}

			couleur.setRouge(rouge);
			couleur.setVert(vert);
			couleur.setBleu(bleu);
			couleur.setNom(NULL);
			break;
		}

		fin++;
		etape++;
	}

	return stream;
}

//Methode private
void Couleur::testCouleur(int rouge, int vert, int bleu)
{
	bool rougeValide = true;
	bool vertValide = true;
	bool bleuValide = true;

	if (rouge > 255 || rouge < 0)
		rougeValide = false;

	if (vert > 255 || vert < 0)
		vertValide = false;

	if (bleu > 255 || bleu < 0)
		bleuValide = false;

	if (!rougeValide || !vertValide || !bleuValide)
		throw(InvalidColorException("Creation Couleur Impossible !", rougeValide, vertValide, bleuValide));
}

bool Couleur::estNombre(const char * chaineCaract)
{
	int i;

	for (i = 0; chaineCaract[i] != '\0' && isdigit(chaineCaract[i]); i++);

	if (chaineCaract[i] != '\0' || i == 0)
		return false;
	return true;
}
