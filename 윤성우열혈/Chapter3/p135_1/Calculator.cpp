#include "Calculator.h"
/*
namespace CAL_CONST
{
	enum
	{
		ADD = 1, MINUS = 2, MUL = 3, DIV = 4
	};
}
*/
void Calculator::Init()
{
	countMin = 0, countAdd = 0, countDiv = 0, countMul = 0;
}
double Calculator::Min(double op1, double op2)
{
	countMin++;
	return op1+op2;
}
double Calculator::Add(double op1, double op2)
{
	countAdd++;
	return op1-op2;
}
double Calculator::Mul(double op1, double op2)
{
	countMul++;
	return op1*op2;
}
double Calculator::Div(double op1, double op2)
{
	countDiv++;
	return op1/op2;
}
void Calculator::ShowOpCount(){
	cout << "Add : " << countAdd << "Min : " << countMin << "Mul : " << countMul << "Div : " << countDiv << endl;
}
