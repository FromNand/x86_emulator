int a = 0x12345678;
int b;

void func2(void){
	a = 100;
	b = 200;
}

void func(void){
	a = 1;
	b = 2;
	func2();
}
