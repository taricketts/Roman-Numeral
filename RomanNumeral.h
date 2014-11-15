/*
 * RomanNumeral.h
 *
 *  Created on: Nov 10, 2014
 *      Author: Tom
 */

#include <string>
#include <iostream>

using namespace std;

#ifndef ROMANNUMERAL_H_
#define ROMANNUMERAL_H_

class RomanNumeral {
private:
	string roman[7];
	int arabic[7];
public:
	RomanNumeral();
	~RomanNumeral();
	int romanToArabic(string input);
	string messyArabicToRoman(int input);
	string subtractiveRoman(string input);
	int getSingleArabic(string input);
	string getSingleRoman(int input);
	bool isRoman(string input);

};

RomanNumeral::RomanNumeral() {
	roman[0] = "I";
	roman[1] = "V";
	roman[2] = "X";
	roman[3] = "L";
	roman[4] = "C";
	roman[5] = "D";
	roman[6] = "M";

	arabic[0] = 1;
	arabic[1] = 5;
	arabic[2] = 10;
	arabic[3] = 50;
	arabic[4] = 100;
	arabic[5] = 500;
	arabic[6] = 1000;

}

RomanNumeral::~RomanNumeral() {
}

int RomanNumeral::romanToArabic(string input) {
	int output = 0;
	int length = input.length();
	if (isRoman(input) == true) {
		for (int i = 0; i < length; i++) {
			if (i == length - 1) {
				output += getSingleArabic(input.substr(i));
			} else if (getSingleArabic(input.substr(i, 1))
					< getSingleArabic(input.substr(i + 1, 1))) {
				output += getSingleArabic(input.substr(i + 1, 1))
						- getSingleArabic(input.substr(i, 1));
				i++;
			} else {
				output += getSingleArabic(input.substr(i, 1));
			}
		}

	} else {
		output = -1;
	}
	return output;
}

string RomanNumeral::messyArabicToRoman(int input) {
	string output;
	int tmp = 0;
	if (input / 1000 >= 1) {
		tmp = input / 1000;
		input -= (tmp * 1000);
		for (int i = 0; i < tmp; i++) {
			output += "M";
		}
	}
	if (input / 500 == 1) {
		tmp = input / 500;
		input -= 500;
		output += "D";
	}
	if (input / 100 >= 1) {
		tmp = input / 100;
		input -= (tmp * 100);
		for (int i = 0; i < tmp; i++) {
			output += "C";
		}
	}
	if (input / 50 >= 1) {
		tmp = input / 50;
		input -= (tmp * 100);
		for (int i = 0; i < tmp; i++) {
			output += "L";
		}
	}
	if (input / 10 >= 1) {
		tmp = input / 10;
		input -= (tmp * 10);
		for (int i = 0; i < tmp; i++) {
			output += "X";
		}
	}
	if (input / 5 >= 1) {
		tmp = input / 5;
		input -= (tmp * 5);
		for (int i = 0; i < tmp; i++) {
			output += "V";
		}
	}
	if (input != 0) {
		for (int i = 0; i < input; i++) {
			output += "I";
		}
	}

	return output;

}

string RomanNumeral::subtractiveRoman(string input) {
	int length = input.length();
	// may not be needed: int count = 0;
	string output = "";
	string tmp = "";
	string single = "";

	for (int i = 0; i < length; i++) {
		if (i == length - 1) {
			output += input.substr(i, 1);
			return output;
		} else if (i == length - 2) {
			output += input.substr(i, 1) + input.substr(i + 1, 1);
			return output;
		} else if (i == length - 3) {
			output += input.substr(i, 1) + input.substr(i + 1, 1)
					+ input.substr(i + 2, 1);
			return output;
		} else {
			tmp = input.substr(i, 4);
			single = tmp.substr(0, 1);
		}
		if (single == tmp.substr(0, 1) && single == tmp.substr(1, 1)
				&& single == tmp.substr(2, 1) && single == tmp.substr(3)) {
			/*
			check single for value, make correct conversion, change
			tmp, and add to output
			*/
		} else {
			output += tmp;
		}

	}

	return input;
}

bool RomanNumeral::isRoman(string input) {
	int length = input.size();
	bool validity = true;

	for (int z = 0; z < length; z++) {
		if (z == length - 1) {
			if (input.substr(z) == roman[0] || input.substr(z) == roman[1]
					|| input.substr(z) == roman[2]
					|| input.substr(z) == roman[3]
					|| input.substr(z) == roman[4]
					|| input.substr(z) == roman[5]
					|| input.substr(z) == roman[6]) {
				//Checks validity
			} else {
				validity = false;
				return validity;
			}
		} else if (input.substr(z, 1) == roman[0]
				|| input.substr(z, 1) == roman[1]
				|| input.substr(z, 1) == roman[2]
				|| input.substr(z, 1) == roman[3]
				|| input.substr(z, 1) == roman[4]
				|| input.substr(z, 1) == roman[5]
				|| input.substr(z, 1) == roman[6]) {
			//Checks validity
		} else {
			validity = false;
			return validity;
		}
	}
	return validity;
}

string RomanNumeral::getSingleRoman(int input) {
	string val;

	if (input == arabic[0])
		val = roman[0];
	else if (input == arabic[1])
		val = roman[1];
	else if (input == arabic[2])
		val = roman[2];
	else if (input == arabic[3])
		val = roman[3];
	else if (input == arabic[4])
		val = roman[4];
	else if (input == arabic[5])
		val = roman[5];
	else if (input == arabic[6])
		val = roman[6];
	else
		val = '0';

	return val;

}

int RomanNumeral::getSingleArabic(string input) {
	int val;

	if (input == roman[0])
		val = arabic[0];
	else if (input == roman[1])
		val = arabic[1];
	else if (input == roman[2])
		val = arabic[2];
	else if (input == roman[3])
		val = arabic[3];
	else if (input == roman[4])
		val = arabic[4];
	else if (input == roman[5])
		val = arabic[5];
	else if (input == roman[6])
		val = arabic[6];
	else
		val = -1;

	return val;
}

#endif /* ROMANNUMERAL_H_ */
