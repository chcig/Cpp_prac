#include "eCalculator.h"
#include "../eStack.h"

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
