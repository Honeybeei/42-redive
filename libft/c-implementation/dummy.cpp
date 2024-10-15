#include <iostream>
#include <stdexcept>
#include <string>
#include <typeinfo>

int main(void) {
  // just want to test what typeid is
  std::cout << typeid(std::exception).name() << std::endl;
  std::cout << typeid(std::runtime_error).name() << std::endl;
  try {
    throw std::runtime_error("test");
  } catch (const std::exception& e) {
    std::cout << typeid(e).name() << std::endl;
  }
}