
#include <string>
#include <cstdlib>
#include <ctime>
// #include <thread>
#include <algorithm>

#include <vector>
#include <string>
#include <unordered_map>
#include <bitset>

using std::string;
using std::vector;
using std::bitset;
using std::unordered_map;

void TestASCII() {
	for (int i = 0; i < 128; ++i) {
		printf("%d = ", i);
		putchar(i);
		printf("\n");
	}
}

void TestStringAssign() {
	string str = "";
	str = "hello world";
	// char *pstr = "hello world";
	const char *pstr = str.c_str();
	printf("%s\n", str.c_str());
	printf("%s\n", pstr);
}

void TestStringFind() {
	string str = "hello world, wordl,he, hello";
	char *pchar = "hello";
	std::size_t pos = str.find(str[0], 1);
	std::size_t pos_unknown = str.find('z', 0);
	std::size_t pos_h = str.find(pchar, 1, 3);
	printf("%d\n", pos);
	printf("%d\n", pos_unknown);
	printf("%d\n", pos_h);
}

void TestSearch() {
	string str = "hello world, wordl,he, hello";
	auto it = std::search(str.begin(), str.end(), str.begin() + 2, str.begin() + 3 );
	printf("offset = %d\n", it - str.begin());
}


void TestRand() {
	srand(time(NULL));
	int i = 100;
	int rand_int;
	while (i--) {
		int rand_int = rand() % 2 + 1;
		switch (rand_int) {
			case 1: printf("%4d: rand = 1\n", 100 - i); break;
			case 2: printf("%4d: rand = 2\n", 100 - i); break;
		}
	}
}

void TestVector() {
	vector<int> iv(128, -1);
	for (int i : iv) {
		printf("%d ", i);
	}
	printf("\n");
}

inline void TestInline() {
	int n = 0;
	printf("%d\n", n);
	printf("end of TestInline\n");
}

void TestNonInline() {
	int n = 0;
	printf("%d\n", n);
	printf("end of TestNonInline\n");
}

void TestFlip() {
	int i = 0; int j = 1;
	int flip_i = ~i;
	int flip_j = ~j;
	printf("~%d = %d\n", i, flip_i);
	printf("~%d = %d\n", j, flip_j);
}

void TestHashtable() {
	unordered_map<int, int> hashtable;
	vector<int> iv = {1, 2, 3, 2, 4, 2, 0, 1, 2, 3};
	int size = iv.size();
	// save {value, index}
	for (int i = 0; i < size; ++i) {
		if (hashtable.count(iv[i]) == 1) {
		  printf("found %d\n", iv[i]);
		  printf("index %d\n", hashtable.find(iv[i])->second);
		}
		hashtable[iv[i]] = i;
	}
	printf("not found\n");

	/* test operator[] , when key not exist, will insert*/
	unordered_map<int, int> cnt = {
		{1, 1}, {2, 2}, {3, 3}
	};
	int not_exist = 4;
	if (cnt[not_exist]) printf("first found = %d\n", cnt[not_exist]);
	else printf("first not found\n");
	for (auto it = cnt.begin(); it != cnt.end(); ++it) { 
		printf("%d : %d ", it->first, it->second);
	}
	printf("\n");

	if (cnt.count(not_exist)) printf("second found = %d\n", cnt[not_exist]);
	else printf("second not found\n");

	not_exist = 5;
	if (cnt.at(not_exist)) printf("not exist and throw exception\n");
}

void TestChar2String() {
	vector<string> sv;
	vector<char> cv;
	int i = 0;
	int char_size = 26;
	string tmp;
	for (int i = 0; i < char_size; ++i) {
		cv.push_back(i + 'a');
		tmp.push_back(i + 'a');
		sv.push_back(tmp);
		tmp.erase();
		printf("%c %s ", cv.back(), sv.back().c_str());
	}
	printf("\n");
}


void f(int * pArr)
{
  * pArr = 200 ;
  free(pArr);//把pArr 所指向的内存释放掉
}


void TestFree() {
  int * p = (int *)malloc(sizeof(int));
  *p = 10;

  printf("%d\n",*p); //10
  f(p);    
	*p = 100;
	free(p);
	// int q = 0x1d88c20;
  printf("%d\n",*p); //200
  // printf("%d\n",q); //200
  printf("%p\n",p); //200
}

