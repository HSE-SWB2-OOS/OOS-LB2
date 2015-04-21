/* Uebungen zu OOP, Aufgabe 2.3
Erstersteller: Matthias Geckeler
E-Mail: matthias.geckeler@stud.hs-esslinge.de

Datum: 16.04.2015
Version: 1.0
Zeitaufwand: xh

Aenderungshistorie:
-------------------
Aenderungsgrund  durchgefuehrte Aenderung  Autor  Datum
-------------------------------------------------------
Programmbeschreibung:
Die Header Datei für die Klasse Polygonlinie.
---------------------
*/

#pragma once

#include "PlgElement.hpp"


class Polygonline
{
public:
	Polygonline();
	Polygonline(Point pPos);
	~Polygonline();

	void createNewHead(Point pPos);
	void print();
	Polygonline & addPoint(Point pPos);
	void appendPolygonline(Polygonline & additionalLine);
	void move(double dx, double dy);

	PlgElement & getList();

private:
	PlgElement *endNode;
	PlgElement *head;
	int elementCounter;

};

