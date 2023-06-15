/**
 * @file uTest_defines.h
 * @author Salvador Z
 * @version 1.0
 * @brief File for uTest MACROS and uTest behaviour cfg
 *
 */

#ifndef UTEST_DEFINES_H_
#define UTEST_DEFINES_H_

#ifdef __cplusplus
extern "C" {
#endif

// Includes
#include "uTest_common.h"

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

/** Macros for Handle uTEST Section Addition*/
#ifndef ADD_uTEST
  #define ADD_uTEST_FN(...)                 RUN_uTEST_FN(__VA_ARGS__, __LINE__, discard)
  #define ADD_uTEST_MSG(...)                RUN_uTEST_MSG(__VA_ARGS__, __LINE__, discard)
  #define RUN_uTEST_FN(fn, line, msg, ...)  uTest_run(fn, #fn, line, NULL)
  #define RUN_uTEST_MSG(fn, msg, line, ...) uTest_run(fn, #fn, line, msg)
#endif

/*****************************************************************************************************
 * Definition of TEST STRING MACROs
 *****************************************************************************************************/

// clang-format off
#define TST_STR_OK          " OK "
#define TST_STR_NACK        "NOT OK"
#define TST_STR_PASS        "PASS"
#define TST_STR_FAIL        "FAIL"
#define TST_STR_BRKR        "------------------------------------------"

#define TST_CHECK_MARK      "\u2713"
#define TST_WRONG_MARK      "\u2718"
// clang-format on

#ifdef __cplusplus
}
#endif

#endif /* UTEST_DEFINES_H_ */