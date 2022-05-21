#include <cstdio>
#include <ctime>
#include <vector>

#include "../include/ivv.hpp"

using std::vector;

void ReverseString(vector<char> &s);

void SolutionOne(vector<char> &s) {
	int half_size = s.size() >> 1;
	int left = 0; int right = s.size() - 1;
	while (left < half_size) { std::swap(s[left++], s[right--]); }
}

void Solution(vector<char> &s) {
	srand(time(nullptr));
	int rand_int = rand() % 1 + 1;
	switch (rand_int) {
		case 1: printf("SolutionOne: \n"); SolutionOne(s); break;
	}
}

void Test00034() {
	// vector<char> s = {'h','e','l','l','o','0'};
	vector<char> s = {'h','e','l','l','o'};
	int size = s.size();
	Solution(s);
	intvectorvector::PrintIV(s, size);
}

int main(int argc, char **argv) {
	Test00034();
}
