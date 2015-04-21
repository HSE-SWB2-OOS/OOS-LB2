/* Uebungen zu OOP, Aufgabe 2.3
Erstersteller: Matthias Geckeler
E-Mail: matthias.geckeler@stud.hs-esslinge.de

Datum: 15.04.2015
Version: 1.0
Zeitaufwand: 0,25h

Aenderungshistorie:
-------------------
Aenderungsgrund  durchgefuehrte Aenderung  Autor  Datum
-------------------------------------------------------
Programmbeschreibung:
Die Header Datei für die Klasse Circle die das geometrische Objekt für Kreis darstellt.
---------------------
*/

#pragma once

#include "Ponit.hpp"

class Circle
{
public:
	Circle();
	Circle(Point pos);
	~Circle();

	void setCentre(Point pos);
	Point getCentre();
	void setRadius(double r);
	double getRadius();

	void move(double dx, double dy);
	void print(bool newLine = true);

private:
	Point centre;
	double radius;
	

};
