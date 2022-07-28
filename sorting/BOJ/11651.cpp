#include <bits/stdc++.h>
using namespace std;

int N;
vector<pair<int, int>> coord;

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.second != b.second) return a.second < b.second;
    return a.first < b.first;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    int x, y;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        coord.push_back({ x, y });
    }
    sort(coord.begin(), coord.end(), cmp);
    for (int i = 0; i < N; i++) {
        cout << coord[i].first << ' ' << coord[i].second << '\n';
    }
    return 0;
}