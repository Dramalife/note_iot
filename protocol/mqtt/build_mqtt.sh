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
source paho.mqtt.dl.sample/pub.sh

# Variables
RTT_REPO=paho.mqtt.c/paho.mqtt.c/
TOP_DIR=$(pwd)

# Get source code
if [ -e "${RTT_REPO}" ]
then
	echo "Folder \"${RTT_REPO}\" exists, updating..."
	cd ${RTT_REPO}/
	#git pull
	cd ${TOP_DIR}
else
	#git clone https://github.com/eclipse/paho.mqtt.c.git
	~/note/lib_dramalife/exec_files/git_sparse_clone.sh paho.mqtt.c https://gitee.com/Dramalife/tools_note.git
fi

# Call script
cd paho.mqtt.dl.sample
echo "pass ($1)($2)"
./install_exec.sh ${CMD1} ${CMD2} ${PRODUCT_ID} ${DEVICE_ID} ${DEVICE_PASSWORD} ${RTT_REPO}
## Check return
if [ $? = 0 ]
then
	echo -e ${DLTERM_LGREEN}"FINISH : exec."${DLTERM_NONE}
else
	echo -e ${DLTERM_LRED}"ERROR : exec."${DLTERM_NONE}
fi

# ./build_mqtt.sh exec pub 376241 636888257 iot00001
# ./build_mqtt.sh exec sub 376241 637834390 iot00002
