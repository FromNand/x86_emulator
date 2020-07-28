#include<type.h>
#include<arch.h>
#include<instruction.h>
#include<rm_data.h>

func_inst *instruction[256];

void mov_r32_imm32(x86_ARCH *arch){
	sint32 reg_index = arch->memory[arch->eip] - 0xb8;
	uint32 data = get_code32(arch, 1);
	set_register32(arch, data, reg_index);
	arch->eip += 5;
}

void short_jump(x86_ARCH *arch){
	sint8 diff = get_sign_code8(arch, 1);
	arch->eip += (2 + diff);
}

void near_jump(x86_ARCH *arch){
	sint32 diff = get_code32(arch, 1);
	arch->eip += (5 + diff);
}

void instruction_init(void){
	int i;

	// 命令を初期化する
	for(i = 0; i < 256; i++){
		instruction[i] = null;
	}

	/***** 命令を設定していく *****/

	// mov imm32 to r32
	for(i = 0; i < REGISTERS_COUNT; i++){
		instruction[0xb8 + i] = mov_r32_imm32;
	}

	// 8bit相対ジャンプ
	instruction[0xeb] = short_jump;

	// 32bit相対ジャンプ
	instruction[0xe9] = near_jump;
}
