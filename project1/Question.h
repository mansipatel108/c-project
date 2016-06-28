#pragma once
#include <iostream>
#include <sstream>
#include "Util.h"
#include <iostream>
#include <vector>
#include <fstream>
#include "Menu.h"



using namespace std;
class Question
{
public:
	Question(string question);
	~Question();
	vector<string> v_add(string s );
	void askQuestion();

private:
	string quizQquestion;
	string answer1;
	string answer2;
	string answer3;
	string answer4;
	string correct_answer;
	void parsequestion();
	vector<string> buildAnswers();
};

