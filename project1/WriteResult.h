#pragma once

#include <iostream>

using namespace std;
class WriteResult
{
public:
	WriteResult();
	~WriteResult();
	bool writeUserScore(string user, int scoreArray[]);

private:
	void loadAnswerFile();
	int findUserPos(string user);
};


