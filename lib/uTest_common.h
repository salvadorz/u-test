/**
 * @file uTest_common.h
 * @author Salvador Z
 * @version 1.0
 * @brief File for common Macros and datatypes for uTest Framework
 *
 */

#ifndef UTEST_COMMON_H_
#define UTEST_COMMON_H_

#ifdef __cplusplus
extern "C" {
#endif

// Includes

#define SEND_OUT() fflush(stdout)

#define uTEST_PRINT(msg, ...) \
  printf(msg, ##__VA_ARGS__); \
  SEND_OUT()

#ifndef uTEST_OK
  #define uTEST_OK (0U)
#endif

#ifndef uTEST_NOT_OK
  #define uTEST_NOT_OK (1U)
#endif

#ifndef PASS
  #define PASS (0U)
#endif

#ifndef DISABLE
  #define DISABLE (0U)
#endif

#ifndef ENABLE
  #define ENABLE (1U)
#endif

#if !defined(PASSED) && !defined(FAILED)
  #define PASSED(x)            (PASS == (x))
  #define FAILED(x)            (PASS != (x))
  #define EXPECTED_VAL(tst, x) ((tst) == (x))
#endif

#ifdef __cplusplus
}
#endif

#endif /* UTEST_COMMON_H_ */