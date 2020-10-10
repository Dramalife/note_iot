//#include "yc3121.h"
//#include "yc_gpio.h"
//#include "yc_uart.h"
//#include "yc_ipc.h"
//#include "yc_timer.h"
//#include "misc.h"
//#include "shell.h"
#include "rtthread.h"

//#define printf	MyPrintf

ALIGN(RT_ALIGN_SIZE);

static rt_uint8_t 
thread_stack_dl_sample_led1[1024];

static struct rt_thread 
thread_fd_dl_sample_led1;

static void thread_func_dl_sample_led1(void *param)
{

	while(1)
	{
		printf("%s,%d\n",__func__,__LINE__);
		rt_thread_mdelay(3000);
	}
}


#if 0
#define DL_DEF_RTT_FUNC(f,c) 	\
	do{ \
		ALIGN(RT_ALIGN_SIZE);	\
		static rt_uint8_t stack_[1024];	\
		static struct rt_thread 	\
		fd_;	\
		static void 	\
		f(void *param)##c	\
		rt_thread_init(	\
				&fd_,	\
				"tname_led",	\
				f,	\
				RT_NULL,	\
				&stack_[0],	\
				sizeof(stack_),	\
				3,	\
				20);	\
		rt_thread_startup(&fd_);	\
		while(0)
#endif



#define DLRTT_DEFFUNC(f, fd_, stack_, size_stack)	\
		ALIGN(RT_ALIGN_SIZE);	\
		static rt_uint8_t stack_[size_stack];	\
		static struct rt_thread 	\
		fd_;	\
		static void 	\
		f(void *param)

#define DLRTT_INITFUNC(f, fd_,stack_, name, param)	do{ \
	rt_thread_init(	\
			&fd_,	\
			name,	\
			f,	\
			param,	\
			&stack_[0],	\
			sizeof(stack_),	\
			3,	\
			20);	\
	rt_thread_startup(&fd_);	\
}while(0)


DLRTT_DEFFUNC(fhaha, fdhaha, stackhaah, 1024)
{
	while(1)
	{
		printf("%s,%d\n",__func__,__LINE__);
		rt_thread_mdelay(1000);
	}
}

DLRTT_DEFFUNC(fhaha2, fdhaha2, stackhaah2, 1024)
{
	while(1)
	{
		printf("%s,%d\n",__func__,__LINE__);
		rt_thread_mdelay(2000);
	}
}

#define DLRTT_INITFUNC_ALL()	do{ \
	DLRTT_INITFUNC(fhaha, fdhaha, stackhaah, "haha", RT_NULL);	\
	DLRTT_INITFUNC(fhaha2, fdhaha2, stackhaah2, "haha2", RT_NULL);	\
}while(0)

/*
 * Usage :
 * 	In main() : 
 *		extern void test_dl(void);
 *		test_dl();
 *		return 0;
 */
void test_dl(void)
{
	rt_thread_init(
			&thread_fd_dl_sample_led1,
			"tname_led",
			thread_func_dl_sample_led1,
			RT_NULL,
			&thread_stack_dl_sample_led1[0],
			sizeof(thread_stack_dl_sample_led1),
			3,
			20);
	rt_thread_startup(&thread_fd_dl_sample_led1);

#if 0
	DLRTT_INITFUNC(fhaha, fdhaha, stackhaah, "haha", RT_NULL);
	DLRTT_INITFUNC(fhaha2, fdhaha2, stackhaah2, "haha2", RT_NULL);
#else
	DLRTT_INITFUNC_ALL();
#endif

}

