#ifndef _CONFIG_MQTT_DL_H_
#define _CONFIG_MQTT_DL_H_


#define ADDRESS     "tcp://183.230.40.39:6002"
#define CLIENTID    	argv[2]
#define USERNAME	argv[1]
#define PASSWORD	argv[3]


//#define TOPIC       "dlmqtt"
#define TOPIC       "prompt"
//#define TOPIC       "$dp"
#define PAYLOAD     "{\"prompt\":haha}"
#define QOS         1
#define TIMEOUT     10000L

#define printf(f,...)	do{printf("%s,%s,%d :",__FILE__,__func__,__LINE__);printf(f,##__VA_ARGS__);}while(0)
//#define printf(f,...)	do{printf("[%s,%d] : ",__func__,__LINE__);printf(f,##__VA_ARGS__);}while(0)

#endif

