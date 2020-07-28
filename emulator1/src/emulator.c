#include<stdio.h>
#include<stdlib.h>
#include<type.h>
#include<arch.h>

void show_arch_info(x86_ARCH *arch, sint32 alloc_flag){
	// loop variable
	int i;

	// failure
	if (alloc_flag == 0){
		printf("failure!\n");
		printf("can't alloc 0x200 byte memory.\n");
		printf("memory can't be alloced.\n");
		exit(1);
	}
	// succeed
	else {
		printf("succeeed!\n\n");
		printf("show arch information...\n\n");
		printf("*****[Registers]*****\n");
		for(i = 0; i < REGISTERS_COUNT; i++){
			printf("%s = 0x%x\n", registers_name[i], arch->registers[i]);
		}
		printf("\n*****[Memory]*****\n");
		printf("memory is from %p and size is 0x%x\n", arch->memory, 0x200U);
		printf("\n*****[EIP, EFLAGS]*****\n");
		printf("eip = 0x%x, eflags = 0x%x\n\n", arch->eip, arch->eflags);
	}

	return;
}

x86_ARCH* create_emu(uint32 mem_size, sint8 *filename, uint32 eip, uint32 esp){
	int i;

	// create arch
	x86_ARCH *arch = malloc(sizeof(x86_ARCH));

	// clear registers
	for(i = 0; i < REGISTERS_COUNT; i++){
		arch->registers[i] ^= arch->registers[i];
	}

	// alloc memory
	arch->memory = malloc(mem_size);

	// initialize eip
	arch->eip = eip;

	// initialize esp
	arch->registers[ESP] = esp;

	// clear eflags
	arch->eflags ^= arch->eflags;

	// load program
	FILE *fp = fopen(filename, "rb");
	if(fp == null){
		printf("input file isn't exist!\n");
		exit(1);
	}
	fread(arch->memory + arch->eip, 1, 0x200, fp);

	// show info and check arch and memory
	printf("create_emu() ... ");
	show_arch_info(arch, arch != null && arch->memory != null);

	// flose file
	fclose(fp);

	return arch;
}

void destroy_emu(x86_ARCH *arch){
	printf("\nprogram has ended successfully!\n\n");
	free(arch->memory);
	free(arch);
}
