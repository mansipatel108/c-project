#include <iostream>
#include <sstream>
#include "Util.h"
#pragma once
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
class Question
{
public:
	Question(string question);
	~Question();
	vector<string> v_add(string s );

private:
	string question;
	string answer1;
	string answer2;
	string answer3;
	string answer4;
	string correct_answer;
	void parsequestion();

};

