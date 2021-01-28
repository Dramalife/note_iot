#! /bin/bash

CUR_DIR=$(pwd)
SRC_FILE=${1}

if [ "${SRC_FILE}" = "" ]
then
	echo -e "\n\nUsage:\n${0} <FILE.c>"
else
	ln -vsf ${CUR_DIR}/${SRC_FILE} ../../../build/rt-thread/bsp/qemu-vexpress-a9/applications/main.c
	echo -e "\n\nDONE!"
fi
