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
## src
ln -svf ${CURRDIR}/dl_mqtt_client_pub.c	${PAHO_MQTT_DIR}/src/samples/dl_mqtt_client_pub.c
ln -svf ${CURRDIR}/dl_mqtt_client_sub.c	${PAHO_MQTT_DIR}/src/samples/dl_mqtt_client_sub.c
## header
ln -svf ${CURRDIR}/config_mqtt_dl.h	${PAHO_MQTT_DIR}/src/config_mqtt_dl.h
## scripts
cp -vf ${CURRDIR}/Makefile_dl		${PAHO_MQTT_DIR}/Makefile
cp -vf ${CURRDIR}/CMakeLists.txt_dl	${PAHO_MQTT_DIR}/src/samples/CMakeLists.txt
echo -e ${DLTERM_LGREEN} "\nDONE :"${DLTERM_NONE}" Install files.\n"


# Compile
make -C ${PAHO_MQTT_DIR}
echo -e ${DLTERM_LGREEN}"\nDONE :"${DLTERM_NONE}" Compile.\n"


# Exec
if [ "$1" = "exec" ]
then
	echo ""
	if [ "$2" = "pub" ]
	then
		${PAHO_MQTT_DIR}build/output/samples/dl_mqtt_client_pub
		echo -e ${DLTERM_LGREEN}"\nDONE :"${DLTERM_NONE}" Exec (${2}).\n"
	elif [ "$2" = "sub" ]
		${PAHO_MQTT_DIR}build/output/samples/dl_mqtt_client_pub
		echo -e ${DLTERM_LGREEN}"\nDONE :"${DLTERM_NONE}" Exec (${2}).\n"
	else
		echo -e ${DLTERM_LGREEN}"\nDONE :"${DLTERM_NONE}" Not Exec (${2})!\n"
	fi
else
	echo -e ${DLTERM_LGREEN}"\nDONE :"${DLTERM_NONE}" No need Exec!\n"
fi
