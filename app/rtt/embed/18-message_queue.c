/*
 * [note_iot] "rt-thread Message Queue" related file
 * Copyright (C) 2019 Dramalife <dramalife@live.com>
 * 
 * This file is part of [note_iot](https://github.com/Dramalife/note_iot.git)
 * 
 * [note_iot] is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * Init : Wed Jan 20 14:14:22 CST 2021
 *  
 * Update
 *
 */


/****
 * 
 * 依赖
 * 	rtconfig.h 中打开 RT_USING_MESSAGEQUEUE;
 * 
 * 消息接收
 * 	自带mutex机制;
 * 
 * 
 * 消息发送
 * 	因为发送消息的环境可能是在中断中，不允许有阻塞的情况;
 * 	Message Queue满时，返回RT_EFULL;
 * 
 * 结构体
 * 	struct rt_messagequeue
 * 
 * API
 * 	创建消息队列   rt_mq_create
 * 	写队列操作函数 rt_mq_send
 * 	读队列操作函数 rt_mq_recv
 * 	删除队列       rt_mq_delete
 */


#include "board.h"
#include "rtthread.h"


/***
 * TESTs 
 */
/* RT_EFULL test enable */
#define DRAMALIFE_TEST_MQ_SEND_FULL	1



/* Default Value */
#define DL_SEND_INTERVAL	400	// send 2 msg each time
#define DL_RECV_INTERVAL	200	// recv 1 msg each time

/* Application */
#if DRAMALIFE_TEST_MQ_SEND_FULL
#define DL_SEND_INTERVAL	50
#define DL_RECV_INTERVAL	200
#endif


static rt_thread_t recv_thread = RT_NULL;
static rt_thread_t send_thread = RT_NULL;

static rt_mq_t fd_test_mq = RT_NULL;

static void recv_thread_entry(void *arg)
{
	rt_err_t ret = RT_EOK;
	uint32_t data_r_queue;

	while(1){

		/* Read Data from message queue */
		ret = rt_mq_recv(fd_test_mq,		/* fd of message queue */
				&data_r_queue,		/* buffer(mem) */
				sizeof(data_r_queue),	/* Length to read */
				RT_WAITING_FOREVER);	/* Timeout time : never */

		if( RT_EOK == ret ){
			rt_kprintf("Recv Data : %d\n", data_r_queue);
		}
		else{
			rt_kprintf("Recv ERR, 0x%1x\n", ret);
		}

		rt_thread_delay(DL_RECV_INTERVAL);

	}
}

static void send_thread_entry(void *arg)
{
	rt_err_t ret = RT_EOK;
	uint32_t send_data1 = __LINE__;
	uint32_t send_data2 = __LINE__;

	while(1){

		/* Send Data1 to message queue */
		ret = rt_mq_send(fd_test_mq,
				&send_data1,
				sizeof(send_data1));
		if(RT_EOK != ret){
			rt_kprintf("Send ERR, 0x%1x, reason:%s.\n", ret, ((-RT_EFULL)==ret)?"MQ full":"-");
		}

		/* Send Data2 to message queue */
		ret = rt_mq_send(fd_test_mq,
				&send_data2,
				sizeof(send_data2));
		if(RT_EOK != ret){
			rt_kprintf("Send ERR, 0x%1x, reason:%s.\n", ret, ((-RT_EFULL)==ret)?"MQ full":"-");
		}

		rt_thread_delay(DL_SEND_INTERVAL);
	}
}

int main(void)
{
	rt_kprintf("rt-thread Message Queue Sample Code!\n");

	/* Create Message Queue */
	fd_test_mq = rt_mq_create("fd_test_mq",	/* the name of message queue */
			40,                     /* the size of message */
			20,                     /* the maximum number of message in queue */
			RT_IPC_FLAG_FIFO);      /* the flag of message queue */
	if(RT_NULL != fd_test_mq){
		rt_kprintf("Message Queue created successfully!\n");
	}
	else{
		rt_kprintf("Message Queue created failed!\n");
	}

	/* Create Thread - recv */
	recv_thread = 
		rt_thread_create("dramalife_mq_recv_thread",
				recv_thread_entry,
				RT_NULL,
				512,
				3,
				20);
	if( RT_NULL != recv_thread ){
		rt_thread_startup(recv_thread);
	}
	else{
		return -1;
	}

	/* Create Thread - send */
	send_thread = 
		rt_thread_create("dramalife_mq_send_thread",
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

