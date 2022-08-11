#include <bits/stdc++.h>
#define MOD 1000000
using namespace std;

string code;
int dp[5002];


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> code;
    int len = code.length();

    dp[0] = 1;
    if (code[0] >= '1' && code[0] <= '9') dp[1] = 1;
    else {
        cout << 0;
        return 0;
    }

    for (int i = 2; i <= len; i++) {
        if (code[i - 1] >= '1' && code[i - 1] <= '9') dp[i] =  (dp[i] + dp[i - 1]) % MOD;
        if (code[i - 2] == '0') continue; // 예외 상황 제외
        int num = (code[i - 1] - '0') + (code[i - 2] - '0') * 10;
        if (num >= 1 && num <= 26) dp[i] = (dp[i] + dp[i - 2]) % MOD;
    }
    cout << dp[len];
    return 0;
}

// https://www.acmicpc.net/problem/2011
