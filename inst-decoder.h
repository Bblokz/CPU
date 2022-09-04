/* rv64-emu -- Simple 64-bit RISC-V simulator
 *
 *    inst-decoder.h - RISC-V instruction decoder.
 *
 * Copyright (C) 2016,2019  Leiden University, The Netherlands.
 */

#ifndef __INST_DECODER_H__
#define __INST_DECODER_H__

#include "reg-file.h"

#include <stdexcept>
#include <cstdint>
#include <unordered_map>

/* TODO: add enums and constants necessary for your instruction decoder. */
enum InstructionTypes{ RType,IType,SType,BType,UType,JType};

struct offsetParts {
  const uint32_t RD = 7; //also used for immediate for SType and BType
  const uint32_t Funct3 = 12; //also used for immediates for UType and JType
  const uint32_t RS1 = 15;
  const uint32_t RS2 = 20; //also used for immediate IType
  const uint32_t Funct7 = 25; //also used for immediate for SType and BType
};

struct sizeParts {
  const uint32_t Opcode = 7;
  const uint32_t RD = 5;
  const uint32_t Funct3 = 3;
  const uint32_t RS1 = 5;
  const uint32_t RS2 = 5;
  const uint32_t Funct7 = 7;
  const uint32_t I_imm = 12;
  const uint32_t S_imm = 7;
  const uint32_t B_imm = 7;
  const uint32_t U_imm = 20;
  const uint32_t J_imm = 20;
};

struct opcodeIdentifier {

    // funct 3 - opcode -> string
    std::unordered_map<std::string, std::pair<uint32_t,uint32_t>> opcodeToInstruction;
    opcodeIdentifier()
    {
        std::pair<uint32_t, uint32_t> newPair; std::string newString;
        newPair.first = (int)(0b000); newPair.second = (int)(0b1100111);
        newString = "JALR"; opcodeToInstruction.insert(newString, newPair);
        newPair.first = (int)(0b000); newPair.second = (int)(0b0110011);
        newString = "ADD"; opcodeToInstruction.insert(newString, newPair);
    }

    std::string getInstruction(uint32_t funct3, uint32_t Opcode)
    {
        if( funct3 == 9)
        {
            return "nope";
        }
        else
        {
            std::pair<uint32_t,uint32_t> pair;
            pair.first = funct3; pair.second = Opcode;
            return opcodeToInstruction[hallo];
        }
    }
};

/* Exception that should be thrown when an illegal instruction
 * is encountered.
 */
class IllegalInstruction : public std::runtime_error
{
  public:
    explicit IllegalInstruction(const std::string &what)
      : std::runtime_error(what)
    { }

    explicit IllegalInstruction(const char *what)
      : std::runtime_error(what)
    { }
};


/* InstructionDecoder component to be used by class Processor */
class InstructionDecoder
{
  public:
    void                setInstructionWord(const uint32_t instructionWord);
    uint32_t            getInstructionWord() const;

    RegNumber           getRS1();
    RegNumber           getRS2();
    RegNumber           getRS2();
    
    uint8_t             getOP(); 

    /* TODO: probably want methods to get opcode, function code */

    /* TODO: need a method to obtain the immediate */

  private:
    uint32_t instructionWord;
    offsetParts offsets;
    sizeParts sizes;
    uint32_t opcode;
    uint32_t rd;
    uint32_t funct3;
    uint32_t rs1;
    uint32_t rs2;  
    uint32_t funct7;
    uint32_t i_imm;
    uint32_t s_imm;    
    uint32_t b_imm;    
    uint32_t u_imm;
    uint32_t j_imm;

    opcodeIdentifier identifier;
    uint32_t split (uint32_t offset, uint32_t size);
    void           calcOP();
};

std::ostream &operator<<(std::ostream &os, const InstructionDecoder &decoder);

#endif /* __INST_DECODER_H__ */
