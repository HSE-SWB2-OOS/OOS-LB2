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
Main um die Fifo-Klasse zu testen.
---------------------
*/

#include <iostream>
#include "Fifo.hpp"

using namespace std;

int main()
{
	Fifo FiFo(5);

	cout << "Size of Fifo: " << FiFo.getMaxSize() << endl;

	cout << "is Fifo empty: " << FiFo.isEmpty() << endl;
	cout << "is Fifo Full: " << FiFo.isFull() << endl<< endl;
	cout << "Fill with ""Hallo" << endl;

	cout << "push Char at index: " << FiFo.push('H')+1 << endl;
	cout << "push Char at index: " << FiFo.push('a')+1 << endl;
	cout << "push Char at index: " << FiFo.push('l')+1 << endl;
	cout << "push Char at index: " << FiFo.push('l')+1 << endl;
	cout << "push Char at index: " << FiFo.push('o')+1 << endl << endl;

	cout << "is Fifo empty: " << FiFo.isEmpty() << endl;
	cout << "is Fifo Full: " << FiFo.isFull() << endl << endl;

	cout << "write another Character." << endl;
	cout << "write Char at index: " << FiFo.push('H') << endl;

	for (int i = 0; i < 5; i++)
	{
		cout << "pop Char: " << FiFo.pop() << endl;
	}

	cout << "is Fifo empty: " << FiFo.isEmpty() << endl;
	cout << "is Fifo Full: " << FiFo.isFull() << endl << endl;

	cout << "Fill with ""Hallo" << endl;
	cout << "push Char at index: " << FiFo.push('H')+1 << endl;
	cout << "push Char at index: " << FiFo.push('a')+1 << endl;
	cout << "push Char at index: " << FiFo.push('l')+1 << endl;
	cout << "push Char at index: " << FiFo.push('l')+1 << endl;
	cout << "push Char at index: " << FiFo.push('o')+1 << endl << endl;

	cout << "pop Char: " << FiFo.pop() << endl;
	cout << "pop Char: " << FiFo.pop() << endl;
	cout << "pop Char: " << FiFo.pop() << endl;
	cout << "write Char at index: " << FiFo.push('Y') << endl<< endl;

	cout << "is Fifo empty: " << FiFo.isEmpty() << endl;
	cout << "is Fifo Full: " << FiFo.isFull() << endl << endl;

	for (int i = 0; i < 5; i++)
	{
		cout << "pop Char: " << FiFo.pop() << endl;
	}

	cin.get();
	return 0;
}