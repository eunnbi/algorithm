#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  stack<int> S;
  int num = 1; // 스택에 넣어야 할 숫자

  string res; // char 배열 대신 string 이용
  while (n--) {
    int t;
    cin >> t;
    while (num <= t) {
      S.push(num++);
      res += "+\n";
    }
    if (S.top() != t) {
      cout << "NO\n";
      return 0;
    }
    S.pop();
    res += "-\n";
  }
    cout << res;
}

/*
- char 배열 대신 string을 이용하는 것이 런타임 에러 발생을 줄일 수 있다.
- string에 문자를 추가할 때는 "+=" 이용
*/
// https://www.acmicpc.net/problem/1874