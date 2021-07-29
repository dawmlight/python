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
        dtpython.c

  Description: 
        The implementation of the interface for using Python in C code.

  Author:
       Delphi Tang (唐佐林)
       http://www.dt4sw.com/

  Revision History:
       V0.1.0 (Initial Version)
  =======================================================================================
*/


#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "py/compile.h"
#include "py/runtime.h"
#include "py/repl.h"
#include "py/gc.h"
#include "py/mperrno.h"
#include "lib/utils/pyexec.h"

#if MICROPY_ENABLE_COMPILER
static void do_str(const char *src, mp_parse_input_kind_t input_kind) {
    nlr_buf_t nlr;
    if (nlr_push(&nlr) == 0) {
        mp_lexer_t *lex = mp_lexer_new_from_str_len(MP_QSTR__lt_stdin_gt_, src, strlen(src), 0);
        qstr source_name = lex->source_name;
        mp_parse_tree_t parse_tree = mp_parse(lex, input_kind);
        mp_obj_t module_fun = mp_compile(&parse_tree, source_name, true);
        mp_call_function_0(module_fun);
        nlr_pop();
    } else {
        // uncaught exception
        mp_obj_print_exception(&mp_plat_print, (mp_obj_t)nlr.ret_val);
    }
}

static void do_file(const char *filename) {
    FILE* fp = fopen(filename, "r");

    if( fp != NULL )
    {
        char* buf = NULL;
        long len = 0;

        fseek(fp, 0, SEEK_END);

        len = ftell(fp);

        fseek(fp, 0, SEEK_SET);

        if( (buf = (char*)malloc(len + 1)) != NULL )
        {
            len = fread(buf, 1, len, fp);
            buf[len] = 0;

            do_str(buf, MP_PARSE_FILE_INPUT);
        }

        free(buf);
    }

    fclose(fp);
}
#endif

static char *stack_top;
#if MICROPY_ENABLE_GC
static char heap[10240];
#endif

#if MICROPY_ENABLE_GC
void gc_collect(void) {
    // WARNING: This gc_collect implementation doesn't try to get root
    // pointers from CPU registers, and thus may function incorrectly.
    void *dummy;
    gc_collect_start();
    gc_collect_root(&dummy, ((mp_uint_t)stack_top - (mp_uint_t)&dummy) / sizeof(mp_uint_t));
    gc_collect_end();
    gc_dump_info();
}
#endif

void nlr_jump_fail(void *val) {
    while (1) {
        ;
    }
}

mp_lexer_t *mp_lexer_new_from_file(const char *filename) {
    mp_raise_OSError(MP_ENOENT);
}

mp_import_stat_t mp_import_stat(const char *path) {
    return MP_IMPORT_STAT_NO_EXIST;
}

mp_obj_t mp_builtin_open(size_t n_args, const mp_obj_t *args, mp_map_t *kwargs) {
    return mp_const_none;
}

MP_DEFINE_CONST_FUN_OBJ_KW(mp_builtin_open_obj, 1, mp_builtin_open);

void DTPython_Init()
{
    int stack_dummy;
    stack_top = (char *)&stack_dummy;

    gc_init(heap, heap + sizeof(heap));

    mp_init();
}

void DTPython_RunFile(const char* file)
{
    if(file != NULL)
    {
        do_file(file);
    }
}

void DTPython_RunCode(const char* statement)
{
    if( statement != NULL )
    {
        do_str(statement, MP_PARSE_FILE_INPUT);
    }
}

void DTPython_Deinit()
{
    mp_deinit();
}
