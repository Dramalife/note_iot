SOURCE_EXIST:=$(shell ls mbedtls 2>/dev/null)


default: all


source_download:
ifeq ("$(SOURCE_EXIST)","")
	git clone https://github.com/ARMmbed/mbedtls.git --depth 1 --branch mbedtls-2.24.0
else
	#cd mbedtls
	#git pull
endif







all: source_download
	gcc \
	-o ssl_client1.out \
	mbedtls/programs/ssl/ssl_client1.c \
	-I ./mbedtls/include/ -L ./mbedtls/library/ -lmbedtls -lmbedx509 -lmbedcrypto
	gcc \
	-o ssl_server.out \
	mbedtls/programs/ssl/ssl_server.c \
	-I ./mbedtls/include/ -L ./mbedtls/library/ -lmbedtls -lmbedx509 -lmbedcrypto

clean:
	rm -rf ./*.out
