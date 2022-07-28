#include <bits/stdc++.h>
using namespace std;

int N;
vector<pair<int, int>> ages;
string names[100001];

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.second != b.second) return a.second < b.second;
    return a.first < b.first;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    int age;
    for (int i = 0; i < N; i++) {
        cin >> age >> names[i];
        ages.push_back({ i, age });
    }

    sort(ages.begin(), ages.end(), cmp);

    for (int i = 0; i < N; i++) {
        cout << ages[i].second << ' ' << names[ages[i].first] << '\n';
    }
    return 0;
}