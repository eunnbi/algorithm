#include <bits/stdc++.h>
using namespace std;

int N;
vector<string> nums;

bool cmp(const string& a, const string& b) {
    int indexA = a.size() - 1;
    int indexB = b.size() - 1;
    while (indexA > 0 && a[indexA] == '0') indexA--;
    while (indexB > 0 && b[indexB] == '0') indexB--;
    if (indexA != indexB) return indexA < indexB;
    else {
        for (int i = indexA; i >= 0; i--) {
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
        nums.push_back(str);
    }

    sort(nums.begin(), nums.end(), cmp);
    for (int i = 0; i < N; i++) {
        string res = nums[i];
        int index = res.size() - 1;
        while (res[index] == '0') index--;
        for (int j = index; j >= 0; j--) {
            cout << res[j];
        }
        cout << '\n';
    }
    
    return 0;
}

// https://www.acmicpc.net/problem/5648