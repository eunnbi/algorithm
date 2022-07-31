#include <bits/stdc++.h>
using namespace std;

int N;
int x, y, d, g;
int board[105][105];
int cnt;

int main(void) {
    cin >> N;
    while (N--) {
        cin >> x >> y >> d >> g;
        vector<int> v; // 방향 저장
        v.push_back(d % 4);
        board[y][x] = 1;

        while (g--) {
            int size = v.size();
            // 👉 세대가 증가할 때마다 기존 세대의 방향(숫자)을 뒤에서부터 1을 더한 방향(숫자)을 추가
            for (int i = size - 1; i >= 0; i--) {
                v.push_back((v[i] + 1) % 4);
            }
        }

        for (int i = 0; i < v.size(); i++) {
            int dir = v[i];
            if (dir == 0) x++;
            else if (dir == 1) y--;
            else if (dir == 2) x--;
            else if (dir == 3) y++;
            board[y][x] = 1;
        }
    }

    for (int i = 0; i < 100; i++){
        for (int j = 0; j < 100; j++){
            if (!board[i][j]) continue;
            if (board[i + 1][j] && board[i][j + 1] && board[i + 1][j + 1]) cnt++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}

// https://www.acmicpc.net/problem/15685