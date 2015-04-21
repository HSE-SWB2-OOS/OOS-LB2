/* Uebungen zu OOP, Aufgabe 2.3
Erstersteller: Matthias Geckeler
E-Mail: matthias.geckeler@stud.hs-esslinge.de

Datum: 15.04.2015
Version: 1.1
Zeitaufwand: 0,25h

Aenderungshistorie:
-------------------
Aenderungsgrund | durchgefuehrte Aenderung | Autor | Datum
Main von Aufgabe 3.2 fordert weiteren Konstruktor |	Parameter behafteter Konstruktor angelegt | Geckeler | 16.04.15
-------------------------------------------------------
Programmbeschreibung:
Die Header Datei für die Klasse Point die das geometrische Objekt Punkt darstellt.
---------------------
*/

#pragma once

#include <iostream>
using namespace std;

class Point
{
public:
	Point();
	Point(double posX, double posY);
	~Point();

	void setX(double posX);
	double getX();
	void setY(double posY);
	double getY();

	void move(double dx, double dy);
	void print(bool newLine = true);

private:
	double x;
	double y;
};

