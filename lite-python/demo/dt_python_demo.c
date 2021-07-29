/****************************************************************************

MIT License

Copyright (c) 2020 唐佐林

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*****************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include "ohos_init.h"
#include "cmsis_os2.h"
#include "wifiiot_gpio.h"
#include "wifiiot_gpio_ex.h"
#include "wifiiot_pwm.h"

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

SYS_RUN(DTPython_Demo_Entry);
