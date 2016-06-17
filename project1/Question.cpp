#include "stdafx.h"
#include "Question.h"

/**
* Splits a string on a delimeter
*
* @param string The string to split
* @param char The delimeter to split on
* @return A vector containing the string tokens
*/
vector<string> Question::splitString(string s, char del) {
	vector<string> newString;
	stringstream ss(s);
	string token;

	while (getline(ss, token, del)) {
		newString.push_back(token);
	}

	return newString;

}

Question::Question(string question)
{	
}


Question::~Question()
{
}

void Question::parsequestion()
{
}