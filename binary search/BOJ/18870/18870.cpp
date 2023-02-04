#include <bits/stdc++.h>
using namespace std;

int N;
int x[1000001];
vector<int> uni; // 중복 제거

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x[i];
        uni.push_back(x[i]);
    }

    sort(uni.begin(), uni.end());
    uni.erase(unique(uni.begin(), uni.end()), uni.end()); // 중복 제거 🔥
    for (int i = 0; i < N; i++) {
        cout << lower_bound(uni.begin(), uni.end(), x[i]) - uni.begin() << ' ';
    }
    return 0;
}
