# Backtracking

## ✨ Concept

- 현재 상태에서 가능한 모든 후보군을 따라 들어가며 탐색하는 알고리즘
- 해를 찾는 도중 해가 아니어서 막히면, 되돌아가서 다시 해를 찾아가는 기법

<br/>

## STL next_permutation

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

| BOJ                                                                                      |
| ---------------------------------------------------------------------------------------- |
| [N과 M (1)](https://github.com/eunnbi/algorithm/blob/main/backtracking/BOJ/15649.cpp)    |
| [N-Queen](https://github.com/eunnbi/algorithm/blob/main/backtracking/BOJ/9663.cpp)       |
| [부분수열의 합](https://github.com/eunnbi/algorithm/blob/main/backtracking/BOJ/1182.cpp) |
