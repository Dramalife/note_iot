#! /bin/bash
#
# https://github.com/Dramalife/note_RTOS.git
# Dramalife@live.com
#
# Ref : note_iot/build/build_rtt.sh
#


# Include
export LIB_DRAMALIFE_PWD=/home/dramalife/note/lib_dramalife/
export LIB_DRAMALIFE_TERMINAL_COLOR_VERSION=5002
source ${LIB_DRAMALIFE_PWD}/lib_dramalife.sh

# Variables
RTT_REPO=paho.mqtt.c
TOP_DIR=$(pwd)

# Get source code
if [ -e "${RTT_REPO}" ]
then
	echo "Folder \"${RTT_REPO}\" exists, updating..."
	cd ${RTT_REPO}/
	#git pull
	cd ..
else
	git clone https://github.com/eclipse/paho.mqtt.c.git
fi

# Call script
cd paho.mqtt.dl.sample
echo "pass ($1)($2)"
./install_exec.sh $1 $2 $3 $4 $5
## Check return
if [ $? = 0 ]
then
	echo -e ${DLTERM_LGREEN}"FINISH : exec."${DLTERM_NONE}
else
	echo -e ${DLTERM_LRED}"ERROR : exec."${DLTERM_NONE}
fi

# ./build_mqtt.sh exec pub 376241 636888257 iot00001
# ./build_mqtt.sh exec sub 376241 637834390 iot00002
