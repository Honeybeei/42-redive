#include "Test.hpp"

// Print a divider line
static void printDivider(std::string color = RESET, int width = 80) {
  std::string line(width, '-');
  std::cout << color << line << RESET << std::endl;
}

// Print the start of a test function
static void printStart(std::string func_name) {
  // 80 characters wide, centered text
  std::string title = START_EMOJI + std::string(" ") + func_name;
  int padding_left = (80 - title.length()) / 2;
  int padding_right = 80 - title.length() - padding_left;
  printDivider();
  std::cout << "|" << std::string(padding_left, ' ') << CYAN << title << RESET
            << std::string(padding_right, ' ') << "|" << std::endl;
  printDivider();
}

// Print the result of a test case
static void printResult(std::vector<TestCase> &test_cases) {
  int success_count = 0;
  for (std::vector<TestCase>::iterator it = test_cases.begin();
       it != test_cases.end(); it++) {
    if (it->getIsSuccess()) {
      success_count++;
    }
  }
  double success_rate = (double)success_count / test_cases.size() * 100;
  std::cout << std::endl;
  std::cout << "Success rate: " << success_count << "/" << test_cases.size()
            << " (" << success_rate << "%)" << std::endl;
  if (success_count == test_cases.size()) {
    std::cout << GREEN << SUCCESS_EMOJI << " All test cases passed" << RESET
              << std::endl;
  } else {
    std::cout << RED << FAILURE_EMOJI << " Some test cases failed" << RESET
              << std::endl;
  }
  std::cout << std::endl;
}

// ft_isalpha
void test_ft_isalpha(void) {
  std::string func_name = "ft_isalpha";
  printStart(func_name);
  std::vector<TestCase> test_cases;
  test_cases.push_back(TestCase(1, ft_isalpha, 'a'));
  test_cases.push_back(TestCase(1, ft_isalpha, 'z'));
  test_cases.push_back(TestCase(1, ft_isalpha, 'A'));
  test_cases.push_back(TestCase(1, ft_isalpha, 'Z'));
  test_cases.push_back(TestCase(0, ft_isalpha, '0'));
  test_cases.push_back(TestCase(0, ft_isalpha, '9'));
  test_cases.push_back(TestCase(0, ft_isalpha, ' '));
  test_cases.push_back(TestCase(0, ft_isalpha, '\n'));
  test_cases.push_back(TestCase(0, ft_isalpha, '\t'));
  test_cases.push_back(TestCase(0, ft_isalpha, '\v'));
  test_cases.push_back(TestCase(0, ft_isalpha, '\f'));
  test_cases.push_back(TestCase(0, ft_isalpha, '\r'));
  test_cases.push_back(TestCase(0, ft_isalpha, '\0'));
  test_cases.push_back(TestCase(0, ft_isalpha, -1));
  test_cases.push_back(TestCase(0, ft_isalpha, 256));
  test_cases.push_back(TestCase(0, ft_isalpha, 2147483647));
  test_cases.push_back(TestCase(0, ft_isalpha, -2147483648));
  test_cases.push_back(TestCase(0, ft_isalpha, 2147483648));
  test_cases.push_back(TestCase(0, ft_isalpha, -2147483649));
  test_cases.push_back(TestCase(0, ft_isalpha, 4294967295));
  test_cases.push_back(TestCase(0, ft_isalpha, -4294967296));
  test_cases.push_back(TestCase(0, ft_isalpha, 4294967296));
  test_cases.push_back(TestCase(0, ft_isalpha, -4294967297));
  test_cases.push_back(TestCase(0, ft_isalpha, 9223372036854775807));
  test_cases.push_back(TestCase(0, ft_isalpha, -9223372036854775808));
  test_cases.push_back(TestCase(0, ft_isalpha, 9223372036854775808));
  test_cases.push_back(TestCase(0, ft_isalpha, -9223372036854775809));
  test_cases.push_back(TestCase(0, ft_isalpha, 18446744073709551615));
  printResult(test_cases);
}