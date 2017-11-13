#ifndef COULEUR_H
#define COULEUR_H
#include <iostream>

using namespace std;

class Couleur
{
	//Operator Friend
	friend Couleur operator+ (int entier, const Couleur& couleur);
	friend Couleur operator+ (const Couleur& couleur, int entier);
	friend Couleur operator- (int entier, const Couleur& couleur);
	friend Couleur operator- (const Couleur& couleur, int entier);
	friend ostream& operator<< (ostream& stream, const Couleur& couleur);
	friend istream& operator>> (istream& stream, Couleur& couleur);

private:
	int _rouge;
	int _vert;
	int _bleu;
	char* _nom;
	static int _compteur;

public:
	static const Couleur ROUGE;
	static const Couleur VERT;
	static const Couleur BLEU;

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
	static int getCompteur();
	int getLuminance() const;

	//Affiche
	void Affiche() const;

	//Opérateur
	Couleur& operator= (const Couleur& couleur);
	Couleur operator+ (const Couleur& couleur) const;
	bool operator> (const Couleur& couleur) const;
	bool operator< (const Couleur& couleur) const;
	bool operator== (const Couleur& couleur) const;
	Couleur& operator++ ();
	Couleur& operator-- ();
	Couleur operator++ (int);
	Couleur operator-- (int);
	
	//Methode
	static bool estNombre(const char* chaineCaract);
};

#endif

