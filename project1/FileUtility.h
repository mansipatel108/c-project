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

private:
	bool file_exists(string file_name);
};

