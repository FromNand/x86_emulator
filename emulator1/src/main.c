#include<stdio.h>
#include<stdlib.h>
#include<type.h>
#include<arch.h>
#include<emulator.h>
#include<instruction.h>
#include<rm_data.h>

sint8 *registers_name[REGISTERS_COUNT] = { "eax", "ecx", "edx", "ebx", "esp", "ebp", "esi", "edi" };

void wait_enter(void){
	printf("please put enter...\n");
	while(getchar() != '\n');
	system("clear");
}

sint32 main(sint32 argc, sint8 *argv[]){
	// loop variable
	int i;

	// input check
	if(argc != 2) {
		printf("your command is incorrect!\n");
		printf("usage : ./semu_x86 input.bin\n");
		exit(1);
	}

	// initialization
	x86_ARCH *arch = create_emu(0x200U, argv[1], 0x7c00U, 0x7c00U);
	instruction_init();

	// wait
	wait_enter();

	// emulate
	uint8 opecode;
	while(arch->eip != 0){
		opecode = get_code8(arch, 0);
		printf("eip = %x, opecode = %x\n", arch->eip, opecode);

		if(instruction[opecode] == null){
			printf("opecode = %x\n", opecode);
			printf("this opecode is not implemented!!!\n\n");
			break;
		}

		instruction[opecode](arch);
	}

	// wait
	wait_enter();

	// show registers
	system("clear");
	printf("*****Registers*****\n\n");
	for(i = 0; i < REGISTERS_COUNT; i++){
		printf("%s : %x\n", registers_name[i], arch->registers[i]);
	}
	printf("eip : %x\n", arch->eip);

	// delete emu
	destroy_emu(arch);

	return 0;
}
