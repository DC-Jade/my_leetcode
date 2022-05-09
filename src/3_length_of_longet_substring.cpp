#include <stdio.h>
#include <assert.h>

#include <string>

using std::string;

int SolutionOne(const string &s);
int SolutionTwo(const string &s);
int Solution(const string &s);

int Solution(const string &s) {
	int rand_int = rand() % 2;
	switch (rand_int) {
		case 0: return SolutionOne(s); break;
		case 1: return SolutionTwo(s); break;
	}
	return 0;
}

int SolutionOne(const string &s) {
	int len = s.length();

	int max_len = 0;
	int cur_len = 0;
	for (int i = 0; i < len; ++i) {
		int j;
		for (j = i; j < len; ++j) {
			// cur_len = j - i;
			int k;
			for (k = i; k < j; ++k) {
				if (s[k] == s[j]) break; 
			}
			if(k != j) break;
		}
		/* special case: a total unique string */
		// if (j == len) ++cur_len;
		cur_len = j - i;
		max_len = std::max(cur_len, max_len);
	}
	printf("SolutionOne: %d\n", max_len);
	return max_len;
}

int SolutionTwo(const string &s) {
	/* use find to detect unique char */
	int len = s.length();
	int max_len = 0;
	int cur_len = 0;
	for (int i = 0; i < len; ++i) {
		int j;
		for (j = i; j < len; ++j) {
			/* find pos: i <= pos < j  */
			// if (s.find(s[j]) != string::npos &&
			//     s.find(s[j]) < j && s.find(s[j]) >= i) {
			//   break;
			// }
			std::size_t pos = s.find(s[j], i);
			if (pos != string::npos && pos < j) {
				printf("pos: %d\n", pos);
				printf("i = %d j = %d\n", i, j);
				break;
			}
			// assert(j != 6);
		}
		cur_len = j - i;	/* cur sutstring [i, j) */
		max_len = std::max(max_len, cur_len);
	}
	printf("SolutionTwo: %d\n", max_len);
	return max_len;
}

/* TODO */
void SolutionThree(const string &s) {
	
}

int LengthOfLongestSubstring(const string &s) {
	return Solution(s);
}

void Test3() {
	string s = "au";
	s = "abcabcbb";
	s = "pwwkew";
	Solution(s);
}

int main() {
	Test3();
}
