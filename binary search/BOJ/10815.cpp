#include <bits/stdc++.h>
using namespace std;

int N, M;
int cards[500001];
int targets[500001];

int search(int target) {
    int left = 0;
    int right = N - 1;
    int mid;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (cards[mid] == target) {
            return 1;
        }
        else if (cards[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return 0;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> cards[i];
    }
    sort(cards, cards + N);
    cin >> M;
    int num;
    while (M--) {
        cin >> num;
        cout << search(num) << ' ';
        // cout << binary_search(cards, cards + N, num) << ' ';
    }
    return 0;
}