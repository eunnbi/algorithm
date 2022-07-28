#include <bits/stdc++.h>
using namespace std;

vector<string> str;

bool cmp(const string& a, const string& b) {
    int indexA = 0;
    int indexB = 0;
    while (indexA < a.size() && indexB < b.size()) {
        if (a[indexA] == b[indexB]) {
            indexA++;
            indexB++;
            continue;
        }
        return a[indexA] < b[indexB];
    }
    return a.size() < b.size();
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string S;
    cin >> S;
    int size = S.size();
    for (int i = 0; i < size; i++) {
        str.push_back(S.substr(i, size)); // substr 함수 이용
    }

    sort(str.begin(), str.end(), cmp);
    for (int i = 0; i < str.size(); i++) {
        cout << str[i] << '\n';
    }

    return 0;
}