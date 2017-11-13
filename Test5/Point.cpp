#include "Point.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

int Point::_compteur = 0;

//Constructeur
Point::Point()
{
	//cout << endl << "Point: Debut du constructueur par default" << endl;

	setX(0);
	setY(0);

	_compteur++;

	//cout << endl << "Point: Fin du constructueur par default" << endl;
}

Point::Point(int x, int y)
{
	//cout << endl << "Point: Debut du constructueur d'initialisation" << endl;

	setX(x);
	setY(y);

	_compteur++;

	//cout << endl << "Point: Fin du constructueur d'initialisation" << endl;
}

Point::Point(const Point& point)
{
	//cout << endl << "Point: Debut du constructueur de copie" << endl;

	setX(point.getX());
	setY(point.getY());

	_compteur++;

	//cout << endl << "Point: Fin du constructueur de copie" << endl;
}

//Destructeur
Point::~Point()
{
	//cout << endl << "Point: Debut du destructeur" << endl;

	_compteur--;

	//cout << endl << "Point: Fin du destructeur" << endl;
}

//Getteur
int Point::getX() const
{
	return _x;
}

int Point::getY() const
{
	return _y;
}

int Point::getCompteur()
{
	return _compteur;
}

//Setteur
void Point::setX(int x)
{
	_x = x;
}

void Point::setY(int y)
{
	_y = y;
}

//Affiche
void Point::Affiche() const
{
	cout << endl
		<< "X: " << getX() << endl
		<< "Y: " << getY() << endl;
}

//Operateur
ostream& operator<< (ostream& stream, const Point& point)
{
	stream << "[POINT : X(" << point.getX() << "), Y(" << point.getY() << ")]";
	return stream;
}
