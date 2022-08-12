#include <bits/stdc++.h>
using namespace std;

int N;
int dp[1001];
string res[2] = { "CY", "SK" };


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    dp[1] = 1;
    dp[2] = 0;
    dp[3] = 1;
    dp[4] = 1;
    for (int i = 5; i <= N; i++) {
        if (dp[i - 1] + dp[i - 3] + dp[i - 4] < 3) dp[i] = 1;
        else dp[i] = 0;
    }
    cout << res[dp[N]];
    return 0;
}

/*
둘이 완벽하게 게임을 했다는 것 = 서로 자신이 이기는 수만 골랐다는 것
상근이가 이길 가능성이 있다면 창영이가 이기는 수는 고르지 않는다.
*/
// https://www.acmicpc.net/problem/9657