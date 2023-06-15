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

// Set format
#define TST_FRMT_RESETN     "\e[0m"
#define TST_FRMT_BOLD_T     "\e[1m"
#define TST_FRMT_FAINTT     "\e[2m"
#define TST_FRMT_ITALIC     "\e[3m"
#define TST_FRMT_UNDERL     "\e[4m"
#define TST_FRMT_BLINKL     "\e[5m"
#define TST_FRMT_F_BLCK     "\e[30m"
#define TST_FRMT_F_RED      "\e[31m"
#define TST_FRMT_F_GRN      "\e[32m"
#define TST_FRMT_F_YLLW     "\e[33m"
#define TST_FRMT_F_BLUE     "\e[34m"
#define TST_FRMT_F_MGNT     "\e[35m"
#define TST_FRMT_F_CYAN     "\e[36m"
#define TST_FRMT_F_GRAY     "\e[90m"
#define TST_FRMT_F_LGRY     "\e[37m"
#define TST_FRMT_F_LRED     "\e[91m"
#define TST_FRMT_F_LGRN     "\e[92m"
#define TST_FRMT_F_LYLLW    "\e[93m"
#define TST_FRMT_F_LBLUE    "\e[94m"
#define TST_FRMT_F_LMGNT    "\e[95m"
#define TST_FRMT_F_LCYAN    "\e[96m"
#define TST_FRMT_F_WHITE    "\e[97m"
#define TST_FRMT_B_BLCK     "\e[40m"
#define TST_FRMT_B_RED      "\e[41m"
#define TST_FRMT_B_GRN      "\e[42m"
#define TST_FRMT_B_YLLW     "\e[43m"
#define TST_FRMT_B_BLUE     "\e[44m"
#define TST_FRMT_B_MGNT     "\e[45m"
#define TST_FRMT_B_CYAN     "\e[46m"
#define TST_FRMT_B_GRAY     "\e[100m"
#define TST_FRMT_B_LGRY     "\e[47m"
#define TST_FRMT_B_LRED     "\e[101m"
#define TST_FRMT_B_LGRN     "\e[102m"
#define TST_FRMT_B_LYLLW    "\e[103m"
#define TST_FRMT_B_LBLUE    "\e[104m"
#define TST_FRMT_B_LMGNT    "\e[105m"
#define TST_FRMT_B_LCYAN    "\e[106m"
#define TST_FRMT_B_WHITE    "\e[107m"

#define TST_FRMT_FAIL     TST_FRMT_F_LRED TST_FRMT_ITALIC TST_FRMT_UNDERL
#define TST_FRM_LN_BRKR_O TST_FRMT_BOLD_T TST_FRMT_UNDERL TST_FRMT_F_LCYAN TST_STR_BRKR
#define TST_FRM_LN_BRKR_I TST_FRMT_BOLD_T TST_FRMT_BLINKL TST_FRMT_F_LCYAN TST_STR_BRKR
// clang-format on

#ifdef __cplusplus
}
#endif

#endif /* UTEST_DEFINES_H_ */