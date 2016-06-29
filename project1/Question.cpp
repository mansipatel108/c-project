#include "stdafx.h"
#include "Question.h"


vector<string> Question::v_add(string s) //adds words to the vector
{
	vector<string> words;
	ifstream in_file;
	in_file.open("files/answers/dougger.txt");
	//--------------------------------------------
	//check for failure
	if (in_file.fail()) //This is left over from when I was debugging opening the file. I'll clean it up later.
	{
		cout << "Failed to open file.";
		system("pause");
		exit(EXIT_FAILURE);
	}
	//--------------------------------------------	
	string current_word;
	if (in_file >> current_word)
	{
		getline(in_file, current_word);
		words.push_back(current_word);
	}
	in_file.close();
	return words;
}

Question::Question(string question)
{	
	Util u = Util();
	vector<string>questionpie = u.splitString(question,'~');
	quizQquestion = questionpie[0];
	answer1 = questionpie[1];
	answer2 = questionpie[2];
	answer3 = questionpie[3];
	answer4 = questionpie[4];
    correct_answer = std::stoi(questionpie[5]); // save the answer as an int for easier comparison
	
}

void Question::askQuestion() {
	vector<string> answers = vector<string>();
	Menu m = Menu(quizQquestion, buildAnswers());

	int response = m.getPromptResponse();

	// quit the quiz
	if (response == -1) {
		Error e = Error("The quiz has been terminated");

	// mark if they got the question correct
	} else if (response == correct_answer) {
		questionStatus = true;
	}
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