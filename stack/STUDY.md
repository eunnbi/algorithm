# Stack

👉 **LIFO (Last In First Out)** : 가장 마지막으로 들어간 데이터가 가장 먼저 나오는 것을 말한다.

<br/>

## Features

- 원소의 추가가 O(1)
- 원소의 제거가 O(1)
- 제일 상단의 원소 확인이 O(1)
- 제일 상단이 아닌 나머지 원소들의 확인 및 변경이 원칙적으로 불가능함.

<br/>

## Array-based Implementation of Stack

```cpp
typedef struct _Stack {
	int itmes[STACK_SIZE];
	int top;
} Stack;

void initStack(Stack* pstack){
	pstack->top = -1;
}

int isFull(Stack* pstack){
	return pstack->top == STACK_SIZE - 1;
}

int isEmpty(Stack* pstack){
	return pstack->top == -1;
}

int peek(Stack* pstack){
	if (isEmpty(pstack)) exit(-1);
	return pstack->itmes[pstack->top];
}

void push(Stack* pstack, int item){
	if (isFull(pstack)) exit(-1);
	pstack->items[++(pstack->top)] = item;
}

int pop(Stack* pstack){
	if (IsEmpty(pstack)) exit(-1);
	return pstack->itmes[pstack->top--];
}
```

<br/>

## STL stack

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  stack<int> S;
  S.push(10); // 10
  S.push(20); // 10 20
  S.push(30); // 10 20 30
  cout << S.size() << '\n'; // 3
  if(S.empty()) cout << "S is empty\n";
  else cout << "S is not empty\n"; // S is not empty
  S.pop(); // 10 20
  cout << S.top() << '\n'; // 20
  S.pop(); // 10
  cout << S.top() << '\n'; // 10
  S.pop(); // empty
  if(S.empty()) cout << "S is empty\n"; // S is empty
  cout << S.top() << '\n'; // runtime error 발생 주의!!!!
}
```

- Method: `push`, `pop`, `top`, `empty`, `size`
- [stack - C++ Reference](https://m.cplusplus.com/reference/stack/stack/)

<br/>

## ❓ Problems

| Leetcode                                                                                         |
| :----------------------------------------------------------------------------------------------- |
| [Valid Parentheses](https://github.com/eunnbi/algorithm/blob/main/stack/leetcode/20.cpp)         |
| [Score of Parentheses](https://github.com/eunnbi/algorithm/blob/main/stack/leetcode/856.cpp)     |
| [Validate Stack Sequences](https://github.com/eunnbi/algorithm/blob/main/stack/leetcode/946.cpp) |
