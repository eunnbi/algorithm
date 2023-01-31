# Priority Queue

> `pop`할 때 가장 먼저 들어온 원소가 아닌 우선순위가 가장 높은 원소가 나오는 큐

- 원소 추가: `O(logN)`
- 우선순위가 가장 높은 원소의 확인: `O(1)`
- 우선순위가 가장 높은 원소의 제거: `O(logN)`

<br/>

## 최대힙과 최소힙

- 최소힙: 모든 정점에서 부모가 자식보다 작아야 한다.
- 최대힙: 모든 정점에서 부모가 자식보다 커야 한다.

<br/>

## 최소힙을 배열로 구현하기

```cpp
int heap[100005]; // 2i: 왼쪽 자식, 2i+1: 오른쪽 자식, i/2: 부모
int sz = 0; // heap에 들어있는 원소의 수

void push(int x){
  heap[++sz] = x;
  int idx = sz;
  while(idx != 1){
    int par = idx/2;
    if(heap[par] <= heap[idx]) break;
    swap(heap[par], heap[idx]);
    idx = par;
  }
}

int top(){
  return heap[1];
}

void pop(){
  heap[1] = heap[sz--];
  int idx = 1;
  // 왼쪽 자식의 인덱스(=2*idx)가 size보다 크면 idx는 Leaf
  while(2*idx <= sz){
    int lc = 2*idx, rc = 2*idx+1; // 왼쪽 자식, 오른쪽 자식
    int min_child = lc; // 두 자식 중 작은 인덱스를 담을 예정
    if(rc <= sz && heap[rc] < heap[lc])
      min_child = rc;
    if(heap[idx] <= heap[min_child]) break;
    swap(heap[idx],heap[min_child]);
    idx = min_child;
  }
}
```

## STL

```cpp
#include <iostream>
#include <queue>
using namespace std;

int main(void){
  priority_queue<int> pq; // 최대 힙
  // priority_queue<int, vector<int>, greater<int>>로 선언시 최소 힙
  pq.push(10); pq.push(2); pq.push(5); pq.push(9); // {10, 2, 5, 9}
  cout << pq.top() << '\n'; // 10
  pq.pop(); // {2, 5, 9}
  cout << pq.size() << '\n'; // 3
  if(pq.empty()) cout << "PQ is empty\n";
  else cout << "PQ is not empty\n";
  pq.pop(); // {2, 5}
  cout << pq.top() << '\n'; // 5
  pq.push(5); pq.push(15); // {2, 5, 5, 15}
  cout << pq.top() << '\n'; // 15
}
```
