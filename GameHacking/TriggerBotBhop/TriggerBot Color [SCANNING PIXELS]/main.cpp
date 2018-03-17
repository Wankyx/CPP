#include <iostream>

#include "process.hpp"
#include "scanning.hpp"

static Process processGame{ "Counter-Strike Source" };


DWORD WINAPI ThreadBhop(void* arg)
{
	DWORD client = processGame.attachModule("client.dll");
	DWORD dwJump = 0x4F3B3C;

	DWORD address = client + dwJump;
	DWORD val = 0;
	while (!GetAsyncKeyState(VK_NUMPAD0))
	{

		if (GetAsyncKeyState(VK_SPACE))
		{
			val = 6;
 			processGame.processWPM(address, &val);
			Sleep(10);
 		}
		Sleep(15);
  	}
	return 0;
}

int main()
{
  	ScanningPixel scanPixel{GetDC(HWND_DESKTOP)};	 
	HANDLE bhop = CreateThread(nullptr, 0, ThreadBhop, nullptr, 0, nullptr);

	processGame.shownProcessInfo();
	scanPixel.scan();
	return 0;
}