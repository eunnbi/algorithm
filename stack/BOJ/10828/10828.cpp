#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; // 명령어 개수
  cin >> n;

  stack<int> S;
  while (n--){ // n번 반복
    string c;
    cin >> c;
    if(c == "push"){
      int t;
      cin >> t;
      S.push(t);
    }
    else if(c == "pop"){
      if (S.empty()) cout << -1 << '\n';
      else{
        cout << S.top() << '\n';
        S.pop();
      }
    }
    else if(c == "size")
      cout << S.size() << '\n';
    else if(c == "empty")
      cout << (int)S.empty() << '\n';
    else{ // top
      if (S.empty()) cout << -1 << '\n';
      else cout << S.top() << '\n';
    }
  }

/*
💜 string 비교 연산자
- C언어에서는 문자열끼리 비교할 때는 strcmp 함수를 이용했다.
- 하지만, C++ 에서 string 자료형끼리 비교할 때는 '==' 연산자를 이용해도 된다.

💜 STL stack member function
- empty(): stack이 비어있으면 true 반환, 아니면 false 반환
- size(): stack의 사이즈 반환
- push(value): stack에 데이터 삽입
- ✨ pop(): top에 있는 원소 삭제. return type이 void. 만약 stack이 비어있다면 오류 발생
- ✨ top(): 맨 위에 있는 원소 반환. 만약 stack이 비어있다면 오류 발생
*/

// https://www.acmicpc.net/problem/10828