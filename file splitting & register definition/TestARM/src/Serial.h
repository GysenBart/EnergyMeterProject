/*
 * Serial.h
 *
 *  Created on: 25 okt. 2022
 *      Author: bart
 */

#ifndef SERIAL_H_
#define SERIAL_H_

void closeserial(int fd);
int openserial(char *devicename);
int setRTS(int fd, int level);
int getCTS(int fd);


#endif /* SERIAL_H_ */
