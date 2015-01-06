#pragma once

#include <vector>
#include "Rect.h"
#include "Color.h"
#include "pcd8544.h"


class BackBuffer {
public:
	BackBuffer(pcd8544 &lcd);

	unsigned char* getData();

	unsigned char _BV(int v);

	bool getPixel(int x, int y);

	void setPixel(int x, int y, bool value);

	//84x48
	int getHeight() {
		return 48;
	}

	int getWidth() {
		return 84;
	}
private:
	unsigned char *data;
	unsigned char rows;
	unsigned char columns;
	unsigned char pixelsPerRow;
	pcd8544 &lcd;
};
