/*
 * GraphicalGUI.h
 *
 *  Created on: 12.1.2017
 *      Author: Saana Vallius
 */

#ifndef GRAPHICALUI_H_
#define GRAPHICALUI_H_
#include "LiquidCrystal.h"

class GraphicalUI {
public:
	GraphicalUI();
	virtual ~GraphicalUI();
	void print_auto();
	void print_error();
	void print_man();
	void update_values(int setPressure, int realPressure, int setFanspeed);

private:
	int setPressure;
	int realPressure;
	int setFanSpeed;
	LiquidCrystal *lcd;
	DigitalIoPin pin_rs; //register select
	DigitalIoPin pin_en; //enable
	DigitalIoPin pin_d0;
	DigitalIoPin pin_d1;
	DigitalIoPin pin_d2;
	DigitalIoPin pin_d3;
};

#endif /* GRAPHICALUI_H_ */
