#pragma once
#include "../Default/Standard.h"
#include "stdio.h"
#include "stdarg.h"

using namespace ESTD;

class EString
{
private:
	char* strData;
	int nDataLength;

public:
	EString()
	{
		this->nDataLength = 0;
		this->strData = nullptr;
	}

	EString(const char* str)
	{
		this->nDataLength = Estrlen(str);
		this->strData = new char[Estrlen(str)+1];
		Estrcpy(strData, Estrlen(str), str);
	}

	virtual ~EString()
	{
		if (strData)
			delete[] strData;
		strData = nullptr;
	}

	EString& operator=(const EString& str);
	EString& operator+(const EString& str);
	EString& operator+=(const EString& str);
	bool operator==(const EString& str);

	int Getlength() { return nDataLength; }

	bool Find(const char* str);
	void Format(const char* strformat, ...);
	void Trim(int nStartPos, int nCnt = 0);

};
