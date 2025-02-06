#pragma once

#include <cstdint>

namespace eblang {
enum : std::uint8_t {
  OP_DUMP = 123,

  OP_HALT = 0x00,
  OP_MOV = 0x01,
  OP_ADD = 0x02,
  OP_SUB = 0x03,
  OP_MUL = 0x04,
  OP_DIV = 0x05,
  OP_MOD = 0x06,

  OP_AND = 0x07,
  OP_OR = 0x08,
  OP_XOR = 0x09,
  OP_NOT = 0x0A,
  OP_SHL = 0x0B,
  OP_SHR = 0x0C,

  OP_PUSH = 0x0D,
  OP_POP = 0x0E,
  OP_JMP = 0x0F,
  OP_CALL = 0x10,
  OP_RET = 0x11,
};

}  // namespace eblang