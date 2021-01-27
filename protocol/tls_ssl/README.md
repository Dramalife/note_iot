### Docs
[mbedtls Offical doc](https://tls.mbed.org/kb/how-to/mbedtls-tutorial)
[mbedtls linux环境调试](https://blog.csdn.net/dashanque/article/details/106056401)

[AES online, support hex/utf-8 format](https://the-x.cn/cryptography/Aes.aspx)  
[HASH online, ](https://hash.online-convert.com/)

[知乎(浅谈SSL/TLS工作原理)](https://zhuanlan.zhihu.com/p/36981565)
(md)[浅析TLS 1.2协议](./doc/tls1.2_whxl.segmentfault.com.md)

Ref : https://segmentfault.com/a/1190000005998141


### Source Code

#### mbedtls
```bash
# Get Source 
git clone https://github.com/ARMmbed/mbedtls.git --depth 1 --branch mbedtls-2.24.0

# Compile
cd mbedtls
make

# Test Demo
./programs/ssl/ssl_server
./programs/ssl/ssl_client1
```

HMAC : Hash-based Message Authentication Code

