#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int N;
stack<pair<int,int>> tower; // 높이 값과 인덱스 저장

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 1; i <= N; i++) {
    int height; // 입력된 값 저장
    cin >> height;
    
    // 입력된 값보다 작은 숫자들은 정답 가능성이 없으므로 제거한다.
    while (!tower.empty() && tower.top().X < height) tower.pop();
    if (tower.empty())  cout << "0 "; // 스택이 비어있다면 0을 출력
    else cout << tower.top().Y << " "; // 비어있지 않다면 top에 있는 값을 출력
    tower.push({height, i}); // 입력된 값과 인덱스는 스택에 저장한다.     
  }
  return 0;
}
