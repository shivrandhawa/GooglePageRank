//  Header.h
//  PageRank
//
//  Created by Shiv Randhawa on 2018-03-16.
//  Copyright © 2018 Shiv Randhawa. All rights reserved.
//

#ifndef Header_h

#define Header_h
#include <regex>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

class getMatrix {

public:
	int size = 0;
	vector<vector<float>> myVector;

	getMatrix() {
		string text;
		string textfull;
		string piece;
		ifstream inFile;
		int ch = 0;


		inFile.open("connectivity.txt");
		while (!inFile.eof())
		{
			size++;
			getline(inFile, text);

			textfull.append(text);
		}
		inFile.close();
		cout << "array size: " << size << endl;
		//removing whitespace using regex
		textfull = std::regex_replace(textfull, std::regex("\\s+"), "");
		cout << "compressed text: " + textfull << endl;

		for (int i = 0; i < size; i++) {
			vector<float>temp;
			for (int j = 0; j < size; j++) {
				//converting the string value to an int.
				int num = atoi(textfull.substr(ch, 1).c_str());
				ch++;
				temp.push_back(num);

			}
			myVector.push_back(temp);
		}
	}
};


class sMatrix {
	static constexpr float p = 0.85;
	int size1;
	vector<vector<float>> myVector1;
	vector<vector<float>> myVector2;

public:
	int colSum = 0;
	float svalue;
	sMatrix(getMatrix m) {
		myVector1 = m.myVector;
		myVector2 = m.myVector;
		size1 = m.size;
	}
	void printMatrix() {
		std::vector< std::vector<float> >::const_iterator row;
		std::vector<float>::const_iterator col;

		for (row = myVector1.begin(); row != myVector1.end(); ++row)
		{
			for (col = row->begin(); col != row->end(); ++col)
			{
				std::cout << *col;


			}
			cout << endl;
		}
	}
	void getStoiMatrix() {

		for (int i = 0; i <size1; i++)
		{

			cout << endl;
			for (int j = 0; j<size1; j++)
			{
				//int jj = 0;
				for (int jj = 0; jj < size1; jj++)
				{
					if (myVector1[jj][j] == 1)
					{
						colSum++;

					}
				}

				float f = myVector1[i][j] / colSum;
				//checks if f is NaN
				if (f != f) {
					myVector2[i][j] = 1 / (float)size1;
					cout << myVector2[i][j] << " , ";

				}
				else {
					myVector2[i][j] = myVector1[i][j] / colSum;
					cout << myVector2[i][j] << " , ";
					colSum = 0;
				}

			}
		}


	}
	void transMatrix() {
		float val_vector1;
		float val_vector2;
		for (int i = 0; i < size1; i++) {
			for (int j = 0; j <size1; j++) {
				// myVector1[i][j] = ((float) 1/size1) * (1-p );
				//myVector2[i][j] *= p;
				val_vector1 = myVector1[i][j] = ((float)1 / size1) * (1 - p);
				val_vector2 = myVector2[i][j] *= p;
				//myVector2 is now the Tranistion matrix.
				myVector2[i][j] = val_vector1 + val_vector2;

			}
		}

	}

};

#endif /* Header_h */
