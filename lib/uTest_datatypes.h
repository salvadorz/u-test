/**
 * @file uTest_datatypes.h
 * @author Salvador Z
 * @version 1.0
 * @brief File for datatypes for uTest and typedefinitions
 *
 */

#ifndef UTEST_DATATYPES_H_
#define UTEST_DATATYPES_H_

#include <sys/types.h>
#ifdef __cplusplus
extern "C" {
#endif

// Includes
#ifndef STD_LIB
  #include <stdint.h>
#else
  #include "utils_common.h"
#endif

typedef struct uTest_s {
  char const *str_TestFile;   // Test File Name (*.c)
  char const *str_TestFnName; // Test (Module or Section) Name
  char const *str_TestFnDesc; // Test Function Description *Optional*
  uint32_t    u32_TestFnLine; // Line Number for Report printing
  uint32_t    u32_TestMCases; // Test Fn (Modules) Cases Counter
  uint32_t    u32_TestMFails; // Test Fn (Modules) Failed Counter
  uint32_t    u32_TestCCases; // Assertions expected in Current Section Counter
  uint32_t    u32_TestCFails; // Assertions Failed in Current Section Counter
  __time_t    u64_strat_Time; // Init time-stamp
  __time_t    u64_stop_Time;
} uTest_t;

typedef struct uTest_Module_s {
  char const *str_TestFnName; // Test (Module or Section) Name
  char const *str_TestFnDesc; // Test Function Description *Optional*
} uTest_Module_t;

typedef struct uTest_Status_s {
  uint32_t u32_TestTotal; // Test Fn (Modules) Cases Counter
  uint32_t u32_TestFails; // Test Fn (Modules) Failed Counter
} uTest_Status_t;

typedef uTest_Status_t *uTest_St_handle_t;

typedef void (*uTest_fn_ptr)(uTest_St_handle_t); // Expected function for Declare a Section Test

// Handle for uTest
typedef uTest_t *uTest_handle_t;

#ifdef __cplusplus
}
#endif

#endif /* UTEST_DATATYPES_H_ */