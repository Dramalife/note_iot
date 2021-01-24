[rtthread - 应用 AT 组件连接 ESP8266 模块](https://www.rt-thread.org/document/site/application-note/components/at/an0014-at-client/)
[新增串口](https://www.rt-thread.org/document/site/rtthread-studio/drivers/uart/v4.0.2/rtthread-studio-uart-v4.0.2/)  


#### 配置rtthread
components (组件)
Enable AT commands client

packages (软件包)
AT DEVICE (AT 设备)
乐鑫ESP8266


#### 新增串口 (WIFI - UART2)
board.h
```diff
+ #define BSP_USING_UART2
+ #define BSP_UART2_TX_PIN       "PA2"
+ #define BSP_UART2_RX_PIN       "PA3"
```

#### 配置WIFI (SSID, PASSWORD)
rtconfig.h
```
#define ESP8266_SAMPLE_WIFI_SSID "rtthread"
#define ESP8266_SAMPLE_WIFI_PASSWORD "12345678"
```


#### 异常 - wait AT client(uart2) connect timeout
描述:
msh />[E/at.clnt] wait AT client(uart2) connect timeout(5000 tick).
解决:
需要给ESP8266模块重启(代码配置)(手动插拔一下模组)


#### 验证WIFI联网功能
```
ping 8.8.8.8
32 bytes from 8.8.8.8 icmp_seq=3 time=203 ms
```
