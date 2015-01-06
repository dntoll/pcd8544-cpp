#include "BackBuffer.h"
#include <iostream>


using namespace std;

BackBuffer::BackBuffer(pcd8544 &a_lcd) : lcd(a_lcd) {
	int sizeInBytes = lcd.ROWS * lcd.COLUMNS * lcd.PIXELS_PER_ROW;
	data = new unsigned char[sizeInBytes];

	for(int i = 0;i < sizeInBytes; i++)
		data[i] = (unsigned char) 0x00;
}

unsigned char* BackBuffer::getData() {
	return data;
}

unsigned char BackBuffer::_BV(int v) {
	return (unsigned char) (1 << v);
}

bool BackBuffer::getPixel(int x, int y) {
	return (data[x+ (y/8)*getWidth()] & _BV(y%8)) == 0;
}

void BackBuffer::setPixel(int x, int y, bool value) {
	//https://github.com/adafruit/Adafruit-PCD8544-Nokia-5110-LCD-library/blob/master/Adafruit_PCD8544.cpp
	if (x >= 0 && x < getWidth() && y >= 0 && y < getHeight()) {
		if (value)
			data[x+ (y/8)*getWidth()] |= _BV(y%8);
		  else
			data[x+ (y/8)*getWidth()] &= ~_BV(y%8);
	}
}
