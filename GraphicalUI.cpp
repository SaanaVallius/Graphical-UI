/*
 * GraphicalUI.cpp
 *
 *  Created on: 12.1.2017
 *      Author: Saana Vallius
 */

#include "GraphicalUI.h"
#include "DigitalIoPin.h"
#include "LiquidCrystal.h"
#include <cstdio>

GraphicalUI::GraphicalUI() :
		pin_rs(0, 8, DigitalIoPin::output),
		pin_en(1, 6, DigitalIoPin::output),
		pin_d0(1, 8, DigitalIoPin::output),
		pin_d1(0, 5, DigitalIoPin::output),
		pin_d2(0, 6, DigitalIoPin::output),
		pin_d3(0, 7, DigitalIoPin::output) {
		lcd = new LiquidCrystal(&pin_rs, &pin_en, &pin_d0, &pin_d1, &pin_d2, &pin_d3);
		setPressure = 0;
		realPressure = 0;
		setFanSpeed = 0;
}

GraphicalUI::~GraphicalUI() {
	// TODO Auto-generated destructor stub
}

void GraphicalUI::print_man() {
	char buffer[64];

	//print first row
	lcd->setCursor(0, 0); //(column, row)
	sprintf(buffer, " FAN: %3d%%   MAN", setFanSpeed);
	lcd->print(buffer);

	//print second row
	lcd->setCursor(0, 1); //(column, row)
	sprintf(buffer, "REAL: %3dPa      ", realPressure);
	lcd->print(buffer);
}

void GraphicalUI::print_auto() {
	char buffer[64];

	//print first row
	lcd->setCursor(0, 0); //(column, row)
	sprintf(buffer, " SET:%3dPa  AUTO", setPressure);
	//sprintf(buffer, "blah");
	lcd->print(buffer);

	//print second row
	lcd->setCursor(0, 1); //(column, row)
	sprintf(buffer, "REAL:%3dPa      ", realPressure);
	lcd->print(buffer);
}

void GraphicalUI::print_error() {
	char buffer[64];

	//print first row
	lcd->setCursor(0, 0); //(column, row)
	sprintf(buffer, " SET:%3dPa  AUTO", setPressure);
	lcd->print(buffer);

	//print second row
	lcd->setCursor(0, 1); //(column, row)
	sprintf(buffer, "REAL:%3dPa ERROR", realPressure);
	lcd->print(buffer);
}

void GraphicalUI::update_values(int iSetPressure, int iRealPressure, int iSetFanSpeed) {
	//setPressure is the pressure set by the user
	//realPressure is the measured pressure
	//setFanSpeed is the fan speed set by the user
	setPressure = iSetPressure;
	realPressure = iRealPressure;
	setFanSpeed = iSetFanSpeed;
}
