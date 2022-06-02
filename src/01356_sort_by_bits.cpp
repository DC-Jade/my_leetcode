#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <algorithm>

#include <vector>

using std::vector;

vector<int> sortByBits(vector<int> &arr);
vector<int> SolutionOne(vector<int> &arr);
vector<int> Solution(vector<int> &arr);


int OneNumber(int n) {
	int cnt = 0;
	while (n) {
		if (n & 1) ++cnt;
		n >>= 1;
	}
	return cnt;
}

bool Compare(const int &x, const int &y) {
	if (OneNumber(x) == OneNumber(y)) return x < y;
	else return OneNumber(x) < OneNumber(y);
}

vector<int> SolutionOne(vector<int> &arr) {
	std::sort(arr.begin(), arr.end(), Compare);
	return arr;
}

vector<int> Solution(vector<int> &arr) {
	srand(time(nullptr));
	int rand_int = rand() % 1 + 1;
	switch (rand_int) {
		case 1: printf("SolutionOne\n"); return SolutionOne(arr); break;
	}
	return {0};
}

void Test01356() {
	vector<int> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8};
	arr = {1024,512,256,128,64,32,16,8,4,2,1};
	arr = {10000, 10000};
	arr = {2,3,5,7,11,13,17,19};
	Solution(arr);
	for (const int &i : arr) printf("%d ", i);
	printf("\nend of Test01356\n");
}

int main(int argc, char **argv) {
	Test01356();
}


