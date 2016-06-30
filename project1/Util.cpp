#include "stdafx.h"
#include "Util.h"

Util::Util(){}

/**
* Splits a string on a delimeter
*
* @param string The string to split
* @param char The delimeter to split on
* @return A vector containing the string tokens
*/
vector<string> Util::splitString(string s, char del) {
	vector<string> newString;
	stringstream ss(s);
	string token;

	while (getline(ss, token, del)) {
		newString.push_back(token);
	}

	return newString;
}

/**
	Converts a string to lowercase via mutation

	@param &str The string to convert to lowercase
*/
void Util::lowercase(string &str) {
	transform(str.begin(), str.end(), str.begin(), ::tolower);
}

Util::~Util() {}
