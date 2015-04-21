/* Uebungen zu OOP, Aufgabe 2.1
Erstersteller: Matthias Geckeler
E-Mail: matthias.geckeler@stud.hs-esslinge.de

Datum: 12.04.2015
Version: 1.0
Zeitaufwand: 0,5h

Aenderungshistorie:
-------------------
Aenderungsgrund  durchgefuehrte Aenderung  Autor  Datum
-------------------------------------------------------
Programmbeschreibung:
Header Datei für Spieler.cpp
---------------------
*/

#include <cstring>
#include "MyString.hpp"
#include "Labyrinth.hpp"
#include "Position.hpp"

const int kAnzGeister = 3;

class Spieler
{
public:
	// Konstruktoren
	Spieler();
	// Konvertierkonstruktor
	Spieler(MyString String);
	Spieler(char *String);

	// Destruktor
	~Spieler();

	MyString name;
	Labyrinth lab;

	Position pos;
	Position getPos();
	void setPos(Position & aktuellePos);
	void setRichtung(Richtung r);

	int getMuenzen();
	void plusMuenze();

	Spieler & schritt(Labyrinth& Lab);

	void orientieren(Labyrinth& lab);

private:
	int muenzen;
};

