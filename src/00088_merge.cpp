#include <cstdlib>
#include <vector>
#include <ctime>
#include "../include/ivv.hpp"

using std::vector;

void Merge(vector<int> nums1, int m, vector<int> nums2, int n);

void SolutionOne(vector<int> &nums1, int m, vector<int> &nums2, int n) {
	int i = 0; int j = 0;
	vector<int> sorted_nums(m + n, 0);
	int cur_pos = 0;
	while (i < m && j < n) {
		if (nums1[i] < nums2[j]) { sorted_nums[cur_pos++] = nums1[i++]; }
		else { sorted_nums[cur_pos++] = nums2[j++]; }
	}
	while (i < m) { sorted_nums[cur_pos++] = nums1[i++]; }
	while (j < n) { sorted_nums[cur_pos++] = nums2[j++]; }
	for (int k = 0; k < cur_pos; ++k) {
		nums1[k] = sorted_nums[k];
	}
}

void Solution(vector<int> &nums1, int m, vector<int> &nums2, int n) {
	srand(time(nullptr));
	int rand_int = rand() % 1 + 1;
	switch (rand_int) {
		case 1:
			printf("SolutionOne:\n");
			SolutionOne(nums1, m, nums2, n);
			break;
	}
}

void Test00088() {
	int m = 3; int n = 3;
	vector<int> nums1 = {1, 2, 3, 0, 0, 0};
	vector<int> nums2 = {2, 5, 6};
	Solution(nums1, m, nums2, n);
	intvectorvector::PrintIV(nums1, m + n);
}

int main(int argc, char **argv) {
	Test00088();
}
