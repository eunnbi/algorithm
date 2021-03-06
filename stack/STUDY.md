# Stack

π **LIFO (Last In First Out)** : κ°μ₯ λ§μ§λ§μΌλ‘ λ€μ΄κ° λ°μ΄ν°κ° κ°μ₯ λ¨Όμ  λμ€λ κ²μ λ§νλ€.

<br/>

## Features

- μμμ μΆκ°κ° O(1)
- μμμ μ κ±°κ° O(1)
- μ μΌ μλ¨μ μμ νμΈμ΄ O(1)
- μ μΌ μλ¨μ΄ μλ λλ¨Έμ§ μμλ€μ νμΈ λ° λ³κ²½μ΄ μμΉμ μΌλ‘ λΆκ°λ₯ν¨.

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
  cout << S.top() << '\n'; // runtime error λ°μ μ£Όμ!!!!
}
```

- Method: `push`, `pop`, `top`, `empty`, `size`
- [stack - C++ Reference](https://m.cplusplus.com/reference/stack/stack/)

<br/>

## β Problems

| Leetcode                                                                                         | BOJ                                                                                  |
| :----------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------ |
| [Valid Parentheses](https://github.com/eunnbi/algorithm/blob/main/stack/leetcode/20.cpp)         | [μ€ν](https://github.com/eunnbi/algorithm/blob/main/stack/BOJ/10828.cpp)            |
| [Score of Parentheses](https://github.com/eunnbi/algorithm/blob/main/stack/leetcode/856.cpp)     | [μ λ‘](https://github.com/eunnbi/algorithm/blob/main/stack/BOJ/10733.cpp)            |
| [Validate Stack Sequences](https://github.com/eunnbi/algorithm/blob/main/stack/leetcode/946.cpp) | [μ€ν μμ΄](https://github.com/eunnbi/algorithm/blob/main/stack/BOJ/1874.cpp)        |
|                                                                                                  | [ν](https://github.com/eunnbi/algorithm/blob/main/stack/BOJ/2493.cpp)               |
|                                                                                                  | [μ₯μ μ μ κΎΈλ―ΈκΈ°](https://github.com/eunnbi/algorithm/blob/main/stack/BOJ/6198.cpp) |
|                                                                                                  | [μ€ν°μ](https://github.com/eunnbi/algorithm/blob/main/stack/BOJ/17298.cpp)          |
|                                                                                                  | [μ λ§λκΈ°](https://github.com/eunnbi/algorithm/blob/main/stack/BOJ/10799.cpp)        |
|                                                                                                  | [κ΄νΈμ κ°](https://github.com/eunnbi/algorithm/blob/main/stack/BOJ/2504.cpp)        |
