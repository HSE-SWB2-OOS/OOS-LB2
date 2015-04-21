/* Uebungen zu OOP, Aufgabe 2.1
Erstersteller: Matthias Geckeler
E-Mail: matthias.geckeler@stud.hs-esslinge.de

Datum: 04.12.2015
Version: 1.0
Zeitaufwand: 1h

Aenderungshistorie:
-------------------
Aenderungsgrund  durchgefuehrte Aenderung  Autor  Datum
-------------------------------------------------------
Programmbeschreibung:
Klasse Spieler die den Spieler und die Geister im PacMan Spiel verwaltet
---------------------
*/

#include "Spieler.hpp"
#include <stdlib.h>

// Dafault Konstruktor
Spieler::Spieler()
{
}

// Konvertierkonstruktor c-String
Spieler::Spieler(char *String)
{

}

// Konvertierkonstruktor MyString
Spieler::Spieler(MyString String)
{

}

// Destruktor
Spieler::~Spieler()
{
}

// Spiechert die Aktuelle Position des Spielers
void Spieler::setPos(Position & aktuellePos)
{
	this->pos = aktuellePos;
}

// Git das Struct in dem sich die Aktuelle Position befindet zurück.
Position Spieler::getPos()
{
	return this->pos;
}

// Setzt die laufrichtung des Spielers
void Spieler::setRichtung(Richtung r)
{
	this->pos.r = r;
}

// Gibt die Anzahl an gesammelten Münzen
int Spieler::getMuenzen()
{
	return this->muenzen;
}

// Erhöht den Wert der gesammelten Münzen um 1.
void Spieler::plusMuenze()
{
	this->muenzen++;
}

Spieler & Spieler::schritt(Labyrinth& Lab)
{
	pos.schritt(Lab);
}

void Spieler::orientieren(Labyrinth & Lab)
{
	Position postmp = pos;
	// Eine von 4 Richtungen auswählen
	int rint = rand() % 4;
	postmp.r = Richtung(rint);
	while ((lab.getZeichenAnPos(postmp)) == MAUER) {
		rint = rand() % 4;
		postmp.r = Richtung(rint);
	}
	pos.r = Richtung(rint);
}