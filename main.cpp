#include "OrderedSet.h"
#include <iostream>
#include <Windows.h>
//Objektum elv� alkalmaz�sok fejeszt�se gyakorlat 1. beadand�
//S�ndor Bal�zs - AZA6NL

int main()
{
	//K�perny�be�ll�t�sok
	system("color 1f");
	OAF::OrderedSet* set = new OAF::OrderedSet();
	set->insert(12);
	set->insert(11);
	set->insert(10);
	set->insert(9);
	set->insert(8);
	set->insert(7);
	set->insert(6);
	set->insert(5);
	set->insert(4);
	set->insert(3);
	set->insert(2);
	set->insert(1);
	std::cout << *set << std::endl;
    return 0;
}
