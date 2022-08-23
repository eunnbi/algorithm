#include <bits/stdc++.h>
using namespace std;

int N, M;
int nums[100001];

int search(int target) {
    int left = 0;
    int right = N - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return 1;
        }
        else if (nums[mid] < target) {
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
        cin >> nums[i];
    }
    sort(nums, nums + N);

    cin >> M;
    int num;
    while (M--) {
        cin >> num;
        cout << search(num) << '\n';
    }
    return 0;
}