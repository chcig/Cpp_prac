#pragma once
#include<string>
#include"../../../Algorithm/ExpresstionNotation.h"

class eCalculator
{
private:
	std::string strEquation;

public:
	// 후위표기법 <계산>
	int CalcReversePolishNotation(std::string strExp);
};