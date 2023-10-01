#pragma once
#include<string>

#define STRT_CHAR '('
#define END_CHAR  ')'

#define MUL_CHAR '*'
#define DIV_CHAR '/'
#define ADD_CHAR '+'
#define SUB_CHAR '-'
#define EQU_CHAR '='

class eCalculator
{
private:
	std::string strEquation;
	inline int GetOperatorPriority(char op);
	int CompareOperatorPriority(char op1, char op2);

public:
	// 후위표기법 <변환>
	std::string ConvertToReversePolishNotation(std::string strExp);
	// 후위표기법 <계산>
	int CalcReversePolishNotation(std::string strExp);
};

