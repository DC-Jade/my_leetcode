#include <stdio.h>

void TestASCII() {
	for (int i = 0; i < 128; ++i) {
		printf("%d = ", i);
		putchar(i);
		printf("\n");
	}
}

int main() {
	TestASCII();
}
