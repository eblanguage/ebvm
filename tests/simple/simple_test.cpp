#include <ebvm/ebvm.hpp>
#include <iostream>
#include <vector>

int main() {
  eblang::VM vm;
  static std::vector<std::uint8_t> code = {
      // clang-format off
      123, // Dump
    	0x1, 0, 1, // MOV R0, 1
			0x1, 1, 4,  // MOV R1, 4
      0xF, 10,  // JMP 10
      0x12, // Unknown instruction
      123, // Dump
      // 0x0, // HALT

      // TODO: Implement stack
      0xD, 98, // PUSH R0
      0xD, 78, // PUSH R1
      0xE, 0, // POP R0
      0xE, 1, // POP R1
      123, // Dump

      0xD, 0, // PUSH R0
      0xD, 1, // PUSH R1
      0x10, 27, // CALL 0
      123, // Dump

      0xE, 0, // POP R0
      0xE, 1, // POP R1
      0x11, // RET

      // clang-format on
  };
  vm.Load(code);

  try {
    vm.Execute();
  } catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  auto& processor = vm.GetProcessor();
  // processor.Move(2, 8);
  // processor.Move(3, 8);
  // processor.Add(2, 3);
  // processor.Jump(0);
  // vm.Dump();
}