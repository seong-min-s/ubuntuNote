#include <iostream>
using namespace std;

class Calculator{
	private :
		int countAdd, countMin, countMul, countDiv;
	public:
		void Init();
		double Add(double op1, double op2);
		double Min(double op1, double op2);
		double Mul(double op1, double op2);
		double Div(double op1, double op2);
		void ShowOpCount();
};
