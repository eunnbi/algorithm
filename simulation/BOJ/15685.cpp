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
        vector<int> v; // λ°©ν₯ μ μ₯
        v.push_back(d % 4);
        board[y][x] = 1;

        while (g--) {
            int size = v.size();
            // π μΈλκ° μ¦κ°ν  λλ§λ€ κΈ°μ‘΄ μΈλμ λ°©ν₯(μ«μ)μ λ€μμλΆν° 1μ λν λ°©ν₯(μ«μ)μ μΆκ°
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