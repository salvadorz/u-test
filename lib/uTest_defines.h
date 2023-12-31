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

/** Utils-Test Macro configuration to enable/disable features */
#define uTST_FORMAT_COLOR_CFG (ENABLE)  // ENABLE/DISABLE the COLOR OUTPUT FORMAT
#define uTST_SET_LONG_JMP_CFG (ENABLE)  // ENABLE/DISABLE the LONG JUMP for TEST FAIL
#define uTST_SET_ENV_TEST_CFG (DISABLE) // ENABLE/DISABLE the PRE and POST RUN functions to set the env test

#if !(uTST_SET_ENV_TEST_CFG)
  #undef uTST_SET_ENV_TEST_CFG
#endif

#if !(uTST_SET_LONG_JMP_CFG)
  #undef uTST_SET_LONG_JMP_CFG
#endif

#if !(uTST_FORMAT_COLOR_CFG)
  #undef uTST_FORMAT_COLOR_CFG
#endif

// Internal macros
#define uTEST_EPSILON (1e-2f) // 0.01f
#ifdef uTST_SET_LONG_JMP_CFG
  #define uTST_CHECK() (setjmp(uTst_g.jmp_uTestJmpBuf) == 0)
  #define uTST_ABORT() longjmp(uTst_g.jmp_uTestJmpBuf, 1)
#else
  #define uTST_CHECK() (1)
  #define uTST_ABORT() return
#endif

#define uTST_RETURN_IF_FAIL_     \
  do {                           \
    if (uTst_g.u32_TstCFailed) { \
      uTST_ABORT();              \
    }                            \
  } while (0)

#define uTEST_ASSERT_EXPECTED(x, y)                  \
  do {                                               \
    if (x != y) uTest_assert_fail(#x, #y, __LINE__); \
  } while (0)

#ifndef uTEST_ADD
  #define uTEST_RUN_FN(fn, line, msg, ...)  uTest_run(fn, #fn, line, NULL)
  #define uTEST_RUN_MSG(fn, msg, line, ...) uTest_run(fn, #fn, line, msg)
#endif

#define uTEST_ASSERT_EQUAL(tst, line, message) uTest_assert_expected_val((bool)(tst), (message), (line))
#define uTEST_ASSERT_EQUAL_VAL(expected, actual, line, message) \
  uTest_assert_expected_int_val((expected), (actual), (message), (line))
#define uTEST_ASSERT_EQUAL_FLOAT(expected, actual, line, message) \
  uTest_assert_expected_float_val((expected), (actual), (message), (line))

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
#ifdef  uTST_FORMAT_COLOR_CFG
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

#else
#define TST_FRMT_RESETN  
#define TST_FRMT_BOLD_T  
#define TST_FRMT_FAINTT  
#define TST_FRMT_ITALIC  
#define TST_FRMT_UNDERL  
#define TST_FRMT_BLINKL  
// Foreground
#define TST_FRMT_F_BLCK  
#define TST_FRMT_F_RED   
#define TST_FRMT_F_GRN   
#define TST_FRMT_F_YLLW  
#define TST_FRMT_F_BLUE  
#define TST_FRMT_F_MGNT  
#define TST_FRMT_F_CYAN  
#define TST_FRMT_F_GRAY  
#define TST_FRMT_F_LGRY  
#define TST_FRMT_F_LRED  
#define TST_FRMT_F_LGRN  
#define TST_FRMT_F_LYLLW 
#define TST_FRMT_F_LBLUE 
#define TST_FRMT_F_LMGNT 
#define TST_FRMT_F_LCYAN 
#define TST_FRMT_F_WHITE 
// Background
#define TST_FRMT_B_BLCK  
#define TST_FRMT_B_RED   
#define TST_FRMT_B_GRN   
#define TST_FRMT_B_YLLW  
#define TST_FRMT_B_BLUE  
#define TST_FRMT_B_MGNT  
#define TST_FRMT_B_CYAN  
#define TST_FRMT_B_GRAY  
#define TST_FRMT_B_LGRY  
#define TST_FRMT_B_LRED  
#define TST_FRMT_B_LGRN  
#define TST_FRMT_B_LYLLW 
#define TST_FRMT_B_LBLUE 
#define TST_FRMT_B_LMGNT 
#define TST_FRMT_B_LCYAN 
#define TST_FRMT_B_WHITE 
#endif

#define TST_FRMT_FAIL     TST_FRMT_F_LRED TST_FRMT_ITALIC TST_FRMT_UNDERL
#define TST_FRM_LN_BRKR_O TST_FRMT_BOLD_T TST_FRMT_UNDERL TST_FRMT_F_LCYAN TST_STR_BRKR
#define TST_FRM_LN_BRKR_I TST_FRMT_BOLD_T TST_FRMT_BLINKL TST_FRMT_F_LCYAN TST_STR_BRKR
// clang-format on

#ifdef __cplusplus
}
#endif

#endif /* UTEST_DEFINES_H_ */