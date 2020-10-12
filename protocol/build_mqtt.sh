#! /bin/bash
#
# https://github.com/Dramalife/note_RTOS.git
# Dramalife@live.com
#
# Ref : note_iot/build/build_rtt.sh
#


# Include
source ~/note/lib_dramalife/terminal_color_bash.sh

# Variables
RTT_REPO=paho.mqtt.c
TOP_DIR=$(pwd)

# Get source code
if [ -e "${RTT_REPO}" ]
then
	echo "Exist"
	cd ${RTT_REPO}/
	git pull
	cd ..
else
	git clone https://github.com/eclipse/paho.mqtt.c.git
fi

# Call script
cd paho.mqtt_dl_sample
echo "pass ($1)($2)"
./install_exec.sh $1 $2
## Check return
if [ $? = 0 ]
then
	echo -e ${DLTERM_LGREEN}"FINISH : exec."${DLTERM_NONE}
else
	echo -e ${DLTERM_LRED}"ERROR : exec."${DLTERM_NONE}
fi

