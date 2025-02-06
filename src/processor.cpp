#include <iostream>

#include "ebvm/ebvm.hpp"

namespace eblang {

Processor::Processor(VM& vm) : vm(vm) {}

void Processor::Move(std::uint8_t dest, std::uint8_t src) {
  vm.registers[dest] = src;
}

void Processor::Add(std::uint8_t dest, std::uint8_t src) {
  vm.registers[dest] += vm.registers[src];
}

void Processor::Sub(std::uint8_t dest, std::uint8_t src) {
  vm.registers[dest] -= vm.registers[src];
}

void Processor::Mul(std::uint8_t dest, std::uint8_t src) {
  vm.registers[dest] *= vm.registers[src];
}

void Processor::Div(std::uint8_t dest, std::uint8_t src) {
  vm.registers[dest] /= vm.registers[src];
}

void Processor::Mod(std::uint8_t dest, std::uint8_t src) {
  vm.registers[dest] %= vm.registers[src];
}

void Processor::And(std::uint8_t dest, std::uint8_t src) {
  vm.registers[dest] &= vm.registers[src];
}

void Processor::Or(std::uint8_t dest, std::uint8_t src) {
  vm.registers[dest] |= vm.registers[src];
}

void Processor::Xor(std::uint8_t dest, std::uint8_t src) {
  vm.registers[dest] ^= vm.registers[src];
}

void Processor::Not(std::uint8_t dest) {
  vm.registers[dest] = ~vm.registers[dest];
}

void Processor::Shl(std::uint8_t dest, std::uint8_t src) {
  vm.registers[dest] <<= vm.registers[src];
}

void Processor::Shr(std::uint8_t dest, std::uint8_t src) {
  vm.registers[dest] >>= vm.registers[src];
}

void Processor::Jump(std::uint8_t offset) { vm.pc = offset; }

void Processor::Call(std::uint8_t offset) { vm.stack.push_back(vm.pc); }

void Processor::Ret() {
  vm.pc = vm.stack.back();
  std::cout << "1PC: " << vm.pc << std::endl;
  vm.stack.pop_back();
}

}  // namespace eblang