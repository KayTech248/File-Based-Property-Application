#pragma once
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


class entityType
{
public:
	entityType();
	//~entityType();
	virtual void  SelectAll(string pk) = 0;
	virtual void Insert(string pk) = 0;
	virtual void Delete(string pk) = 0;


protected:
	int size;
	string tname;
};
entityType::entityType()
{
	size = 20;								
	tname = "";

}
