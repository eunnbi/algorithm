#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int N;
  int a[10];
  int res;
  cin >> N;
  
  // 자리수 추출
  while (N){
    a[N % 10]++;
    N /= 10;
  }

  for(int i = 0; i < 10; i++){
    if (i == 6 || i == 9) continue;
    res = max(res, a[i]);
  }
  // (a[6]+a[9])/2를 올림한 값이 6, 9에 대한 필요한 세트의 수이므로 (a[6]+a[9]+1)/2을 계산
  res = max(res, (a[6]+a[9]+1)/2);
  cout << res;
}



// 6과 9에 대한 조건을 해결하는 것이 관건 
// 6은 9를 뒤집어서 이용할 수 있고, 9는 6을 뒤집어서 이용할 수 있다.
// https://www.acmicpc.net/problem/1475