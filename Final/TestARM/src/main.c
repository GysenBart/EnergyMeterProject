//============================================================================
// Name        : TestARM.c
// Author      : Bart
// Version     :
// Copyright   : Your copyright notice
// Description : Energiemeter to cloud
//============================================================================


#include <ctype.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include "Serial.h"
#include "Modbus.h"
#include "Modbus_Circutor_CVM_1D_Registers.h"
#include "MQTTClient.h"
#include "MQTT_Custom.h"




int main (int argc, char *argv[])
{
	// In this struct we put al the modbus data that we want to send through mqtt.
	struct mqtt mqttdata;
	// Topic part one we will always use in every topic because it is a part of the energy meter.
	strcpy(mqttdata.TopicPartOne, "ProjectenVoorHetWerkveld/CircutorEnergyMeter/");
	// Used for the serial connection.
    int fd;
    char serialdev[] = "/dev/ttyUSB0";

    int unit_state = VOLTAGE;

    MQTT_init();


    while(1)
    {
        // Open the serial port, read the modbus data and close the serial port.
        fd = openserial(serialdev);

        if (!fd)
        {
            fprintf(stderr, "Error while initializing %s.\n", serialdev);
        }

        switch(unit_state)
        {
        case VOLTAGE:
            Readmodbus_CircutorData_MqttTopicPayload(VOLTAGE, fd, &mqttdata);
            MQTT_SendMessage(&mqttdata);
            unit_state = CURRENT;
            sleep(2);
            break;

        case CURRENT:
            Readmodbus_CircutorData_MqttTopicPayload(CURRENT, fd, &mqttdata);
            MQTT_SendMessage(&mqttdata);
            unit_state = ACTIVEPOWER;
            sleep(2);
            break;

        case ACTIVEPOWER:
            Readmodbus_CircutorData_MqttTopicPayload(ACTIVEPOWER, fd, &mqttdata);
            MQTT_SendMessage(&mqttdata);
            unit_state = ACTIVEENERGIE;
            sleep(2);
            break;

        case ACTIVEENERGIE:
            Readmodbus_CircutorData_MqttTopicPayload(ACTIVEENERGIE, fd, &mqttdata);
            MQTT_SendMessage(&mqttdata);
            unit_state = VOLTAGE;
            sleep(2);
            break;

        }


        closeserial(fd);

    }
}



