#include <string>
#include <iostream>
#pragma once

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

