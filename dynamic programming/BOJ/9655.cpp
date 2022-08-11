#include <bits/stdc++.h>
using namespace std;

int N;
int dp[1002];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    if (N % 2) cout << "SK";
    else cout << "CY";
    
    return 0;
}
