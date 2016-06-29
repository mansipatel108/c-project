#include "stdafx.h"
#include "Question.h"

Question::Question(string question)
{	
	Util u = Util();
	vector<string>questionpie = u.splitString(question,'~');
	quizQuestion = questionpie[0];
	answer1 = questionpie[1];
	answer2 = questionpie[2];
	answer3 = questionpie[3];
	answer4 = questionpie[4];
    correct_answer = std::stoi(questionpie[5]); // save the answer as an int for easier comparison
}

void Question::askQuestion() {
	vector<string> answers = vector<string>();
	Menu m = Menu(quizQuestion, buildAnswers());

	int response = m.getPromptResponse();

	// quit the quiz
	if (response == -1) {
		Error e = Error("The quiz has been terminated");

	// mark if they got the question correct
	} else if (response == correct_answer) {
		questionStatus = true;
	}
}

bool Question::getResult() {
	return questionStatus;
}

vector<string> Question::buildAnswers() {

	vector<string> answers;
	answers.push_back(answer1);
	answers.push_back(answer2);
	answers.push_back(answer3);
	answers.push_back(answer4);

	return answers;
}


Question::~Question()
{
}

void Question::parsequestion()
{
}