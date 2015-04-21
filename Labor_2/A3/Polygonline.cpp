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
Die Klasse Polygonline die eien Linienzug mit einer verkettenten Liste darstellt.
---------------------
*/

#include "Polygonline.hpp" 

// Default Konstruktor
Polygonline::Polygonline()
{
}

Polygonline::Polygonline(Point pPos)
{
	createNewHead(pPos);
}

// Destruktor
Polygonline::~Polygonline()
{

	if (head != nullptr)
	{
		do
		{
			endNode = head->next;
			delete head;
			head = endNode;
		} while (endNode != nullptr);

		delete endNode;
	}
}

void Polygonline::createNewHead(Point pPos)
{
	endNode = new PlgElement();
	endNode->point = pPos;
	endNode->next = nullptr;
	this->elementCounter++;

	head = new PlgElement();
	head = endNode;
}

// Ausgabe der Linie
void Polygonline::print()
{
	PlgElement *temp = head;
	cout << "|";

	
	if (this->elementCounter > 0)
	{
		do
		{
			cout << "(" << temp->point.getX() << "," << temp->point.getY() << ")" ;
			temp = temp->next;

			if (this->elementCounter > 1 && temp != nullptr)
				cout << "-";
					
		} while (temp != nullptr);
	}
	cout << "|" << endl;
}

// Diese Methode fügt einen neuen Punkt zu Linie hinzu.
Polygonline & Polygonline::addPoint(Point pPos)
{
	PlgElement *temp = new PlgElement;
	temp->point = pPos;
	temp->next = nullptr;

	if (this->elementCounter == 0)
		createNewHead(pPos);
	else
	{
		endNode->next = temp;
		endNode = endNode->next;
		this->elementCounter++;
	}
	
	return *this;
}

// Diese Methode hängt die übergebene Linie an die bestehende Linie hinten an.
void Polygonline::appendPolygonline(Polygonline & additionalLine)
{
	PlgElement *temp = additionalLine.head;

	do
	{
		addPoint(temp->point);
		temp = temp->next;
	} while (temp != nullptr);
		
}

// Diese Methode verschiebt die Linie um den angegebenen offset.
void Polygonline::move(double dx, double dy)
{
	PlgElement *temp = head;

	do
	{
		temp->point.move(dx,dy);
		temp = temp->next;
	} while (temp != nullptr);
}

PlgElement & Polygonline:: getList()
{
	return *this->endNode;
}