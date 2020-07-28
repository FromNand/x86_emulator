#ifndef _EMULATOR_H
#define _EMULATOR_H

#include<type.h>
#include<arch.h>

x86_ARCH* create_emu(uint32 mem_size, sint8 *filename, uint32 eip, uint32 esp);
void destroy_emu(x86_ARCH *arch);

#endif
