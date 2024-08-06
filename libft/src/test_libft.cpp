#include <cassert>
#include <climits>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include "libft.h"

// ANSI color codes
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"

template <typename Func, typename Input, typename Output>
void runTests(const std::vector<std::pair<Input, Output>>& testCases, Func func,
              const std::string& functionName) {
  bool allTestsPassed = true;
  int testCount = 0;

  std::cout << MAGENTA << "\n🧪 Running tests for function '" << functionName
            << "'" << RESET << std::endl;
  std::cout << BLUE << "=====================================" << RESET
            << std::endl;

  for (const auto& [input, expected] : testCases) {
    testCount++;
    Output result = func(input);

    std::cout << CYAN << "Test " << std::setw(3) << testCount << ": ";
    if (result == expected) {
      std::cout << GREEN << "✅ PASSED" << RESET;
    } else {
      std::cout << RED << "❌ FAILED" << RESET;
      allTestsPassed = false;
    }

    std::cout << " | Input: " << YELLOW << input << RESET
              << ", Expected: " << YELLOW << expected << RESET
              << ", Got: " << YELLOW << result << RESET << std::endl;
  }

  std::cout << BLUE << "=====================================" << RESET
            << std::endl;
  std::cout << MAGENTA << "📊 Test Results for '" << functionName << "': ";
  if (allTestsPassed) {
    std::cout << GREEN << "🎉 All " << testCount
              << " tests passed successfully! 🎉" << RESET << std::endl;
  } else {
    std::cout << RED << "😕 Some tests failed. Please review the results above."
              << RESET << std::endl;
  }
}

// Test cases for ft_isalpha
std::vector<std::pair<int, int>> isalpha_tests = {
    {'a', 1}, {'z', 1},     {'A', 1},    {'Z', 1},  // Basic alphabetic cases
    {'0', 0}, {'9', 0},     {' ', 0},    {'!', 0},  // Non-alphabetic cases
    {-1, 0},  {128, 0},  // Edge cases: negative and beyond ASCII
    {0, 0},   {INT_MAX, 0}, {INT_MIN, 0}  // Extreme values
};

// Test cases for ft_isdigit
std::vector<std::pair<int, int>> isdigit_tests = {
    {'0', 1}, {'9', 1},                             // Basic digit cases
    {'a', 0}, {'z', 0},     {'A', 0},    {'Z', 0},  // Alphabetic cases
    {' ', 0}, {'!', 0},                             // Non-alphanumeric cases
    {-1, 0},  {128, 0},  // Edge cases: negative and beyond ASCII
    {0, 0},   {INT_MAX, 0}, {INT_MIN, 0}  // Extreme values
};

// Test cases for ft_isalnum
std::vector<std::pair<int, int>> isalnum_tests = {
    {'a', 1}, {'z', 1},     {'A', 1},    {'Z', 1},  // Alphabetic cases
    {'0', 1}, {'9', 1},                             // Digit cases
    {' ', 0}, {'!', 0},     {'\n', 0},              // Non-alphanumeric cases
    {-1, 0},  {128, 0},  // Edge cases: negative and beyond ASCII
    {0, 0},   {INT_MAX, 0}, {INT_MIN, 0}  // Extreme values
};

// Test cases for ft_isascii
std::vector<std::pair<int, int>> isascii_tests = {
    {0, 1},       {127, 1},                          // ASCII range
    {-1, 0},      {128, 0},                          // Just outside ASCII range
    {'a', 1},     {'Z', 1},     {'0', 1}, {' ', 1},  // Various ASCII characters
    {INT_MIN, 0}, {INT_MAX, 0},                      // Extreme values
    {255, 0},     {256, 0}  // Extended ASCII and beyond
};

