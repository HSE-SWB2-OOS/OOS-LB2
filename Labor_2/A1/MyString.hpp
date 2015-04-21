#include <cstring>
#pragma once;
using namespace std;

class MyString
{
public:
	MyString();
	~MyString();

	// Konvertierkonstruktor Definition
	MyString(char*);

	// Kopierkonstruktor
	MyString(MyString const & str);

	void reserve(unsigned int);
	MyString & append(MyString & str);
	MyString & assign(MyString & str);
	const char * c_str();
	int size();
	int capacity();
	void clear();
	bool empty();
	char & at(unsigned int i);

private:
	unsigned int strSize;
	unsigned int strCapacity;
	char *strPtr;
};

