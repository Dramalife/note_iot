#### MQTTClient_connect - Failed to connect, return code -5
/src/mqtt_client.c,main_mqtt,99 :Failed to connect, return code -5
```c
if ((rc = MQTTClient_connect(client, &conn_opts)) != MQTTCLIENT_SUCCESS)
{   
	printf("Failed to connect, return code %d\n", rc);                                                                                                                   
	rc = EXIT_FAILURE;
	goto destroy_exit;
} 
```
```c
/**             
 * Return code: An invalid UTF-8 string has been detected.
 */             
#define MQTTCLIENT_BAD_UTF8_STRING -5
```
./paho.mqtt.c/src/MQTTClient.c
Func : MQTTClient_connectAll
```diff
-if ((options->username && !UTF8_validateString(options->username)) ||
-		(options->password && !UTF8_validateString(options->password)))
+if ((options->username && !UTF8_validateString(options->username)) /*||
+		(options->password && !UTF8_validateString(options->password))*/)
{    
	rc.reasonCode = MQTTCLIENT_BAD_UTF8_STRING;
	goto exit;
}  
```