void TestMapIteration() {
	unordered_map<string, int> cnt = {
		{"hello", 1}, {"world", 2},
		{"xxx", 4}, {"yyyy", 3}
	};
	for (auto it = cnt.begin(); it != cnt.end(); ++it) {
		printf("word: %s count %d\n", it->first.c_str(), it->second);
	}
}

void TestReturn() {
	int i = 1;
	return;
}

void TestChar() {
	char c = 'a';
	c = 'b';
	printf("%c\n", c);
}

void TestBitset() {
	bitset<4> bs;
	bs.set();
	bs.set(1, 0);
	bs.set(3, 0);
	bitset<4> bs2;
	bs2.set();
	bs2.set(0, 0);
	bs2.set(2, 0);
	bitset<4> bs3 = bs ^ bs2;
	printf("%s\n", bs.to_string().c_str());
	printf("%lld\n", bs.to_ullong());
	printf("%s\n", bs3.to_string().c_str());
	printf("%lld\n", bs3.to_ullong());
}

void TestBitReverse() {
	int n = 1;
	/* wrong */
	n = ~n;
	printf("%d\n", n);
}

void TestStack() {
	long local;
	printf("local at %p\n", &local);
	// return 0;
}

void PassRefernce(int &ri) {
	int *ri_address = &ri;
	printf("%p\n", ri_address);
}

void TestReference() {
	int n = 1;
	PassRefernce(n);
}

void TestLoop() {
	int size = 100;
	for (int i = 0; i < size; ++i) {
		for (int k = 10; k < size; ++k) {
			++k;
			++k;
			if (k & 0) break;
			printf("%d\t", k);
		}
		/* break from this line */
		if (i & 1) continue;
		++i;
		++i;
		/* continue from this line */
	}
}

void TestReverseString() {
	string s = "12345";
	string s_rev(s.rbegin(), s.rend());
	printf("%s\n", s_rev.c_str());
}

int globalVariable = 0;

void Task1() {
	int n = 1000000;
	for (int i = 0; i < n; ++i) {
		globalVariable++;
		globalVariable--;
	}
}

// void TestThread() {
//   std::thread t1(Task1);
//   std::thread t2(Task1);
//   t1.join();
//   t2.join();
//   printf("globalVariable = %d\n", globalVariable);
// }

void TestDivide() {
	int n = 701;
	printf("%d\n", n / 26);
}

void TestStr2Ch() {
	char ch = 'd';
	string str = "abc";
	str += ch;
	printf("%s\n", str.c_str());
}

int Product(int base, int n) {
	while (--n) {
		base *= base;
	}
	return base;
}

void TestConstReference() {
	int base = 10;
	int n = 3;
	int res = Product(base, n);
	printf("%d\n", res);
}

void TestReferenceMoveConstructible() {
	int a = 1;
	int &ra = a;
	std::is_nothrow_move_constructible<int&>::value ? printf("true\n") :
		printf("false\n");
	std::is_nothrow_move_constructible<int*>::value ? printf("true\n") :
		printf("false\n");
}

void TestVectorReference() {
	// vector<int&> riv;
	int a = 1;
	int &ra = a;
	printf("%p\n", &a);
	printf("%p\n", &ra);
	*(&ra) = 2;
	printf("%d\n", ra);
	int *pra = &ra;
	*pra = 3;
	printf("%d\n", ra);
	// riv.push_back(ra);
}

int main() {
	// TestASCII();
	// TestStringAssign();
	// TestStringFind();
	// TestRand();
	// TestSearch();
	// TestVector();
	// TestInline();
	// TestNonInline();
	// TestFlip();
	// TestHashtable();
	// TestChar2String();
	// TestFree();
	// TestMapIteration();
	// TestReturn();
	// TestChar();
	// TestBitset();
	// TestBitReverse();
	// TestStack();
	// TestReference();
	// TestLoop();
	// TestReverseString();
	// TestThread();
	// TestDivide();
	// TestStr2Ch();
	// TestConstReference();
	// TestReferenceMoveConstructible();
	TestVectorReference();
}
