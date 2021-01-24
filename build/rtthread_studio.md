### Compile

#### undefined reference to \`_sbrk'
“组件和服务层” 开启 “AT客户端” 后报错:
```
d:/soft_games/rt-threadstudio/repo/extract/toolchain_support_packages/arm/gnu_tools_for_arm_embedded_processors/5.4.1/bin/../lib/gcc/arm-none-eabi/5.4.1/../../../../arm-none-eabi/lib/armv7-m\libg.a(lib_a-sbrkr.o): In function `_sbrk_r':
sbrkr.c:(.text._sbrk_r+0xc): undefined reference to `_sbrk'
```
解决
[ref_url](https://blog.csdn.net/hanhui22/article/details/107288621/)  
同时需要开启 “libc”

