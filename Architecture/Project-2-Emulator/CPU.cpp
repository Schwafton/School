/******************************
 * Submitted by: Afton Schwendiman, as1425
 * CS 3339 - Spring 2022, Texas State University
 * Project 2 Emulator
 * Copyright 2021, Lee B. Hinkle, all rights reserved
 * Based on prior work by Martin Burtscher and Molly O'Neil
 * Redistribution in source or binary form, with or without modification,
 * is *not* permitted. Use in source or binary form, with or without
 * modification, is only permitted for academic use in CS 3339 at
 * Texas State University.
 ******************************/

#include "CPU.h"

const string CPU::regNames[] = {"$zero","$at","$v0","$v1","$a0","$a1","$a2","$a3",
                                "$t0","$t1","$t2","$t3","$t4","$t5","$t6","$t7",
                                "$s0","$s1","$s2","$s3","$s4","$s5","$s6","$s7",
                                "$t8","$t9","$k0","$k1","$gp","$sp","$fp","$ra"};

CPU::CPU(uint32_t pc, Memory &iMem, Memory &dMem) : pc(pc), iMem(iMem), dMem(dMem) {
  for(int i = 0; i < NREGS; i++) {
    regFile[i] = 0;
  }
  hi = 0;
  lo = 0;
  regFile[28] = 0x10008000; // gp
  regFile[29] = 0x10000000 + dMem.getSize(); // sp

  instructions = 0;
  stop = false;
}

void CPU::run() {
  while(!stop) {
    instructions++;

    fetch();
    decode();
    execute();
    mem();
    writeback();

    D(printRegFile());
  }
}

void CPU::fetch() {
  instr = iMem.loadWord(pc);
  pc = pc + 4;
}

