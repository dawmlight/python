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

const char* c_test_py = 
{
"\r\n"
"def SayHello(n) :\r\n"
"    for i in range(n) :\r\n"
"        print(\"Hello World: \" + str(i))\r\n"
"\r\n"
"a = 4\r\n"
"b = 5\r\n"
"\r\n"
"print(\'a + b = \', a + b)\r\n"
"\r\n"
"SayHello(6)\r\n"
"    \r\n"
"s1 = \'Delphi\'\r\n"
"s2 = \'Tang\'\r\n"
"\r\n"
"if s1 == s2 :\r\n"
"    print(\'Equal\')\r\n"
"else :\r\n"
"    print(\'No Equal\')\r\n"
"    \r\n"
"print(\'s1 + s2 = \', s1 + \' \' + s2)\r\n"
};

const char* c_another_py = 
{
"class Person:\r\n"
"    def __init__(self, name):\r\n"
"        self.name = name\r\n"
"        \r\n"
"    def SayHello(self):\r\n"
"        print(\'My name is:\', self.name)\r\n"
"\r\n"
"p = Person(\'Delphi Tang\')\r\n"
"\r\n"
"p.SayHello();\r\n"
"\r\n"
"print(p)\r\n"
};

