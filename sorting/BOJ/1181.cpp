#include <bits/stdc++.h>
using namespace std;

int N;
vector<string> words;

bool cmp(const string& a, const string& b) {
    if (a.size() != b.size()) return a.size() < b.size();
    else {
        int size = a.size();
        for (int i = 0; i < size; i++) {
            if (a[i] == b[i]) continue;
            return a[i] < b[i];
        }
        return false;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    string str;
    for (int i = 0; i < N; i++) {
        cin >> str;
        words.push_back(str);
    }

    sort(words.begin(), words.end(), cmp);

    string prev = words[0];

    for (int i = 0; i < N; i++) {
        if (i == 0) cout << words[i] << '\n';
        if (words[i] == prev) continue;
        cout << words[i] << '\n';
        prev = words[i];
    }
    return 0;
}