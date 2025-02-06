#include "ebvm/ebvm.hpp"

#include <iostream>

#include "ebvm/processor.hpp"

namespace eblang {

VM::VM() : processor(*this), stack(*this) {}

void VM::Load(std::vector<std::uint8_t> data) {
  this->bytecode = std::move(data);
}

void VM::Execute() {
  while (pc < bytecode.size()) {
    Step();
  }
}

void VM::Step() {
  auto op = bytecode[pc++];

  switch (op) {
    case OP_DUMP: {
      Dump();
      break;
    }

    // Arithmetic
    case OP_MOV: {
      auto dest = bytecode[pc++];
      auto src = bytecode[pc++];
      processor.Move(dest, src);
      break;
    }
    case OP_ADD: {
      auto dest = bytecode[pc++];
      auto src = bytecode[pc++];
      processor.Add(dest, src);
      break;
    }
    case OP_SUB: {
      auto dest = bytecode[pc++];
      auto src = bytecode[pc++];
      processor.Sub(dest, src);
      break;
    }
    case OP_MUL: {
      auto dest = bytecode[pc++];
      auto src = bytecode[pc++];
      processor.Mul(dest, src);
      break;
    }
    case OP_DIV: {
      auto dest = bytecode[pc++];
      auto src = bytecode[pc++];
      processor.Div(dest, src);
      break;
    }
    case OP_MOD: {
      auto dest = bytecode[pc++];
      auto src = bytecode[pc++];
      processor.Mod(dest, src);
      break;
    }

    // Bitwise
    case OP_AND: {
      auto dest = bytecode[pc++];
      auto src = bytecode[pc++];
      processor.And(dest, src);
      break;
    }
    case OP_OR: {
      auto dest = bytecode[pc++];
      auto src = bytecode[pc++];
      processor.Or(dest, src);
      break;
    }
    case OP_XOR: {
      auto dest = bytecode[pc++];
      auto src = bytecode[pc++];
      processor.Xor(dest, src);
      break;
    }
    case OP_NOT: {
      auto dest = bytecode[pc++];
      processor.Not(dest);
      break;
    }
    case OP_SHL: {
      auto dest = bytecode[pc++];
      auto src = bytecode[pc++];
      processor.Shl(dest, src);
      break;
    }
    case OP_SHR: {
      auto dest = bytecode[pc++];
      auto src = bytecode[pc++];
      processor.Shr(dest, src);
      break;
    }

    // Stack
    case OP_PUSH: {
      auto value = bytecode[pc++];
      stack.Push(value);
      break;
    }
    case OP_POP: {
      auto dest = bytecode[pc++];
      processor.Move(dest, stack.Pop());
      break;
    }

    default: {
      throw std::runtime_error("Unknown instruction");
    }

      // Stack
      // case OP_PUSH: {
      //   stack.push_back(registers[REG_R0]);
      //   break;
      // }
      // case OP_POP: {
      //   registers[REG_R0] = stack.back();
      //   stack.pop_back();
      //   break;
      // }
  }
}

Processor& VM::GetProcessor() { return processor; }

Stack& VM::GetStack() { return stack; }

void VM::Dump() {
  std::cout << "PC: " << pc << " | " << "r0: " << registers[REG_R0]
            << " r1: " << registers[REG_R1] << " r2: " << registers[REG_R2]
            << " "
            << "r3: " << registers[REG_R3] << " | Stack: ";
  for (auto& value : stack.stack) {
    std::cout << static_cast<int>(value) << " ";
  }
  std::cout << std::endl;
}

}  // namespace eblang