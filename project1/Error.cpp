#include "stdafx.h"
#include "Error.h"


Error::Error(string message) {
	
	cout << message << endl;
	cout << "Press enter to exit program";
	string conformExit;
	cin.ignore();
	getline(cin, conformExit);
	exit(EXIT_FAILURE);
}


Error::~Error()
{
}
