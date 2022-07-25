#include <bits/stdc++.h>
using namespace std;

deque<int> gear[4];
int K;
vector<pair<int, int>> info;
int direction[4];
int score[4] = { 1, 2, 4, 8 };

// dir : 1 or -1
void rotate(int num, int dir) {
    if (dir == 1) { // 시계방향
        int back = gear[num].back();
        gear[num].pop_back();
        gear[num].push_front(back);
    }
    else if (dir == -1) { // 반시계 방향
        int front = gear[num].front();
        gear[num].pop_front();
        gear[num].push_back(front);
    }
    else return;
}

int main(void){
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 8; j++) {
            char ch;
            cin >> ch;
            gear[i].push_back(ch - '0');
        }
    }
    cin >> K;
    for (int i = 0; i < K; i++) {
        int num, dir;
        cin >> num >> dir; // num : 1 ~ 4, dir : 1 or -1
        info.push_back({ num - 1, dir }); 
    }
    

    for (int i = 0; i < K; i++) {
        for (int j = 0; j < 4; j++) direction[j] = 0; // direction 배열 초기화
        int num, dir;
        tie(num, dir) = info[i];
        direction[num] = dir;
        int left = num - 1;
        int cur = num;
        while (left >= 0) {
            if (gear[cur][6] != gear[left][2]) {
                direction[left] = - direction[cur];
            }
            else break;
            left--;
            cur--;
        }
        
        int right = num + 1;
        cur = num;
        while (right < 4) {
            if (gear[cur][2] != gear[right][6]) {
                direction[right] = -direction[cur];
            }
            else break;
            right++;
            cur++;
        }

        // 톱니바퀴 회전하기
        for (int j = 0; j < 4; j++) {
            if (direction[j] == 0) continue;
            rotate(j, direction[j]);
        }
    }

    // 점수 계산하기
    int res = 0;
    for (int i = 0; i < 4; i++) {
        res += gear[i].front() * score[i];
    }
    printf("%d\n", res);
    return 0;
}