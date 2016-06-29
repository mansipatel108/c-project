#include "stdafx.h"
#include "PromptUser.h"


PromptUser::PromptUser(string prompt, vector<string> requiredChecks)
{

	// store the checks
	PromptUser::checks = requiredChecks;

	while (true) {

		// display the prompt to the user
		cout << prompt << ": ";

		// get the users response
		string response;
		getline(cin, response);

		// return the response if there are no validtions to perform
		if (requiredChecks.size() == 0) {
			responseString = response;
			break;

		 
		} // run the required checks
		else {
			if (validateInput(response)) {
				responseString = response;
				break;
			}
		}
	}
}

/**
 * Returns true if every character is a latin letter, false otherwise
 */
bool PromptUser::onlyLatinCheck(string str) {
	for (char& c : str) {
		if (!(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')) {
			return false;
		}
	}
	return true;
}

/**
 * Validates the input according to supplied arguments
 */
bool PromptUser::validateInput(string str) {
	if (std::find(checks.begin(), checks.end(), "onlyLatin") != checks.end()) {
		if (!onlyLatinCheck(str)) { 
			cout << endl << "*** ERROR ***" <<endl ;
			cout << "Please enter only latin characters (no spaces)" << endl << endl;
			return false;
		}
	}
	return true;
}


string PromptUser::getResponse() {
	return responseString;
}


PromptUser::~PromptUser()
{
}
