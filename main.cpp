#include "PolynomConsole.h"
#include <iostream>
#include <Windows.h>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>
#include "PolynomConsole.h"
//Objektum elv� alkalmaz�sok fejeszt�se gyakorlat 1. beadand�
//S�ndor Bal�zs - AZA6NL

int main()
{
	//K�perny�be�ll�t�sok
	SetConsoleOutputCP(65001);
	system("color 1f");
	std::cout << "Adj meg egy kifejez�st val�s eggy�tthat�s polinomok k�z�tt:\n" <<
	"(Sz�k�zzel elv�lasztva add meg az egy�tthat�kat foksz�m szerint �vekv� rendben)" <<
	"\n�rtelmezett kommutat�v m�veletek:\n\tPOLINOM+POLINOM\n\tPOLINOM*POLINOM\n\tPOLINOM+VAL�S\n\tPOLINOM*VAL�S" <<
	std::endl;
	PolynomConsole::readExpression();
    return 0;
}
