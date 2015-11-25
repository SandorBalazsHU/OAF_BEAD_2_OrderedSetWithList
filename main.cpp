#include "PolynomConsole.h"
#include <iostream>
#include <Windows.h>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>
#include "PolynomConsole.h"
//Objektum elvû alkalmazások fejesztése gyakorlat 1. beadandó
//Sándor Balázs - AZA6NL

int main()
{
	//Képernyõbeállítások
	SetConsoleOutputCP(65001);
	system("color 1f");
	std::cout << "Adj meg egy kifejezést valós eggyütthatós polinomok között:\n" <<
	"(Szóközzel elválasztva add meg az együtthatókat fokszám szerint övekvõ rendben)" <<
	"\nÉrtelmezett kommutatív mûveletek:\n\tPOLINOM+POLINOM\n\tPOLINOM*POLINOM\n\tPOLINOM+VALÓS\n\tPOLINOM*VALÓS" <<
	std::endl;
	PolynomConsole::readExpression();
    return 0;
}
