#include <bits/stdc++.h>
using namespace std;

int N, M, G, R;
int board[52][52]; // 0, 1, 2
vector<pair<int, int>> cand;
int candSize;
int dx[4] = {1, 0, -1 ,0};
int dy[4] = {0, 1, 0, -1};

const int EMPTY = 0;
const int GREEN = 1;
const int RED = 2;
const int FLOWER = 3;


// next_permutation을 위한 변수
int brute[10];  // candSize가 7, green = 1, red = 4일 때 { 0, 0, 1, 2, 2, 2, 2 }
int sol() {
    int cnt = 0;
    pair<int, int> state[52][52]; // { arrival time, color }
    queue<pair<int, int>> Q;

    // brute 배열에 따라서 배양액 시적점 넣기
    for (int i = 0; i < candSize; i++){
        if (brute[i] == GREEN || brute[i] == RED){
            state[cand[i].first][cand[i].second] = { 0, brute[i] };
            Q.push(cand[i]);
        }
    }

    while (!Q.empty()){
        auto cur = Q.front(); Q.pop();
        int curTime = state[cur.first][cur.second].first;
        int curColor = state[cur.first][cur.second].second;
        if (curColor == FLOWER) continue;
        for (int dir = 0; dir < 4; dir++){
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (board[nx][ny] == 0) continue;
            if (state[nx][ny].second == EMPTY) {
                state[nx][ny] = { curTime + 1, curColor };
                Q.push({ nx, ny });
            }
            else if (state[nx][ny].second == RED) {
                if (curColor == GREEN && state[nx][ny].first == curTime + 1) {
                    cnt++;
                    state[nx][ny].second = FLOWER;
                }
            }
            else if (state[nx][ny].second == GREEN) {
                if (curColor == RED && state[nx][ny].first == curTime + 1) {
                    cnt++;
                    state[nx][ny].second = FLOWER;
                }
            }
        }

    }
    return cnt;
}

int main(void){
    cin >> N >> M >> G >> R;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> board[i][j];
            if (board[i][j] == 2) {
                cand.push_back({ i, j });
            }
        }
    }

    candSize = cand.size();
    // brute 베열 초기화
    fill(brute + candSize - G - R, brute + candSize - R, GREEN);
    fill(brute + candSize - R, brute + candSize, RED);

    int mx = 0;
    int cnt;
    do {
        cnt = sol();
        if (mx < cnt) mx = cnt;

    } while (next_permutation(brute, brute + candSize));
    cout << mx;
    return 0;
}