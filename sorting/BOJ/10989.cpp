#include <bits/stdc++.h>
using namespace std;

int N;
int cnt[10001];

int main(void) {
    // 밑에 두 줄 코드 안 적으면 시간초과 발생
    ios::sync_with_stdio(0); 
    cin.tie(0);

    cin >> N;
    int num;
    for (int i = 0; i < N; i++) {
        cin >> num;
        cnt[num]++;
    }
    for (int i = 1; i <= 10000; i++) {
        while (cnt[i]) {
            printf("%d\n", i);
            cnt[i]--;
        }
    }
    return 0;
}

// 👉 배열의 원소 개수는 많은데 수들의 분포가 모여있으면 counting sort가 유리함.
// https://www.acmicpc.net/problem/10989

/*
**메모리 초과**
**nums 배열이 없어도 해결 가능**
int N;
int nums[10000001];
int cnt[10001];

void countingSort() {
    for (int i = 0; i < N; i++) {
        cnt[nums[i]]++;
    }
    int index = 0;
    for (int i = 0; i < 10001; i++) {
        while (cnt[i]) {
            nums[index++] = i;
            cnt[i]--;
        }
    }
}

int main(void) {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    countingSort();
    for (int i = 0; i < N; i++) {
        printf("%d\n", nums[i]);
    }
    return 0;
}
*/