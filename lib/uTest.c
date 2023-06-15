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
#include "uTest_common.h"

#include <stdbool.h>
#include <stdio.h>  // uTEST_PRINT
#include <string.h> // memset
#include <time.h>   // time

#define DATE_TIME_STR_LEN 64

char date_time[DATE_TIME_STR_LEN];

char *time_string(time_t *t) {
  strftime(date_time, DATE_TIME_STR_LEN, "%d/%m/%y-%H:%M:%S %z", localtime(t));
  return date_time;
}

static void uTest_header_report(void) {
  printf("\n");
  printf("------------------------------------------\n");
  printf("        uTest Unit Test Framework         \n");
  printf("------------------------------------------\n");
}

static void uTest_footer_report(void) {
  printf("\n");
  printf("------------------------------------------\n");
  printf("                Test Report               \n");
  printf("------------------------------------------\n");
}

uTest_t uTst_g = { 0 };

static void uTest_results(char const *file, uint32_t const line, bool failed) {

  uTEST_PRINT("%s:%d:%s%s", file, line, uTst_g.str_uTestFnName, failed ? fail_mark : pass_mark);
}

uT_Rtn_t uTest_init(char const *filename) {
  uT_Rtn_t exec_ok = uTEST_OK;

  if (filename) {

    memset(&uTst_g, 0, sizeof(uTest_t));

    uTst_g.str_uTestFile  = filename;
    uTst_g.u64_start_Time = time(NULL);

    uTest_header_report();
  } else {
    exec_ok = uTEST_NOT_OK;
  }
  return exec_ok;
}

uint32_t uTest_end(void) {

  // End Time-Stamp
  uTst_g.u64_stop_Time = time(NULL);

  uint32_t const tst_success = uTst_g.u32_uTestTCases - uTst_g.u32_uTestTFails;

  uTest_footer_report();
  uTEST_PRINT("Start Time: %s\n", time_string(&uTst_g.u64_start_Time));
  uTEST_PRINT("End Time:   %s\n", time_string(&uTst_g.u64_stop_Time));
  uTEST_PRINT("Executed:  %3d \n", uTst_g.u32_uTestTCases);
  uTEST_PRINT("Sucessful: %3d \n", tst_success);
  uTEST_PRINT("Test Result: %s\n\n", (uTst_g.u32_uTestTCases == tst_success) ? "PASS" : "FAIL");

  return uTst_g.u32_uTestTFails;
}

void uTest_check(void) {
  bool const any_fail = (0 == uTst_g.u32_uTestCFails) ? false : true;
  if (false == any_fail) {
    uTest_results(uTst_g.str_uTestFile, uTst_g.u32_uTestFnLine, false);
    uTEST_PRINT("\n");
  } else {
    ++uTst_g.u32_uTestTFails;
  }
  uint32_t const cTestPassed = uTst_g.u32_uTestCCases - uTst_g.u32_uTestCFails;

  uTEST_PRINT("- %s total:%3d pass:%3d - Test Name: %s\n", any_fail ? brckt_nak : dbrckt_ok,
              uTst_g.u32_uTestCCases, cTestPassed, uTst_g.str_uTestFnDesc);
  uTst_g.u32_uTestCCases = 0;
  uTst_g.u32_uTestCFails = 0;
  uTst_g.str_uTestFnDesc = NULL;
}

uT_Rtn_t uTest_run(uTest_fn_ptr fnTst, char const *fnName, uint32_t line, char const *msg) {
  uT_Rtn_t exec_ok = uTEST_OK;

  if (fnTst && fnName && line) {
    uTst_g.str_uTestFnName = fnName;
    uTst_g.u32_uTestFnLine = line;
    uTst_g.u32_uTestTCases++;

    if (msg) {
      uTst_g.str_uTestFnDesc = msg;
    }

    uTEST_PRE_RUN();
    fnTst();
    uTEST_POST_RUN();

    uTest_check();
    // @TODO Conclude Test to see if any failure
  } else {
    exec_ok = uTEST_NOT_OK;
  }
  return exec_ok;
}
