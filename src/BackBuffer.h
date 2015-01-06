#pragma once

#include <vector>
#include "Rect.h"
#include "Color.h"
#include "pcd8544.h"


class BackBuffer {
public:
	BackBuffer(pcd8544 &lcd);
	void clearScreen();
	void fillBox(const Rect &screen, const Color &fill);
	void flush();
private:
	static const int buffersize = pcd8544::WIDTH*pcd8544::HEIGHT*2; //two bytes per pixel
	std::vector<Rect> dirtyRects;
	unsigned char backBuffer[pcd8544::WIDTH][pcd8544::HEIGHT][2];
	unsigned char writeBuffer[buffersize];
	pcd8544 &screen;
};
