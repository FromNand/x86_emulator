TARGET=semu-x86
SRCPAS=src
INCPAS=-I header
ALLSRC=$(SRCPAS)/main.c $(SRCPAS)/emulator.c $(SRCPAS)/instruction.c $(SRCPAS)/rm_data.c

all : Makefile
	make $(TARGET)

$(TARGET) : $(ALLSRC) Makefile
	gcc $(INCPAS) $(ALLSRC) -o $@

clean : Makefile
	rm $(TARGET)
