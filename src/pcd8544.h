#pragma once

#include <vector>
#include "Rect.h"
#include "Color.h"

class pcd8544 {

public:
	pcd8544();
	void test();
	void setBrightness(unsigned char lightLevel);

	void adressSet( int x, int y, int w, int h);
	void writeToBuffer(const Rect &rect, unsigned char *writeBuffer);
	void shutdown();
	static const unsigned char ROWS = 6;
	static const unsigned char COLUMNS = 14;
	static const unsigned char PIXELS_PER_ROW = 6;
private:

	void gotoxy(int x, int y);
	void gotorc(int r, int c);
	void LCD_Write_DATA(unsigned char *data, int size);
	void LCD_Write_COM(unsigned char *com, int size);


	static const unsigned char DC   = 4;// # gpio pin 16 = wiringpi no. 4 (BCM 23)
	static const unsigned char RST  = 5;// # gpio pin 18 = wiringpi no. 5 (BCM 24)
	static const unsigned char LED  = 1;// # gpio pin 12 = wiringpi no. 1 (BCM 18)

	//# SPI connection, these are only for documentation...
	static const unsigned char SCE  = 10;// # gpio pin 24 = wiringpi no. 10 (CE0 BCM 8) 
	static const unsigned char SCLK = 14;// # gpio pin 23 = wiringpi no. 14 (SCLK BCM 11)
	static const unsigned char DIN  = 12;// # gpio pin 19 = wiringpi no. 12 (MOSI BCM 10)

	static const int spiChannel = 0;
	static const int spiSpeed = 4000000;

};


