/* Uebungen zu OOP, Aufgabe 2.2
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
Header Datei für Fifo.cpp
---------------------
*/

class Fifo
{
public:
	Fifo();
	Fifo(int spiecherPlatz);
	~Fifo();

	int getWPos();
	int getRPos();
	int getMaxSize();

	bool isEmpty();
	bool isFull();

	int push(char character);
	char pop();

private:
	int maxSize;
	int number;

	char *ptr;
	int wPos;
	int rPos;

};