/*
GooglePageRank.

 This c++ program is a simplified version of Googles Page Rank.  Reads a
 connectivity matrix (1's or 0's seperated by spaces and new lines)
 from a file named "connectivity.txt" and prints the page rank to a file named
 Rank.txt.

Author: Shivbir Randhawa.
Version: 1.0
*/

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