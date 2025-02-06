#include <ebvm/ebvm.hpp>
#include <vector>

int main() {
  eblang::VM vm;
  static std::vector<std::uint8_t> code = {
      // clang-format off
    	0x1, 0, 1, // MOV R0, 1
			0x1, 1, 4,  // MOV R1, 4

      // TODO: Implement stack
      0xD, 0, // PUSH R0
      0xD, 1, // PUSH R1
      0xE, 0, // POP R0
      0xE, 1, // POP R1
      // clang-format on
  };
  vm.Load(code);
  vm.Execute();

  auto& processor = vm.GetProcessor();
  processor.Move(2, 8);
  processor.Move(3, 8);
  processor.Add(2, 3);
  vm.Dump();
}