﻿#include <iostream>
#include <string>
#include "DataStructure/Stack/Calculator/eCalculator.h"

int main()
{
    std::string strQ1 = "1+2*3";
    std::string strQ2 = "(1+2)*3";
    std::string strQ3 = "((1-2)+3)*(5-2)";

    std::string ret;
    eCalculator cal;
    ret = cal.ConvertToReversePolishNotation(strQ1);
    std::cout << strQ1 << " 후위표기법 변환 -> " << ret << " = " << cal.CalcReversePolishNotation(strQ1) << std::endl;

    ret = cal.ConvertToReversePolishNotation(strQ2);
    std::cout << strQ2 << " 후위표기법 변환 -> " << ret << " = " << cal.CalcReversePolishNotation(strQ2) << std::endl;

    ret = cal.ConvertToReversePolishNotation(strQ3);
    std::cout << strQ3 << " 후위표기법 변환 -> " << ret << " = " << cal.CalcReversePolishNotation(strQ3) << std::endl;

}