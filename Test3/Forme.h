#ifndef FORME_H
#define FORME_H
#include "Couleur.h"
#include "Point.h"

class Forme
{
private:
	char* _id;
	Point _position;
	const Couleur* _couleur;
	int _profondeur;
	static int _compteur;

public:
	//Constructeur
	Forme();
	Forme(const char* id, const Point& position);
	Forme(const char* id, const Point& position, const Couleur* couleur, int profondeur);
	Forme(const Forme& forme);

	//Destructeur
	~Forme();

	//Getteur
	const char* getId() const;
	const Point& getPosition() const;
	const Couleur* getCouleur() const;
	int getProfondeur() const;
	static int getCompteur();

	//Setteur
	void setId(const char* id);
	void setPosition(const Point& position);
	void setCouleur(const Couleur* couleur);
	void setProfondeur(int profondeur);

	//Affiche
	void Affiche() const;
};

#endif
