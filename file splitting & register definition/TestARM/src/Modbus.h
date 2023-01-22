/*
 * Modbus.h
 *
 *  Created on: 25 okt. 2022
 *      Author: bart
 */

#ifndef MODBUS_H_
#define MODBUS_H_

unsigned short CRC16 (unsigned char* puchMsg, unsigned short usDataLen );
void ReadAddress(int l_fd, unsigned char l_slaveaddress, unsigned int l_address, unsigned char l_debug);


#endif /* MODBUS_H_ */
