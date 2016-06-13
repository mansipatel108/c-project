// project1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Error.h"
#include <iostream>
#include <vector>


int main()
{
	std::vector<std::string> myvector;
	std::vector<std::string>::iterator it;

	it = myvector.begin();
	std::string myarray[] = { "Hi","hello","wassup" };
	myvector.insert(myvector.begin(), myarray, myarray + 3);

	std::cout << "myvector contains:";
	for (it = myvector.begin(); it<myvector.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';



	string hi;
	Error e = Error();
	cin >> hi;

    return 0;
}

