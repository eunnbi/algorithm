#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int N;
int board[101][101];
int vis[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void){
    int max = -1;
    cin >> N;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> board[i][j];
            if (max < board[i][j]) max = board[i][j];
        }
    }

    int res = 0;
    // num 이하의 높이를 가진 칸은 물에 잠긴다. (1 <= 높이 <= 100)
    // ❗이때 아무 지역도 물에 잠기지 않을 수도 있으므로 num은 반드시 "0"부터 시작해야 한다.
    for (int num = 0; num < max; num++){ // 

        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                vis[i][j] = 0;
            }
        }

        int area = 0;
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                if (board[i][j] <= num || vis[i][j]) continue;
                area++;
                queue<pair<int, int>> Q;
                Q.push({ i, j });
                vis[i][j] = 1;
                while (!Q.empty()){
                    auto cur = Q.front(); Q.pop();
                    for (int dir = 0; dir < 4; dir++){
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                        if (board[nx][ny] <= num || vis[nx][ny]) continue;
                        vis[nx][ny] = 1;
                        Q.push({ nx, ny });
                    }
                }
            }
        }
        if (res < area) res = area;
    }
    cout << res;
    return 0;
}


// https://www.acmicpc.net/problem/2468