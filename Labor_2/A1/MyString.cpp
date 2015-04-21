#include "MyString.hpp"

// Standartkonstruktor
MyString::MyString()
{
	this->strSize = 0;
	this->strCapacity = 0;
	strPtr = new char[1];
	strPtr[0] = '\0';
}

// Konvertierkonstruktor
MyString::MyString(char* str)
{
	strSize = (unsigned int)strlen(str);
	strPtr = new char[strSize + 1];
	//memcpy(strPtr, str, strSize);
	strcpy_s(strPtr, strSize + 1, str);
	strCapacity = strSize;
}

// Kopierkonstruktor
MyString::MyString(MyString const & str)
{
	strSize = str.strSize;
	strPtr = new char[strSize + 1];
	//memcpy(strPtr, str.strPtr, strSize);
	strcpy_s(this->strPtr, str.strSize + 1, str.strPtr);
	strCapacity = strSize;
}

// Destruktor
MyString::~MyString()
{
	delete[] strPtr;
}

void MyString::reserve(unsigned int c)
{
	if (strCapacity < c)
	{
		char *temp = new char[strSize+1];
		strcpy_s(temp, strSize+1, strPtr);

		strCapacity = c;
		delete[] strPtr;
		strPtr = new char[strCapacity+1];
		strcpy_s(strPtr, strSize + 1, temp);
	}
}

MyString & MyString::append(MyString & str)
{
	// String größe überprüfen
	reserve(this->strSize + str.strSize);
	this->strSize = this->strSize + str.strSize;

	strcat_s(this->strPtr, this->strSize+1, str.strPtr);
	return *this;
}

MyString & MyString::assign(MyString & str)
{
	// String größe überprüfen
	//if ((this->strSize + str.strSize) < this->strCapacity)
	reserve(str.strSize);
	this->strSize = str.strSize;
	strcpy_s(this->strPtr, str.strSize+1, str.strPtr);
	return *this;
}

const char* MyString::c_str()
{
	return this->strPtr;
}

int MyString::size()
{
	return strSize;
}

int MyString::capacity()
{
	return strCapacity;
}

void MyString::clear()
{
	//strcpy_s(this->strPtr, 1, '\0');
	this->strPtr[0] = '\0';
	this->strSize = 0;

}

bool MyString::empty()
{
	if (strSize == 0)
		return true;
	else
		return false;
}

char & MyString::at(unsigned int i)
{
	if (i > strSize)
		return strPtr[0];
	else
		return strPtr[i-1];
}