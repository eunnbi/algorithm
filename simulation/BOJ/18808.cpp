#include <bits/stdc++.h>
using namespace std;

int N, M, K;
int R, C;
int sticker[11][11];
int notebook[41][41];


// 👀 스티거 90도로 회전하기
void rotate() {
    int tmp[12][12] = { 0, }; // 복사본
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            tmp[i][j] = sticker[i][j];
        }
    }
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            sticker[j][R - 1 - i] = tmp[i][j];
        }
    }
    swap(R, C);
}

// 노트북에 스티커 붙이기
void sol() {
    int i, j, row, col;
    bool isPossible = true;
    for (int dir = 0; dir < 4; dir++) {
        for (i = 0; i <= N - R; i++) {
            for (j = 0; j <= M - C; j++){
                isPossible = true;
                for (row = 0; row < R; row++) {
                    for (col = 0; col < C; col++) {
                        if (notebook[i + row][j + col] && sticker[row][col]) {
                            isPossible = false;
                            break;
                        }
                    }
                    if (!isPossible) break;
                }
                if (isPossible) {
                    for (int x = i; x < row + i; x++) {
                        for (int y = j; y < col + j; y++) {
                            if (sticker[x - i][y - j] == 0) continue;
                            notebook[x][y] = sticker[x - i][y - j];
                        }
                    }
                    return;
                }
            }
        }
        rotate();
    }
}

int main(void) {
    cin >> N >> M >> K;
    for (int i = 0; i < K; i++) {
        cin >> R >> C;
        for (int j = 0; j < R; j++) {
            for (int k = 0; k < C; k++) {
                cin >> sticker[j][k];
            }
        }
        sol();
    }

    int res = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            res += notebook[i][j];
        }
    }
    printf("%d\n", res);
    return 0;
}

// https://www.acmicpc.net/problem/18808