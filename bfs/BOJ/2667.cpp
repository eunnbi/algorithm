#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int N;
string board[26];
int vis[26][26];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
    cin >> N;

    for (int i = 0; i < N; i++) cin >> board[i];

    int total = 0;
    vector<int> area;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (board[i][j] == '0' || vis[i][j]) continue;
            int res = 0;
            total++;
            queue<pair<int, int>> Q;
            Q.push({ i, j });
            vis[i][j] = 1;
            while (!Q.empty()){
                auto cur = Q.front(); Q.pop();
                res++;
                for (int dir = 0; dir < 4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                    if (board[nx][ny] == '0' || vis[nx][ny]) continue;
                    vis[nx][ny] = 1;
                    Q.push({ nx, ny });
                }
            }
            area.push_back(res);
        }
    }
    sort(area.begin(), area.end());
    cout << total << '\n';
    for (int i : area) cout << i << '\n';
    return 0;
}

// https://www.acmicpc.net/problem/2667