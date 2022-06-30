# Stack

👉 **LIFO (Last In First Out)**

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

## ❓ Problems

| Leetcode                                                                                         |
| :----------------------------------------------------------------------------------------------- |
| [Valid Parentheses](https://github.com/eunnbi/algorithm/blob/main/stack/leetcode/20.cpp)         |
| [Score of Parentheses](https://github.com/eunnbi/algorithm/blob/main/stack/leetcode/856.cpp)     |
| [Validate Stack Sequences](https://github.com/eunnbi/algorithm/blob/main/stack/leetcode/946.cpp) |
