#include<type.h>
#include<arch.h>

uint32 get_register32(x86_ARCH *arch, sint32 index){
	return arch->registers[index];
}

void set_register32(x86_ARCH *arch, uint32 data, sint32 index){
	if(index >= 0 && index <= 7){
		arch->registers[index] = data;
	}
}

sint8 get_sign_code8(x86_ARCH *arch, sint32 index){
	return arch->memory[arch->eip + index];
}

uint8 get_code8(x86_ARCH *arch, sint32 index){
	return arch->memory[arch->eip + index];
}

uint32 get_code32(x86_ARCH *arch, sint32 index){
	uint32 i, data = 0;
	for(i = 0; i < 4; i++){
		data |= arch->memory[arch->eip + index + i] << (8 * i);
	}
	return data;
}
