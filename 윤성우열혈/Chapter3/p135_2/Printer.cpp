#include "Printer.h"
#include <cstring>
void Printer::SetString(char get[])
{
	strcpy(str, get);
}
void Printer::ShowString()
{
	cout << str << endl;
}
