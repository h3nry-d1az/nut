#define MAGC 0x1BADB002
#define FLGS 0

const int MAGIC = MAGC;
const int FLAGS = FLGS;
const int CHECKSUM = -(MAGC + FLGS);


void _start() {
	NutInit();
	Main();
}

__attribute__((__noreturn__))
void loop() {
	while (1) {}
	__builtin_unreachable();
}
