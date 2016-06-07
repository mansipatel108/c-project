#include <string>
#include <iostream>

#pragma once

using namespace std;
class UserInfo
{
public:
	UserInfo();
	~UserInfo();

public:
	void getUserInfo(string userName);

public:
	string check_username(string username);


};

