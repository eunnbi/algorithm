#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000002];
int chainMaxLIS;

int main() {
    int n, num;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        dp[num] = dp[num - 1] + 1;
        chainMaxLIS = max(chainMaxLIS, dp[num]);
    }
    cout << n - chainMaxLIS << '\n';
    return 0;
}

// (N - 최대로 번호가 연속해서 증가하게끔 배치되어있는 어린이들의 수)가 정답이다.