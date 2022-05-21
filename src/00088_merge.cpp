#include <cstdlib>
#include <vector>
#include <ctime>

#include "../include/ivv.hpp"

using std::vector;

void Merge(vector<int> nums1, int m, vector<int> nums2, int n);

void SolutionOne(vector<int> &nums1, int m, vector<int> &nums2, int n) {
	int i = 0; int j = 0;
	vector<int> sorted_nums(m + n, 0);
	/* position should be placed next */
	int cur_pos = 0;
	/* case - nums1 and nums2 both have element */
	while (i < m && j < n) {
		if (nums1[i] < nums2[j]) { sorted_nums[cur_pos++] = nums1[i++]; }
		else { sorted_nums[cur_pos++] = nums2[j++]; }
	}
	/* case - nums1 have element but nums2 do not */
	while (i < m) { sorted_nums[cur_pos++] = nums1[i++]; }
	/* case - nums2 have element but nums1 do not */
	while (j < n) { sorted_nums[cur_pos++] = nums2[j++]; }
	/* cur_pos now is (m + n), the next postion placed */
	for (int k = 0; k < cur_pos; ++k) {
		nums1[k] = sorted_nums[k];
	}
}

/* in place, from tail to front */
void SolutionTwo(vector<int> &nums1, int m, vector<int> &nums2, int n) {
	int i = m - 1; int j = n - 1;
	int cur_pos = m + n - 1;
	while (i >= 0 && j >= 0) {
		if (nums1[i] > nums2[j]) { nums1[cur_pos--] = nums1[i--]; }
		else { nums1[cur_pos--] = nums2[j--]; }
	}
	while (i >= 0) break;
	while (j >= 0) { nums1[cur_pos--] = nums2[j--]; }
}

void Solution(vector<int> &nums1, int m, vector<int> &nums2, int n) {
	srand(time(nullptr));
	int rand_int = rand() % 2 + 1;
	switch (rand_int) {
		case 1:
			printf("SolutionOne:\n");
			SolutionOne(nums1, m, nums2, n);
			break;
		case 2:
			printf("SolutionTwo:\n");
			SolutionTwo(nums1, m, nums2, n);
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
