#include <bits/stdc++.h>
#define MAX 1000001
using namespace std;

int N;
int dp[MAX][2];


int main(void) {
    cin >> N;
    dp[1][0] = 0;
    dp[1][1] = 1;

    for (int i = 2; i <= N; i++){
        dp[i][0] = MAX;
        if (!(i % 3)) {
            if (dp[i][0] > dp[i / 3][0] + 1) {
                dp[i][0]  = dp[i / 3][0] + 1;
                dp[i][1] = i / 3;
            }
        }
        if (!(i % 2)) {
            if (dp[i][0] > dp[i / 2][0] + 1) {
                dp[i][0] = dp[i / 2][0] + 1;
                dp[i][1] = i / 2;
            }
        }
        if (dp[i][0] > dp[i - 1][0] + 1) {
            dp[i][0] = dp[i - 1][0] + 1;
            dp[i][1] = i - 1;
        }
    }
    printf("%d\n", dp[N][0]);
    int res = N;
    while (res != 1) {
        printf("%d ", res);
        res = dp[res][1];
    }
    printf("1");
    return 0;
}