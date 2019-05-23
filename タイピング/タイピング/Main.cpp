#include "Main.h"
#include "Typing.h"

int main()
{
	clsTyping*	pclsTyping;
	pclsTyping = new clsTyping();
   //あ
	pclsTyping->GameMain();

	delete pclsTyping;

	return 0;
}