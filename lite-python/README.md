# Python for OHOS  
  
#### 介绍
这个仓库是为了能够在OpenHarmony设备上使用 Python 进行应用程序开发而创建。  
[1. 使用Python开发OpenHarmony设备程序（0-初体验）](https://harmonyos.51cto.com/posts/1887)  
  
#### 软件架构
这个仓库的 Baseline 是 [MicroPython v1.13](https://github.com/micropython/micropython/tree/v1.13)，在 MicroPython 的基础上进行了必要的剪裁以满足 OHOS 上的应用开发需求。  
  
#### 编译说明
1.  编译环境：  
    1）OS - Ubuntu 16+  
    2）Make - 3.81+  
    3）Python - 3.8+  
2.  配置交叉编译器：  
    1）打开源码根目录中的 Makefile  
    2）对变量 CROSS_COMPILE 进行赋值，如：CROSS_COMPILE ?= /home/harmony/gcc_riscv32/bin/riscv32-unknown-elf-  
3.  在源码根目录中执行 make  
  
#### 使用说明
1.  将编译得到的库文件 //build/libdtpython.a 拷贝到 //vendor/hisi/hi3861/hi3861/build/libs 目录下，如图：
![输入图片说明](https://images.gitee.com/uploads/images/2020/1130/102742_bea41b9a_8048968.png "82c43e952c89d664c1513719385ef6b12ba1a7.png")  
2.  在设备应用中加载 Python 并执行代码  

```
#include "dtpython.h"

extern const char* c_test_py;      // test.py
extern const char* c_another_py;   // another.py

static void DTPython_Demo_Entry(void)
{
    printf("[DTPython_Demo] DTPython_Demo_Entry()\n");

    DTPython_Init();   // 初始化Python环境

    DTPython_RunCode("print(\'Python Code Begin\')");    // 执行Python语句：print('Python Code Begin')
    
    DTPython_RunCode("s = \'HOS Device Development\'");  // 执行Python语句：s = 'HOS Device Development'
    DTPython_RunCode("print(s)");                        // 执行Python语句：print(s)

    DTPython_RunCode(c_test_py);                         // 模拟执行Python文件：DTPython_RunFile("test.py");
    DTPython_RunCode(c_another_py);                      // 模拟执行Python文件：DTPython_RunFile("another.py");

    DTPython_RunCode("print(\'Python Code End\')");      // 执行Python语句：print('Python Code End')

    DTPython_Deinit(); // 清理Python环境
}
```



