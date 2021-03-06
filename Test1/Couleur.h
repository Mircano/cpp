#ifndef COULEUR_H
#define COULEUR_H
#include <iostream>

using namespace std;

class Couleur
{
private:
	int _rouge;
	int _vert;
	int _bleu;
	char* _nom;

public:
	//Constructeurs
	Couleur();
	Couleur(int rouge, int vert, int bleu,const char* nom);
	Couleur(int rouge, int vert, int bleu);
	Couleur(const Couleur& couleur);

	//Destructeur
	~Couleur();

	//Setteur
	void setRouge(int rouge);
	void setVert(int vert);
	void setBleu(int bleu);
	void setNom(const char* nom);

	//Getteur
	int getRouge() const;
	int getVert() const;
	int getBleu() const;
	const char* getNom() const;

	//Affiche
	void Affiche() const;
};

#endif

