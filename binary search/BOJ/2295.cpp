#include <bits/stdc++.h>
using namespace std;

int N;
int nums[1001];
vector<int> two;

int main(void) {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    sort(nums, nums + N);
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            two.push_back(nums[i] + nums[j]);
        }
    }

    sort(two.begin(), two.end());
    for (int i = N - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (binary_search(two.begin(), two.end(), nums[i] - nums[j])) {
                cout << nums[i];
                return 0;
            }
        }
    }
}

// two[m] + a[j] = a[i]를 만족하는 a[i] 중 최댓값
// https://www.acmicpc.net/problem/2295