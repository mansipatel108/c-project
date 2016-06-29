#include <string>
#include <iostream>
#include <vector>
#include "Util.h"

#pragma once

using namespace std;

class FileUtility
{
public:

	FileUtility();
	~FileUtility();
	string file_load(string file_name);
	vector<string> load_answers();
	bool file_exists(string file_name);
	bool file_write(string name);
	bool file_write(string name, vector<string> contents);
private:
	const string FILE_FOLDER = "files";
};

