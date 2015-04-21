/* Uebungen zu OOP HA, Aufgabe 2.1
Erstersteller: Matthias Geckeler
E-Mail: matthias.geckeler@stud.hs-esslinge.de

Datum: 04.04.2015 - 06.04.2015
Version: 1.0
Zeitaufwand: 3h

Aenderungshistorie:
-------------------
Aenderungsgrund  durchgefuehrte Aenderung  Autor  Datum
-------------------------------------------------------
Programmbeschreibung:
Die Labyrinth Klasse mit allen ausdefienierten Methoden um ein Labyrinth zu verwalten.
---------------------
*/

#include "Position.hpp"
#include "Labyrinth.hpp"
#include <iostream>
#include <fstream>
#include <conio.h> // für _getch()
// Achtung: _getch() ist nicht im Standard und
// daher abhängig vom Compiler
using namespace std;

Labyrinth::Labyrinth(){}

Labyrinth::Labyrinth(int zeilen, int spalten, int anzGeister)
{
	labZeilen = zeilen;
	labSpalten = spalten;
	labAnzGeister = anzGeister;
	muenzen = 0;

	initialisieren();
}
// Labyrinth mit # füllen
void Labyrinth::initialisieren() {
	/* HIER */
	int i, j;

	for (i = 0; i < kZeilen; i++)
	{
		lab[i][0] = MAUER;

		for (j = 1; j < kSpalten + 2; j++)
		{
			if (j == (kSpalten))
				lab[i][j] = NL;
			else if (j == (kSpalten + 1))
				lab[i][j] = EOS;
			else
				lab[i][j] = MAUER;
		}
	}

}

// Labyrinth auf dem Bildschirm ausgeben
void Labyrinth::drucken() {
	// Console frei machen
	system("cls");
	// Labyrinth ausgeben
	/* HIER */

	int i, j;

	for (i = 0; i < kZeilen; i++)
	{

		for (j = 0; j < kSpalten - 1; j++)
		{
			cout << lab[i][j];
		}
	}
}

// Durch Herumlaufen werden Wege im Labyrinth erzeugt
// ASCII-Wert der Tasten: oben 72, links 75, rechts 77, unten 80
void Labyrinth::erzeugen() {
	char c = 'x';
	int posx = kSpalten / 2;
	int posy = kZeilen / 2;
	lab[posy][posx] = ICH;
	drucken();
	while (c != 'q') {
		drucken();
		cout << "\nLaufen mit Pfeiltasten. Beenden mit q." << endl;
		lab[posy][posx] = WEG;
		c = _getch();
		switch (int(c)) {
			// oben
		case 72: posy = max(1, posy - 1); break;
			// links
		case 75: posx = max(1, posx - 1); break;
			// rechts
		case 77: posx = min(kSpalten - 2, posx + 1); break;
			// unten
		case 80: posy = min(kZeilen - 2, posy + 1); break;
			// q = quit
		case 113: break;
		}
		lab[posy][posx] = ICH;
	}
}
// Hilfsfunktion max
int Labyrinth::max(int x, int y) {
	return (x <= y) ? y : x;
}
// Hilfsfunktion min
int Labyrinth::min(int x, int y) {
	return (x <= y) ? x : y;
}

// Im Labyrinth werden auf den Wegen (' ')  Münzen(':') verteilt.
void Labyrinth::legeMuenzen() {
	int i, j;
	char labTeil;

	for (i = 0; i < kZeilen; i++)
	{
		labTeil = lab[i][0];
		if (labTeil == ' '){
			lab[i][0] = ':';
			muenzen++;
		}

		for (j = 0; j < kSpalten + 2; j++)
		{
			labTeil = lab[i][j];
			if (labTeil == ' '){
				lab[i][j] = ':';
				muenzen++;
			}
		}
	}
}

// Fragt die Anzahl an Zeilen ab.
int Labyrinth::getZeilen(){
	return labZeilen;
}

// Fragt die Anzahl an Spalten ab.
int Labyrinth::getSpalten(){
	return labSpalten;
}

// Fargt die Anzahl an Geistern ab.
int Labyrinth::getAnzGeister(){
	return labAnzGeister;
}

// Fragt die Anzahl an Münzen ab die gelegt wurden.
int Labyrinth::getMuenzen(){
	return muenzen;
}

// Zeichnet ein Zeichen an die angebene Position.
void Labyrinth::zeichneChar(char c, Position pos)
{
	lab[pos.posx][pos.posy] = c;
	cout << lab[pos.posx][pos.posy];
}

// Ersetzt an der Position alt das Zeichen durch ' ' 
// und da der Posiotion neu das Zeichen durch das angegebene.
void Labyrinth::zeichneChar(char c, Position posalt, Position posneu)
{
	lab[posalt.posx][posalt.posy] = ' ';
	zeichneChar(c, posneu);
}

// Fragt das Zachen an der angegeben Position ab.
char Labyrinth::getZeichenAnPos(Position pos)
{
	return lab[pos.posx][pos.posy];
}

// Überprüft ob an der angeben Position sich eine Münze befindet.
bool Labyrinth::istMuenzeAnPos(Position pos)
{
	if (lab[pos.posx][pos.posy] == ':')
		return true;
	else
		return false;
}

#pragma region InExport
// Labyrinth als Textdatei speichern
void Labyrinth::exportDatei(char * dateiname) {
	ofstream datei(dateiname);
	if (!datei) {
		cerr << "Kann Datei nicht oeffnen" << endl;
	}
	for (int i = 0; i < kZeilen; i++) {
		datei << lab[i];
	}
	datei.close();
}
// Labyrinth als Textdatei einlesen
void Labyrinth::importDatei(char * dateiname) {
	ifstream datei(dateiname);
	if (!datei) {
		cerr << "Kann Datei nicht oeffnen" << endl;
	}
	for (int i = 0; i < kZeilen; i++) {
		datei.getline(lab[i], kSpalten + 2);
		lab[i][kSpalten] = '\n';
		lab[i][kSpalten + 1] = '\0';
	}
	datei.close();
}
#pragma endregion 
