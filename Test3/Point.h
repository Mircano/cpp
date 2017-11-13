#ifndef POINT_H
#define POINT_H
#include <iostream>

using namespace std;

class Point
{
	//Operateur
	friend ostream& operator<< (ostream& stream,const Point& point);

private:
	int _x;
	int _y;
	static int _compteur;

public:

	//Constructeur
	Point();
	Point(int x, int y);
	Point(const Point& point);

	//Destructeur
	~Point();

	//Getteur
	int getX() const;
	int getY() const;
	static int getCompteur();

	//Setteur
	void setX(int x);
	void setY(int y);

	//Affiche
	void Affiche() const;
};

#endif
