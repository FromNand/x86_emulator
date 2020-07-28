BIN=$(OBJ)/test.bin
FLAT=$(OBJ)/flat.bin

SRC=src
OBJ=obj
LS=ls

# .text .data .rodata .bssといったセクションを含むバージョン
GCC-OP=-m32 -nostdlib -fno-pie -T $(LS)/binary.ls

# .textセクションだけを出力したフラットなバイナリ
GCC-OP2=-m32 -nostdlib -fno-pie -T $(LS)/text_only.ls

# i386向けにディスアセンブル
OBJDUMP-OP=-D -b binary -mi386

# ファイルを増やしたい場合はバイナリを配置したい順番にここにファイル名を記述する
ALLSRC=$(SRC)/test.c

all : bin flat

bin : $(ALLSRC)
	gcc $(GCC-OP) $? -o $(BIN)

flat : $(ALLSRC)
	gcc $(GCC-OP2) $? -o $(FLAT)

bdump : $(BIN)
	objdump $(OBJDUMP-OP) $?

fdump : $(FLAT)
	objdump $(OBJDUMP-OP) $?

clean :
	rm $(BIN) $(FLAT)
