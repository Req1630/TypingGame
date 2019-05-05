#ifndef INPUT_H
#define INPUT_H

#include "Console.h"
#include "ProblemData.h"

class clsTyping
{
public:
	clsTyping();
	~clsTyping();

	void GameMain();

	void AnswerInput();
	void ProblemOutput();
	void AlphabetOutput();
	void Check();
	void ResultOut();
	void AllClear();

	void RestOut();
	void ProblemCntMaxInput();
	void UI();

private:
	const int INPUT_Y = 5;
	const int INPUT_X = 20;
	const int OUTPUT_X = INPUT_X;
	const int OUTPUT_Y = INPUT_Y - 3;

	const int ANSWER_OUT_X = 45;
	const int ANSWER_OUT_Y = 2;


	clsConsole*		m_clsConsole;
	clsProblemData*	m_clsProData;

	string m_sAnswer;

	int CorrectCnt;
	int RandomCnt;

	int ProbCntMax;
	int ProbCntNow;
	int ProbCnt;

};

#endif // #ifndef INPUT_H.
