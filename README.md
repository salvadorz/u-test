![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white) ![CMake](https://img.shields.io/badge/CMake-%23008FBA.svg?style=for-the-badge&logo=cmake&logoColor=white)

----
#  µ-Test ㎌ramework

![Static Badge](https://img.shields.io/badge/-95%25-green?style=flat&logo=github&label=Coverage&color=green) ![GitHub](https://img.shields.io/github/license/salvadorz/embedded_c_utils?style=flat&logo=github) [![uTest-CI](https://github.com/salvadorz/u-test/actions/workflows/cmake.yml/badge.svg?branch=develop)](https://github.com/salvadorz/u-test/actions/workflows/cmake.yml)

This ㎌ramework is intended to make an easy validation of C/C++ Code by comparing the expected vs the received value from the function.
This comparison could be by comparing the values it self or by logical expressions.

## Usage
 To create a test cases you can easy do by using the macros provided in the API.

 The general (easy-way) method is:
 ```c
  #include "uTest.h"

  // define the function wich perform a specific test case with void signature
  void test_functionMath(void){
    int expected = 13;
    int received = add(5,8);

    TEST_ASSERT_EQUAL_VAL_MSG(expected, received, "Checking sum function");

    float expected_float = 12.5f;
    float reveived_float = mul(5.0,2.5f);
    TEST_ASSERT_EQUAL_FLOAT_MSG(expected_float, reveived_float, "Checking mul function");

  }

  // Now we need to subscribe the test cases
  int main(){
    uTEST_START(); // Registers this file as part of a test
    // Register each test case uTEST_ADD_MSG(test_function, "Test message");
    uTEST_ADD_MSG(test_functionMath, "Circular Buffers test using a custom struct");
    // Finalize the test in order to provide a report
    return (uTEST_END());
  }

 ```

 ### Example

 ```c

 #include "cbuff.h"
 #include "uTest.h"

 #define BUFFER_SIZE (5)

 void test_cbuff_lib(void) {
  my_struct_t obj = { 0 };
  my_struct_t cb_buffer[BUFFER_SIZE];
  cbuff_t cb_buffer_struct = { 0 };
  TEST_ASSERT_EQUAL_VAL_MSG(OK, cbuff_init(&cb_buffer_struct, cb_buffer, BUFFER_SIZE, sizeof(my_struct_t)), "Init failed");

  for (int i = 0; i < BUFFER_SIZE; ++i) {
    ++obj.data;
    TEST_ASSERT_EQUAL_VAL(OK, cbuff_push(&cb_buffer_struct, &obj, false));
    TEST_ASSERT_EQUAL_VAL((BUFFER_SIZE - 1) - i, CBUFF_SPACES(cb_buffer_struct));
  }
  // The Buffer should be full
  TEST_ASSERT_EQUAL_VAL(BUSY_W, cbuff_push(&cb_buffer_struct, &obj, false));
  TEST_ASSERT_EQUAL_VAL(0, CBUFF_SPACES(cb_buffer_struct));

  for (int i = 0; i < BUFFER_SIZE; ++i) {
    TEST_ASSERT_EQUAL_VAL(OK, cbuff_pop(&cb_buffer_struct, &obj, false));
    TEST_ASSERT_EQUAL_VAL(i + 1, obj.data);
  }

  // The Buffer should be empty
  TEST_ASSERT_EQUAL_VAL(NOT_OK, cbuff_pop(&cb_buffer_struct, &obj, false));
  TEST_ASSERT_EQUAL_VAL(BUFFER_SIZE, CBUFF_SPACES(cb_buffer_struct));
}

void test_cbuff_overwrite(void) {
  my_struct_t obj = { 0 };
  for (int i = 1; i <= BUFFER_SIZE * 2; ++i) {
    obj.data = i;
    TEST_ASSERT_EQUAL_VAL(OK, CBUFF_PUSH(my_cb, &obj));
  }
  for (int i = 1; i <= BUFFER_SIZE; ++i) {
    TEST_ASSERT_EQUAL_VAL(OK, CBUFF_POP(my_cb, &obj));
    TEST_ASSERT_EQUAL_VAL((BUFFER_SIZE + i), obj.data);
  }
  // Testing error
  TEST_ASSERT_EQUAL_VAL(NOT_OK, CBUFF_PUT(my_cb, NULL));
}

int main() {
  uTEST_START();
  uTEST_ADD_MSG(test_cbuff_lib, "Circular Buffers test using a custom struct");
  uTEST_ADD_MSG(test_cbuff_overwrite, "Circular Buffers test with a push forced");
  return (uTEST_END());
}
 ```

 ## Report

 If all test succeeded then a report with `Test Result: PASS`` it's given and returns with EXIT_SUCCESS. Also provides a report which gives the number of total assertions on each test case subscribed.

 [![uTest Report](https://user-images.githubusercontent.com/32500615/252052901-ad890395-abca-41d1-900c-8ae6b801d23a.png)](https://github.com/salvadorz/u-test/blob/develop/README "I'm a Summary Rport from uTest! duh...")

 ### Failure case
 If an error it's detected within a test case (function) then that test_function will skip the remaining test cases and will proceed with the next test case subscribed. Although you can configure to perform all test cases even on a failure case within the test function. On the report you will see in which line of the `TEST_ASSERT_EQUAL...()` failed and a message with the details.
 
[![uTest Report](https://user-images.githubusercontent.com/32500615/252053388-da797b95-d20c-4182-a02b-02982d33438a.png)](https://github.com/salvadorz/u-test/blob/develop/README "I'm a Summary Report with a failure from uTest! duh...")

> This report give a failure assertion in line `30` and line `68` and also mentions which was the expected value and which value was returned from the function.