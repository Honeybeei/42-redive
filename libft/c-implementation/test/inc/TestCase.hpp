#ifndef TEST_CASE_HPP_
#define TEST_CASE_HPP_

#include <iostream>
#include <thread>
#include <vector>

#include "UI.hpp"

#define GIVE_DELAY false

class TestCase {
 public:
  // constructors & destructor
  TestCase();
  TestCase(int expected, int (*func_ptr)(int), int input);
  TestCase(size_t expected, size_t (*func_ptr)(const char *),
           const char *input);
  TestCase(void *expected, void *(*func_ptr)(void *, int, size_t), void *input1,
           int input2, size_t input3);
  ~TestCase();
  // getter
  bool getIsSuccess(void) const { return is_success_; }

 private:
  bool is_success_;

  // member functions
  template <typename Expected, typename Result, typename... Args>
  static void printSuccess(Expected expected, Result result, Args... args);
  template <typename Expected, typename Result, typename... Args>
  static void printFailure(Expected expected, Result result, Args... args);
  template <typename Expected, typename... Args>
  static void printException(Expected expected, std::string exception,
                             Args... args);

  // utility functions
  static void printDelay(int delay = 10);
};

#endif