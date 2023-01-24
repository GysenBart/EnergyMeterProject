//============================================================================
// Name        : TestARM.cpp
// Author      : Bart
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

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

    cfsetospeed (&tty, B115200);
    cfsetispeed (&tty, B115200);

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

/*    if (serialdev[11] != '7')
    {
        puts ("Set RTS low");
        setRTS(fd, 0);
        puts ("Check CTS");
        if(getCTS(fd))
        {
            puts("RTS/CTS test 1 FAILED");
            error = 1;
        }

        puts ("set RTS high");
        setRTS(fd, 1);

        puts ("check CTS");
        if(!getCTS(fd))
        {
            puts("RTS/CTS test 2 FAILED");
            error = 1;
        }
    }
    else
    {
       puts("Skipping RTS/CTS for payter");
    }
*/

    puts("Send data over TX");
    unsigned char msg[] = {"Data RX/TX test passed"};
    write(fd, msg, sizeof(msg));

    puts ("wait 1 second");
    sleep (1);

    puts("Read data from RX buffer");
    char read_buf [256];
    int n = read(fd, &read_buf, sizeof(read_buf));

    puts("Bytes recieved:");
    puts(read_buf);

    puts("Compare RX with TX data");

    if (memcmp(read_buf, "Data RX/TX test passed", 22))
    {
        error = 1;
        puts ("Data RX/TX test FAILED");
    }

    if (error)
    {
        puts("*********** SERAIL PORT TEST FAILED *****************");
    }
    else
    {
        puts("serial port OK");
    }

    closeserial(fd);
    return 0;
}



