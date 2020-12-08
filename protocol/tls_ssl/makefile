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
	make -C . cone NAME=ssl_client1
	make -C . cone NAME=ssl_server
	make -C . cone NAME=aescrypt2

cone:
	gcc \
	-o $(NAME).out \
	sample_code/$(NAME).c \
	-I ./mbedtls/include/ -L ./mbedtls/library/ -lmbedtls -lmbedx509 -lmbedcrypto

clean:
	rm -rf ./*.out
