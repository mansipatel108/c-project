#include <iostream>
#include <vector>
#include <sstream>

#pragma once
using namespace std;
class Question
{
public:
	Question(string question);
	~Question();
	vector<string> splitString(string s, char del);

private:
	string question;
	string answer1;
	string answer2;
	string answer3;
	string answer4;
	string correct_answer;
	void parsequestion();

};

