#include <iostream>

#include "process.hpp"
#include "scanning.hpp"

int main()
{
	Process processGame{"Counter-Strike Source"};
 	ScanningPixel scanPixel{GetDC(HWND_DESKTOP)};

	processGame.shownProcessInfo();
	scanPixel.scan();
	return 0;
}