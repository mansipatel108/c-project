#pragma once

#include <iostream>
#include <string>

using namespace std;

class PromptUser
{
public:
	PromptUser(string options[]);
	~PromptUser();
	int prompt();
};


