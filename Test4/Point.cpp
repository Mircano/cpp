#include "Point.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

int Point::_compteur = 0;

//Constructeur
Point::Point()
{
	setX(0);
	setY(0);

	_compteur++;
}

Point::Point(int x, int y)
{
	setX(x);
	setY(y);

	_compteur++;
}

Point::Point(const Point& point)
{
	setX(point.getX());
	setY(point.getY());

	_compteur++;
}

//Destructeur
Point::~Point()
{
	_compteur--;
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
	cout << "[POINT : X(" << getX() << "), Y(" << getY() << ")]";
}

//Operateur
ostream& operator<< (ostream& stream, const Point& point)
{
	stream << "[POINT : X(" << point.getX() << "), Y(" << point.getY() << ")]";
	return stream;
}
