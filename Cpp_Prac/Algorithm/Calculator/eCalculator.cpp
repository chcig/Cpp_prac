#include "eCalculator.h"
#include "../../DataStructure/Stack/eStack.h"

inline int eCalculator::GetOperatorPriority(char op)
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

int eCalculator::CompareOperatorPriority(char op1, char op2)
{
	int Op1Priority = GetOperatorPriority(op1);
	int Op2Priority = GetOperatorPriority(op2);

	if (Op1Priority > Op2Priority)
		return 1;
	else if (Op1Priority < Op2Priority)
		return -1;

	return 0;
}

std::string eCalculator::ConvertToReversePolishNotation(std::string strExp)
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

int eCalculator::CalcReversePolishNotation(std::string strExp)
{
	eStack<int> stack;
	std::string RetPostNotation = ConvertToReversePolishNotation(strExp);

	char op1, op2;
	for (int i = 0; i < RetPostNotation.size(); i++)
	{
		if (isdigit(RetPostNotation[i]))
			stack.push(RetPostNotation[i] - '0');
		else
		{
			op2 = stack.pop();
			op1 = stack.pop();
			switch (RetPostNotation[i])
			{
			case MUL_CHAR:
				stack.push(op1 * op2);
				break;
			case DIV_CHAR:
				stack.push(op1 / op2);
				break;
			case ADD_CHAR:
				stack.push(op1 + op2);
				break;
			case SUB_CHAR:
				stack.push(op1 - op2);
				break;
			}
		}
	}

	return stack.pop();
}
