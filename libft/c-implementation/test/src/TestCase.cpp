#include "TestCase.hpp"

// public **********************************************************************

//  constructors & destructor --------------------------------------------------

//  Default constructor
TestCase::TestCase() {}

//  Constructor - int function(int)
TestCase::TestCase(int expected, int (*func_ptr)(int), int input) {
  try {
    int result = func_ptr(input);
    if (result == expected) {
      printSuccess(expected, result, input);
      is_success_ = true;
    } else {
      printFailure(expected, result, input);
      is_success_ = false;
    }
  } catch (const std::exception &e) {
    printException(expected, e.what(), input);
    is_success_ = false;
  }
}

//  Constructor - size_t function(const char *)
TestCase::TestCase(size_t expected, size_t (*func_ptr)(const char *),
                   const char *input) {
  try {
    size_t result = func_ptr(input);
    if (result == expected) {
      printSuccess(expected, result, input);
      is_success_ = true;
    } else {
      printFailure(expected, result, input);
      is_success_ = false;
    }
  } catch (const std::exception &e) {
    printException(expected, e.what(), input);
    is_success_ = false;
  }
}

//  Constructor - void *function(void *, int, size_t)
TestCase::TestCase(void *expected, void *(*func_ptr)(void *, int, size_t),
                   void *input1, int input2, size_t input3) {
  try {
    void *result = func_ptr(input1, input2, input3);
    if (result == expected) {
      printSuccess(expected, result, input1, input2, input3);
      is_success_ = true;
    } else {
      printFailure(expected, result, input1, input2, input3);
      is_success_ = false;
    }
  } catch (const std::exception &e) {
    printException(expected, e.what(), input1, input2, input3);
    is_success_ = false;
  }
}
//  destructor
TestCase::~TestCase() {}

// private *********************************************************************

//  member functions -----------------------------------------------------------

template <typename Expected, typename Result, typename... Args>
void TestCase::printSuccess(Expected expected, Result result, Args... args) {
  printDelay();
  std::cout << GREEN << SUCCESS_EMOJI << " Success: " << RESET;
  std::cout << "Expected: " << BLUE << expected << RESET << ", ";
  std::cout << "Result: " << BLUE << result << RESET << ", ";
  std::cout << "Args: ";
  ((std::cout << args << ", "), ...);
  std::cout << std::endl;
}

template <typename Expected, typename Result, typename... Args>
void TestCase::printFailure(Expected expected, Result result, Args... args) {
  printDelay();
  std::cout << RED << FAILURE_EMOJI << " Failure: " << RESET;
  std::cout << "Expected: " << BLUE << expected << RESET << ", ";
  std::cout << "Result: " << MAGENTA << result << RESET << ", ";
  std::cout << "Args: ";
  ((std::cout << args << ", "), ...);
  std::cout << std::endl;
}

template <typename Expected, typename... Args>
void TestCase::printException(Expected expected, std::string exception,
                              Args... args) {
  printDelay();
  std::cout << YELLOW << EXCEPTION_EMOJI << " Exception: " << RESET;
  std::cout << "Expected: " << BLUE << expected << RESET << ", ";
  std::cout << "Exception: " << YELLOW << exception << RESET << ", ";
  std::cout << "Args: ";
  ((std::cout << args << ", "), ...);
  std::cout << std::endl;
}

void TestCase::printDelay(int delay) {
  if (!GIVE_DELAY) {
    return;
  }
  for (int i = 0; i < delay; i++) {
    std::cout << "." << std::flush;
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
  }
}