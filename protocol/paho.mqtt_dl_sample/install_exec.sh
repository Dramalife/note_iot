#! /bin/bash


# Include "note/"
source ~/note/lib_dramalife/terminal_color_bash.sh


# Variables
CURRDIR=$(pwd)
PAHO_MQTT_DIR=${CURRDIR}/../paho.mqtt.c/


# Check direcotry variable
if [[ ${CURRDIR} = "" || ${PAHO_MQTT_DIR} = "" ]]
then
	echo ${DLTERM_LRED}"Error :"${DLTERM_NONE}" check DIR_VAR! exit now..."
	exit
fi


# Install files
ln -svf ${CURRDIR}/dl_mqtt_client_pub.c	${PAHO_MQTT_DIR}/src/samples/dl_mqtt_client_pub.c
cp -vf ${CURRDIR}/Makefile_dl		${PAHO_MQTT_DIR}/Makefile
cp -vf ${CURRDIR}/CMakeLists.txt_dl	${PAHO_MQTT_DIR}/src/samples/CMakeLists.txt
echo -e ${DLTERM_LGREEN} "\nDONE :"${DLTERM_NONE}" Install files.\n"


# Compile
make -C ${PAHO_MQTT_DIR}
echo -e ${DLTERM_LGREEN}"\nDONE :"${DLTERM_NONE}" Compile.\n"


# Exec
${PAHO_MQTT_DIR}build/output/samples/dl_mqtt_client_pub
echo -e ${DLTERM_LGREEN}"\nDONE :"${DLTERM_NONE}" Exec.\n"
