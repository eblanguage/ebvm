#pragma once

#include <cstdint>

#include "registers.hpp"

namespace eblang {
class VM;

class Processor {
 private:
  VM& vm;

 public:
  Processor(VM& vm);

  void Move(std::uint8_t dest, std::uint8_t src);
  void Add(std::uint8_t dest, std::uint8_t src);
  void Sub(std::uint8_t dest, std::uint8_t src);
  void Mul(std::uint8_t dest, std::uint8_t src);
  void Div(std::uint8_t dest, std::uint8_t src);
  void Mod(std::uint8_t dest, std::uint8_t src);

  void And(std::uint8_t dest, std::uint8_t src);
  void Or(std::uint8_t dest, std::uint8_t src);
  void Xor(std::uint8_t dest, std::uint8_t src);
  void Not(std::uint8_t dest);
  void Shl(std::uint8_t dest, std::uint8_t src);
  void Shr(std::uint8_t dest, std::uint8_t src);

  void Jump(std::uint8_t offset);
  void Call(std::uint8_t offset);
  void Ret();
};
}  // namespace eblang