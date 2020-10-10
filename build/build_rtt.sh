#! /bin/bash
#
# https://github.com/Dramalife/note_RTOS.git
# Dramalife@live.com
#
# Ref url : https://www.rt-thread.org/document/site/application-note/setup/qemu/ubuntu/an0005-qemu-ubuntu/
#


# Variables
RTT_REPO=rt-thread
TOP_DIR=$(pwd)

# Get source code
if [ -e "${RTT_REPO}" ]
then
	echo "Exist"
	cd ${RTT_REPO}/
	git pull
	cd ..
else
	git clone https://gitee.com/rtthread/${RTT_REPO}.git --depth 1 --branch lts-v3.1.x
fi

# Change directory
cd ${RTT_REPO}/
cd bsp/qemu-vexpress-a9/

# Configuration
# scons --menuconfig

# Compile
source ~/.env/env.sh
scons

# Run
${TOP_DIR}/elf_run/qemu.sh