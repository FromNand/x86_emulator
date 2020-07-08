OUTPUT_FORMAT("binary")
ENTRY(func)

SECTIONS {
	.head 0x0 : AT(0x0) {
		LONG(LOADADDR(.data))
		LONG(SIZEOF(.data))
		LONG(LOADADDR(.bss))
		LONG(SIZEOF(.bss))
		LONG(LOADADDR(.text))
		LONG(SIZEOF(.text))
	}

	.data 0x0 : AT(SIZEOF(.head)) {
		*(.data)
		*(.rodata*)
	}

	.bss SIZEOF(.data) : AT(SIZEOF(.head) + SIZEOF(.data)) {
		*(.bss)
	}

	.text 0x7c00 : AT(SIZEOF(.head) + SIZEOF(.data) + SIZEOF(.bss)) {
		*(.text)
		*(.text.*)
	}

	/DISCARD/ : { *(.eh_frame) }
}
