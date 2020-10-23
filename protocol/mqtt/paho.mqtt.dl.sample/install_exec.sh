#! /bin/bash


# Include
export LIB_DRAMALIFE_PWD=/home/dramalife/note/lib_dramalife/
export LIB_DRAMALIFE_TERMINAL_COLOR_VERSION=5002
source ${LIB_DRAMALIFE_PWD}/lib_dramalife.sh
source pub.sh


# Variables
CURRDIR=$(pwd)
PAHO_MQTT_DIR=${CURRDIR}/../${RTT_REPO}


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
#ln -svf ${CURRDIR}/config_mqtt_dl.h	${PAHO_MQTT_DIR}/src/config_mqtt_dl.h
ln -svf ${CURRDIR}/config_mqtt_dl.h	${PAHO_MQTT_DIR}/src/samples/config_mqtt_dl.h
## scripts
cp -vf ${CURRDIR}/Makefile_dl		${PAHO_MQTT_DIR}/Makefile
cp -vf ${CURRDIR}/CMakeLists.txt_dl	${PAHO_MQTT_DIR}/src/samples/CMakeLists.txt
echo -e ${DLTERM_LGREEN} "\nDONE :"${DLTERM_NONE}" Install files.\n"


# Compile
make -C ${PAHO_MQTT_DIR} -j4
echo -e ${DLTERM_LGREEN}"\nDONE :"${DLTERM_NONE}" Compile.\n"


# Exec
#CMD1=$1
#CMD2=${CMD2}
#PRODUCT_ID=${PRODUCT_ID}
#DEVICE_ID=${DEVICE_ID}
#DEVICE_PASSWORD=${DEVICE_PASSWORD}
if [ "${CMD1}" = "exec" ]
then
	echo ""
	if [ "${CMD2}" = "pub" ]
	then
		${PAHO_MQTT_DIR}build/output/samples/dl_mqtt_client_pub ${PRODUCT_ID} ${DEVICE_ID} ${DEVICE_PASSWORD}
		echo -e ${DLTERM_LGREEN}"\nDONE :"${DLTERM_NONE}" Exec (${2}).\n"
	elif [ "${CMD2}" = "sub" ]
	then
		${PAHO_MQTT_DIR}build/output/samples/dl_mqtt_client_sub ${PRODUCT_ID} ${DEVICE_ID} ${DEVICE_PASSWORD}
		echo -e ${DLTERM_LGREEN}"\nDONE :"${DLTERM_NONE}" Exec (${2}).\n"
	else
		echo -e ${DLTERM_LGREEN}"\nDONE :"${DLTERM_NONE}" Unknown program name!\n"
	fi
else
	echo -e ${DLTERM_LGREEN}"\nDONE :"${DLTERM_NONE}" No need Exec!\n"
	echo -e ${DLTERM_LGREEN}"\nNote :"${DLTERM_NONE}
	echo -e "Type \"$0 exec PROG_NAME ProductID DeviceID SN/Password\" to run. ex.PROG_NAME={pub|sub}."
fi
