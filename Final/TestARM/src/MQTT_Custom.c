/*
 * MQTT_Custom.c
 *
 *  Created on: 24 jan. 2023
 *      Author: bart
 */

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

#define ADDRESS     "tcp://test.mosquitto.org:1883"
#define CLIENTID    "Circutor"
#define QOS         1
#define TIMEOUT     10000L

// Used with paho mqtt library
MQTTClient client;
MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;
MQTTClient_message pubmsg = MQTTClient_message_initializer;
MQTTClient_deliveryToken token;


void MQTT_init()
{

	    int rc;


	    // Creating the mqtt client.
	    if ((rc = MQTTClient_create(&client, ADDRESS, CLIENTID,
	        MQTTCLIENT_PERSISTENCE_NONE, NULL)) != MQTTCLIENT_SUCCESS)
	    {
	         printf("Failed to create client, return code %d\n", rc);
	         exit(EXIT_FAILURE);
	    }

	    else
	    {
	    	printf("MQTT Client created.\n\n");
	    }

	    conn_opts.keepAliveInterval = 20;
	    conn_opts.cleansession = 1;


	    // Connecting to the mqtt broker.
	    if ((rc = MQTTClient_connect(client, &conn_opts)) != MQTTCLIENT_SUCCESS)
	    {
	        printf("Failed to connect, return code %d\n", rc);
	        exit(EXIT_FAILURE);
	    }
	    else
	    {
	    	printf("MQTT Client connected to the Mosquitto broker.\n\n");
	    }
}

void MQTT_SendMessage(struct mqtt *data)
{
	int rc;
    // Publish message
    pubmsg.payload = (char *) malloc(20);
    sprintf(pubmsg.payload, "%f", data->Payload);
    pubmsg.payloadlen = (int)strlen(pubmsg.payload);
    pubmsg.qos = QOS;
    pubmsg.retained = 0;
    if ((rc = MQTTClient_publishMessage(client, data->Topic, &pubmsg, &token)) != MQTTCLIENT_SUCCESS)
    {
         printf("Failed to publish message, return code %d\n", rc);
         exit(EXIT_FAILURE);
    }
    else
    {
    	printf("Message published.\n");
    }

    printf("Waiting for up to %d seconds for publication of %s\n"
            "on topic %s for client with ClientID: %s\n",
            (int)(TIMEOUT/1000), pubmsg.payload, data->Topic, CLIENTID);

    rc = MQTTClient_waitForCompletion(client, token, TIMEOUT);
    printf("Message with delivery token %d delivered.\n\n", token);
}
