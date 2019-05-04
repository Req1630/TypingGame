#ifndef CONSOLE_H
#define CONSOLE_H

#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

class clsConsole
{
public:
	clsConsole();
	~clsConsole();
	enum class enColor
	{
		L_BLACK,	// ��P�x�E���F
		L_BLUE,		// ��P�x�E�F
		L_GREEN,	// ��P�x�E�ΐF
		L_CYAN,		// ��P�x�E���F
		L_RED,		// ��P�x�E�ԐF
		L_PURPLE,	// ��P�x�E���F
		L_YELLOW,	// ��P�x�E���F
		L_WHITE,	// ��P�x�E���F

		H_BLACK,	// ���P�x�E���F
		H_BLUE,		// ���P�x�E�F
		H_GREEN,	// ���P�x�E�ΐF
		H_CYAN,		// ���P�x�E���F
		H_RED,		// ���P�x�E�ԐF
		H_PURPLE,	// ���P�x�E���F
		H_YELLOW,	// ���P�x�E���F
		H_WHITE,	// ���P�x�E���F
	};
	void Draw( int x, int y, const char *c, bool isnewline = true );
	void Draw( int x, int y, const int value, bool isnewline = true );

	void Input( int x, int y, string *c );
	void Input( int x, int y, int *value );

	void SetColor( int fore, int back );

	void Clear( int x, int y, const char *c, enColor f = enColor::H_WHITE, enColor b = enColor::H_WHITE );

private:
	HANDLE m_hConStdOut;
};

#endif // #ifndef CONSOLE_H.