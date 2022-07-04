#include <bits/stdc++.h>
using namespace std;


int L, R, C;
char building[31][31][31];
int dist[31][31][31];
int dx[6] = { 1, 0, -1, 0, 0, 0 };
int dy[6] = { 0, 1, 0, -1, 0, 0};
int dz[6] = { 0, 0, 0, 0, 1, -1 };

int main(void){
    
    while (true) {
        cin >> L >> R >> C;
        if (L == 0 && R == 0 && C == 0) break;

        queue<tuple<int, int, int>> Q;
        for (int i = 0; i < L; i++){
            for (int j = 0; j < R; j++){
                for (int k = 0; k < C; k++){
                    char ch;
                    cin >> ch;
                    if (ch == '\n') continue;
                    building[i][j][k] = ch;
                    if (ch == 'S') {
                        Q.push({ i, j, k });
                        dist[i][j][k] = 0;
                    }
                    else {
                        dist[i][j][k] = -1;
                    }
                }
            }
        }

        bool isEscape = false;
        while (!Q.empty()){
            int x, y, z;
            tie(z, y, x) = Q.front(); Q.pop();
            for (int dir = 0; dir < 6; dir++){
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                int nz = z + dz[dir];
                if (nz < 0 || nz >= L || ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
                if (building[nz][ny][nx] == '#') continue;
                if (dist[nz][ny][nx] >= 0) continue;
                if (building[nz][ny][nx] == 'E') {
                    cout << "Escaped in " << dist[z][y][x] + 1 << " minute(s)." << '\n';
                    isEscape = true;
                    break;
                }
                dist[nz][ny][nx] = dist[z][y][x] + 1;
                Q.push({ nz, ny, nx });

            }
            if (isEscape) break;
        }
        if (!isEscape) cout << "Trapped!" << '\n'; 
    }
    return 0;
}

// https://www.acmicpc.net/problem/6593