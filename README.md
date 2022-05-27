# my_leetcode

## Introduction

- This is a  leetcode  notebook

## Supported

- os

  Ubuntu 16.04 LTS

- compiler

  g++ version 9.4.0

## Start

```bash
git clone git@github.com:DC-Jade/my_leetcode.git
```

## compilation

```bash
g++ -Wall -g -o ../bin <.cpp>
```

## [read_string_file.hpp](./include/read_string_file.hpp)

```cpp
/* this statement cannot initialize and pvec_str is a nullptr(0x0) */
/* so will throw segmention fault */
vector<string> *pvec_str;
```

## [3_length_of_longest_substring.cpp](./src/3_length_of_longest_substring.cpp)

```cpp
/* hashmap can be used to boost search unique element */
/* vector<int> vec(128, 0) can used as a special unordered_map<char, int>
 * due to char is a number, between [0, 127]
 */ 
```

## Recursion

- Core
	Top-Down

- Steps

- Examples
	
	[00509_fibonacci](src/00509_fibonacci.cpp)
## Dynamic Programming, DP

- Core
	Bottom-Up

- Steps
1. base case, or initial state
2. dp function

- Examples

	[00509_fibonacci](src/00509_fibonacci.cpp)

## Trick

1. IsEven or IsOdd

```C++
int i = 0;
// True when even
i & 0;  
// True when odd
i & 1;	
```
- Examples

	[00409_longest_palindrome](src/00409_longest_palindrome.cpp)

2. Use unordered_map check element whether exist and count recurrence
	
	- unordered_map can save {key, value} pair and key is unique
	
	- hashtale.find();
	
	- hashtale.count();
	
	  **check key whether exist**
	
	- hashtale.erase();
	
	- **replace hashtable[] with hashtable.at() **
	
	  at() and [ ] has the same behavior when an element with the key exists
	
	  **[] will insert when key not exist,** but at will throw exception

```C++
std::unordered_map<int, int> hashtable;
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
```

3. unordered_set used to check element whether exists
   - unordered_set only save unique value {value}, more space efficient than map

   - hash.count();

   - examples

     [00819_most_common_word.cpp](src/00819_most_common_word.cpp)

```cpp
std::unordered_set<string> hash_set;
hash_set.push_back("hello");
hash_set.push_back("world");
if (hash_set.count("hello")) printf("find\n");
else printf("not found\n");
```





