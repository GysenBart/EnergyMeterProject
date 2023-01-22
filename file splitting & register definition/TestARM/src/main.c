//============================================================================
// Name        : TestARM.cpp
// Author      : Bart
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================




#include <ctype.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include "Serial.h"
#include "Modbus.h"
#include "Modbus_Circutor_CVM_1D_Registers.h"






int main (int argc, char *argv[])
{
    int fd;
    int error = 0;
    char serialdev[] = "/dev/ttyUSB0";

    puts(serialdev);
    puts ("Open port");

    fd = openserial(serialdev);

    if (!fd) {
        fprintf(stderr, "Error while initializing %s.\n", serialdev);
        return 1;
    }

    ReadAddress(fd, Circutor_CVM_1D_Address, Registers_Circutor_CVM_1D[1], 1);
    closeserial(fd);
    return 0;
}



