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

/*
  =======================================================================================
  File: 
        dtpython.h

  Description: 
        This header file is for the interface of DTPython project which is an experiment to make HOS board 
        to support Python. DTPython is made from MicroPython, but is NOT MicroPython anymore,
        because the basic purpose of DTPython is to supply another option to develop HOS device application.

  Author:
       Delphi Tang (唐佐林)
       http://www.dt4sw.com/

  Revision History:
       V0.0.1 (Initial Version)
  =======================================================================================

*/


#ifndef DTPYTHON_H
#define DTPYTHON_H

/*
  Description: 
      To initialize Python enviroment.

  Parameter:
      None

  Return Value:
      None
*/
void DTPython_Init(void);

/*
  Description: 
      To run a python file.

  Parameter:
      file -- python file name, such as "test.py"

  Return Value:
      None
*/
void DTPython_RunFile(const char* file);

/*
  Description: 
      To run python code statements.

  Parameter:
      statement -- python statements, such as "a = 1 + 2"

  Return Value:
      None
*/
void DTPython_RunCode(const char* statement);

/*
  Description: 
      To clean up Python enviroment.

  Parameter:
      None

  Return Value:
      None
*/
void DTPython_Deinit(void);

#endif
