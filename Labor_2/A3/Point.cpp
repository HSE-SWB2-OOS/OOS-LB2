/* Uebungen zu OOP, Aufgabe 2.3
Erstersteller: Matthias Geckeler
E-Mail: matthias.geckeler@stud.hs-esslinge.de

Datum: 15.04.2015
Version: 1.1
Zeitaufwand: 0,5h

Aenderungshistorie:
-------------------
Aenderungsgrund | durchgefuehrte Aenderung | Autor | Datum
Main von Aufgabe 3.2 fordert weiteren Konstruktor |	Parameter behafteter Konstruktor angelegt | Geckeler | 16.04.15
-------------------------------------------------------
Programmbeschreibung:
Die Klasse Point die das geometrische Objekt Punkt darstellt
---------------------
*/

#include "Ponit.hpp"

// Standart Konstruktor
Point::Point() :x(0), y(0)
{
}

Point::Point(double posX, double posY) : x(posX), y(posY)
{
}

// Destruktor
Point::~Point()
{
}

// Methode um die X-Koordinade vom Punkt zu setzten.
void Point::setX(double posX)
{
	this->x = posX;
}

// // Methode um die X-Koordinade vom Punkt abzufragen.
double Point::getX()
{
	return this->x;
}

// Methode um die Y-Koordinade vom Punkt zu setzten.
void Point::setY(double posY)
{
	this->y = posY;
}

// Methode um die Y-Koordinade vom Punkt abzufragen.
double Point::getY()
{
	return this->y;
}

// Methode um den Punkt an die neuen Koordinaten zu verschieben.
// Die neue Koordinaten werden mit den alten addiert.
void Point::move(double dx, double dy)
{
	this->x += dx;
	this->y += dy;
}

// Methode um die Koordinaten des Punktes auszugeben.
void Point::print(bool newLine)
{
	if (newLine== true)
		cout << "(" << this->x << ", " << this->y << ")"<< endl;
	else
		cout << "(" << this->x << ", " << this->y << ")";
}