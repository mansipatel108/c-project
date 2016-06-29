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

	// method variables
	FileUtility fu = FileUtility();

	// get the users name
	vector<string> checks = vector<string>();
	checks.push_back("onlyLatin");
	PromptUser firstName = PromptUser("Please enter your first name (latin characters only)", checks);
	PromptUser lastName = PromptUser("Please enter your last name (latin characters only)", checks);
	string fileName = firstName.getResponse() + lastName.getResponse();
	string username = firstName.getResponse() + " " + lastName.getResponse();


	////// Get the users previous high score

	// holds the users current high score
	string answerFile;

	if (fu.file_exists("answers/" + fileName)) {
		answerFile = fu.file_load("answers/" + fileName);
	}
	else {
		fu.file_write("answers/" + fileName);
		answerFile = "0.0";
	}

	// convert answer file value to float for comparisons below
	// and display welcome message
	float previousScore;
	if (answerFile == "" || answerFile == "0.0") {
		previousScore = 0.0;
		cout << "Welcome to the quiz" << endl;
	}
	else {
		previousScore = std::stof(answerFile);
		cout << "Welcome back " << username << endl;
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
	float percentCorrect = calculateScore(questions);


	////// display and record results

	// display percentage correct
	if (previousScore != 0.0) {
		cout << "Previous score: " << answerFile << "%" << endl;;
	}
	else {
		cout << "Previous score: no score recorded" << endl;
	}

	cout << "Time time you got " << percentCorrect << "%" << endl;

	// record the answer if there is not previous schore
	if (previousScore == 0.0) {

		fu.file_write("answers/" + fileName, percentCorrect);

		// record the quiz results if the new score is better
	}
	else if (percentCorrect > (float)std::stoi(answerFile)) {
		fu.file_write("answers/" + fileName, percentCorrect);
	}

	string hi;
	cin.ignore();
	cin >> hi;

	return 0;
}


