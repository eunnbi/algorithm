# Linked List

> 원소를 저장할 때 그 다음 원소의 위치를 포함시키는 자료구조이다.

<br/>

## 성질

- `k`번째 원소를 확인/변경하기 위해 `O(k)`가 필요하다.
- 임의의 위치에 원소를 추가하거나 제거할 때는 `O(1)`이 필요하다.
- 원소들이 메모리 상에 연속해있지 않아 `Cache hit rate`가 낮지만 할당이 다소 쉽다.

<br/>

## 종류

1. 단일 연결리스트 (Singly Linked List)
2. 이중 연결리스트 (Doubly Linked List)
3. 원형 연결리스트 (Circular Linked List)

<br/>

## 배열 vs 연결리스트

배열과 연결리스트는 선형 자료구조이다.

|                                   | 배열 | 연결리스트 |
| --------------------------------- | ---- | ---------- |
| k번째 원소 접근                   | O(1) | O(k)       |
| 임의의 위치의 원소 추가/제거      | O(N) | O(1)       |
| 메모리 상의 배치                  | 연속 | 불연속     |
| 추가적으로 필요한 공간 (overload) | 없음 | O(N)       |

<br/>

## 구현

```cpp
// Single Linked List

#include <stdlib.h>

typedef int Data;

typedef struct _Node {
  struct _Node* next;
  Data data;
} Node;

typedef struct _LinkedList {
  Node* head;
  int num;
} LinkedList;

void InitList(LinkedList* plist) {
  plist->head = (Node*)malloc(sizeof(Node)); // dummy node
  plist->head->next = NULL;
  plist->num = 0;
}

bool IsEmpty(LinkedList* plist) {
  return (plist->num == 0);
}

// Insert an item at the k-th position. (0 <= k <= plist->num)
void Insert(LinkedList* plist, int pos, Data data) {
  Node* cur = plist->head;
  Node* newNode;
  if (pos < 0 || pos > plist->num) {
    exit(-1);
  }
  newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  for (int i = 0; i < pos; i++) {
    cur = cur->next;
  }
  newNode->next = cur->next;
  cur->next = newNode;
  plist->num++;
}

// Remove an item at the k-th position. (0 <= k < plist->num)
void Remove(LinkedList* plist, int pos) {
  Node* cur;
  Node* delNode;
  if (IsEmpty(plist) || pos < 0 || pos >= plist->num) {
    exit(-1);
  }
  cur = plist->head;
  for (int i = 0; i < pos; i++) {
    cur = cur->next;
  }
  delNode = cur->next;
  cur->next = delNode->next;
  free(delNode);
  plist->num--;
}

// Read an item at the k-th position. (0 <= k < plist->num)
Data ReadData(LinkedList* plist, int pos) {
  Node* cur;
  if (IsEmpty(plist) || pos > 0 || pos >= plist->num) {
    exit(-1);
  }
  cur = plist->head->next;
  for (int i = 0; i < pos; i++) {
    cur = cur->next;
  }
  return cur->data;
}
```

<br/>

```cpp
// Circular Linked List

#include <stdlib.h>

typedef int Data;

typedef struct _Node {
  struct _Node* next;
  Data data;
} Node;

typedef struct _CircularList {
  Node* tail;
  int num;
} CircularList;

void InitList(CircularList* plist) {
  plist->tail = NULL;
  plist->num = 0;
}

bool IsEmpty(CircularList* plist) {
  return (plist->num == 0);
}

void InsertInitItem(CircularList* plist, Data data){
  Node* newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = newNode;
  plist->tail = newNode;
  plist->num++;
}

void InsertFirst(CircularList* plist, Data data){
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = plist->tail->next;
  plist->tail->next = newNode;
  plist->num++;
}

void InsertLast(CircularList* plist, Data data){
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = plist->tail->next;
  plist->tail->next = newNode;
  plist->tail = newNode;
  plist->num++;
}

void Insert(CircularList* plist, int pos, Data data) {
  if (IsEmpty(plist)) InsertInitItem(plist, item);
  else if (pos == 0) InsertFirst(plist, data);
  else if (pos == plist->num) InsertLast(plist, data);
  else if (pos < 0 || pos > plist->num ) exit(-1);
  else {
    Node* cur = plist->tail;
    for (int i = 0; i < pos; i++) { // move to (k - 1)th position
      cur = cur->next;
    }
    Node* newNode;
    newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = cur->next;
    cur->next = newNode;
    plist->num++;
  }
}

void RemoveInitItem(CircularList* plist){
  if (IsEmpty(plist)) exit(-1);
  free(plist->tail);
  plist->num--;
  plist->tail = NULL;

}

void RemoveFirst(CircularList* plist){
  Node* delNode = plist->tail->next;
  plist->tail->next = delNode->next;
  free(delNode);
  plist->num--;
}

void RemoveLast(CircularList* plist){
  Node* cur = plist->tail;
  Node* delNode;
  cur = plist->tail;
  for (int i = 0; i < plist->len - 1; i++){
    cur = cur->next;
  }

  delNode = cur->next;
  cur->next = delNode->next;
  free(delNode);
  plist->tail = cur;
  plist->num--;
}

void RemoveMiddle(CircularList* plist, int pos) {
  if (IsEmpty(plist) || pos < 0 || pos >= plist->num) {
    exit(-1);
  }
  else if (plist->len == 1) RemoveInitItem(plist);
  else if (pos == 0) RemoveFirst(plist);
  else if (pos == plist->num - 1) RemoveLast(plist);
  else {
    Node* cur = plist->tail;
    Node* delNode;

    for (int i = 0; i < pos; i++) {
      cur = cur->next;
    }
    delNode = cur->next;
    cur->next = delNode->next;
    free(delNode);
    plist->num--;
  }
}

// Read an item at the k-th position. (0 <= k < plist->num)
Data ReadItem(CircularList* plist, int pos) {
  Node* cur;
  if (IsEmpty(plist) || pos > 0 || pos >= plist->num) {
    exit(-1);
  }
  cur = plist->tail->next;
  for (int i = 0; i < pos; i++) {
    cur = cur->next;
  }
  return cur->data;
}
```

