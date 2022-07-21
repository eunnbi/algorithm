#include <bits/stdc++.h>
using namespace std;


int N;
vector<pair<int, int>> eggs;
bool mask[10]; // true : 계란 깨짐, false: 계란 안 깨짐
int maxNum;

void sol(int i, int res, int remain) {
    if (i == N || remain <= 1) { // 더 이상 왼쪽 손에 들 계란이 없거나 1개 이하의 계란이 남아 있는 경우 종료
        if (maxNum < res) maxNum = res;
        return;
    }
    if (!mask[i]) { // i 번째 계란이 이미 깨져 있음.
        sol(i + 1, res, remain);
        return;
    }

    /*
    **WRONG**
    if (remain <= 1) {
        if (maxNum < res) maxNum = res;
    }
    다른 종료 조건과 예외 상황을 고려하지 않음.
    - 문제 : "가장 최근에 든 계란이 가장 오른쪽에 위치한 계란일 경우 치는 과정을 종료한다." => 종료 조건 : i == N
    - 예외 상황 : i 번째 계란이 이미 깨져 있는 경우
    */

    for (int j = 0; j < N; j++){
        if (!mask[j]) continue;
        if (i == j) continue;
        eggs[i].first -= eggs[j].second;
        eggs[j].first -= eggs[i].second;
        if (eggs[i].first <= 0) mask[i] = false;
        if (eggs[j].first <= 0) mask[j] = false;
        sol(i + 1, res + !mask[i] + !mask[j], remain - !mask[i] - !mask[j]);
        // 원상 복구
        if (eggs[i].first <= 0) mask[i] = true;
        if (eggs[j].first <= 0) mask[j] = true;
        eggs[i].first += eggs[j].second;
        eggs[j].first += eggs[i].second;
    }
}

int main(void){
    cin >> N;
    for (int i = 0; i < N; i++){
        int s, w;
        cin >> s >> w;
        eggs.push_back({ s, w });
        mask[i] = true; // mask 배열 초기화도 같이
    }
    sol(0, 0, N);
    cout << maxNum;
    return 0;
}


// https://www.acmicpc.net/problem/16987