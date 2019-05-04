#include "Main.h"

HANDLE hStdout1;

const int WND_W = 60;
const int WND_H = 20;

void CharDraw( int x, int y, const char *c )
{
	COORD coord;

	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(hStdout1,coord);
	cout << c << endl;
}

void CharInput( int x, int y, string *c )
{
	COORD coord;

	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(hStdout1,coord);

	cin >> *c;
}

void SetColor( int f, int b )
{
	WORD wFore = f;
	WORD wBack = b;
	SetConsoleTextAttribute(hStdout1, wFore + (wBack << 4));
}

void Clear( int x, int y, const char *c )
{
	SetColor( 7, 0 );
	CharDraw ( x, y, c );
}

void GameFrameOut()
{
	SetColor( 3, 0 );
	for( int y = 0; y < WND_H; y++ ){
		for( int x = 0; x < WND_W; x++ ){
			if ( x == 0 || x == WND_W - 1 ){
				CharDraw( x, y, "◇" );
			}
			if ( y == 0 || y == WND_H - 1 ){
				CharDraw( x, y, "━" );
			}

			if ( x == 0 && y == 0 ){
				CharDraw( x, y, "┏" );
			} else if ( x == 0 && y == WND_H - 1 ){
				CharDraw( x, y, "┗" );
			} else if ( x == WND_W - 1 && y == 0 ){
				CharDraw( x, y, "┓" );
			} else if ( x == WND_W - 1 && y == WND_H - 1 ){
				CharDraw( x, y, "┛" );
			}
			Sleep( 5 );
		}
	}
}

int main()
{
	hStdout1 = GetStdHandle(STD_OUTPUT_HANDLE);
	clsMain * cls_Main;
	cls_Main = new clsMain();
	cls_Main->DataIn();
	int mc = 0;
	int mcmax = 0;

	GameFrameOut();
	SetColor( 4, 0 );
	CharDraw ( 4, 2,"問題数を入力してください" );
	COORD coord;
	coord.X = 5;
	coord.Y = 3;
	SetConsoleCursorPosition(hStdout1,coord);
	cin >> mcmax;

	Clear( 4, 2, "　　　　　　　　　　　　" );
	Clear( 5, 3, "　　　　  " );

	while(1){
		COORD coord;

		coord.X = 5;
		coord.Y = 3;
		Clear( 5, 3, "　　　　  " );
		SetConsoleCursorPosition(hStdout1,coord);
		SetColor( mcmax - mc, 0 );
		cout << "残り = " << mcmax - mc << endl;

		cls_Main->StringOutput();

		mc++;
		if( mc == mcmax){
			break;
		}
	}
	cls_Main->ResultOut();
	system( "pause" );

	delete cls_Main;

	CloseHandle(hStdout1);
	hStdout1 = NULL;

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
	CharInput ( INPUT_X, INPUT_Y, &InStr );
}
void clsMain::StringOutput()
{
	int r = rand() % QuestionStr.size() + 0;

	CharDraw ( OUTPUT_X, OUTPUT_Y - 1, QuestionStr[r].c_str() );
	CharDraw ( OUTPUT_X, OUTPUT_Y, RomanStr[r].c_str() );

	StringInput();

	StrCheck( r );
	Sleep( 500 );
	Clear( ANSWER_OUT_X, ANSWER_OUT_Y, "　　　" );
	Clear( OUTPUT_X, OUTPUT_Y - 1, "                      " );
	Clear( OUTPUT_X, OUTPUT_Y, "                      " );
	Clear( INPUT_X, INPUT_Y, "                   " );
}
void clsMain::StrCheck( int i )
{	
	if( InStr == RomanStr[i] ){
		CharDraw ( ANSWER_OUT_X, ANSWER_OUT_Y, "正解" );
		RightCnt++;
	} else {
		CharDraw ( ANSWER_OUT_X, ANSWER_OUT_Y, "不正解" );
	}
}

void clsMain::DataIn()
{
	ifstream FileName( "Mondai.csv" );
	string line;	// 列での文字取得用.
	string field;	// 行での文字取得用.
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
	COORD coord;

	coord.X = 5;
	coord.Y = 3;
	SetConsoleCursorPosition(hStdout1,coord);
	cout << "正解数 = " << RightCnt << endl;
}