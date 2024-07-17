#include <functional>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <tuple>
#include <vector>

#include "libft.h"

template <typename Ret, typename... Args>
void test_function(
    const std::string& function_name, Ret (*func)(Args...),
    const std::vector<std::pair<std::tuple<Args...>, Ret>>& test_cases) {
  for (const auto& [input, expected] : test_cases) {
    try {
      auto result = std::apply(func, input);
      if (result != expected) {
        std::ostringstream oss;
        oss << "Test failed for function " << function_name
            << " with parameters: ";
        std::apply([&oss](const Args&... args) { ((oss << args << " "), ...); },
                   input);
        oss << "\nExpected: " << expected << ", Got: " << result;
        throw std::runtime_error(oss.str());
      }
    } catch (const std::exception& e) {
      std::cerr << "Error: " << e.what() << std::endl;
    }
  }
  std::cout << "All tests passed for function " << function_name << std::endl;
}

void test_ft_isalpha() {
  std::vector<std::pair<std::tuple<int>, int>> test_cases = {
      {{'a'}, 1}, {{'z'}, 1}, {{'A'}, 1}, {{'Z'}, 1}, {{'0'}, 0},
      {{'9'}, 0}, {{' '}, 0}, {{'.'}, 0}, {{'/'}, 0}, {{'@'}, 0},
      {{'['}, 0}, {{'`'}, 0}, {{'{'}, 0}, {{'~'}, 0}};

  test_function("ft_isalpha", ft_isalpha, test_cases);
};

void test_ft_isdigit() {
  std::vector<std::pair<std::tuple<int>, int>> test_cases = {
      {{'a'}, 0}, {{'z'}, 0}, {{'A'}, 0}, {{'Z'}, 0}, {{'0'}, 1},
      {{'9'}, 1}, {{' '}, 0}, {{'.'}, 0}, {{'/'}, 0}, {{'@'}, 0},
      {{'['}, 0}, {{'`'}, 0}, {{'{'}, 0}, {{'~'}, 0}};

  test_function("ft_isdigit", ft_isdigit, test_cases);
};

void test_ft_isalnum() {
  std::vector<std::pair<std::tuple<int>, int>> test_cases = {
      {{'a'}, 1}, {{'z'}, 1}, {{'A'}, 1}, {{'Z'}, 1}, {{'0'}, 1},
      {{'9'}, 1}, {{' '}, 0}, {{'.'}, 0}, {{'/'}, 0}, {{'@'}, 0},
      {{'['}, 0}, {{'`'}, 0}, {{'{'}, 0}, {{'~'}, 0}};

  test_function("ft_isalnum", ft_isalnum, test_cases);
};

int main() {
  test_ft_isalpha();
  test_ft_isdigit();
  test_ft_isalnum();
  return 0;
}