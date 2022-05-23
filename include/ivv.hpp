#include <cstdio>
#include <cstdlib>
#include <vector>

using std::vector;

namespace intvectorvector {

/* initialize a IVV */
void InitializeIVV(vector<vector<int>> &ivv, const int &m, const int &n) {
	for (int i = 0; i < m; ++i) {
		vector<int> iv;
		for (int j = 0; j < n; ++j) { iv.push_back(0); }
		ivv.push_back(iv);
	}	
}

void InitializeIV(vector<int> &iv, const int &n) {
	for (int i = 0; i < n; ++i) iv.push_back(0);
}

/* traverse and printf elements in vector<vector<int>> */
void PrintIVV(const vector<vector<int>> &ivv) {
	for (auto iv : ivv) {
		for (auto i : iv) printf("%d ", i);
		printf("\n");
	}
}

/* printf vector<int> */
void PrintIV(const vector<int> &iv, const int &n) {
	for (int i = 0; i < n; ++i) { printf("%d ", iv[i]); }
	printf("\n");
}

/* printf vector<char> */
void PrintIV(const vector<char> &iv, const int &n) {
	for (char i = 0; i < n; ++i) { printf("%c ", iv[i]); }
	printf("\n");
}


}	/* namespace intvectorvector, vector<vector<int>> */
