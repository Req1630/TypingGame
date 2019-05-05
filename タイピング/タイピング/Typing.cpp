#include "Typing.h"

clsTyping::clsTyping()
	: m_clsConsole	( new clsConsole )
	, m_clsProData	( new clsProblemData )
	, CorrectCnt	( 0 )
	, RandomCnt		( 0 )
{
	srand( (unsigned int)time( NULL ) );
	m_clsProData->DataIn();
}

clsTyping::~clsTyping()
{
	delete m_clsProData;
	delete m_clsConsole;
}

void clsTyping::GameMain()
{
	UI();
	ProblemCntMaxInput();
	
	for( ProbCnt = 0; ProbCnt != ProbCntMax; ProbCnt++ ){
		RestOut();
		ProblemOutput();
		AlphabetOutput();
		AnswerInput();
		Check();
		AllClear();
	}
	ResultOut();

	system( "pause" );
}

void clsTyping::AnswerInput()
{
	m_clsConsole->Input( INPUT_X, INPUT_Y, &m_sAnswer );
}

void clsTyping::ProblemOutput()
{
	RandomCnt = rand() % m_clsProData->GetProblemNum() + 0;
	m_clsConsole->Draw( OUTPUT_X, OUTPUT_Y - 1, m_clsProData->GetProblem(RandomCnt) );
}
void clsTyping::AlphabetOutput()
{
	m_clsConsole->Draw( OUTPUT_X, OUTPUT_Y, m_clsProData->GetPAlphabet(RandomCnt) );
}

void clsTyping::Check()
{
	string s_isAnswer;
	if ( m_sAnswer == m_clsProData->GetPAlphabet(RandomCnt) ){
		s_isAnswer = "正解";
		CorrectCnt++;
	} else {
		s_isAnswer = "不正解";
	}
	m_clsConsole->Draw ( ANSWER_OUT_X, ANSWER_OUT_Y, s_isAnswer );
}

void clsTyping::ResultOut()
{
	m_clsConsole->Draw ( ANSWER_OUT_X, ANSWER_OUT_Y, "正解数 = ", false );
	m_clsConsole->Draw ( ANSWER_OUT_X + 9, ANSWER_OUT_Y, CorrectCnt );
}

void clsTyping::AllClear()
{
	Sleep ( 1000 );
	m_clsConsole->Clear( INPUT_X, INPUT_Y, "　　　　　　　　　" );
	m_clsConsole->Clear( OUTPUT_X, OUTPUT_Y, "　　　　　　　　　　　　　　" );
	m_clsConsole->Clear( OUTPUT_X, OUTPUT_Y - 1, "　　　　　　　　　　　　" );
	m_clsConsole->Clear( ANSWER_OUT_X, ANSWER_OUT_Y, "　　　" );
}

void clsTyping::RestOut()
{
	ProbCntNow = ProbCntMax - ProbCnt;
	m_clsConsole->Clear( 2, 1, "　　　　　　　　　　　　　" );
	m_clsConsole->Draw( 2, 1, "残り = ", false );
	m_clsConsole->Draw( 10, 1, ProbCntNow );
}

void clsTyping::ProblemCntMaxInput()
{
	m_clsConsole->Draw( 4, 2,"問題数を入力してください → ", false );
	m_clsConsole->Input( 32, 2, &ProbCntMax );
	m_clsConsole->Clear( 4, 2, "　　　　　　　　　　　　　　　　　" );
}

void clsTyping::UI()
{
	m_clsConsole->SetColor( 3, 0 );
	for( int y = 0; y < 20; y++ ){
		for( int x = 0; x < 60; x++ ){
			if ( x == 0 || x == 60 - 1 ){
				m_clsConsole->Draw( x, y, "┃" );
			}
			if ( y == 0 || y == 20 - 1 || y == 4 ){
				m_clsConsole->Draw( x, y, "━" );
				Sleep( 5 );
			}
			if ( y == 4 && x == 0 ){
				m_clsConsole->Draw( x, y, "┣" );
			}
			if ( y == 4 && x == 60 - 1 ){
				m_clsConsole->Draw( x, y, "┫" );
			}

			if ( x == 0 && y == 0 ){
				m_clsConsole->Draw( x, y, "┏" );
			} else if ( x == 0 && y == 20 - 1 ){
				m_clsConsole->Draw( x, y, "┗" );
			} else if ( x == 60 - 1 && y == 0 ){
				m_clsConsole->Draw( x, y, "┓" );
			} else if ( x == 60 - 1 && y == 20 - 1 ){
				m_clsConsole->Draw( x, y, "┛" );
			}
			Sleep( 1 );
		}
	}
}