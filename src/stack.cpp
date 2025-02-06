#include "ebvm/ebvm.hpp"

namespace eblang {

Stack::Stack(VM& vm) : vm(vm) {}

void Stack::Push(std::uint8_t value) { stack.push_back(value); }

std::uint8_t Stack::Pop() {
  auto value = stack.back();
  stack.pop_back();
  return value;
}

}  // namespace eblang