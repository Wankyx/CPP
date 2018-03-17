#include <iostream>
#include <cstdio>
#include "scanning.hpp"

ScanningPixel::ScanningPixel(HDC deviceContext)
{
	this->setHandleToScan(deviceContext);
}

void ScanningPixel::setHandleToScan(HDC deviceContext)
{
	this->handleToScan = deviceContext;
}
HDC ScanningPixel::getHandleToScan()
{
	return this->handleToScan;
}

void ScanningPixel::setCursorPosition(LONG x, LONG y)
{
	this->cursor.x = x;
	this->cursor.y = y;
}
int ScanningPixel::getCursorPositionX()
{
	return this->cursor.x;
}
int ScanningPixel::getCursorPositionY()
{
	return this->cursor.y;
}

void ScanningPixel::getPixelColor(BYTE* r, BYTE* g, BYTE* b)
{
	*r = this->pixelColor.rgbtRed;
	*g = this->pixelColor.rgbtGreen;
	*b = this->pixelColor.rgbtBlue;
}
void ScanningPixel::setPixelColor(BYTE r, BYTE g, BYTE b)
{
	this->pixelColor.rgbtRed = r;
	this->pixelColor.rgbtGreen = g;
	this->pixelColor.rgbtBlue = b;
 }

void ScanningPixel::scan()
{
	BYTE red = 0;
	BYTE green = 0;
	BYTE blue = 0;

	while (!GetAsyncKeyState(VK_NUMPAD0))
	{
		GetCursorPos(&this->cursor);
		this->pointColor = GetPixel(this->getHandleToScan(), this->getCursorPositionX(), this->getCursorPositionY());

		this->setPixelColor(GetRValue(this->pointColor), GetGValue(this->pointColor), GetBValue(this->pointColor));

		this->getPixelColor(&red, &green, &blue);

		if (red == 255 && green < 15 && blue < 15)
		{
 			mouse_event(MOUSEEVENTF_LEFTDOWN, this->getCursorPositionX(), this->getCursorPositionY(), 0, 0);
			Sleep(10);
			mouse_event(MOUSEEVENTF_LEFTUP, this->getCursorPositionX(), this->getCursorPositionY(), 0, 0);

		}

		if (red <= 10 && green <= 10 && blue >= 130)
		{
			mouse_event(MOUSEEVENTF_LEFTDOWN, this->getCursorPositionX(), this->getCursorPositionY(), 0, 0);
			Sleep(10);
			mouse_event(MOUSEEVENTF_LEFTUP, this->getCursorPositionX(), this->getCursorPositionY(), 0, 0);
		}

		if (GetAsyncKeyState(VK_UP))
		{
			printf("(%d, %d, %d)\n", red,  green, blue);

			Sleep(1000);
		}

	}
}
