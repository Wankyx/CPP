#ifndef __SCANNING__HPP__ 

#include <Windows.h>

class ScanningPixel
{
public:
	ScanningPixel(HDC deviceContext);

	void setHandleToScan(HDC deviceContext);
	HDC getHandleToScan();

	void setCursorPosition(LONG x, LONG y);
	int getCursorPositionX();
	int getCursorPositionY();

	void getPixelColor(BYTE* r, BYTE* g, BYTE* b);
	void setPixelColor(BYTE r, BYTE g, BYTE b);

	void scan();
private:
	HDC handleToScan;
	POINT cursor;
	RGBTRIPLE pixelColor;
	COLORREF pointColor;

};



#endif 