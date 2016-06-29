#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>

#pragma once
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
class Util
{
public:
	Util();
	~Util();
	vector<string> splitString(string s, char del);
	void lowercase(string &str);
};

