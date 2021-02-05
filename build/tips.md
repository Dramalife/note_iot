## RT-Thread

### lts-v3.1.x
#### error: unknown type name 'fd_set'
rtconfig.h
```diff
+ #define HAVE_SYS_SELECT_H
```

#### error: conflicting types for 'pthread_kill'
```
# avoid ;-(
RT-Thread Components  --->
	POSIX layer and C standard library  --->
		[ ] Enable pthreads APIs
```

#### Dependents
```bash
apt install gcc-arm-none-eabi
apt install scons
apt-get install libncurses5-dev
```


## FreeRTOS