<br/>

```cpp
// Doubly Linked List

#include <stdlib.h>

typedef int Data;

typedef struct _Node {
  struct _Node* next;
  struct _Node* prev;
  Data data;
} Node;

typedef struct _DoubleLinkedList {
	Node* head;
	int num;
} DoubleLinkedList;

void InitList(DoubleLinkedList* plist) {
  Node* dummy1 = (Node*)malloc(sizeof(Node));
  Node* dummy2 = (Node*)malloc(sizeof(Node));

  dummy1->prev = NULL;
  dummy1->next = dummy2;
  dummy2->prev = dummy1;
  dummy2->next = NULL;
  plist->head = dummy1;
  plist->num = 0;
}

bool IsEmpty(LinkedList* plist) {
  return (plist->num == 0);
}

// Insert an item at the k-th position. (0 <= k <= plist->num)
void Insert(LinkedList* plist, int pos, Data data) {
  Node* cur = plist->head;
  Node* newNode;
  if (pos < 0 || pos > plist->num) {
    exit(-1);
  }
  newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->prev = NULL;
  newNode->next = NULL;
  for (int i = 0; i < pos; i++) {
    cur = cur->next;
  }
  newNode->prev = cur;
  newNode->next = cur->next;
  cur->next = newNode;
  cur->next->prev=  newNode;
  plist->num++;
}

// Remove an item at the k-th position. (0 <= k < plist->num)
void Remove(LinkedList* plist, int pos) {
  Node* cur;
  Node* delNode;
  if (IsEmpty(plist) || pos < 0 || pos >= plist->num) {
    exit(-1);
  }
  cur = plist->head;
  for (int i = 0; i < pos; i++) {
    cur = cur->next;
  }
  delNode = cur->next;
  delNode->next->prev = cur;
  cur->next = delNode->next;
  free(delNode);
  plist->num--;
}

// Read an item at the k-th position. (0 <= k < plist->num)
Data ReadData(LinkedList* plist, int pos) {
  Node* cur;
  if (IsEmpty(plist) || pos > 0 || pos >= plist->num) {
    exit(-1);
  }
  cur = plist->head->next;
  for (int i = 0; i < pos; i++) {
    cur = cur->next;
  }
  return cur->data;
}
```

## STL list

`Double Linked List`로 구현되어 있음.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  list<int> L = {1,2}; // 1 2
  list<int>::iterator t = L.begin(); // t는 1을 가리키는 중
  L.push_front(10); // 10 1 2
  cout << *t << '\n'; // t가 가리키는 값 = 1을 출력
  L.push_back(5); // 10 1 2 5
  L.insert(t, 6); // t가 가리키는 곳 앞에 6을 삽입, 10 6 1 2 5
  t++; // t를 1칸 앞으로 전진, 현재 t가 가리키는 값은 2
  t = L.erase(t); // t가 가리키는 값을 제거, 그 다음 원소인 5의 위치를 반환
                  // 10 6 1 5, t가 가리키는 값은 5
  cout << *t << '\n'; // 5

	// 연결리스트 순회
  for(auto i : L) cout << i << ' ';
  cout << '\n';
  for(list<int>::iterator it = L.begin(); it != L.end(); it++)
    cout << *it << ' ';
}
```

- `push_back`, `pop_back`, `push_front`, `pop_front` → O(1)
- `iterator`가 `pointer` 역할을 한다.
- [list - C++ Reference](https://m.cplusplus.com/reference/list/list/)

<br/>

## Floyd's Tortoise 🐢 and Hare 🐇 Algorithm

**Detecting the First Element in the Loop**

- Two Pointers
  - Slow Pointer (tortoise): moves by 1 node at a time
  - Fast Pointer (hare): moves by 2 node at a time
- S and F point to the same node. A loop is detected.
- If a loop is found, we want to find the first element of the loop.
- Move S to the beginning and move forward both points by 1 node at a time.
- S and F met. This is the first element in the loop.

<br/>

## ❓ Problems

| Leetcode                                                                                                        |
| :-------------------------------------------------------------------------------------------------------------- |
| [Add Two Numbers](https://github.com/eunnbi/algorithm/blob/main/linked%20list/leetcode/2.cpp)                   |
| [Remove nth Node from End of List](https://github.com/eunnbi/algorithm/blob/main/linked%20list/leetcode/19.cpp) |
| [Merge k Sorted Lists](https://github.com/eunnbi/algorithm/blob/main/linked%20list/leetcode/23.cpp)             |
