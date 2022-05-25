#include <cstdio>
#include <cstdlib>
#include <ctime>

#include <vector>
#include <string>

using std::vector;
using std::string;

vector<string> CommonChars(vector<string> &words);

// vector<string> SolutionOne(vector<string> &words) {
//   int row = words.size();
//   int chr_size = 26;
//   vector<int> iv(chr_size, 0);
//   vector<string> sv;
//   string stmp;
//   int i = 0;
//   for (i = 0; i < row; ++i) {
//     for (const auto &c : words[i]) {
//       ++iv[c - 'a'];
//     }
//   }
//   // int cnt = 0;
//   for (const auto &c : words.back()) {
//     // cnt = iv[c - 'a'] / row;
//     if (iv[c - 'a'] / row > 0) {
//       stmp.push_back(c);
//       sv.push_back(stmp);
//       stmp.erase(stmp.begin(), stmp.end());
//       iv[c - 'a'] -= row;
//     }
//   }
//   return sv;
// }

vector<string> SolutionOne(vector<string> &words) {
	int char_size = 26;
	/* wrong, or element will be 0 */
	// vector<int> min_cnt(char_size, 0);
	vector<int> min_cnt(char_size, 1000000);
	vector<int> cnt(char_size, 0);
	int char2int = 0;
	for (const auto &s : words) {
		std::fill(cnt.begin(), cnt.end(), 0);
		for (const auto &c : s) {
			char2int = c - 'a';
			++cnt[char2int];
		}
		/* wrong, this will cause elements not existing will be 1000000 */
		// for (const auto &c : s) {
		for (int i = 0; i < char_size; ++i) {
			min_cnt[i] = std::min(cnt[i], min_cnt[i]);
		}
	}
	string tmp = "";
	vector<string> sv;
	for (int i = 0; i < char_size; ++i) {
		while (min_cnt[i]--) {
			// if (i > 0) {
			tmp.push_back(i + 'a');
			sv.push_back(tmp);
			tmp.erase();
				// sv.emplace_back(1, i + 'a');
				// --i;
			// }
		}
	}
	return sv;
}

vector<string> Solution(vector<string> &words) {
	srand(time(nullptr));
	int rand_int = rand() % 1 + 1;
	switch (rand_int) {
		case 1: printf("SolutionOne\n"); return SolutionOne(words);
	}
	return {""};
}

void Test01102() {
	vector<string> words = {"bella", "label", "roller"};
	vector<string> res;
	res = Solution(words);
	for (auto &s : res) printf("%s ", s.c_str());
	printf("\nend of Test01102\n");
}

int main(int argc, char **argv) {
	Test01102();
}
