#include <stdio.h>
#include <fstream>
#include <string>

using std::string;

int SolutionOne(const string *jewels, const string *stones) {
	int cnt = 0;	/* initialized is required, or cnt is undetermined */
	// for (auto chr : (*stones)) { if (jewels->find(chr)) ++cnt; }
	for (auto chr : (*stones)) { if (jewels->find(chr) != string::npos) ++cnt; }
	printf("%d\n", cnt);
	return cnt;
}

int Solution(const string *jewels, const string *stones) {
	int rand_count = rand() % 2;
	switch (rand_count) {
		case 1: return SolutionOne(jewels, stones); break;
		case 2: return 0; break;
	}
}

int NumJewelsInStones(const string *jewels, const string *stones) {
	return Solution(jewels, stones);
}

void Test771() {
	string jewels, stones;
	std::ifstream file("../data/771_jewels_stones.txt");
	while ( getline(file, jewels, '\n') && getline(file, stones, '\n') ) {
		Solution(&jewels, &stones);
	}
}

int main() {
	Test771();
}
