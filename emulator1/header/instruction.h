#ifndef _INSTRUCTION_H
#define _INSTRUCTION_H

#include<arch.h>

typedef void func_inst(x86_ARCH *arch);
extern func_inst *instruction[256];

// operation function
/*void mov_r32_imm32(x86_ARCH *arch);
void short_jump(x86_ARCH *arch);
void near_jump(x86_ARCH *arch);*/

// set above function to function pointer
void instruction_init(void);

#endif
