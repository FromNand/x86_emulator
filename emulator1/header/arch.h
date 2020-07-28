#ifndef _ARCH_H
#define _ARCH_H

#include<type.h>

// レジスタの番号
enum registers_number { EAX, ECX, EDX, EBX, ESP, EBP, ESI, EDI, REGISTERS_COUNT };

// レジスタの名前
extern sint8 *registers_name[REGISTERS_COUNT];

// x86アーキテクチャ
typedef struct x86_archtecture {
	// レジスタ
	uint32 registers[REGISTERS_COUNT];

	// メモリ
	uint8* memory;

	// EIP
	uint32 eip;

	// EFLAGS
	uint32 eflags;
} x86_ARCH;

#endif
