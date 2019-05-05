#ifndef PORBLEM_DATA
#define PORBLEM_DATA

#include <fstream>
#include <string>
#include <sstream>

#include <vector>
#include <stdlib.h>

using namespace std;

class clsProblemData
{
public:
	clsProblemData();
	~clsProblemData();

	void DataIn();

	int GetProblemNum();

	string GetProblem( int n );
	string GetPAlphabet( int n );


private:
	vector<string> QuestionStr;
	vector<string> RomanStr;
};

#endif // #ifndef PORBLEM_DATA.