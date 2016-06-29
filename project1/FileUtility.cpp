#include "stdafx.h"
#include <sstream>
#include <fstream>
#include "FileUtility.h"


FileUtility::FileUtility() {}

/**
	Checks if a file exists in the "files" folder

	@param file_name The name of the file to load
	@return true if found, false otherwise
*/
bool FileUtility::file_exists(string file_name) {
	if (std::ifstream(FILE_FOLDER + "/" + file_name)) {
		return true;
	} else {
		return false;
	}
}

/**
	Loads a file from the "files" folder

	This function will throw a fatal error if the file cannot be loaded.

	@param file_name The name of the file to load
	@string The file contents
*/
string FileUtility::file_load(string file_name) {

	// ensure the file exists
	if (!file_exists(file_name)) {
		file_write(file_name);
	}

	// load file contents into stream
	std::ifstream ifs;
	ifs.open(FILE_FOLDER + "/" + file_name, std::ifstream::in);

	// return the stream as a string4
	stringstream sstr;
	sstr << ifs.rdbuf();
	return sstr.str();

}

/**
	Loads the answer into a string vector
*/
vector<string> FileUtility::load_answers() {

	string answers = file_load("names.txt");
	Util util = Util();
	return util.splitString(answers, '\n');

}

/**
	Writes an new empty file to the "files" folder

	@param file_name The file name
	@return true if written, false otherwise
*/
bool FileUtility::file_write(string file_name) {
	file_write(file_name, vector<string>());
	return true;
}

/**
	Writes a file with contents to the "files" folder

	@param file_name The filename
	@param contents The file contents
*/
bool FileUtility::file_write(string file_name, vector<string> contents) {

	// build file contents
	string fileContents;
	int index = 0;
	for (auto i = contents.begin(); i != contents.end(); i++) {
		fileContents += contents[index] + "\n";
		index++;
	}

	// open file and write contents
	std::ofstream fs;
	fs.open(FILE_FOLDER + "/" + file_name);
	fs << fileContents;
	fs.close();

	return true;

}

FileUtility::~FileUtility() {}
