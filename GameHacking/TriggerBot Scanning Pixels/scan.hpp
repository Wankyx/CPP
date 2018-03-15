#ifndef __SCAN__HPP__
#define __SCAN__HPP__ 
#include <Windows.h>

class Scanner
{
public:
	Scanner();



	void scan();
private:
 	RECT rectClientWindowSize;
	HDC desktopScreen;
	COLORREF rgb;
};

#endif