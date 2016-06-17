// project1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Error.h"
#include "Util.h"
#include "Question.h"
#include <iostream>
#include <vector>
#include "FileUtility.h"


int main()
{
	// load thhe quiz file
	FileUtility fu = FileUtility();
	string quiz = fu.file_load("quiz/firstquiz.txt");

	// parse the file by new line in to  vector 	
	Util q = Util();
	vector<string> quizLines =q.splitString(quiz,'\n');
	vector<Question> question;
   int counter = 0;
		// loop through the vector of lines
		for (auto i = quizLines.begin(); i != quizLines.end(); ++i) {
			Question q = Question(quizLines[counter]);
			question.push_back(q);
			counter++;
		}

	string hi;
	Error e = Error();
	cin >> hi;

    return 0;
}

