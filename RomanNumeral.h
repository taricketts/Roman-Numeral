/*
 * RomanNumeral.h
 *
 *  Created on: Nov 10, 2014
 *      Author: Tom
 */

#include <string>

using namespace std;

#ifndef ROMANNUMERAL_H_
#define ROMANNUMERAL_H_

class RomanNumeral {
private:
	char roman[7];
	int arabic[7];
	const int null = -1;
public:
	void RomanToArabic(string input);
	int getArabic(char input);

};

RomanNumeral::RomanNumeral() {
	roman[0] = 'I';
	roman[1] = 'V';
	roman[2] = 'X';
	roman[3] = 'L';
	roman[4] = 'C';
	roman[5] = 'D';
	roman[6] = 'M';

	arabic[0] = 1;
	arabic[1] = 5;
	arabic[2] = 10;
	arabic[3] = 50;
	arabic[4] = 100;
	arabic[5] = 500;
	arabic[6] = 1000;

}

RomanNumeral::~RomanNumeral(){}

void RomanNumeral::RomanToArabic(string input) {

}

int RomanNumeral::getArabic(char input){
	int val = null;

	if(input == roman[0])
		val = roman[0];
	else if(input == roman[1])
		val = arabic[1];
	else if(input == roman[2])
			val = arabic[2];
	else if(input == roman[3])
			val = arabic[3];
	else if(input == roman[4])
			val = arabic[4];
	else if(input == roman[5])
			val = arabic[5];
	else if(input == roman[6])
			val = arabic[6];
	else
		val = null;

	return val;
}

#endif /* ROMANNUMERAL_H_ */
