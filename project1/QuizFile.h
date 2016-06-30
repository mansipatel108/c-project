#pragma once
#include <string>
#include <iostream>

using namespace std;

class QuizFile
{
public:
	QuizFile();
	~QuizFile();
	bool checkAnswer(int ans);

private:
	bool validateFile(string contents);
	bool loadContents(string contents);
	bool setAnswer();
};

