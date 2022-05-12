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

```C
/* this statement cannot initialize and pvec_str is a nullptr(0x0) */
/* so will throw segmention fault */
vector<string> *pvec_str;
```

## [3_length_of_longest_substring.cpp](./src/3_length_of_longest_substring.cpp)

```C
/* hashmap can be used to boost search unique element */
/* vector<int> vec(128, 0) can used as a special unordered_map<char, int>
 * due to char is a number, between [0, 127]
 */ 
```

## Dynamic Programming, DP

- Steps
1. initial state
2. dp function


