#include "EString.h"
#include "../Default/Standard.h"

using namespace ESTD;

EString& EString::operator=(const EString& str)
{
	if (this->strData != nullptr)
	{
		delete[] this->strData;
		this->nDataLength = 0;
	}

	this->strData = new char[str.nDataLength + 1];
	this->nDataLength = str.nDataLength;
	Estrcpy(this->strData, str.nDataLength, str.strData);
	return *this;
}

EString& EString::operator+(const EString& str)
{
	EString* temp = new EString;
	temp->strData = new char[this->nDataLength + str.nDataLength + 1];
	temp->nDataLength = this->nDataLength + str.nDataLength;

	Estrcpy(temp->strData, this->nDataLength ,this->strData);
	Estrcat(temp->strData, str.strData);
	return *temp;
}

EString& EString::operator+=(const EString& str)
{
	EString* temp = new EString;
	temp->strData = new char[this->nDataLength + str.nDataLength + 1];
	temp->nDataLength = this->nDataLength + str.nDataLength;

	Estrcpy(temp->strData, this->nDataLength, this->strData);
	Estrcat(temp->strData, str.strData);
	if (this->strData != nullptr)
	{
		delete[] this->strData;
	}
	
	this->strData = temp->strData;
	this->nDataLength = temp->nDataLength;
	return *this;
}

bool EString::operator==(const EString& str)
{
	return Estrcmp(this->strData, str.strData);
}

bool EString::Find(const char* str)
{
	int i = 0;
	int j = 0;
	while (this->strData[i++] != '\0')
	{
		if (this->strData[i] == str[j])
		{
			for (j = 0; j < Estrlen(str); j++)
				if (this->strData[i + j] == str[j])
					if (j == Estrlen(str)-1) return true;
		}
	}
	return false;
}

void EString::Format(const char* strformat, ...)
{
	if (this->strData != nullptr)
		delete[] this->strData;
	this->nDataLength = 0;
	
	this->strData = new char[1024];
	
	va_list lpStart;
	va_start(lpStart, strformat);
	int size = vsprintf_s(strData, 1024, strformat, lpStart);

	this->nDataLength = size+1;
}

void EString::Trim(const int nStartPos, int nCnt)
{
	if (nCnt == 0)
	{
		char* strbuff = new char[nStartPos];
		for (int i = 0; i < nStartPos; i++)
			strbuff[i] = this->strData[i];
		strbuff[nStartPos] = '\0';

		delete[] this->strData;

		this->strData = strbuff;
		this->nDataLength = nStartPos;
	}
	else
	{

	}
}