// Test cases for ft_isprint
std::vector<std::pair<int, int>> isprint_tests = {
    {' ', 1},  {'~', 1},  // First and last printable ASCII
    {31, 0},   {127, 0},  // Control characters
    {'a', 1},  {'Z', 1},     {'0', 1},
    {'@', 1},                              // Various printable characters
    {'\n', 0}, {'\t', 0},    {'\r', 0},    // Non-printable characters
    {-1, 0},   {128, 0},                   // Outside ASCII range
    {0, 0},    {INT_MAX, 0}, {INT_MIN, 0}  // Extreme values
};

// Test cases for ft_strlen
std::vector<std::pair<const char*, size_t>> strlen_tests = {
    {"", 0},                // Empty string
    {"Hello", 5},           // Basic string
    {"Hello, World!", 13},  // String with punctuation
    {"12345", 5},           // Numeric string
    {"\0Hidden", 0},        // String with null character
    {"Hi\0Hidden", 2},      // String with embedded null
    {"\n\t\r\v\f", 5},      // String with escape characters
    {"      ", 6},          // String with only spaces
    {"Lorem ipsum dolor sit amet, consectetur adipiscing elit.",
     56}  // Long string
};

// Test cases for ft_memset

void test_memset(void* (*ft_memset)(void*, int, size_t)) {
  std::cout << MAGENTA << "\n🧪 Running tests for function 'ft_memset'" << RESET
            << std::endl;
  std::cout << BLUE << "=====================================" << RESET
            << std::endl;

  std::vector<std::tuple<size_t, int, size_t, std::string>> test_cases = {
      {20, 'A', 20, "Fill entire buffer with 'A'"},
      {20, 'B', 10, "Fill partial buffer with 'B'"},
      {20, 0, 20, "Fill entire buffer with zero"},
      {20, 256 + 'C', 20, "Fill with non-char value (should be 'C')"},
      {4, 'x', 0, "Zero-length operation"}};

  int test_count = 0;
  bool all_tests_passed = true;

  for (const auto& [buf_size, value, set_size, description] : test_cases) {
    test_count++;
    char* buffer = new char[buf_size];
    char* expected = new char[buf_size];

    // Prepare expected result
    memset(expected, value, set_size);
    if (set_size < buf_size) {
      memset(expected + set_size, 0, buf_size - set_size);
    }

    // Run ft_memset
    ft_memset(buffer, value, set_size);

    bool test_passed = (memcmp(buffer, expected, buf_size) == 0);

    std::cout << CYAN << "Test " << std::setw(3) << test_count << ": ";
    if (test_passed) {
      std::cout << GREEN << "✅ PASSED" << RESET;
    } else {
      std::cout << RED << "❌ FAILED" << RESET;
      all_tests_passed = false;
    }

    std::cout << " | " << YELLOW << description << RESET << std::endl;

    if (!test_passed) {
      std::cout << "  Expected: ";
      for (size_t i = 0; i < buf_size; ++i) {
        std::cout << (isprint(expected[i]) ? expected[i] : '.');
      }
      std::cout << std::endl << "  Got:      ";
      for (size_t i = 0; i < buf_size; ++i) {
        std::cout << (isprint(buffer[i]) ? buffer[i] : '.');
      }
      std::cout << std::endl;
    }

    delete[] buffer;
    delete[] expected;
  }

  std::cout << BLUE << "=====================================" << RESET
            << std::endl;
  std::cout << MAGENTA << "📊 Test Results for 'ft_memset': ";
  if (all_tests_passed) {
    std::cout << GREEN << "🎉 All " << test_count
              << " tests passed successfully! 🎉" << RESET << std::endl;
  } else {
    std::cout << RED << "😕 Some tests failed. Please review the results above."
              << RESET << std::endl;
  }
}

int main() {
  runTests(isalpha_tests, ft_isalpha, "ft_isalpha");
  runTests(isdigit_tests, ft_isdigit, "ft_isdigit");
  runTests(isalnum_tests, ft_isalnum, "ft_isalnum");
  runTests(isascii_tests, ft_isascii, "ft_isascii");
  runTests(isprint_tests, ft_isprint, "ft_isprint");
  runTests(strlen_tests, ft_strlen, "ft_strlen");
  test_memset(ft_memset);

  return 0;
}