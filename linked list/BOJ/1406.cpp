#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string init;
  cin >> init;

  list<char> L;
  for (auto c : init) L.push_back(c); // string 순회, list 초기화

  auto cursor = L.end(); // 타입명이 길어 auto 이용
  int M; // 명령어 개수
  cin >> M;
  while (M--) {
    char op; // 명령어
    cin >> op;

    if (op == 'P') {
      char add;
      cin >> add;
      L.insert(cursor, add);
    }
    else if (op == 'L') {
      if (cursor != L.begin()) cursor--;
    }
    else if (op == 'D') {
      if (cursor != L.end()) cursor++;
    }
    else { // 'B'
      if (cursor != L.begin()) {
        cursor--;
        cursor = L.erase(cursor);
      }
    }
  }
  for (auto c : L) cout << c; // list 순회
}
/*
💡 STL list
- 중간에 위치한 데이터의 삭제와 삽입이 자주 발생하는 경우 STL vector보다 STL list를 이용하는 것이 훨씬 효율적이다.

💚 STL list member function
- front(): 리스트의 첫 번째 요소의 레퍼런스 값 반환
- back(): 리스트의 마지막 요소의 레퍼런스 값 반환
- begin(): 리스트의 첫 번째 요소를 가리키는 반복자 (iterator) 반환
- end(): end()를 호출하여 반환된 iterator는 back()과 달리 맨 마지막 원소의 ✨ 바로 다음 원소를 가리킨다.
- empty(): 리스트가 비었다면 true 아니면 false를 반환
- size(): 리스트의 크기 반환
- push_front(element): 리스트의 맨 앞에 원소 삽입
- push_back(element): 리스트의 맨 뒤에 원소 삽입
- pop_front(element): 리스트의 맨 앞의 원소 삭제
- pop_back(element): 리스트의 맨 뒤의 원소 삭제
- insert(iterator 위치, element): 리스트의 iterator 위치의 왼쪽에 원소를 삽입
- insert(iterator 위치, int 개수, element): 리스트의 iterator 위치에 원소를 입력된 개수만큼 삽입
- erase(iterator 위치): 리스트의 iterator 위치의 원소를 삭제하고 그 다음 원소의 위치를 반환함.
- erase(iterator 시작위치, iterator 끝위치): 리스트의 iterator 시작위치부터 끝 위치 전까지의 원소를 삭제하고 그 다음 원소의 위치를 반환함.

👉 auto : 컴파일러에 의해 자동으로 타입이 정해지는 변수를 선언할 때 사용하는 명령어

👉 향상된 for문
- 배열과 STL의 배열 기반 컨테이너에 대한 간략한 구문 제공
- 일반 배열, vector, list, string 등
- auto를 함께 사용하면 더욱 간략화됨.

*/

// https://www.acmicpc.net/problem/1406