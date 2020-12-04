#define MAGC 0x1BADB002
#define FLGS 0

const int MAGIC = MAGC;
const int FLAGS = FLGS;
const int CHECKSUM = -(MAGC + FLGS);


void _start() {
	NutInit();
	main();
}

void loop() {
	return loop();
}
