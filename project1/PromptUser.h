#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class PromptUser
{
public:
	PromptUser(string prompt, vector<string> checks);
	string getResponse();
	~PromptUser();
	bool validateInput(string str);
private:
	string responseString;
	vector<string> checks;
	bool onlyLatinCheck(string str);
};

