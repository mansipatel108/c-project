// project1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Error.h"
#include "Util.h"
#include "Question.h"
#include <iostream>
#include <vector>
#include "FileUtility.h"
#include "PromptUser.h"

int main()
{
	
	// get the users details
	vector<string> checks = vector<string>();
	checks.push_back("onlyLatin");
	PromptUser prompt = PromptUser("Please enter your name (latin characters only)", checks);
	



	string hi;
	Error e = Error();
	cin >> hi;

    return 0;
}

