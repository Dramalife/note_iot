#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "mbedtls/md.h"
#include "mbedtls/platform_util.h"

#include "lib_dramalife.h"

#if 0
void zpi_show_n_bytes(const char *buff, uint32_t len)
{       
	int index = 0;

	for(index=0; index<len; index++){
		printf("%02x", *(buff + index) & 0xff );
	}       

	printf("\n");

	return;
}
#endif

int test_sha256()
{
	/****
	 * Checked Data
	 * ---
	 * Plain data :
	 * sha256##
	 * SHA256 (32bytes):
	 * cd3b4b329d4434dcc3ec8185382145bd7e1537f55495d94a10983eb14783132f
	 */

	mbedtls_md_context_t sha_ctx;
	unsigned char buff_sha256_result[32] = {0};	// 32bytes * 8 = 256bits

	const char *buff_plain = "sha256##";

	mbedtls_md_init( &sha_ctx );

	if( 0 != mbedtls_md_setup( &sha_ctx, mbedtls_md_info_from_type( MBEDTLS_MD_SHA256 ), 1 ) ){
		printf("ERROR!\n");
	}

	mbedtls_md_starts( &sha_ctx );
	mbedtls_md_update( &sha_ctx, (const unsigned char *)buff_plain, strlen(buff_plain) );
	mbedtls_md_finish( &sha_ctx, buff_sha256_result );

	mbedtls_md_free( &sha_ctx );

	printf("\nPlain data :\n%s\n", buff_plain);
	printf("\nSHA-256 Result:\n");
	zpi_show_n_bytes((char *)buff_sha256_result, 32);

	return 0;
}

int main(void)
{

	test_sha256();

	return 0;
}
