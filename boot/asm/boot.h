const int MAGIC = 0x1BADB002;
const int FLAGS = 0;
const int CHECKSUM = -(MAGIC + FLAGS);


void _start() {
	NutInit();
	main();
}

void loop() {
	return loop();
}
