#include <stdio.h>

#include <string>
#include <ctime>
#include <algorithm>

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
	string str = "hello world, wordl,he, hello";
	char *pchar = "hello";
	std::size_t pos = str.find(str[0], 1);
	std::size_t pos_unknown = str.find('z', 0);
	std::size_t pos_h = str.find(pchar, 1, 3);
	printf("%d\n", pos);
	printf("%d\n", pos_unknown);
	printf("%d\n", pos_h);
}

void TestSearch() {
	string str = "hello world, wordl,he, hello";
	auto it = std::search(str.begin(), str.end(), str.begin() + 2, str.begin() + 3 );
	printf("offset = %d\n", it - str.begin());
}


void TestRand() {
	srand(time(NULL));
	int i = 100;
	int rand_int;
	while (i--) {
		int rand_int = rand() % 2 + 1;
		switch (rand_int) {
			case 1: printf("%4d: rand = 1\n", 100 - i); break;
			case 2: printf("%4d: rand = 2\n", 100 - i); break;
		}
	}
}

int main() {
	// TestASCII();
	// TestStringAssign();
	// TestStringFind();
	// TestRand();
	TestSearch();
}
