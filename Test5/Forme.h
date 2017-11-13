#ifndef FORME_H
#define FORME_H
#include "Couleur.h"
#include "Point.h"

class Forme
{
protected:
	char* _id;
	Point _position;
	const Couleur* _couleur;
	int _profondeur;
	static int _compteur;
	char* _infos;

public:
	//Constructeur
	Forme();
	Forme(const Point& position);
	Forme(const Point& position, const Couleur* couleur, int profondeur);
	Forme(const Forme& forme);

	//Destructeur
	virtual ~Forme();

	//Getteur
	const char* getId() const;
	const Point& getPosition() const;
	const Couleur* getCouleur() const;
	int getProfondeur() const;
	static int getCompteur();
	virtual const char* getInfos() = 0;

	//Setteur
	virtual void setId(const char* id) = 0;
	void setPosition(const Point& position);
	void setCouleur(const Couleur* couleur);
	void setProfondeur(int profondeur);

	//Affiche
	void Affiche() const;
	
	//Methode
	int nbrCaractEntier(int nbr);
};

#endif
