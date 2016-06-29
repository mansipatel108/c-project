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
#include "Util.h"

vector<Question> generateQuestions(string quizFile) {

	// parse the questions/answers by line
	Util util = Util();
	vector<string> qa = util.splitString(quizFile, '\n');

	// store the questions in a vector
	vector<Question> questions = vector<Question>();

	int counter = 0;
	for (auto i = qa.begin(); i != qa.end(); i++) {
		questions.push_back(Question(qa[counter]));
		counter++;
	}

	return questions;

}

void administerQuiz(vector<Question> &questions) {

	int counter = 0;
	for (auto i = questions.begin(); i != questions.end(); i++) {
		questions[counter].askQuestion();
		counter++;
	}
}

int calculateScore(vector<Question> &questions) {

	// create counters
	int indexCounter = 0;
	int correctCounter = 0;
	int quantityCounter = 0;

	for (auto i = questions.begin(); i != questions.end(); i++) {

		if (questions[indexCounter].getResult()) {
			correctCounter++;
		}

		indexCounter++;
		quantityCounter++;

	}

	if (correctCounter > 0) {
		return ((float)correctCounter / (float)quantityCounter) * 100;
	}
	else {
		return 0;
	}
}

int main()
{
	
	// get the users name
	vector<string> checks = vector<string>();
	checks.push_back("onlyLatin");
	PromptUser prompt = PromptUser("Please enter your name (latin characters only)", checks);
	string username = prompt.getResponse();

	// see if they already have an answer file
	FileUtility fu = FileUtility();
	if (fu.file_exists("answers/" + username)) {
		string answerFile = fu.file_load("answers/" + username);
		
		// display statistics
	
	}

	// load the quiz file and administer the quiz
	if (fu.file_exists("quiz/firstquiz.txt")) {
		vector<Question> questions = generateQuestions(fu.file_load("quiz/firstquiz.txt"));

		// administer quiz and get percentage of correct answers
		administerQuiz(questions);
		float percentCorrect = calculateScore(questions);

		// record the quiz results

	}
	else {
		Error e = Error("Quiz file could not be found. Contact a programmer.");
	}
	
	
	string hi;
	cin.ignore();
	cin >> hi;

    return 0;
}


