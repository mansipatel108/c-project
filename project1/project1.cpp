// project1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Error.h"
#include "Question.h"
#include <iostream>
#include <vector>
#include "FileUtility.h"


int main()
{
	/*
	std::vector<std::string> myvector;
	std::vector<std::string>::iterator it;
	
	it = myvector.begin();
	std::string myarray[] = {"1.WHEN COMPUTER WAS FIRST INVENTIONED?","~","a.1822","~","b.1823","~","c.1834","~","d.1922"};
	myvector.insert(myvector.begin(), myarray, myarray + 9);
		 
	std::cout << "myvector contains:";
	for (it = myvector.begin(); it<myvector.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';
	*/
    
	FileUtility fu = FileUtility();
	string quiz = fu.file_load("quiz/firstquiz.txt");
	cout << quiz;


	string hi;
	Error e = Error();
	cin >> hi;

    return 0;
}

