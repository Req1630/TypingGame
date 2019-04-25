#include "Main.h"

int main()
{
	clsMain * cls_Main;
	cls_Main = new clsMain();
	cls_Main->DataIn();
	int mc = 0;
	int mcmax = 0;

	cout << "��萔����͂��Ă�������" << endl;
	cin >> mcmax;
	system( "cls" );

	while(1){
		cout << "�c�� = " << mcmax - mc << endl;

		cls_Main->StringOutput();

		Sleep( 500 );
		system( "cls" );

		mc++;
		if( mc == mcmax){
			break;
		}
	}
	cls_Main->ResultOut();
	system( "pause" );

	delete cls_Main;

	return 0;
}


clsMain::clsMain()
	: RightCnt ( 0 )
{
	srand( (unsigned int)time( NULL ) );
}
clsMain::~clsMain()
{
}

void clsMain::StringInput()
{
	cin >> InStr;
}
void clsMain::StringOutput()
{
	int r = rand() % QuestionStr.size() + 0;
	cout << QuestionStr[r] << endl;
	cout << RomanStr[r] << endl;

	StringInput();

	StrCheck( r );
}
void clsMain::StrCheck( int i )
{
	if( InStr == RomanStr[i] ){
		cout << "����" << endl;
		RightCnt++;
	} else {
		cout << "�s����" << endl;
	}
}

void clsMain::DataIn()
{
	ifstream FileName( "Mondai.csv" );
	string line;	// ��ł̕����擾�p.
	string field;	// �s�ł̕����擾�p.
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

void clsMain::ResultOut()
{
	cout << "���� = " << RightCnt << endl;
}