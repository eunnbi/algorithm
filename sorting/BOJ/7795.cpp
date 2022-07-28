#include <bits/stdc++.h>
using namespace std;

int T;
int N, M;
int a[20001];
int b[20001];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> N >> M;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < M; i++) {
            cin >> b[i];
        }
        sort(a, a + N);
        sort(b, b + M);

        int res = 0;
        int indexA = 0, indexB = 0;
        while (indexA < N && indexB < M) {
            if (a[indexA] > b[indexB]) {
                res += N - indexA;
                indexB++;
            }
            else indexA++;
        }
        cout << res << '\n';
    }
    return 0;
}