#include <iostream>
#include <Windows.h>
#include <cstdio>
#include "scan.hpp"
#include "process.hpp"

Scanner::Scanner()
{ 
 	this->desktopScreen = GetDC(HWND_DESKTOP);
}
void Scanner::scan()
{
	POINT cursor;

	while (!GetAsyncKeyState(VK_MENU))
	{
		RGBTRIPLE rgb;

		GetCursorPos(&cursor);
		this->rgb = GetPixel(this->desktopScreen, cursor.x, cursor.y);

		rgb.rgbtRed = GetRValue(this->rgb);
		rgb.rgbtGreen = GetGValue(this->rgb);
		rgb.rgbtBlue = GetBValue(this->rgb);
			/*
				trigger: 
			*/

		if (rgb.rgbtRed == 255 && rgb.rgbtGreen == 0 && rgb.rgbtBlue == 0)
		{
			printf("RGB (%d, %d, %d)\n", rgb.rgbtRed, rgb.rgbtGreen, rgb.rgbtBlue);

			std::cout << "Click" << std::endl;
			keybd_event(VK_LBUTTON, 0, MOUSEEVENTF_LEFTDOWN, 0);
			Sleep(30);
			keybd_event(VK_LBUTTON, 0, MOUSEEVENTF_LEFTUP, 0);
		}
			
		if (rgb.rgbtRed == 0 && rgb.rgbtGreen == 0 && rgb.rgbtBlue == 255)
		{
			printf("RGB (%d, %d, %d)\n", rgb.rgbtRed, rgb.rgbtGreen, rgb.rgbtBlue);

			std::cout << "Click" << std::endl;
			keybd_event(VK_LBUTTON, 0, MOUSEEVENTF_LEFTDOWN, 0);
			Sleep(30);
			keybd_event(VK_LBUTTON, 0, MOUSEEVENTF_LEFTUP, 0);
		}
	 
		Sleep(10);
	}
}
