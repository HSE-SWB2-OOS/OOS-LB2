/* Uebungen zu OOP HA, Aufgabe 2.1
Erstersteller: Matthias Geckeler
E-Mail: matthias.geckeler@stud.hs-esslinge.de

Datum: 04.04.2015 - 06.04.2015
Version: 1.0
Zeitaufwand: 2h

Aenderungshistorie:
-------------------
Aenderungsgrund  durchgefuehrte Aenderung  Autor  Datum
-------------------------------------------------------
Programmbeschreibung:
Die Header Datei für die Labyrinth Klasse
---------------------
*/

// Datei Labyrinth.hpp
#pragma once

class Labyrinth
{

	int labZeilen;
	int labSpalten;
	int labAnzGeister;
	int muenzen;
	
public:
	// Konstruktoren
	Labyrinth();
	Labyrinth(int zeilen, int spalten, int anzGeister);
	// Destruktor
	~Labyrinth();

// Zeichen, die im Labyrinth vorkommen können,
	// NL = new line, EOS = end of string
	enum Symbole {
		MAUER = '#',
		WEG = ' ',
		MUENZE = ':',
		NL = '\n',
		EOS = '\0',
		ICH = 'X',
		GEIST = 'G'
	};

	// Größe des Labyrinths
	static const int kZeilen = 11;
	static const int kSpalten = 11;
	
	// Das Labyrinth als char-Array
	// Die vorletzte Spalte speichert ein Zeilenendezeichen \n
	// und die letzte ein \0-Zeichen, damit die Ausgabe leichter wird.
	char lab[kZeilen][kSpalten + 2];

	void initialisieren();
	void erzeugen();
	void drucken();

	void legeMuenzen();
	int getZeilen();
	int getSpalten();
	int getAnzGeister();
	int getMuenzen();

	void zeichneChar(char, struct Position, struct Position);
	void zeichneChar(char, struct Position);
	char getZeichenAnPos(Position);
	bool istMuenzeAnPos(Position);
	int max(int x, int y);
	int min(int x, int y);

	void exportDatei(char *);
	void importDatei(char *);
};

