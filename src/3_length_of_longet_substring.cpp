#include <stdio.h>
#include <assert.h>

#include <string>
#include <ctime>
#include <algorithm>


using std::string;


int SolutionOne(const string &s);
int SolutionTwo(const string &s);
int SolutionThree(const string &s);
int SolutionFour(const string &s);
int SolutionFive(const string &s);
int Solution(const string &s);

int Solution(const string &s) {
	srand(time(NULL));
	int rand_int = rand() % 5;
	switch (rand_int) {
		case 0: return SolutionOne(s); break;
		case 1: return SolutionTwo(s); break;
		case 2: return SolutionThree(s); break;
		case 3: return SolutionFour(s); break;
		case 4: return SolutionFive(s); break;
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
				printf("pos: %ld\n", pos);
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

/* sliding window */
int SolutionThree(const string &s) {
	int start = 0, end = 0, cur_len = 0, result = 0;
	int len = (int)(s.size());
	while (end < len) {
		char tmp_char = s[end];
		for (int i = start; i < end; ++i) {
			if (tmp_char == s[i]) {
				start = i + 1;
				cur_len = end - start;
				break;
			}
		}
		++end;
		++cur_len;
		result = std::max(cur_len, result);
	}
	printf("SolutionThree: %d\n", result);
	return result;
}

/* sliding window with find() */
int SolutionFour(const string &s) {
	int start = 0, end = 0, cur_len = 0, max_len = 0;
	int str_len = s.length();
	std::size_t pos = 0;
	for (end = 0; end < str_len; ++end) {
		/* slower than SolutionThree, due to find in [start, str_len), */
		/* longer than Three, [start, end) */
		pos = s.find(s[end], start);
		if (pos != string::npos && pos < end) {
			start = pos + 1;
			cur_len = end - start;
			// break;  /* break is wrong */
		}
		++cur_len;
		max_len = std::max(cur_len, max_len);
	}
	printf("SolutionFour: %d\n", max_len);
	return max_len;
}

/* sliding window with search */
int SolutionFive(const string &s) {
	int start = 0, end = 0, cur_len = 0, max_len = 0;
	int str_len = s.length();
	int pos = 0;
	/* search [target_b, target_e) in [search_b, search_end) */
	decltype(s.begin()) search_b;  /* begin of search region */
	decltype(s.begin()) search_e;  /* end of search region */
	decltype(s.begin())	target_b;  /* begin of target string */
	decltype(s.begin()) target_e;  /* end of target string */
	for (end = 0; end < str_len; ++end) {
		/* faster than Four, due to searcg in [start, start + len), */
		/* shorted than  [start, end) */
		search_b = s.begin() + start;
		search_e = s.begin() + end;
		target_b = s.begin() + end;
		target_e = s.begin() + end + 1;
		pos = std::search(search_b, search_e, target_b, target_e) - s.begin();

		if (pos < end) {
			start = pos + 1;
			cur_len = end - start;
			// break;  /* break is wrong */
		}
		++cur_len;
		max_len = std::max(cur_len, max_len);
	}

	printf("SolutionFive: %d\n", max_len);
	return max_len;
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
