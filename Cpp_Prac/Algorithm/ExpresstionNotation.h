#pragma once
#include <string>
#include "../DataStructure/Stack/eStack.h"

#define STRT_CHAR '('
#define END_CHAR  ')'

#define MUL_CHAR '*'
#define DIV_CHAR '/'
#define ADD_CHAR '+'
#define SUB_CHAR '-'
#define EQU_CHAR '='

// 연산자 우선순위 부여
inline int GetOperatorPriority(char op)
{
	switch (op)
	{
	case MUL_CHAR:	case DIV_CHAR:
		return 5;
	case ADD_CHAR:	case SUB_CHAR:
		return 3;
	case STRT_CHAR:
		return 1;
	}
	return -1;
}

// 연산자 우선순위 선정
inline int CompareOperatorPriority(char op1, char op2)
{
	int Op1Priority = GetOperatorPriority(op1);
	int Op2Priority = GetOperatorPriority(op2);

	if (Op1Priority > Op2Priority)
		return 1;
	else if (Op1Priority < Op2Priority)
		return -1;

	return 0;
}

// 후위표기법 <변환>
inline std::string ConvertToReversePolishNotation(std::string strExp)
{
	// Operator Buffer
	eStack<char> stack;
	std::string RetPostNotation;

	char popItem;
	for (int i = 0; i < strExp.size(); i++)
	{
		if (isdigit(strExp[i]))
			RetPostNotation.push_back(strExp[i]);
		else
		{
			switch (strExp[i])
			{
			case STRT_CHAR:
				stack.push(strExp[i]);
				break;
			case END_CHAR:
				while (stack.Length && stack.peek() != STRT_CHAR)
				{
					popItem = stack.pop();
					RetPostNotation.push_back(popItem);
				}
				stack.pop();
				break;
			case MUL_CHAR:	case DIV_CHAR:
			case ADD_CHAR:	case SUB_CHAR:
				while (stack.Length && CompareOperatorPriority(stack.peek(), strExp[i]) >= 0)
					RetPostNotation.push_back(stack.pop());
				stack.push(strExp[i]);
				break;
			}
		}
	}

	while (stack.Length)
		RetPostNotation.push_back(stack.pop());

	return RetPostNotation;
}