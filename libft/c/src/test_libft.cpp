#include <functional>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>

#include "libft.h"

template <typename Ret, typename... Args>
void test_function(const std::string& function_name,
                   std::function<Ret(Args...)> func,
                   const std::vector<std::tuple<Args...>>& test_cases,
                   const std::vector<Ret>& expected_results) {
  if (test_cases.size() != expected_results.size()) {
    throw std::runtime_error(
        "Number of test cases doesn't match number of expected results");
  }

  for (size_t i = 0; i < test_cases.size(); ++i) {
    try {
      Ret result = std::apply(func, test_cases[i]);
      if (result != expected_results[i]) {
        std::ostringstream oss;
        oss << "Test failed for function " << function_name
            << " with parameters: ";
        std::apply([&oss](const Args&... args) { ((oss << args << " "), ...); },
                   test_cases[i]);
        oss << "\nExpected: " << expected_results[i] << ", Got: " << result;
        throw std::runtime_error(oss.str());
      }
    } catch (const std::exception& e) {
      std::cerr << "Error: " << e.what() << std::endl;
    }
  }
  std::cout << "All tests passed for function " << function_name << std::endl;
}

int main() {
  // Test ft_isalpha function
  std::function<int(int)> ft_isalpha_func = ft_isalpha;
  std::vector<std::tuple<int>> ft_isalpha_test_cases = {
      {'a'}, {'A'}, {'z'}, {'Z'}, {'1'}, {'0'}, {' '}, {'\n'}, {'\t'}};
  std::vector<int> ft_isalpha_expected_results = {1, 1, 1, 1, 0, 0, 0, 0, 0};

  test_function("ft_isalpha", ft_isalpha_func, ft_isalpha_test_cases,
                ft_isalpha_expected_results);

  // Test ft_isdigit function
  std::function<int(int)> ft_isdigit_func = ft_isdigit;
  std::vector<std::tuple<int>> ft_isdigit_test_cases = {
      {'a'}, {'A'}, {'z'}, {'Z'}, {'1'}, {'0'}, {' '}, {'\n'}, {'\t'}};
  std::vector<int> ft_isdigit_expected_results = {0, 0, 0, 0, 1, 1, 0, 0, 0};

  test_function("ft_isdigit", ft_isdigit_func, ft_isdigit_test_cases,
                ft_isdigit_expected_results);

  // Test ft_isalnum function
  std::function<int(int)> ft_isalnum_func = ft_isalnum;
  std::vector<std::tuple<int>> ft_isalnum_test_cases = {
      {'a'}, {'A'}, {'z'}, {'Z'}, {'1'}, {'0'}, {' '}, {'\n'}, {'\t'}};
  std::vector<int> ft_isalnum_expected_results = {1, 1, 1, 1, 1, 1, 0, 0, 0};

  test_function("ft_isalnum", ft_isalnum_func, ft_isalnum_test_cases,
                ft_isalnum_expected_results);

  // Test ft_isascii function
  std::function<int(int)> ft_isascii_func = ft_isascii;
  std::vector<std::tuple<int>> ft_isascii_test_cases = {{0},   {65},  {97},
                                                        {127}, {128}, {-1}};
  std::vector<int> ft_isascii_expected_results = {1, 1, 1, 1, 0, 0};

  test_function("ft_isascii", ft_isascii_func, ft_isascii_test_cases,
                ft_isascii_expected_results);

  return 0;
}