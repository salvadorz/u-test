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
#include "uTest_datatypes.h"

// This need to be declare on the runner
extern uTest_Module_t uTest_modules[];

/**
 * \brief    Initializes the tTest structure
 * \param    tst structure to initialize
 * \param    filename to Start testing
 * \return   0 if sucees, 1 otherwise
 * \todo
 */
uint8_t uTest_init(uTest_handle_t tst, char const *filename);

/**
 * \brief    Receives a element from the uTest_modules[] and extracts the information
 * \param    tst to populate the info from tst_mod
 * \return   0 if sucees, 1 otherwise
 * \todo
 */
uint8_t uTest_execute(uTest_handle_t tst, uTest_Module_t *tst_mod);

/**
 * \brief    Iterates over uTest_modules
 * \todo
 */
void uTest_runner(void);

#ifdef __cplusplus
}
#endif

#endif /* UTEST_H_ */