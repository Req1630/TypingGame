#pragma once

#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

class clsMain
{
	string InStr;
	vector<string> QuestionStr;
	vector<string> RomanStr;
	
	int RightCnt;
		
public:
	clsMain();
	~clsMain();
	void DataIn();
	void StringInput();
	void StringOutput();
	void StrCheck( int i );
	void ResultOut();
};