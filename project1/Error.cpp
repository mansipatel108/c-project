#include "stdafx.h"
#include "Error.h"

/**
	Shows a fatal error and exits program

	@param message The message to show upon a fatal error
*/
Error::Error(string message) {

	// show the error message
	cout << endl << endl;
	cout << "*****************ERROR*****************" << endl;
	cout << message << endl;
	cout << "Press enter twice to exit program";

	// exit the program
	string confirmExit;
	cin.ignore();
	getline(cin, confirmExit);
	exit(EXIT_FAILURE);
}


Error::~Error(){}
