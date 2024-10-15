#include <exception>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "libft.h"

// Define ANSI color codes for printing
#define RESET "\033[0m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define CYAN "\033[36m"
#define YELLOW "\033[33m"
#define MAGENTA "\033[35m"
#define BLUE "\033[34m"

// Define emojis for better visual feedback
#define PASS_EMOJI "\xE2\x9C\x85"       // ✅
#define FAIL_EMOJI "\xE2\x9D\x8C"       // ❌
#define ERROR_EMOJI "\xF0\x9F\x92\xA5"  // 💥

// Print divider
void printDivider() {
  for (int i = 0; i < 80; i++) {
    std::cout << "-";
  }
  std::cout << std::endl;
}

// Template to test any function with exception handling
template <typename Func, typename Expected, typename... Args>
bool functionWrapper(Func func, Expected expected, Args... args) {
  auto result = func(args...);
  return result == expected;
}

// Test function that prints the result of a test
template <typename Func, typename Expected, typename... Args>
bool testFunction(const std::string &name, Func func, Expected expected,
                  Args... args) {
  bool result;
  // print function name and arguments
  std::cout << "Testing " << BLUE << name << RESET << " with arguments: ["
            << BLUE;
  std::stringstream ss;
  ((ss << args << ", "), ...);
  // pop the last comma and space
  std::cout << ss.str().substr(0, ss.str().size() - 2);
  std::cout << RESET << "] ... ";

  try {
    result = functionWrapper(func, expected, args...);
  } catch (std::exception &e) {
    std::cerr << RED << ERROR_EMOJI << " Exception: " << e.what() << RESET
              << std::endl;
    return false;
  }

  if (result) {
    std::cout << GREEN << PASS_EMOJI << " passed" << RESET << std::endl;
    return true;
  } else {
    std::cout << RED << FAIL_EMOJI << " failed" << RESET << std::endl;
    std::cout << YELLOW << "Expected: " << expected << RESET << std::endl;
    std::cout << MAGENTA << "Got     : " << func(args...) << RESET << std::endl;
    return false;
  }
}

int main(void) {}