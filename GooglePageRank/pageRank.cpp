

#include <iostream>
#include "pageRank.h"
int main()
{
	getMatrix m;
	sMatrix t{ m };
	t.printMatrix();
	t.getStoiMatrix();
	std::cout << "Main method ran sto completion" << std::endl;
	system("pause");
	return 0;
}

