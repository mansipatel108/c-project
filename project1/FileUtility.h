#include <string>
#include <iostream>


#pragma once

using namespace std;

class FileUtility
{
public:

	FileUtility();
	~FileUtility();
	string file_load(string file_name);
	bool file_exists(string file_name);
	bool file_write(string name);
	bool file_write(string name, float contents);
private:
	const string FILE_FOLDER = "files";
};

