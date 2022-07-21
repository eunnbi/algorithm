#include <bits/stdc++.h>
using namespace std;

string stu[5];
bool mask[25]; // false : 소문난 칠공주 O, true : 소문난 칠공주 X
int vis[5][5];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int res;

int main(void){
    for (int i = 0; i < 5; i++){
        cin >> stu[i];
    }

    fill(mask + 7, mask + 25, true); // mask 배열 초기화
    
    do {
        queue<pair<int, int>> Q;
        int dasom = 0; // 칠공주 후보 중 이다솜파의 수
        int adj = 0; // 칠공주 후보 중 가로 세로 인접한 사람 수
        bool isp7[5][5] = {};
        bool vis[5][5] = {};

        // ✨ 소문난 칠공주 후보의 위치 저장
        for (int i = 0; i < 25; i++){
            if (!mask[i]) {
                int x = i / 5;
                int y = i % 5;
                isp7[x][y] = true;
                if (Q.empty()) {
                    Q.push({ x, y });
                    vis[x][y] = true;
                }
            }
        }

        // ✨ 후보들이 가로세로 인접해있는지 BFS로 확인
        while (!Q.empty()) {
            auto cur = Q.front(); Q.pop();
            adj++;
            dasom += stu[cur.first][cur.second] == 'S';
            for (int dir = 0; dir < 4; dir++){
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];
                if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
                if (vis[nx][ny]) continue;
                if (!isp7[nx][ny]) continue; // 소문난 칠공주 후보의 위치가 아닐 경우
                Q.push({ nx, ny });
                vis[nx][ny] = true;

            }
        }

        res += (adj >= 7 && dasom >= 4);

    } while (next_permutation(mask, mask + 25)); // ✨ 25명 중 칠공주가 배치될 수 있는 모든 조합 시도

    cout << res;
    return 0;
}

// https://www.acmicpc.net/problem/1941