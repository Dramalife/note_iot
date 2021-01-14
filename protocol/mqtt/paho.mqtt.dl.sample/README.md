### Doc
```bash
make html

ls paho.mqtt.c/build/output/doc/MQTTClient/html/index.html
```


### RETURN VALUE
```c
/**
  * This function attempts to connect a previously-created client (see
  * MQTTClient_create()) to an MQTT server using the specified options. If you
  * want to enable asynchronous message and status notifications, you must call
  * MQTTClient_setCallbacks() prior to MQTTClient_connect().
  * @param handle A valid client handle from a successful call to
  * MQTTClient_create().
  * @param options A pointer to a valid MQTTClient_connectOptions
  * structure.
  * @return ::MQTTCLIENT_SUCCESS if the client successfully connects to the
  * server. An error code is returned if the client was unable to connect to
  * the server.
  * Error codes greater than 0 are returned by the MQTT protocol:<br><br>
  * <b>1</b>: Connection refused: Unacceptable protocol version<br>
  * <b>2</b>: Connection refused: Identifier rejected<br>
  * <b>3</b>: Connection refused: Server unavailable<br>
  * <b>4</b>: Connection refused: Bad user name or password<br>
  * <b>5</b>: Connection refused: Not authorized<br>
  * <b>6-255</b>: Reserved for future use<br>
  */
LIBMQTT_API int MQTTClient_connect(MQTTClient handle, MQTTClient_connectOptions* options);
```

