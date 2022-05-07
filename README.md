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

## [read_string_file.hpp](https://github.com/DC-Jade/my_leetcode/blob/main/include/read_string_file.hpp)

```C
/* this statement cannot initialize and pvec_str is a nullptr(0x0) */
/* so will throw segmention fault */
vector<string> *pvec_str;
```

