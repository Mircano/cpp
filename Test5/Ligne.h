#ifndef LIGNE_H
#define LIGNE_H
#include "Forme.h"

class Ligne : public Forme
{
	//Operateur
	friend ostream& operator<< (ostream& stream, Ligne& ligne);

private:
	Point _extremite;

public:
	//Constructeur
	Ligne();
	Ligne(const char* id, const Point& position);
	Ligne(const char* id, const Point& position, const Couleur* couleur, int profondeur);
	Ligne(const char* id, const Point& position, const Point& extremite);
	Ligne(const char* id, const Point& position, const Point& extremite, const Couleur* couleur, int profondeur);
	Ligne(const Ligne& ligne);

	//Destructeur
	~Ligne();

	//Setteur
	void setId(const char* id);

	//Getteur
	const char* getInfos();
	const Point& getExtremite() const;

	//Setteur
	void setExtremite(const Point& extremite);
};

#endif
