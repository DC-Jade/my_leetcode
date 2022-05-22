#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>

using std::vector;

int MaxArea(const vector<int> &height);

/* timeout */
int SolutionOne(const vector<int> &height) {
	int size = height.size();
	int bottom_size = 0;
	int area = 0;
	int max_area = 0;
	for (int lhs = 0; lhs < size; ++lhs) {
		for (int rhs = lhs + 1; rhs < size; ++rhs) {
			bottom_size = rhs - lhs;
			area = std::min(height[rhs], height[lhs]) * bottom_size ;
			max_area = std::max(max_area, area);
		}
	}
	return max_area;
}

int SolutionTwo(const vector<int> &height) {
	int size = height.size();
	int lhs = 0; int rhs = size - 1;
	int bottom_size = 0;
	int area = 0;
	int max_area = 0;
	while (lhs < rhs) {
		bottom_size = rhs - lhs;
		/* move shorter side */
		if (height[lhs] < height[rhs])  {
			area = height[lhs] * bottom_size;
			++lhs;
		}
		else {
			area = height[rhs] * bottom_size;
			--rhs;
		}
		max_area = std::max(max_area, area);
	}
	return max_area;
}

int Solution(const vector<int> &iv) {
	srand(time(nullptr));
	int rand_int = rand() % 2 + 1;
	switch (rand_int) {
		case 1: printf("SolutionOne: \n"); return SolutionOne(iv);
		case 2:	printf("SolutionTwo: \n"); return SolutionTwo(iv);
	}
	return {0};
}

void Test00011() {
	int res = 0;
	vector<int> iv = {1, 8, 6, 2, 5, 4, 8, 3, 7};
	res = Solution(iv);
	printf("%d\n", res);
}

int main(int argc, char **argv) {
	Test00011();
}
