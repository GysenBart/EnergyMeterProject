/*
 * Serial.c
 *
 *  Created on: 25 okt. 2022
 *      Author: bart
 */


#include <unistd.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include "Serial.h"
#include "Modbus.h"

static struct termios oldterminfo;

void closeserial(int fd)
{
    tcsetattr(fd, TCSANOW, &oldterminfo);
    if (close(fd) < 0)
        perror("closeserial()");
}


int openserial(char *devicename)
{
    int fd;
    struct termios tty;

    if ((fd = open(devicename, O_RDWR | O_NOCTTY |O_NONBLOCK)) == -1)
    {
        perror("openserial(): open()");
        return 0;
    }

    if (tcgetattr(fd, &oldterminfo) == -1) {
        perror("openserial(): tcgetattr()");
        return 0;
    }

    tty = oldterminfo;

    cfsetospeed (&tty, B19200);
    cfsetispeed (&tty, B19200);

 //   tty.c_cflag = CSTOPB; // use 2 stop bits instead of 1
    tty.c_cflag = (tty.c_cflag & ~CSIZE) | CS8;     // 8-bit chars
    // disable IGNBRK for mismatched speed tests; otherwise receive break
    // as \000 chars
    tty.c_iflag &= ~IGNBRK;         // disable break processing
    tty.c_lflag = 0;                // no signaling chars, no echo,
                                    // no canonical processing
    tty.c_oflag = 0;                // no remapping, no delays
    tty.c_cc[VMIN]  = 0;            // read doesn't block
    tty.c_cc[VTIME] = 5;            // 0.5 seconds read timeout
    tty.c_iflag &= ~(IXON | IXOFF | IXANY); // shut off xon/xoff ctrl
    tty.c_cflag |= (CLOCAL | CREAD);// ignore modem controls,
                                    // enable reading
    tty.c_cflag &= ~(PARENB | PARODD);      // shut off parity
    tty.c_cflag &= ~CSTOPB;
    tty.c_cflag &= ~CRTSCTS;

        if (tcsetattr (fd, TCSANOW, &tty) != 0)
        {

                return 1;
        }

    return fd;
}


int setRTS(int fd, int level)
{
    int RTS_flag = TIOCM_RTS;

    if (level)
    {
         ioctl(fd,TIOCMBIS,&RTS_flag);
    }
    else
    {
         ioctl(fd,TIOCMBIC,&RTS_flag);
    }
    return 1;
}


int getCTS(int fd)
{
    int status;

    ioctl(fd, TIOCMGET, &status);

    return status & (TIOCM_CTS);
}
