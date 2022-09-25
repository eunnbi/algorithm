#include <bits/stdc++.h>
using namespace std;

string s;
int N;
string a[101];
int dp[101]; 
// dp[i]: 문자열의 i번째 글자부터 마지막 글자까지의 substring으로 주어진 단어를 만들 수 있는지를 나타낸다.

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    int len = s.length();
    dp[len] = 1;
    for (int i = len - 1; i >= 0; i--) {
        for (int j = 0; j < N; j++) {
            if (s.find(a[j], i) == i && dp[i + a[j].length()] == 1) {
                dp[i] = 1;
                break;
            }
            else dp[i] = 0;
        }
    }

    cout << dp[0];
    return 0;
}