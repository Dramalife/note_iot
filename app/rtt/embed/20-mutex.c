/*
 * [note_iot] "rt-thread Mutex" related file
 * Copyright (C) 2019 Dramalife <dramalife@live.com>
 * 
 * This file is part of [note_iot](https://github.com/Dramalife/note_iot.git)
 * 
 * [note_iot] is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * Init : Sun Feb  7 11:50:45 CST 2021
 * 	REF : [野火®]《RT-Thread 内核实现与应用开发实战—基于STM32》.pdf;
 *  
 * Update
 *
 */ 


/*
 * 互斥量又称互斥型信号量，是一种特殊的二值信号量，它和信号量不同的是，它支持
 * 互斥量所有权、递归访问以及防止优先级翻转的特性，用于实现对临界资源的独占式处理。
 */


// rt_mutex_create
// 使用 RT_IPC_FLAG_PRIO 优先级 flag 创建的 IPC 对象，在多个线程等
// 待资源时，将由优先级高的线程优先获得资源。而使用 RT_IPC_FLAG_FIFO 先进先出 flag
// 创建的 IPC 对象，在多个线程等待资源时，将按照先来先得的顺序获得资源
// #define RT_IPC_FLAG_FIFO                0x00            /**< FIFOed IPC. @ref IPC. */
// #define RT_IPC_FLAG_PRIO                0x01            /**< PRIOed IPC. @ref IPC. */

// rt_ipc_object_init



#include "board.h"
#include "rtthread.h"

static rt_thread_t recv_thread = RT_NULL;
static rt_thread_t send_thread = RT_NULL;

static rt_mutex_t mtx_test = RT_NULL;

static int data_test[2] = {0};


static void recv_thread_entry(void *arg)
{
	while(1){

		rt_mutex_take(mtx_test, RT_WAITING_FOREVER);

		if( data_test[0] == data_test[1] ){
			rt_kprintf("[ok] eq!\n");
		}
		else{
			rt_kprintf("[err] ne!\n");
		}

		rt_mutex_release(mtx_test);

		rt_thread_delay(1000);
	}

	return;
}

static void send_thread_entry(void *arg)
{
	while(1){

		rt_mutex_take(mtx_test, RT_WAITING_FOREVER);

		data_test[0]++;
		rt_thread_delay(1000);
		data_test[1]++;

		rt_mutex_release(mtx_test);

		rt_thread_yield();

	}
}


int main(void)
{
	rt_kprintf("Mutex test!\n");


	/* Create Mutex */
	mtx_test = rt_mutex_create("mtx_test", RT_IPC_FLAG_PRIO);

	if( RT_NULL != mtx_test ){
		rt_kprintf("Mutex created successfully!\n");
	}


	/* Create Thread - recv */
	recv_thread = rt_thread_create(
			"dlt_recv",
			recv_thread_entry,
			RT_NULL,
			512,
			3,
			20
			);

	if(RT_NULL != recv_thread){
		rt_thread_startup(recv_thread);
	}
	else{
		return -1;
	}


	/* Create Thread - send */
	send_thread = rt_thread_create(
			"dlt_send",
			send_thread_entry,
			RT_NULL,
			512,
			2,
			20
			);

	if(RT_NULL != send_thread){
		rt_thread_startup(send_thread);
	}
	else{
		return -1;
	}

}

