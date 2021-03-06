# Queue

π **FIFO (First In First Out)** : κ°μ₯ λ¨Όμ  λ£μ λ°μ΄ν°κ° κ°μ₯ λ¨Όμ  λμ¨λλ κ²μ λ§νλ€.

<br/>

## Features

- μμμ μΆκ°/μ κ±°κ° `O(1)`
- μ μΌ μκ³Ό λ€μ μμ νμΈμ΄ `O(1)`
- μ μΌ μμ΄ μλ λλ¨Έμ§ μμλ€μ λ³κ²½μ΄ λΆκ°λ₯ν¨.

<br/>

## Array-based Implementation of Queue

```cpp
// Circular Queue

#define QUEUE_SIZE 100


typedef struct _Queue{
    int front;
    int rear;
    int queue[QUEUE_SIZE];
} Queue;

int nextPosIdx(int pos){
    if (pos == QUEUE_SIZE - 1){
        return 0;
    }
    else {
        return (pos + 1);
    }
}

void initQueue(Queue* pq){
    pq->front = 0;
    pq->rear = 0;
}

int IsEmpty(Queue* pq){
    return pq->front == pq->rear;
}

void enqueue(Queue* pq, int data){
    if (pq->front == nextPosIdx(pq->rear)) exit(-1);
    pq->queue[pq->rear] = data;
    pq->rear = nextPosIdx(pq->rear);
}

int dequeue(Queue* pq){
    int rdata;
    if (IsEmpty(pq)) exit(-1);
    rdata = pq->queue[pq->front];
    pq->front = nextPosIdx(pq->front);
    return rdata;
}

int peek(Queue* pq){
    if (IsEmpty(pq)) exit(-1);
    return pq->queue[pq->front];
}
```

<br/>

## STL Queue

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  queue<int> Q;
  Q.push(10); // 10
  Q.push(20); // 10 20
  Q.push(30); // 10 20 30
  cout << Q.size() << '\n'; // 3
  if(Q.empty()) cout << "Q is empty\n";
  else cout << "Q is not empty\n"; // Q is not empty
  Q.pop(); // 20 30
  cout << Q.front() << '\n'; // 20
  cout << Q.back() << '\n'; // 30
  Q.push(40); // 20 30 40
  Q.pop(); // 30 40
  cout << Q.front() << '\n'; // 30
}
```

- [queue - C++ Reference](https://m.cplusplus.com/reference/queue/queue/)

<br/>

## β Problems

| BOJ                                                                               |
| :-------------------------------------------------------------------------------- |
| [ν](https://github.com/eunnbi/algorithm/blob/main/queue/BOJ/10845.cpp)           |
| [μμΈνΈμ€ λ¬Έμ ](https://github.com/eunnbi/algorithm/blob/main/queue/BOJ/1158.cpp) |
