#ifndef MAIN_H
#define MAIN_H

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

	const int INPUT_Y = 5;
	const int INPUT_X = 20;
	const int OUTPUT_X = INPUT_X;
	const int OUTPUT_Y = INPUT_Y - 1;

	const int ANSWER_OUT_X = 5;
	const int ANSWER_OUT_Y = 7;

		
public:
	clsMain();
	~clsMain();
	void DataIn();
	void StringInput();
	void StringOutput();
	void StrCheck( int i );
	void ResultOut();
};

#endif // #ifndef MAIN_H.