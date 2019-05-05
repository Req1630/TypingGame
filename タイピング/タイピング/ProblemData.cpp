#include "ProblemData.h"

clsProblemData::clsProblemData()
{
}
clsProblemData::~clsProblemData()
{
}

void clsProblemData::DataIn()
{
	ifstream FileName( "Mondai.csv" );
	string line;	// —ñ‚Å‚Ì•¶šæ“¾—p.
	string field;	// s‚Å‚Ì•¶šæ“¾—p.
	while ( getline( FileName, line )) {
		istringstream stream( line );
		int f = 0;
		while ( getline( stream, field, ',' )) {
			if ( f == 0 ){
				QuestionStr.push_back( field  );
				f++;
			} else {
				RomanStr.push_back( field );
			}
		}
	}
	FileName.close();
}

int clsProblemData::GetProblemNum()
{
	return static_cast<int>(QuestionStr.size());
}

string clsProblemData::GetProblem( int n )
{
	return QuestionStr[n];
}
string clsProblemData::GetPAlphabet( int n )
{
	return RomanStr[n];
}