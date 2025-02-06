#pragma once

#include <cstdint>
#include <vector>

namespace eblang {
class VM;

class Stack {
 private:
  VM& vm;

 public:
  std::vector<std::uint8_t> stack;

  Stack(VM& vm);

  void Push(std::uint8_t value);
  std::uint8_t Pop();
};

}  // namespace eblang