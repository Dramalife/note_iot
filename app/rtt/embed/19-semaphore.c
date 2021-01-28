/*
 * [note_iot] "rt-thread Semaphore" related file
 * Copyright (C) 2019 Dramalife <dramalife@live.com>
 * 
 * This file is part of [note_iot](https://github.com/Dramalife/note_iot.git)
 * 
 * [note_iot] is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * Init : Tue Jan 26 23:10:15 CST 2021
 * 	REF : [野火®]《RT-Thread 内核实现与应用开发实战—基于STM32》.pdf;
 *  
 * Update
 *
 */ 


/****
 * 信号量（Semaphore）是一种实现线程间通信的机制，实现线程之间同步或临界资源的
 * 互斥访问，常用于协助一组相互竞争的线程来访问临界资源。
 *
 * 场景：互斥、同步；
 *
 * 用作互斥时，有可能产生优先级翻转
 *
 * 二值信号量 - 同步
 * 传感器采集周期 大于 显示器刷新周期时，显示器可等待数据更新后再刷新
 * 串口数据处理线程，没有数据时挂起，数据到达时在串口中断释放信号量；
 *
 *
 * struct rt_semaphore;
 *
 * 信号量创建函数 rt_sem_create()
 * 信号量删除函数 rt_sem_delete()
 * 信号量释放函数 rt_sem_release()
 * 信号量获取函数 rt_sem_take()
 */




#include "board.h"
#include "rtthread.h"



static rt_thread_t recv_thread = RT_NULL;
static rt_thread_t send_thread = RT_NULL;

static rt_sem_t sem_sync = RT_NULL;

uint8_t ga_test [2] = {0};	// global array


static void recv_thread_entry(void *arg)
{
	while(1){

		rt_sem_take(sem_sync, RT_WAITING_FOREVER);

		if( ga_test[0] == ga_test[1] ){
			rt_kprintf("Sync successfully! \n");
		}
		else{
			rt_kprintf("Sync failed! \n");
		}

		rt_sem_release(sem_sync);

		rt_thread_delay(1000);
	}

	return;
}

static void send_thread_entry(void *arg)
{
	while(1){

		rt_sem_take(sem_sync, RT_WAITING_FOREVER);

		ga_test[0]++;
		rt_thread_delay(100);
		ga_test[1]++;

		rt_sem_release(sem_sync);

		rt_thread_yield();
	}

	return;
}

int main(void)
{
	rt_kprintf("rt-thread Semaphore test!\n");

	/* Create a semaphore */
	sem_sync = rt_sem_create("DL_SEM_SYNC",	// the name of semaphore
			1,                  	// the initial value of semaphore
			RT_IPC_FLAG_FIFO);  	// the flag of semaphore

	if( RT_NULL != sem_sync ){
		rt_kprintf("Create semaphore successfully! \n\n");
	}


	recv_thread = rt_thread_create("DL_RECV",	// name the name of thread, which shall be unique
			recv_thread_entry,              // entry the entry function of thread
			RT_NULL,                        // parameter the parameter of thread enter function
			512,                            // stack_size the size of thread stack
			3,                              // priority the priority of thread
			20);                            // tick the time slice if there are same priority thread
	if( RT_NULL != recv_thread ){
		rt_thread_startup(recv_thread);
	}
	else{
		return -1;
	}

	send_thread = rt_thread_create("DL_SEND",
			send_thread_entry,
			RT_NULL,
			512,
			2,
			20);
	if( RT_NULL != send_thread ){
		rt_thread_startup(send_thread);
	}
	else{
		return -1;
	}

	return 0;
}
