

#include <iostream>
#include "pageRank.h"
int main()
{
	getMatrix m;
	sMatrix t{ m };
	t.printMatrix(m.myVector);
	t.getStoiMatrix();
	cout << "Main method ran to completion" << std::endl;
	system("pause");
	return 0;
}