#### MQTT Protocol - Password
```
// http://docs.oasis-open.org/mqtt/mqtt/v3.1.1/os/mqtt-v3.1.1-os.html#_Toc385349247
3.1.3.5 Password
If the Password Flag is set to 1, this is the next field in the payload. The Password field contains 0 to 65535 bytes of binary data prefixed with a two byte length field which indicates the number of bytes used by the binary data (it does not include the two bytes taken up by the length field itself).
```


#### An invalid UTF-8 string has been detected
[Source - paho.mqtt.c (mirror-gitee-dramalife)](https://gitee.com/Dramalife/tools_note/tree/master/paho.mqtt.c)  
```c
// paho.mqtt.c/src/utf-8.c
int UTF8_validateString(const char* string);


MQTTResponse MQTTClient_connectAll(MQTTClient handle, MQTTClient_connectOptions* options,
                MQTTProperties* connectProperties, MQTTProperties* willProperties);
// ...
if ((options->username && !UTF8_validateString(options->username)) ||
		(options->password && !UTF8_validateString(options->password)))	// ?????
// ...


/**
 * Return code: An invalid UTF-8 string has been detected.
 */
#define MQTTASYNC_BAD_UTF8_STRING -5


MQTTClient_connect
```
