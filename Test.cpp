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
	int year = 2013;
	cout << "Value of C = " << conv.getSingleArabic("C") << endl;
	cout << "Value of 1000 = " << conv.getSingleRoman(1000) << endl;
	cout << "Arabic number 2013 to Roman... " << conv.messyArabicToRoman(year) << endl;
	cout << "Did the year variable change? " << year << endl;
	cout << "Is XX roman? 0 = false, 1 = true: " << conv.isRoman("XX") << endl;
	cout << "Is MMXIV roman? 0 = false, 1 = true: " << conv.isRoman("MMXIV") << endl;
	cout << "Roman number XI = " << conv.romanToArabic("XI") << endl;
	cout << "Roman number MMXIV = " << conv.romanToArabic("MMXIV") << endl;
}



