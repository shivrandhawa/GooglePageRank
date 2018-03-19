

#include <iostream>
#include "pageRank.h"
int main()
{
	getMatrix m;
	sMatrix t{ m };
	t.getStoiMatrix();
	t.build_transMatrix();
	t.calc_pagerank();
	cout << "Main method ran to completion" << std::endl;
	system("pause");
	return 0;
}