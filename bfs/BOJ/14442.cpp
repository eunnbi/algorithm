#include <bits/stdc++.h>
using namespace std;

int N, M, K;
string board[1002];
int dist[1002][1002][11];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void){
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) cin >> board[i];

    queue<tuple<int, int, int>> Q;
    dist[0][0][0] = 1;
    Q.push({ 0, 0, 0 });

    while (!Q.empty()) {
        int x, y, k;
        tie(x, y, k) = Q.front(); Q.pop();
        if (x == N - 1 && y == M - 1) {
            cout << dist[x][y][k];
            return 0;
        }
        for (int dir = 0; dir < 4; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (board[nx][ny] == '1' && k < K && dist[nx][ny][k + 1] == 0){
                dist[nx][ny][k + 1] = dist[x][y][k] + 1;
                Q.push({ nx, ny, k + 1 });
            }
            else if (board[nx][ny] == '0' && dist[nx][ny][k] == 0) {
                dist[nx][ny][k] = dist[x][y][k] + 1;
                Q.push({ nx, ny, k });
            }
        }
    }
    cout << -1;
    return 0;
}

// https://www.acmicpc.net/problem/14442