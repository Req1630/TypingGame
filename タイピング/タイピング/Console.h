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
		L_BLACK,	// 低輝度・黒色
		L_BLUE,		// 低輝度・青色
		L_GREEN,	// 低輝度・緑色
		L_CYAN,		// 低輝度・水色
		L_RED,		// 低輝度・赤色
		L_PURPLE,	// 低輝度・紫色
		L_YELLOW,	// 低輝度・黄色
		L_WHITE,	// 低輝度・白色

		H_BLACK,	// 高輝度・黒色
		H_BLUE,		// 高輝度・青色
		H_GREEN,	// 高輝度・緑色
		H_CYAN,		// 高輝度・水色
		H_RED,		// 高輝度・赤色
		H_PURPLE,	// 高輝度・紫色
		H_YELLOW,	// 高輝度・黄色
		H_WHITE,	// 高輝度・白色
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