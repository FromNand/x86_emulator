#ifndef _RM_DATA_H
#define _RM_DATA_H

#include<type.h>
#include<arch.h>

// about registers
uint32 get_register32(x86_ARCH *arch, sint32 index);
void set_register32(x86_ARCH *arch, uint32 data, sint32 index);

// about memory
sint8 get_sign_code8(x86_ARCH *arch, sint32 index);
uint8 get_code8(x86_ARCH *arch, sint32 index);
uint32 get_code32(x86_ARCH *arch, sint32 index);

#endif
