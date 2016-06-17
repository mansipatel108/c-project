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
	/* question = questionpie[0];
	
	answer1 = questionpie[1];
	answer2 = questionpie[2];
	answer3 = questionpie[3];
	answer4 = questionpie[4];
    correct_answer = answer1;
	
	cout << questionpie.size();
	cout << question << answer1 << " " << answer2 << " " << answer3 << " " << answer4 << " " << correct_answer<< endl;
	*/
	
}


Question::~Question()
{
}

void Question::parsequestion()
{
}