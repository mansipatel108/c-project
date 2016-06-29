#pragma once
#include <iostream>
#include <sstream>
#include "Util.h"
#include <iostream>
#include <vector>
#include <fstream>
#include "Menu.h"
#include "Error.h"


using namespace std;
class Question
{
public:
	Question(string question);
	~Question();
	void askQuestion();
	bool getResult();

	string quizQuestion;
private:
	string answer1;
	string answer2;
	string answer3;
	string answer4;
	int correct_answer;
	bool questionStatus = false;
	void parsequestion();
	vector<string> buildAnswers();
};