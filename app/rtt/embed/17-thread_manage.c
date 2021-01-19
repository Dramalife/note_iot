/*
 * [note_iot] "rt-thread thread creation" related file
 * Copyright (C) 2019 Dramalife <dramalife@live.com>
 * 
 * This file is part of [note_iot](https://github.com/Dramalife/note_iot.git)
 * 
 * [note_iot] is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * Init : Tue Jan 19 17:20:01 CST 2021
 * 	REF : 《[野火®]《RT-Thread 内核实现与应用开发实战—基于STM32》.pdf》;
 *  
 * Update
 *
 */



#include "board.h"
#include "rtthread.h"


#define PRINT_INTERVAL_TICK_LED	500
#define PRINT_INTERVAL_TICK_KEY	800


static rt_thread_t led1_thread = RT_NULL;
static rt_thread_t key_thread = RT_NULL;



static void led1_thread_entry(void *arg)
{
	while (1){
		rt_thread_delay(PRINT_INTERVAL_TICK_LED);
		rt_kprintf("LED ON\n");

		rt_thread_delay(PRINT_INTERVAL_TICK_LED);
		rt_kprintf("LED OFF\n");
	}
}

static void key_thread_entry(void *arg)
{
	while (1){
		rt_thread_delay(PRINT_INTERVAL_TICK_KEY);
		rt_kprintf("KEY PRESS\n");

		rt_thread_delay(PRINT_INTERVAL_TICK_KEY);
		rt_kprintf("KEY RELEASE\n");
	}
}

int main(void)
{
	rt_kprintf("%s,%d ::::: rtthread thread manage sample!\n",__func__,__LINE__);

	if( RT_NULL != 
			(led1_thread = rt_thread_create(
							"led1",
							led1_thread_entry,
							RT_NULL,
							512,
							3,
							20
						       ))
	  ){
		rt_thread_startup(led1_thread);
	}
	else{
		return -1;
	}

	if( RT_NULL !=
			(key_thread = rt_thread_create(
						       "key",
						       key_thread_entry,
						       RT_NULL,
						       512,
						       2,
						       20
						      ))
	  ){
		rt_thread_startup(key_thread);
	}
	else{
		return -1;
	}

}

