/* Uebungen zu OOP, Aufgabe 2.2
Erstersteller: Matthias Geckeler
E-Mail: matthias.geckeler@stud.hs-esslinge.de

Datum: 12.04.2015
Version: 1.0
Zeitaufwand: 1h

Aenderungshistorie:
-------------------
Aenderungsgrund  durchgefuehrte Aenderung  Autor  Datum
-------------------------------------------------------
Programmbeschreibung:
Klasse Fifo die einen First-In-First-Out Speicher darstellt.
---------------------
*/

#include "Fifo.hpp"

// Default Konstuktor
Fifo::Fifo()
{
}

// Konstruktor
Fifo::Fifo(int spiecherPlatz = 20)
{
	this->ptr = new char[spiecherPlatz+1];

	// ptr wird aus eien Standart wert gesetzt.
	for (int i = 0; i < spiecherPlatz+1; i++)
	{
		ptr[i] = '\0';
	}

	this->maxSize = spiecherPlatz;
	this->number = 0;
	this->rPos = 0;
	this->wPos = 0;
}

// Destruktor
Fifo::~Fifo()
{
	delete[] this->ptr;
}

// Abfrage der aktuellen Schreibposition.
int Fifo::getWPos()
{
	return this->wPos;
}

// Abfrage der aktuellen Leseposition.
int Fifo::getRPos()
{
	return this->rPos;
}

// Abfrage über den Maximalen Speicherplatz in der FiFo.
int Fifo::getMaxSize()
{
	return this->maxSize;
}

// Es wird überprüft ob de FiFo leer ist.
bool Fifo::isEmpty()
{
	bool result = false;

	if (this->number == 0)
		result = true;
	
	return result;
}

// Es wird überprüft ob die FiFo voll ist.
bool Fifo::isFull()
{
	bool result = false;

	if (this->number == this->maxSize)
		result = true;

	return result;
}

// Es wird an der nächsten freien Stelle ein Char in die Fifo geschreibe.
// Wenn Platz da war wird der Index zurückgegeben, wenn nicht -1.
int Fifo::push(char character)
{
	int result;

	if (isFull())
		result = -1;
	else
	{
		this->ptr[getWPos()] = character;
		result = this->wPos;
		this->number++;
		this->wPos++;

		if (this->wPos > this->maxSize-1)
			this->wPos = 0;
	}
	
	return result;
}

// Es wird das nächste Char aus der FiFo ausgelesen.
// Wenn die FiFo leer ist wird '\0' zurückgegeben.
char Fifo::pop()
{
	char result;

	if (isEmpty())
		result = '\0';
	else
	{
		result = ptr[getRPos()];
		ptr[getRPos()] = '\0';
		this->number--;
		this->rPos++;

		if (this->rPos > this->maxSize-1)
			this->rPos = 0;
	}

	return result;
}