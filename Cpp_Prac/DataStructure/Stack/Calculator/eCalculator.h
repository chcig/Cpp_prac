#pragma once
#include<string>
#include"../../../Algorithm/ExpresstionNotation.h"

class eCalculator
{
private:
	std::string strEquation;

public:
	// ����ǥ��� <���>
	int CalcReversePolishNotation(std::string strExp);
};