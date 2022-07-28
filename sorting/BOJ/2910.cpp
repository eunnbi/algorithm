#include <bits/stdc++.h>
using namespace std;

int N, C;
vector<tuple<int, int, int>> nums;

bool cmp(const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
    int turnA, numberA, freqA;
    int turnB, numberB, freqB;
    tie(turnA, numberA, freqA) = a;
    tie(turnB, numberB, freqB) = b;
    if (freqA != freqB) return freqA > freqB;
    else return turnA < turnB;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> C;
    int num;
    for (int i = 0; i < N; i++) {
        cin >> num;
        bool isExist = false;
        for (int j = 0; j < nums.size(); j++) {
            int turn, number, freq;
            tie(turn, number, freq) = nums[j];
            if (number == num) {
                nums[j] = { turn, number, freq + 1 };
                isExist = true;
                break;
            }
        }
        if (!isExist) nums.push_back({ i, num, 1 });
    }

    sort(nums.begin(), nums.end(), cmp);

    for (int i = 0; i < nums.size(); i++) {
        int turn, number, freq;
        tie(turn, number, freq) = nums[i];
        while (freq--) {
            cout << number << ' ';
        }
    }
    return 0;
}