

#include <iostream>
#include "pageRank.h"
int main()
{
	getMatrix m;
	sMatrix t{ m };
	t.getStoiMatrix();
	t.transMatrix();
	t.mult_matrix();
	cout << "Main method ran to completion" << std::endl;
	system("pause");
	return 0;
}