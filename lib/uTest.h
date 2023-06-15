/*******************************************************************************
 * Copyright (C) 2023 by Salvador Z                                            *
 *                                                                             *
 * This file is part of UTILS_C                                                *
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
 * @file uTest.h
 * @author Salvador Z
 * @version 1.0
 * @brief File for uTest Generic API
 *
 */

#ifndef UTEST_H_
#define UTEST_H_

#ifdef __cplusplus
extern "C" {
#endif

// Includes
#include "uTest_common.h"
#include "uTest_datatypes.h"
#include "uTest_defines.h"

#ifdef uTST_SET_ENV_TEST_CFG
  #define uTEST_PRE_RUN()  uTest_pre_run()
  #define uTEST_POST_RUN() uTest_post_run()
#else
  #define uTEST_PRE_RUN()
  #define uTEST_POST_RUN()
#endif

/**
 * \brief    Initializes/clears the uTest global variable and assigns the File_UT name
 * \param    NONE, the file name is passed automagically
 * \return   OK if success, NOT_OK otherwise
 * \todo
 */
#define uTEST_INIT() uTest_init(__FILE__)

/**
 * \brief    Provides the Test Summary and closes the uTest File_UT name
 * \return   The number of Section failures
 * \todo
 */
#define uTEST_END() uTest_end()

/**
 * \brief    Initialize the uTest structure
 * \param    tst structure to initialize
 * \param    filename to Start testing
 * \return   0 if success, 1 otherwise
 * \todo
 */
uT_Rtn_t uTest_init(char const *filename);

/**
 * \brief    Closes uTest after all tests fn were run and ready to show the report
 * \param    tst - uTest structure to obtain the results
 * \return   Returns number of failures detected, 0 if everything no errors
 * \todo
 */
uint32_t uTest_end(void);

/**
 * \brief    Description...
 * \param    fnTst to Call
 * \param    fnName to register in global structure
 * \param    line to register in global structure
 * \param    msg to print out in the report **optional**
 * \return   0 if success, 1 otherwise
 * \todo
 */
uT_Rtn_t uTest_run(uTest_fn_ptr fnTst, char const *fnName, uint32_t line, char const *msg);

/**
 * \brief    Makes a comparison and evaluates if success or fail in the test. If fails prints the error
 * \param    expected - value to compare
 * \param    actual - value provided from the test
 * \param    msg - If a msg is provided will be printed if the comparison fails
 * \param    line - prints the line number where the assertion failed.
 * \return   NONE
 * \todo     Cancel current section in progress
 */
void uTest_assert_expected_val(int32_t const expected, int32_t const actual, char const *msg, uint32_t line);

/**
 * \brief    Function to set any (global) variables or any environment setup prior to call
 *            the section test (fn) under test
 * \return   void
 * \todo
 */
void uTest_pre_run();

/**
 * \brief    Function to clear or set any (global) variables or any environment setup after call
 *            the section test (fn) under test
 * \return   void
 * \todo
 */
void uTest_post_run();

#ifdef __cplusplus
}
#endif

#endif /* UTEST_H_ */