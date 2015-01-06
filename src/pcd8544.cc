#include "pcd8544.h"
#include <unistd.h>
#include <stdio.h>      /* printf, fopen */
#include <stdlib.h>     /* exit, EXIT_FAILURE */
#include <wiringPiSPI.h>
#include <wiringPi.h>

#include <iostream>


using namespace std;

pcd8544::pcd8544() {
	int fileDescriptor = wiringPiSPISetup(spiChannel, spiSpeed);
	if (fileDescriptor <= -1) {
		 printf ("Error wiringPiSPISetup");
		 exit(EXIT_FAILURE);
	}
	wiringPiSetup();
	pinMode(RST, OUTPUT);
	pinMode(DC, OUTPUT);
	if (LED == 1) {
		pinMode(LED, PWM_OUTPUT);
	} else {
		pinMode(LED, OUTPUT);
	}

	digitalWrite(RST, 0);
	usleep(11000);
	digitalWrite(RST, 1);

	setBrightness(0);

	unsigned char command[] = {0x21, 0x14, 0x20, 0x20, 0x0c};
	LCD_Write_COM(command, 5);

        

}

void pcd8544::setBrightness(unsigned char led_value) {
	if ( LED == 1) {
		if (0 <= led_value && led_value < 1023) {
			pwmWrite(LED, led_value);
		}
	} else {
		if (led_value == 0)
			digitalWrite(LED, 0);
		else
			digitalWrite(LED, 1);
	}
	sleep(1);
	
}

void pcd8544::shutdown() {
	setBrightness(0);
}

void pcd8544::test() {
	gotoxy(0,0);

	unsigned char *data = new unsigned char[ROWS * COLUMNS * PIXELS_PER_ROW];
	for (int i = 0; i < ROWS * COLUMNS * PIXELS_PER_ROW; i++) {
		data[i] = 128;
	}

	LCD_Write_DATA(data, ROWS * COLUMNS * PIXELS_PER_ROW);

	delete[] data;

}

void pcd8544::LCD_Write_DATA(unsigned char *data, int size) {
	digitalWrite(DC, 1);
	if (wiringPiSPIDataRW(spiChannel, data, size) == -1) {
		printf("SPI failed lcd_data");
	}
	
}

void pcd8544::LCD_Write_COM(unsigned char *com, int size) {
	digitalWrite(DC, 0);
	if (wiringPiSPIDataRW(spiChannel, com, size) == -1) {
		printf("SPI failed lcd_cmd");
	}
}


void pcd8544::gotorc(int r, int c) {
	gotoxy(c*ROWS, r);
}
void pcd8544::gotoxy(int x, int y) {
	if ( (0 <= x && x < COLUMNS) && (0 <= y && y < ROWS)) {

		unsigned char command[] = {(unsigned char) (x+128), (unsigned char) (y + 64) };
		LCD_Write_COM(command, 2);
	}
}


