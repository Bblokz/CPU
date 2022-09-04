/* rv64-emu -- Simple 64-bit RISC-V simulator
 *
 *    inst-decoder.cc - RISC-V instruction decoder.
 *
 * Copyright (C) 2016,2019  Leiden University, The Netherlands.
 *
 */

#include "inst-decoder.h"

#include <functional>
#include <map>

/*
InstructionDecoder::InstructionDecoder()
{
    instructionWord = 0;
    offsetParts offsets = 0;
    sizeParts sizes = 0;

}
*/

uint32_t bitmask (uint32_t position){
  return (1 << position) - 1;
}

uint32_t InstructionDecoder::split (const uint32_t offset, const uint32_t size){
  return (instructionWord >> offset) & bitmask(size);
}

/*
 * Class InstructionDecoder -- helper class for getting specific
 * information from the decoded instruction.
 */

void
InstructionDecoder::setInstructionWord(const uint32_t instructionWord)
{
  this->instructionWord = instructionWord;
}

uint32_t
InstructionDecoder::getInstructionWord() const
{
  return instructionWord;
}

RegNumber
InstructionDecoder::getRS1()
{
  return split(offsets.RS1,sizes.RS1);
}

RegNumber
InstructionDecoder::getRS2()
{
  /* TODO: implement */

  return split(offsets.RS2,sizes.RS2);
}

RegNumber
InstructionDecoder::getRD()
{
  /* TODO: implement */

  return split(offsets.RD,sizes.RD);
}

void
InstructionDecoder::calcOP()
{
  opcode = split(0,sizes.Opcode);
  funct3 = split(offsets.Funct3,sizes.Funct3);
  std::cout<<"identified: "<<identifier.getInstruction(funct3,opcode)<<std::endl;
}

//mindnumb ez voor andere delen TODO
