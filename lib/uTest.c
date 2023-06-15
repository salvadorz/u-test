/*******************************************************************************
 * Copyright (C) 2023 by Salvador Z                                            *
 *                                                                             *
 * This file is part of Project                                                *
 *                                                                             *
 *   Permission is hereby granted, free of charge, to any person obtaining a   *
 *   copy of this software and associated documentation files (the Software)   *
 *   to deal in the Software without restriction including without limitation  *
 *   the rights to use, copy, modify, merge, publish, distribute, sublicense,  *
 *   and/or sell copies ot the Software, and to permit persons to whom the     *
 *   Software is furnished to do so, subject to the following conditions:      *
 *                                                                             *
 *   The above copyright notice and this permission notice shall be included   *
 *   in all copies or substantial portions of the Software.                    *
 *                                                                             *
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS   *
 *   OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARANTIES OF MERCHANTABILITY *
 *   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL   *
 *   THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR      *
 *   OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,     *
 *   ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE        *
 *   OR OTHER DEALINGS IN THE SOFTWARE.                                        *
 ******************************************************************************/

/**
 * @file uTest.c
 * @author Salvador Z
 * @date 14 Jun 2023
 * @brief File for uTest Lib Implementation
 *
 */

#include "uTest.h"
#include <stdio.h>  // uTEST_PRINT
#include <string.h> // memset
#include <time.h>   // time

uint8_t uTest_execute(uTest_handle_t tst, uTest_Module_t *tst_mod) {
  uTest_Status_t status;

  uTEST_PRINT("Testing '%s'\n", tst_mod->str_ModuleName);
  tst_mod->fn(&status);
  uTEST_PRINT("Result: name:'%s' total:%d fails:%d\n", tst_mod->str_ModuleName, status.u32_TestTotal,
              status.u32_TestFails);
  tst->u32_TestCFails += status.u32_TestFails;
  tst->u32_TestCCases += status.u32_TestTotal;
}

void uTest_runner(void) {
  uTest_t         test;
  uTest_Module_t *tm;

  memset(&test, 0, sizeof(uTest_t));
  test.u64_start_Time = time(NULL);
  tm                  = uTest_modules;

  while (tm->str_ModuleName != NULL) {
    uTest_execute(&test, tm);
    tm++;
  }
  test.u64_stop_Time = time(NULL);
}
