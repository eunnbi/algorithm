#include <bits/stdc++.h>
using namespace std;

int N, M;
int board[10][10];
int vis[10][10];
vector<pair<int, int>> cctvs; // cctv 좌표 저장
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int res = 10000;
int total; // 사각지대 후보 개수 (0)
int val;

void initialize() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            vis[i][j] = 0;
        }
    }
}

void upd(int x, int y, int dir) {
    dir %= 4;
    while (true) {
        x += dx[dir];
        y += dy[dir];
        if (x < 0 || x >= N || y < 0 || y >= M) return;
        if (board[x][y] == 6) return;
        if (board[x][y] != 0 || vis[x][y]) continue;
        vis[x][y] = 1;
        val--;
    }
}

int main(void) {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j] >= 1 && board[i][j] <= 5) {
                cctvs.push_back({ i, j });
            }
            if (board[i][j] == 0) {
                total++;
            }
        }
    }
    int size = cctvs.size();
    int total = 1 << (2 * cctvs.size()); // 총 경우의 수
    for (int i = 0; i < total; i++) {
        initialize(); // vis 배열 초기화
        val = total; // val 변수 초기화
        int brute = i;
        for (int j = 0; j < size; j++) {
            int dir = brute % 4; // ✨ 4진법을 이용하여 cctv 방향 정하기
            brute /= 4;
            int x = cctvs[j].first;
            int y = cctvs[j].second;
            if (board[x][y] == 1) {
                upd(x, y, dir);
            }
            else if (board[x][y] == 2) {
                upd(x, y, dir);
                upd(x, y, dir + 2);
            }
            else if (board[x][y] == 3) {
                upd(x, y, dir);
                upd(x, y, dir + 1);
            }
            else if (board[x][y] == 4) {
                upd(x, y, dir);
                upd(x, y, dir + 1);
                upd(x, y, dir + 2);
            }
            else { // board1[x][y] == 5
                upd(x, y, dir);
                upd(x, y, dir + 1);
                upd(x, y, dir + 2);
                upd(x, y, dir + 3);
            }
        }
        if (res > val) res = val;
    }
    cout << res;
    return 0;
}

// https://www.acmicpc.net/problem/15683