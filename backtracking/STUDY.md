# Backtracking

## ✨ Concept

- 현재 상태에서 가능한 모든 후보군을 따라 들어가며 탐색하는 알고리즘
- 해를 찾는 도중 해가 아니어서 막히면, 되돌아가서 다시 해를 찾아가는 기법

<br/>

## 👀 STL next_permutation

`next_permutation` 함수를 이용하여 순열과 조합을 쉽게 구할 수 있다.

**Example**

- 1, 2, 3으로 이루어진 모든 순열 구하는 문제

```cpp
int a[3] = {1, 2, 3};
do {
    for (int i = 0; i < 3; i++){
        cout << a[i];
    }
    cout << '\n';
} while(next_permutation(a, a + 3));

// 다음 순열을 만들고 true 반환
// 만약 다음 순열이 존재하지 않는다면 false 반환

/*
123
132
213
231
312
321
*/
```

- 1, 2, 3, 4 중 2개를 뽑아 조합을 만드는 문제

```cpp
int a[4] = { 0, 0, 1, 1 }; // flag 이용
do{
    for (int i = 0; i < 4; i++){
        if (a[i] == 0) {
            cout << i + 1;
        }
    }
    cout << '\n';
} while(next_permutation(a, a + 4));
```

> [Reference - next_permutation](https://cplusplus.com/reference/algorithm/next_permutation/)

<br/>

## ❓ Problems

| BOJ                                                                                           |
| --------------------------------------------------------------------------------------------- |
| [N과 M (1)](https://github.com/eunnbi/algorithm/blob/main/backtracking/BOJ/15649.cpp)         |
| [N-Queen](https://github.com/eunnbi/algorithm/blob/main/backtracking/BOJ/9663.cpp)            |
| [부분수열의 합](https://github.com/eunnbi/algorithm/blob/main/backtracking/BOJ/1182.cpp)      |
| [N과 M (2)](https://github.com/eunnbi/algorithm/blob/main/backtracking/BOJ/15650.cpp)         |
| [N과 M (3)](https://github.com/eunnbi/algorithm/blob/main/backtracking/BOJ/15651.cpp)         |
| [N과 M (4)](https://github.com/eunnbi/algorithm/blob/main/backtracking/BOJ/15652.cpp)         |
| [N과 M (5)](https://github.com/eunnbi/algorithm/blob/main/backtracking/BOJ/15654.cpp)         |
| [N과 M (6)](https://github.com/eunnbi/algorithm/blob/main/backtracking/BOJ/15655.cpp)         |
| [N과 M (7)](https://github.com/eunnbi/algorithm/blob/main/backtracking/BOJ/15656.cpp)         |
| [N과 M (8)](https://github.com/eunnbi/algorithm/blob/main/backtracking/BOJ/15657.cpp)         |
| [N과 M (9)](https://github.com/eunnbi/algorithm/blob/main/backtracking/BOJ/15663.cpp)         |
| [N과 M (10)](https://github.com/eunnbi/algorithm/blob/main/backtracking/BOJ/15664.cpp)        |
| [N과 M (11)](https://github.com/eunnbi/algorithm/blob/main/backtracking/BOJ/15665.cpp)        |
| [N과 M (12)](https://github.com/eunnbi/algorithm/blob/main/backtracking/BOJ/15666.cpp)        |
| [로또](https://github.com/eunnbi/algorithm/blob/main/backtracking/BOJ/6603.cpp)               |
| [암호 만들기](https://github.com/eunnbi/algorithm/blob/main/backtracking/BOJ/1759.cpp)        |
| [소문난 칠공주](https://github.com/eunnbi/algorithm/blob/main/backtracking/BOJ/1941.cpp)      |
| [계란으로 계란치기](https://github.com/eunnbi/algorithm/blob/main/backtracking/BOJ/16987.cpp) |
| [Gaaaaaaaaaarden](https://github.com/eunnbi/algorithm/blob/main/backtracking/BOJ/18809.cpp)   |
| [비숍](https://github.com/eunnbi/algorithm/blob/main/backtracking/BOJ/1799.cpp)               |
