#include <stdio.h>

#include <string>

using std::string;

void TestASCII() {
	for (int i = 0; i < 128; ++i) {
		printf("%d = ", i);
		putchar(i);
		printf("\n");
	}
}

void TestStringAssign() {
	string str = "";
	str = "hello world";
	// char *pstr = "hello world";
	const char *pstr = str.c_str();
	printf("%s\n", str.c_str());
	printf("%s\n", pstr);
}

void TestStringFind() {
	string str = "hello world, wordl, hello";
	std::size_t pos = str.find(str[0], 1);
	std::size_t pos_unknown = str.find('z', 0);
	printf("%d\n", pos);
	printf("%d\n", pos_unknown);
}

int main() {
	// TestASCII();
	// TestStringAssign();
	TestStringFind();
}
