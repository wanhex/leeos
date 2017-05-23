## leeos
leeos是《一步步写嵌入式操作系统》书中所实现的操作系统。

本github repository意在提供本书涉及的相关工具下载链接及环境搭建步骤，方便读者学习、讨论。

### 环境搭建
环境要求
* VMWare + Ubuntu 16.04
* s3c2410交叉编译工具
* skyeye


#### s3c2410交叉编译工具

  * 下载地址1：http://pan.baidu.com/s/1cMWvGM
  * 下载地址2：https://github.com/descent/arm_os

#### skyeye安装

虽然可是使用apt-get进行安装，但使用过程中存在问题，故推荐使用源码编译安装。

源码下载地址：https://sourceforge.net/projects/skyeye/files/skyeye/

编译步骤：

```
$ ./configure
#make前需要将.../skyeye/third-party/opcodes/cgen-ops.h 315行修改为 #ifndef SEMOPS_DEFINE_INLINE
$ make lib
$ make
$ make install_lib
$ make install
```
```

安装完成后，skyeye命令路径为：/opt/skyeye/bin/skyeye_main.py

命令使用示例：

```
$ skyeye_main.py -n
```
如果不额外指定参数，则命令会在当前目录下寻找skyeye.conf配置文件，根据配置执行程序。skyeye.conf文件参考格式，请参见源码目录。

