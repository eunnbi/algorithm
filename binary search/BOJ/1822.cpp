#include <bits/stdc++.h>
using namespace std;

int na, nb;
int a[500001];
int b[500001];

int search(int target) {
    int left = 0;
    int right = nb - 1;
    int mid;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (b[mid] == target) {
            return 0;
        }
        else if (b[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return 1;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> na >> nb;
    for (int i = 0; i < na; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < nb; i++) {
        cin >> b[i];
    }
    sort(a, a + na);
    sort(b, b + nb);
    int num = 0;
    vector<int> res;
    for (int i = 0; i < na; i++) {
        int val = search(a[i]);
        if (val) {
            num += 1;
            res.push_back(a[i]);
        }
    }
    cout << num << '\n';
    for (int val : res) {
        cout << val << ' ';
    }
    return 0;
}