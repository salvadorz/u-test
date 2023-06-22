/**
 * @file uTest_datatypes.h
 * @author Salvador Z
 * @version 1.0
 * @brief File for datatypes for uTest and typedefinitions
 *
 */

#ifndef UTEST_DATATYPES_H_
#define UTEST_DATATYPES_H_

#ifdef __cplusplus
extern "C" {
#endif

// Includes
#include <time.h>
#ifndef UTILS_COMMON_H_
  #include <stdint.h>
#else
  #include "utils_common.h"
#endif

typedef void (*uTest_fn_ptr)(void); // Expected function for Declare a Section Test

typedef struct uTest_s {
  char const *str_uTestFile;   // Test File Name (*.c)
  char const *str_uTestFnName; // Test (Section) Name
  char const *str_uTestFnDesc; // Test Function Description *Optional*
  uint32_t    u32_uTestFnLine; // Line Number for Report printing
  uint32_t    u32_uTestTCases; // Test Fn Total Section Cases Counter
  uint32_t    u32_uTestTFails; // Test Fn Total Section Failed Counter
  uint32_t    u32_uTestCCases; // Assertions expected in Current Section Counter
  uint32_t    u32_uTestCFails; // Assertions Failed in Current Section Counter
  time_t      u64_start_Time;  // Init time-stamp
  time_t      u64_stop_Time;   // close time-stamp
} uTest_t;

typedef uint8_t uT_Rtn_t;

#ifdef __cplusplus
}
#endif

#endif /* UTEST_DATATYPES_H_ */