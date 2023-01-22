/*
 * Modbus_Circutor_CVM_1D_Registers.h
 *
 *  Created on: 25 okt. 2022
 *      Author: bart
 */

#ifndef MODBUS_CIRCUTOR_CVM_1D_REGISTERS_H_
#define MODBUS_CIRCUTOR_CVM_1D_REGISTERS_H_

/*
 * We need to define the modbus device addresses in a array, we need also to define the addresses names in another array.
 */
static int Circutor_CVM_1D_Address = 0x01;

static int Registers_Circutor_CVM_1D[] = {
		0x0000, 0x0032, 0x0044,
		0x0002, 0x0034, 0x0046,
		0x0004, 0x0036, 0x0048,
		0x0006, 0x0038, 0x004A,
		0x0008, 0x003A, 0x004C,
		0x000A, 0x003C, 0x004E,
		0x000C, 0x003E, 0x0050,
		0x000E, 0x0040, 0x0052,
		0x0010, 0x0042, 0x0054,
		0x0012, 0x0014, 0x0016, 0x0018, 0x001A, 0x001C, 0x001E, 0x0020,
		0x0022, 0x0024, 0x0026, 0x0028, 0x002A, 0x002C, 0x002E, 0x0030

};

static char RegisterNames_Circutor_CVM_1D[][50] = {
		"Actual Voltage", "Maximum Voltage", "Minimum Voltage",
		"Actual Current", "Maximum Current", "Minimum Current",
		"Actual Active Power", "Maximum Active Power", "Minimum Active Power",
		"Actual Reactive Power", "Maximum Reactive Power", "Minimum Reactive Power",
		"Actual Inductive Reactive Power", "Maximum Inductive Reactive Power", "Minimum Inductive Reactive Power",
		"Actual Capacitive Inductive Power", "Maximum Capacitive Inductive Power", "Minimum Capacitive Inductive Power",
		"Actual Apparent power", "Maximum Apparent power", "Minimum Apparent power",
		"Actual Power Factor", "Maximum Power Factor", "Minimum Power Factor",
		"Actual Maximum Demand", "Maximum Maximum Demand", "Minimum Maximum Demand",
		"Active energy", "Inductive Reactive Energy", "Capacitive Reactive Energy", "Reactive Energy", "Partial Active Energy",
		"Partial Inductive Reactive Energy", "Partial Capacitive Reactive Energy", "Partial Reactive Energy", "Generated Active Energy",
		"Generated Inductive Reactive Energy", "Generated Capacitive Reactive Energy", "Generated Total Reactive Energy",
		"Partial Generated Active Energy", "Partial Generated Inductive Reactive Energy", "Generated Capacitive Reactive Energy",
		"Partial Generated Total Reactive Energy"
};


#endif /* MODBUS_CIRCUTOR_CVM_1D_REGISTERS_H_ */
