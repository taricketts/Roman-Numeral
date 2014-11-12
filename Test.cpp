/*
 * Test.cpp
 *
 *  Created on: Nov 12, 2014
 *      Author: Tom
 */
#include <iostream>
#include "RomanNumeral.h"
#include <string>
using namespace std;

int main(){
	RomanNumeral conv;
	string in = "ACDC";
	cout << "Testing substr(0,2) on string ACDC: " << in.substr(0,2)<< endl;
	cout << "Value of C = " << conv.getSingleArabic('C') << endl;
	cout << "Value of 1000 = " << conv.getSingleRoman(1000) << endl;
}



