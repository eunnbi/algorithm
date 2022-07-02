# Array

> 동일한 데이터형의 원소를 메모리 상에서 연속하게 배치한 자료구조이다.

<br/>

## 성질

- `O(1)`에 k번째 원소를 확인 및 변경 가능
- 추가적으로 소모되는 메모리의 양 (= `overhead`)가 거의 없음
- `Cache hit rate`가 높음
- 메모리 상에 연속한 구간을 잡아야 해서 할당에 제약이 걸림

<br/>

## 기능

| 기능                                   | 시간복잡도 |
| -------------------------------------- | ---------- |
| 임의의 위치에 있는 원소를 확인 및 변경 | O(1)       |
| 원소를 배열의 끝에 추가                | O(1)       |
| 마지막 원소 제거                       | O(1)       |
| 임의의 위치에 있는 원소 추가           | O(N)       |
| 임의의 위치에 있는 원소 제거           | O(N)       |

<br/>

## 배열 초기화

```cpp
#include <cstring> // memset
#include <algorithm> // fill

int a[21];
int b[21][21];

// 1. memset
memset(a, 0, sizeof a);
memset(b, 0, sizeof b);

// 2. for
for (int i = 0; i < 21; i++){
	a[i] = 0;
}
for (int i = 0; i < 21; i++){
	for (int j = 0; j < 21; j++){
		b[i][j] = 0;
	}
}

// 3. fill
fill(a, a + 21, 0);
for (int i = 0; i < 21; i++){
	fill(b[i], b[i] + 21, 0);
}
```

<br/>

## STL vector

> vector는 배열과 거의 동일한 기능을 수행하는 자료구조이다. 하지만 배열과 달리 크기를 자유자재로 늘리거나 줄일 수 있다.

```cpp
// Example

#include <bits/stdc++.h>
using namespace std;

int main(void) {
  vector<int> v1(3, 5); // {5,5,5};
  cout << v1.size() << '\n'; // 3
  v1.push_back(7); // {5,5,5,7};

  vector<int> v2(2); // {0,0};
  v2.insert(v2.begin()+1, 3); // {0,3,0};

  vector<int> v3 = {1,2,3,4}; // {1,2,3,4}
  v3.erase(v3.begin()+2); // {1,2,4};

  vector<int> v4; // {}
	// deep copy
  v4 = v3; // {1,2,4}
  cout << v4[0] << v4[1] << v4[2] << '\n';
  v4.pop_back(); // {1,2}
  v4.clear(); // {}
}
```

[vector - C++ Reference](https://cplusplus.com/reference/vector/vector/)

<br/>

### Method

| Method                 | 시간 복잡도 |
| ---------------------- | ----------- |
| push_back(element)     | O(1)        |
| pop_back()             | O(1)        |
| push_front(element)    | O(N)        |
| pop_front()            | O(N)        |
| insert(index, element) | O(N)        |
| erase(index)           | O(N)        |

<br/>

### Vector 순회

```cpp
vector<int> v1 = {1, 2, 3, 4, 5, 6};

// 1. range-based for loop (since C++11)
for (int e : v1){
	cout << e << ' ';
}

// 2. not bad
for (int i = 0; i < v1.size(); i++){
	cout << v1[i] << ' ';
}

// 3. **WRONG**
for (int i = 0; i <= v1.size() - 1; i++){
	cout << v1[i] << ' ';
}
```

- `size` 메서드는 `unsigned int`형을 반환함.
- v1이 빈 vector라면 `v1.size() - 1`의 결과는 `-1`이지만 `unsigned int` 형으로 해석하면 `UMAX`가 된다.
