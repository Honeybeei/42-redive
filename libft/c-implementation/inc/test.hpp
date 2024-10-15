#ifndef TEST_HPP
#define TEST_HPP

#include <cctype>
#include <functional>
#include <iostream>
#include <string>
#include <typeinfo>
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

// utils.cpp
template <typename Expected>
bool testFunction(const std::string &name, int (*func)(int), int arg1,
                  Expected expected);

void test_ft_isalnum(void);

#endif  // TEST_HPP
