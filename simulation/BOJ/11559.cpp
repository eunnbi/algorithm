#include <bits/stdc++.h>
using namespace std;

string board[12];
int vis[12][6];
queue<pair<int, int>> Q;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int res;

int main(void) {
    for (int i = 0; i < 12; i++) {
        cin >> board[i];
    }

    while (true) {
        bool isPossible = false;
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 6; j++) {
                vis[i][j] = 0;
            }
        }
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 6; j++) {
                if (board[i][j] == '.' || vis[i][j]) continue;
                int num = 0;
                Q.push({ i, j });
                vis[i][j] = 1;
                vector<pair<int, int>> tmp;
                while (!Q.empty()) {
                    auto cur = Q.front(); Q.pop();
                    num++;
                    tmp.push_back({ cur.first, cur.second });
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if (nx < 0 || nx >= 12 || ny < 0 || ny >= 6) continue;
                        if (board[i][j] != board[nx][ny]) continue;
                        if (vis[nx][ny]) continue;
                        vis[nx][ny] = 1;
                        Q.push({ nx, ny });
                    }
                }
                if (num >= 4) {
                    isPossible = true;
                    int size = tmp.size();
                    for (int k = 0; k < size; k++) {
                        int x = tmp[k].first;
                        int y = tmp[k].second;
                        board[x][y] = '.';
                    }
                }
            }
        }
        if (!isPossible) break;
        res += isPossible;
        for (int i = 11; i > 0; i--) {
            for (int j = 0; j < 6; j++) {
                if (board[i][j] == '.') {
                    int row = i;
                    while (row > 0 && board[row][j] == '.') {
                        row--;
                    }
                    board[i][j] = board[row][j];
                    board[row][j] = '.';
                }
            }
        }
    }
    printf("%d\n", res);
    return 0;
}