/////////////////////////////////////////
// ALL YOUR CHANGES GO IN THIS FUNCTION 
/////////////////////////////////////////
void CPU::decode() {
  uint32_t opcode;      // opcode field
  uint32_t rs, rt, rd;  // register specifiers
  uint32_t shamt;       // shift amount (R-type)
  uint32_t funct;       // funct field (R-type)
  uint32_t uimm;        // unsigned version of immediate (I-type)
  int32_t simm;         // signed version of immediate (I-type)
  uint32_t addr;        // jump address offset field (J-type)

  opcode = (instr >> 26); /* FIXME */
  rs = (instr >> 21) & 0x1f; /* FIXME */
  rt = (instr >> 16) & 0x1f; /* FIXME */
  rd = (instr >> 11) & 0x1f; /* FIXME */
  shamt = (instr >> 6) & 0x1f; /* FIXME */
  funct = instr & 0x3f; /* FIXME */
  uimm = instr & 0xffff; /* FIXME */
  simm = ((signed)uimm << 16) >> 16; /* FIXME */
  addr = instr & 0x3ffffff; /* FIXME */

  // Hint: you probably want to give all the control signals some "safe"
  // default value here, and then override their values as necessary in each
  // case statement below!

  /* Control signals (from cpu.h)
  bool opIsLoad, opIsStore, opIsMultDiv;
  ALU_OP aluOp;
  bool writeDest;
  int destReg;
  unt32_t aluSrc1, aluSrc2, storeData
  */
  opIsLoad = false;
  opIsStore = false;
  opIsMultDiv = false;
  aluOp = ADD;
  writeDest = false;
  destReg = REG_ZERO;
  aluSrc1 = regFile[REG_ZERO];
  aluSrc2 = regFile[REG_ZERO];
  storeData = 0;

  /* alu ops (from alu.h): 
    ADD: return (signed)src1+(signed)src2
    AND: return src1$src2
    SHF_L: return src1<<src2
    SHF_R: return (signed)src1>>src2
    CMP_LT: return ((signed)src1<(signed)src2)?1:0
    MUL: wide=src1*src2, lo=wide&0xffffffff, up=wide>>32D
    DIV: lo=src1/src2, up=arc1%src2
  */
  
  D(cout << "  " << hex << setw(8) << pc - 4 << ": ");
  switch(opcode) {
    case 0x00:
      switch(funct) {
        case 0x00: D(cout << "sll " << regNames[rd] << ", " << regNames[rs] << ", " << dec << shamt);
                   writeDest = true; destReg = rd;
                   aluOp = SHF_L;
                   aluSrc1 = regFile[rs];
                   aluSrc2 = shamt;
                   break; // use prototype above, not the greensheet
        case 0x03: D(cout << "sra " << regNames[rd] << ", " << regNames[rs] << ", " << dec << shamt);
                   writeDest = true; destReg = rd;
                   aluOp = SHF_R;
                   aluSrc1 = regFile[rs];
                   aluSrc2 = shamt;
                   break; // use prototype above, not the greensheet
        case 0x08: D(cout << "jr " << regNames[rs]);
                   aluSrc1 = regFile[rs];
                   pc = regFile[rs];
                   break;
        case 0x10: D(cout << "mfhi " << regNames[rd]);
                   writeDest = true; destReg = rd;
                   aluSrc1 = hi;
                   break;
        case 0x12: D(cout << "mflo " << regNames[rd]);
                   writeDest = true; destReg = rd;
                   aluSrc1 = lo;
                   break;
        case 0x18: D(cout << "mult " << regNames[rs] << ", " << regNames[rt]);
                   opIsMultDiv = true;
                   aluOp = MUL;
                   aluSrc1 = regFile[rs];
                   aluSrc2 = regFile[rt];
                   break;
        case 0x1a: D(cout << "div " << regNames[rs] << ", " << regNames[rt]);
                   opIsMultDiv = true;
                   aluOp = DIV;
                   aluSrc1 = regFile[rs];
                   aluSrc2 = regFile[rt];
                   break;
        case 0x21: D(cout << "addu " << regNames[rd] << ", " << regNames[rs] << ", " << regNames[rt]);
                   writeDest = true; destReg = rd;
                   aluSrc1 = regFile[rs];
                   aluSrc2 = regFile[rt];
                   break;
        case 0x23: D(cout << "subu " << regNames[rd] << ", " << regNames[rs] << ", " << regNames[rt]);
                   writeDest = true; destReg = rd;
                   aluSrc1 = regFile[rs];
                   aluSrc2 = -regFile[rt];
                   break; //hint: subtract is the same as adding a negative
        case 0x2a: D(cout << "slt " << regNames[rd] << ", " << regNames[rs] << ", " << regNames[rt]);
                   writeDest = true; destReg = rd;
                   aluOp = CMP_LT;
                   aluSrc1 = regFile[rs];
                   aluSrc2 = regFile[rt];
                   break;
        default: cerr << "unimplemented instruction: pc = 0x" << hex << pc - 4 << endl;
      }
      break;
    case 0x02: D(cout << "j " << hex << ((pc & 0xf0000000) | addr << 2)); // P1: pc + 4
               pc = (pc & 0xf0000000) | addr << 2;
               break;
    case 0x03: D(cout << "jal " << hex << ((pc & 0xf0000000) | addr << 2)); // P1: pc + 4
               writeDest = true; destReg = REG_RA; // writes PC+4 to $ra
               aluOp = ADD; //ALU should pass pc thru unchanged
               aluSrc1 = pc;
               aluSrc2 = regFile[REG_ZERO]; // always reads zero
               pc = (pc & 0xf0000000) | addr << 2;
               break;
    case 0x04: D(cout << "beq " << regNames[rs] << ", " << regNames[rt] << ", " << pc + (simm << 2));
               if (regFile[rs] == regFile[rt]) {
                 pc = pc + (simm << 2);
               }
               break;  // read the handout carefully, update PC directly here as in jal example
    case 0x05: D(cout << "bne " << regNames[rs] << ", " << regNames[rt] << ", " << pc + (simm << 2));
               if (regFile[rs] != regFile[rt]) {
                 pc = pc + (simm << 2);
               }
               break;  // same comment as beq
    case 0x09: D(cout << "addiu " << regNames[rt] << ", " << regNames[rs] << ", " << dec << simm);
               writeDest = true; destReg = rt;
               aluSrc1 = regFile[rs];
               aluSrc2 = simm;
               break;
    case 0x0c: D(cout << "andi " << regNames[rt] << ", " << regNames[rs] << ", " << dec << uimm);
               break;
    case 0x0f: D(cout << "lui " << regNames[rt] << ", " << dec << simm);
               break; //use the ALU to execute necessary op, you may set aluSrc2 = xx directly
    case 0x1a: D(cout << "trap " << hex << addr);
               switch(addr & 0xf) {
                 case 0x0: cout << endl; break;
                 case 0x1: cout << " " << (signed)regFile[rs];
                           break;
                 case 0x5: cout << endl << "? "; cin >> regFile[rt];
                           break;
                 case 0xa: stop = true; break;
                 default: cerr << "unimplemented trap: pc = 0x" << hex << pc - 4 << endl;
                          stop = true;
               }
               break;
    case 0x23: D(cout << "lw " << regNames[rt] << ", " << dec << simm << "(" << regNames[rs] << ")");
               
               break;  // do not interact with memory here - setup control signals for mem()
    case 0x2b: D(cout << "sw " << regNames[rt] << ", " << dec << simm << "(" << regNames[rs] << ")");
               break;  // same comment as lw
    default: cerr << "unimplemented instruction: pc = 0x" << hex << pc - 4 << endl;
  }
  D(cout << endl);
}

void CPU::execute() {  // needed: aluOut, aluOp, aluSrc1, aluSrc2
  aluOut = alu.op(aluOp, aluSrc1, aluSrc2);
}

void CPU::mem() {  // needed: opIsLoad, writeData, opIsStore, storeData
  if(opIsLoad)
    writeData = dMem.loadWord(aluOut);      
  else
    writeData = aluOut;

  if(opIsStore)
    dMem.storeWord(storeData, aluOut);
}

void CPU::writeback() {  // needed: writeDest, destReg, writeData
  if(writeDest && destReg > 0) // skip when write is to zero_register
    regFile[destReg] = writeData;
  
  if(opIsMultDiv) {  // needed: opIsMultDiv
    hi = alu.getUpper();
    lo = alu.getLower();
  }
}

void CPU::printRegFile() {
  cout << hex;
  for(int i = 0; i < NREGS; i++) {
    cout << "    " << regNames[i];
    if(i > 0) cout << "  ";
    cout << ": " << setfill('0') << setw(8) << regFile[i];
    if( i == (NREGS - 1) || (i + 1) % 4 == 0 )
      cout << endl;
  }
  cout << "    hi   : " << setfill('0') << setw(8) << hi;
  cout << "    lo   : " << setfill('0') << setw(8) << lo;
  cout << dec << endl;
}

void CPU::printFinalStats() {
  cout << "Program finished at pc = 0x" << hex << pc << "  ("
       << dec << instructions << " instructions executed)" << endl;
}
