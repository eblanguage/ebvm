#pragma once

#include <array>
#include <cstddef>
#include <cstdint>
#include <stack>
#include <vector>

#include "opcodes.hpp"
#include "processor.hpp"
#include "stack.hpp"

namespace eblang {
using cell_t = std::uintptr_t;
class VM {
 private:
  friend class Processor;
  friend class Stack;

  std::array<cell_t, 4> registers{};
  std::vector<std::uint8_t> bytecode{};
  std::stack<std::uintptr_t> call_stack{};
  std::vector<std::uint8_t> heap;
  std::uintptr_t pc{};

  Processor processor;
  Stack stack;

  void Step();

 public:
  VM();

  void Load(std::vector<std::uint8_t> code);
  void Execute();

  void Dump();

  Processor& GetProcessor();
  Stack& GetStack();
};
}  // namespace eblang