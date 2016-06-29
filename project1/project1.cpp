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
#include <ctype.h>

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

bool nameSort(string x, string y) {
	return x < y;
}

int main()
{

	// method variables
	FileUtility fu = FileUtility();
	Util util = Util();

	// get the users name
	vector<string> checks = vector<string>();
	checks.push_back("onlyLatin");
	PromptUser firstName = PromptUser("Please enter your first name (latin characters only)", checks);
	PromptUser lastName = PromptUser("Please enter your last name (latin characters only)", checks);
	string firstNameStr = firstName.getResponse();
	string lastNameStr = lastName.getResponse();
	string usernameDispaly = firstNameStr + " " + lastNameStr;
	string username = firstNameStr + lastNameStr;
	util.lowercase(username);							// mutates username
	

	////// Get the users previous high score

	vector<string> answerFile;		// holds the users details
	float previousScore = -1;		// holds their previous score, if any

	// load or create answer file
	if (fu.file_exists("names.txt")) {
		answerFile = fu.load_answers();
	}
	else {
		fu.file_write("names.txt");
		answerFile = vector<string>();
	}

	// find if user exists in answer file
	int indexCounter = 0;
	int matchIndex = -1;
	for (auto i = answerFile.begin(); i != answerFile.end(); i++) {

		// get their name
		vector<string> name = util.splitString(answerFile[indexCounter], ' ');

		// check the next entry if there are no elements
		if (name.size() == 0) {
			continue;
		}

		// see if we find a match
		if (name[0] == username) {
			matchIndex = indexCounter;
			previousScore = stof(name[1]);
			break;
		}
		
		indexCounter++;

	}

	// display welcome message
	
	if (previousScore == -1) {
		cout << "Welcome to the quiz" << endl;
	}
	else {
		cout << "Welcome back " << usernameDispaly << endl;
		cout << "Your previous score was " << previousScore << endl;
	}

	////// Run the quiz

	// holds the questions
	vector<Question> questions;

	// load the quiz file and administer the quiz
	if (fu.file_exists("quiz/firstquiz.txt")) {
		questions = generateQuestions(fu.file_load("quiz/firstquiz.txt"));
	}
	else {
		Error e = Error("Quiz file could not be found. Contact a programmer.");
	}

	// administer quiz and get percentage of correct answers
	administerQuiz(questions);								// will mutate questions variable
	int percentCorrect = calculateScore(questions);

	
	////// display and record results

	// display percentage correct
	if (previousScore >= 0) {
		cout << "Previous score: " << previousScore << "%" << endl;;
	}
	else {
		cout << "Previous score: no score recorded" << endl;
	}

	cout << "Time time you got " << percentCorrect << "%" << endl;
	
	// record the answer if there is not previous schore
	bool writeFlag = false;
	if (matchIndex == -1) {

		answerFile.push_back(username + " " + to_string(percentCorrect));
		sort(answerFile.begin(), answerFile.end(), nameSort);
		writeFlag = true;

	// record the quiz results if the new score is better
	} else if (percentCorrect > previousScore) {
		answerFile[matchIndex] = username + " " + to_string(percentCorrect);
		writeFlag = true;
	}
	
	if (writeFlag) {
		fu.file_write("names.txt", answerFile);
	}

	string hi;
	cin.ignore();
	cin >> hi;

	return 0;
}


