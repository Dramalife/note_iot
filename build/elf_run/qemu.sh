# 2020.10.10
#	Copy from : rt-thread/bsp/qemu-vexpress-a9/qemu.sh
#

if [ ! -f "sd.bin" ]; then
dd if=/dev/zero of=sd.bin bs=1024 count=65536
fi

# Origin
#qemu-system-arm -M vexpress-a9 -kernel rtthread.elf -serial stdio -sd sd.bin

# Dramalife
# ref : https://chuiwenchiu.wordpress.com/2014/12/10/qemu-could-not-initialize-sdlno-available-video-device-exiting/
qemu-system-arm -M vexpress-a9 -kernel rtthread.elf -serial stdio -sd sd.bin -curses 
